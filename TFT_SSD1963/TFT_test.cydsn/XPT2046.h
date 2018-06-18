/*******************************************************************************
* File Name: XPT2046.h
*
* Description:
*  This is a driver for the Touch Screen Controller  XPT2046 
*
*  Data send and get by SPI
*
********************************************************************************
* Copyright (c) 2018 Andres F. Navas
*******************************************************************************/

#include <project.h>

#define  XPT2046_IRQ     T_IRQ_Read()           // Define the IRQ pin to read

uint16 PosX;
uint16 PosY;

uint16 XPT2046_ReadPos(uint16 coord);           // Reading pen coordinate 0x90 - Y coordinate; 0xD0 is the X coordinate; 0xC0 & 0xB0 are Z2 & Z1 coordinates (pressure)
void XPT2046_Start(void);                       // Start controller, enable T_IRQ
uint8 XPT2046_ReadXY(uint16 *X,  uint16 *Y);    // Obtaining X and Y coordinates with Basic Calibration
uint16 XPT2046_ReadZ(void);                     // Obtaining Z coordinate Data Raw (ADC Pressure on Touch Panel)

//*******************    End of File    ********************