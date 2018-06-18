/*******************************************************************************
* File Name: ugui_SSD1963.c
*
* Description:
*  This is a driver for the uGui graphical library developed by 
*  Achim Döbler.
*  It is for SSD1963 graphic controller found in a lot of low cost graphics 
*  chinese displays an to be used with PSoC microcontrollers from Cypress.
*  Will test it with other PSoC micros as soon as I can.
*
* Note:
*  For more information about uGui...
*  Website: http://www.embeddedlightning.com/ugui/
*  Git: https://github.com/achimdoebler/UGUI
*  Forum: http://www.embeddedlightning.com/forum/
*  PDF Reference manual (excellent): http://www.embeddedlightning.com/download/reference-guide/?wpdmdl=205
*
*  Thanks to Achim Döbler for such a god job.
*
* Log version:
*  1.0 - June, 2018.       First version.
*
********************************************************************************
* Copyright (c) 2018 Andres F. Navas
* This driver follows the same license than the uGui library.
*******************************************************************************/

#include <project.h>
#include "ugui.h"
#include "ugui_SSD1963.h"

#define HDP (DISPLAY_WIDTH - 1)
#define VDP (DISPLAY_HEIGHT - 1)

inline void Display_WriteCommand(uint8_t command)
{
    GraphicLCDIntf_Write8(0, command);
}

inline void Display_WriteData(uint8_t data)
{
    GraphicLCDIntf_Write8(1, data);
}

inline void Display_WriteMultiData(uint8_t *data, uint16 size)
{
    GraphicLCDIntf_WriteM8(1, data, size);
}

inline void Display_Reset()
{
    Display_WriteCommand(0x01);         //Software reset
    CyDelay(10);
}

void Display_Init()
{
    int i;
    
    CyDelay(100);
	
    for(i = 0; i < 5; i++)              // Hardware reset
    {
        D_RST_Write(0);
		CyDelay(10);
        D_RST_Write(1);
        CyDelay(10);
	}
    
    Display_Reset();                    //Software reset
    CyDelay(5);
    Display_Reset();                    //Software reset
    CyDelay(5);
    Display_Reset();                    //Software reset
    CyDelay(5);

    Display_WriteCommand(0xe2);         //set multiplier and divider of PLL
    Display_WriteData(0x23);            //PLL = 120MHz
    Display_WriteData(0x02);
    Display_WriteData(0x04);
    
    Display_WriteCommand(0xe0);
    Display_WriteData(0x01);            //Enable PLL
    CyDelay(10);
    
    Display_WriteCommand(0xe0);
    Display_WriteData(0x03);            //Lock PLL
    CyDelay(10);
    Display_Reset();                    //Software reset
       
    Display_WriteCommand(0xe6);   		//SET PCLK Freq = 33.26MHz
    Display_WriteData(0x04);            
    Display_WriteData(0x6f);            
    Display_WriteData(0x46);
    
    Display_WriteCommand(0xb0);		    //SET LCD MODE 
    Display_WriteData(0x27);			//SET TFT 24-Bit MODE / Sync pulse active Low & Rising Edge
    Display_WriteData(0x00);			//SET TFT MODE / SET Hsync + Vsync + DE MODE
    Display_WriteData((HDP>>8)&0x00ff); //SET HDP Horizontal size = Display Width - 1 HightByte = 799 ((800x480 PANEL))
    Display_WriteData(HDP & 0x00ff);    //SET HPS Horizontal size = Display Width - 1 LowByte
    Display_WriteData((VDP>>8)&0x00ff); //SET VDP Vertical size = Display Height - 1 HightByte  = 479
    Display_WriteData(VDP & 0x00ff);	//SET VPS Vertical size = Display Height - 1 LowByte
    Display_WriteData(0x00);			//SET Even/Odd line RGB sequence = RGB 

    Display_WriteCommand(0xb4);         //SET HBP,
    Display_WriteData(0x03);            //SET HT Hsync Total = 928 HightByte
    Display_WriteData(0xa0);            //SET HT Hsync Total = 928 LowByte
    Display_WriteData(0x00);            //SET HPS  0 HightByte
    Display_WriteData(0x2e);            //SET HPS 46 LowByte
    Display_WriteData(0x30);            //SET HPW 48 
    Display_WriteData(0x00);            //SET LPS Hsync pulse start position  0 HighByte
    Display_WriteData(0x0f);            //SET LPS Hsync pulse start position 15 LowByte
    Display_WriteData(0x00);            //SET LPSPP Hsync pulse subpixel start position
    
    Display_WriteCommand(0xb6);         //SET VBP,
    Display_WriteData(0x02);            //SET VT Vsync total = 525 HighByte
    Display_WriteData(0x0d);            //SET VT Vsync total = 525 LowByte
    Display_WriteData(0x00);            //SET VPS  0 HighByte
    Display_WriteData(0x10);            //SET VPS 16 LowByte
    Display_WriteData(0x10);            //SET VPW Vsync pulse 16 Byte
    Display_WriteData(0x00);            //SET FPS Vsync pulse start position  0 HighByte
    Display_WriteData(0x19);            //SET FPS Vsync pulse start position 25 LowByte 
    
    Display_WriteCommand(0x36);
    Display_WriteData(0x00);	        //SET rotation
    
    Display_WriteCommand(0xf0);
    Display_WriteData(0x00);	        //SET pixel data I/F format=8bit
    
    CyDelay(5);
    
    Display_WriteCommand(0x29);		//SET display on
    CyDelay(10);
   
    // Initialize global structure and set PSET to this.PSET. 
    UG_Init(&gui1963, Display_PSet, DISPLAY_WIDTH, DISPLAY_HEIGHT); 
    
    // Register acceleratos.
    UG_DriverRegister(DRIVER_FILL_FRAME, (void*)HW_FillFrame);
    UG_DriverRegister(DRIVER_DRAW_LINE, (void*)HW_DrawLine);
    UG_DriverRegister(DRIVER_DRAW_IMAGE, (void*)HW_DrawImage);
    
}

