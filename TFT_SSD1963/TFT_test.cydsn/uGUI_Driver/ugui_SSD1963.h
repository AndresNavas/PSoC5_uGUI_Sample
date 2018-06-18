/*******************************************************************************
* File Name: ugui_SSD1963.h  
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

#if !defined(PSOC_UGUI_SSD1963_H)
#define PSOC_UGUI_SSD1963_H

#include "ugui.h"
    
/* *** Configuration. *** */
    
    /* Set here the name you have given to display CD and RESET signals in your schematic. */
#define DISPLAY_RESET           GraphicLCDIntf_Write8(0, 0x01)
#define DISPLAY_CD              DISP_CD
    
    /* Set here your display resolution. */
#define DISPLAY_WIDTH           800
#define DISPLAY_HEIGHT          480
    

#define CONCATENATE(name, function)                 CONCAT(name, function)
#define CONCAT(name, function)                      name##function

#define mmDisplayReset_Write(value) CONCATENATE(DISPLAY_RESET, _Write(value))
#define mmDisplayCD_Write(value)    CONCATENATE(DISPLAY_CD, _Write(value))
    
/* *** Glogal GUI structure for this. *** */
UG_GUI gui1963;

/* *** Function prototypes. *** */
void Display_Init();
void Display_PSet(UG_S16 x, UG_S16 y, UG_COLOR c);
void Display_WindowSet(unsigned int s_x,unsigned int e_x,unsigned int s_y,unsigned int e_y);

    // Accelerators.
UG_RESULT HW_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c);
UG_RESULT HW_DrawLine(UG_S16 x1 , UG_S16 y1 , UG_S16 x2 , UG_S16 y2 , UG_COLOR c );
UG_RESULT HW_DrawImage(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, uint8_t *image, uint16_t pSize);

#endif /* End PSOC_UGUI_SSD1963_H */    

/* [] END OF FILE */

