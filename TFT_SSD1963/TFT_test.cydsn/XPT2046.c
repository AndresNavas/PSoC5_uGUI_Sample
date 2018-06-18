/*******************************************************************************
* File Name: XPT2046.c
*
* Description:
*  This is a driver for the Touch Screen Controller  XPT2046 
*
*  Data send and get by SPI
*  Read Pos Coordinates X & Y with Basic Calibration
*  Read Z Coordinate in Data Raw for Touch Pressure
********************************************************************************
* Copyright (c) 2018 Andres F. Navas
*******************************************************************************/

#include <project.h>
#include <stdlib.h>
#include "XPT2046.h"
#include "ugui_SSD1963.h"

#define DelayCycles         10      // About 400ns period for 63MHz BUS Clock
#define XPT2046_MAX_ADC     0x0fff  // Max ADC Value of 12bits
#define X_Min               120     // Min and Max coordinates in raw values for calibration
#define X_Max               4000
#define Y_Min               200
#define Y_Max               3712

//**********************************************************
//******** Send data to XPT2046   Touch Controller *********
//********            SPI Transaction              *********
//**********************************************************
inline void Write_2046(unsigned char Num)          
{
    unsigned char count = 0;
    T_CLK_Write(0);
    for(count = 0; count < 8; count++)  // Command control 8 bits
    {
        if(Num & 0x80) T_DIN_Write(1);   // Write command from MSB  to LSB        
        else T_DIN_Write(0);
        T_CLK_Write(0);                 // Rising Edge to write
        CyDelayCycles(DelayCycles);
        T_CLK_Write(1);
        CyDelayCycles(DelayCycles);
        Num <<= 1;                      // Shift the register
    }
}

//**********************************************************
//******** Get data from XPT2046  Touch Controller *********
//********            SPI Transaction              *********
//**********************************************************
inline uint16 Read_2046()             
{
	uint8 count = 0;
	uint16 Num = 0;
	for(count = 0; count < 12; count++)     // ADC Data read 12 bits
	{
		Num <<= 1;		                    // Shift the register
		T_CLK_Write(1);                     // Falling Edge to read
        CyDelayCycles(DelayCycles);           
		T_CLK_Write(0);
        CyDelayCycles(DelayCycles);
		Num |= T_DO_Read();	            // Read the data from MSB to LSB
	}

return(Num);
}	

//**********************************************************
//******    Reading the position of the coordinate    ******
//******            Data RAW / 12Bits ADC             ******
//**********************************************************
uint16 XPT2046_ReadPos(uint16 coord)
{
    uint16 pos;
    T_CS_Write(0);
    Write_2046(coord);                    // Send Command     
    T_CLK_Write(1);
    CyDelayCycles(DelayCycles);           //Falling Edge to continue
    T_CLK_Write(0);
    CyDelayCycles(DelayCycles);
    pos = Read_2046();                    // Read ADC data
    T_CS_Write(1);
    return pos;
}

//**********************************************************
//*****************    Start controller   ******************
//*****************  Enable the Touch IRQ ******************
//**********************************************************
void XPT2046_Start(void)
{
    XPT2046_ReadPos(0x80);
    CyDelay(5);
}

//**********************************************************
//*****************   Obtain X and Y Pos  ******************
//*****************   Basic  Calibration  ******************
//**********************************************************
uint8 XPT2046_ReadXY(uint16 *X,  uint16 *Y)  // Return 1 if data is valid
{
    uint16 x0, y0, x1, y1, xav, yav, px, py;
    uint16 timeout = 0;
    
    do{         
        XPT2046_ReadPos(0x90);                         
        y0 = XPT2046_ReadPos(0x90);     // read coordinate Y
        y1 = XPT2046_ReadPos(0x90);     // again...
                              
        XPT2046_ReadPos(0xd0);
        x0 = XPT2046_ReadPos(0xd0);     // read coordinate X
        x1 = XPT2046_ReadPos(0xd0);	    // again...                     
        
        timeout++;                      // Incr. Time Out
   }while(((abs(x0 - x1) > 50) && (abs(y0 - y1) > 50)) || timeout >= 255);     // Cycle if the error is less than 50 ADC data raw aprox. 10px or Time out

    if(timeout < 255)       // Cycle ends with good data
    { 
        // Update the current coordinate values
        xav  = (x0 + x1)/2;                                     // Data raw Average for X and Y
        yav  = XPT2046_MAX_ADC - ((y0 + y1)/2);                 // Normalization of touchpad to achieve the same origin points (0,0) for the TFT and Touchpad.
        px = ((xav - X_Min) * DISPLAY_WIDTH) / (X_Max - X_Min); // Calibration for LCD Panel Size; needs Max & Min data Raw for each coordinate
        if(px <= 0) px = 0;
        if(px >= DISPLAY_WIDTH) px = DISPLAY_WIDTH;
        py = ((yav - Y_Min) * DISPLAY_HEIGHT) / (Y_Max - Y_Min);
        if(py <= 0) py = 0;
        if(py >= DISPLAY_HEIGHT) py = DISPLAY_HEIGHT;
        *X = px;
        *Y = py;
        return(1);      // Data Valid
    }
    else
    {
        return(0);      // Data not valid
    }
}

//**********************************************************
//**************    Obtain Z Coordinate    *****************
//**************  Touch Pressure RAW Data  *****************
//**********************************************************
uint16 XPT2046_ReadZ(void)
{
    return(XPT2046_ReadPos(0xc0) - XPT2046_ReadPos(0xb0));      // Z Data Raw is inverse, so 4095 is min (no Touched), Touch pressure avrg. under 2500
}

//*******************    End of File    ********************