void Display_WindowSet(unsigned int s_x,unsigned int e_x,unsigned int s_y,unsigned int e_y)
{
    uint8_t data[4];
    
    data[0] = ((s_x)>>8);                   //SET start column address
    data[1] = (s_x);
    data[2] = ((e_x)>>8);			        //SET end column address
    data[3] = (e_x);
	Display_WriteCommand(0x2a);		        //SET column address
    Display_WriteMultiData(data, 4);

	
    data[0] = ((s_y)>>8);                   //SET start row address
    data[1] = (s_y);
    data[2] = ((e_y)>>8);			        //SET end row address
    data[3] = (e_y);
	Display_WriteCommand(0x2b);		        //SET row address
    Display_WriteMultiData(data, 4);
}

void Display_PSet(UG_S16 x, UG_S16 y, UG_COLOR c)
{    
    uint8_t data[3];
    
    data[0] = (c >> 16);
    data[1] = (c >> 8);
    data[2] = (c);
    
    if((x < 0) ||(x >= DISPLAY_WIDTH) || (y < 0) || (y >= DISPLAY_HEIGHT)) return;
 
    Display_WindowSet(x, x + 1, y, y + 1);    
    Display_WriteCommand(0x2c);
    Display_WriteMultiData(data, 3);

}

UG_RESULT HW_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c)
{
    uint16 loopx, loopy;
    uint8_t data[3];
    
    data[0] = (c >> 16);
    data[1] = (c >> 8);
    data[2] = (c);
    
    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;

    Display_WindowSet(x1,x2,y1,y2);

    Display_WriteCommand(0x2c);            
    for (loopx = x1; loopx < x2 + 1; loopx++)
    {
        for (loopy = y1; loopy < y2 + 1; loopy++)
        {
            Display_WriteMultiData(data, 3);
        }
    } 
    
    return UG_RESULT_OK;
}

UG_RESULT HW_DrawLine( UG_S16 x1 , UG_S16 y1 , UG_S16 x2 , UG_S16 y2 , UG_COLOR c )
{
    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    
    // If it is a vertical or a horizontal line, draw it.
    // If not, then use original drawline routine.
    if ((x1 == x2) || (y1 == y2)) 
    {
        HW_FillFrame(x1, y1, x2, y2, c);
        return UG_RESULT_OK;
    }
    
    return UG_RESULT_FAIL;
}

UG_RESULT HW_DrawImage(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, uint8_t *image, uint16_t pSize)
{
        
    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;

    Display_WindowSet(x1,x2,y1,y2);

    Display_WriteCommand(0x2c);            
    Display_WriteMultiData(image, pSize*3);
    
    return UG_RESULT_OK;
}

/* [] END OF FILE */
