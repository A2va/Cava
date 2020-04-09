/****************************************************************************
* Cava Library: Graphic LCD												
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 26.03.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  A graphic library for LCD
*    This library should be able to work with different drivers as long 
                    as the sending functions are modified.   
*    /!\ Some functions have the possibility to be modified to adapt to /!\
*                             the lcd driver                        			
* Note: 1. The parser system for printfLCD come from this 
        repository https://github.com/drh/lcc
        2. The function SetPixel,Circle and Rect come from this repository
            https://github.com/adafruit/ST7565-LCD
****************************************************************************/
#ifndef GRAPHIC_LCD_H
#define GRAPHIC_LCD_H
#include <stdarg.h>
/****************************************************************************
* LCD SIZE DEFINITION 	    /!\ You can modify this /!\															                       			
****************************************************************************/
#define LCD_SIZEX 128
#define LCD_SIZEY 64
#define LCD_SIZEPAGE 8
/****************************************************************************
* LCD COMMAND DEFINITION 	/!\ You can modify this /!\															                       			
****************************************************************************/
#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF
#define CMD_SET_DISP_START_LINE  0x40
#define CMD_SET_PAGE  0xB0
#define CMD_SET_COLUMN_UPPER  0x10
#define CMD_SET_COLUMN_LOWER  0x00
#define CMD_SET_ADC_NORMAL  0xA0
#define CMD_SET_ADC_REVERSE 0xA1
#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7
#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON  0xA5
#define CMD_SET_BIAS_9 0xA2 
#define CMD_SET_BIAS_7 0xA3
#define CMD_RMW  0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET  0xE2
#define CMD_SET_COM_NORMAL  0xC0
#define CMD_SET_COM_REVERSE  0xC8
#define CMD_SET_POWER_CONTROL  0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST  0x81
#define CMD_SET_VOLUME_SECOND  0
#define CMD_SET_STATIC_OFF  0xAC
#define CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_SET_BOOSTER_234  0
#define CMD_SET_BOOSTER_5  1
#define CMD_SET_BOOSTER_6  3
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0
/****************************************************************************
* INZERNAL DEFINITION  															                       			
****************************************************************************/
#define LCD_PAGE (LCD_SIZEY /LCD_SIZEPAGE)
#define swap(a, b) { unsigned char t = a; a = b; b = t; }
/****************************************************************************
* FONT DEFINITION 														                       			
****************************************************************************/
#define FONT_WIDTH_FRAME 2
#define FONT_HEIGHT_FRAME 3
#define FONT_CHAR0_FRAME 4
#define FONT_NUMCHAR_FRAME 5
#define FONT_FIRSTCHAR_FRAME 6
#define FONT_CHARWIDTH_FRAME 7
typedef struct str_font str_font;
struct str_font
{
    unsigned char *firstChar;
    unsigned char *charWidth;
    unsigned char numChar;
    unsigned char numBytesinChar;
    unsigned char fontWidth;
    unsigned char fontHeight;
    unsigned char Char0;
};
/****************************************************************************
* BUFFER DEFINITION 																                       			
****************************************************************************/
unsigned char Buffer[LCD_SIZEX*LCD_PAGE];
/****************************************************************************
* Function SetPixel()														
*		Input Parameter: x,y,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*         Set a pixel on buffer											    
****************************************************************************/
void SetPixel(unsigned char x, unsigned char  y, unsigned char  color);
/****************************************************************************
* Function DrawCircle()																					
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*          Set a pixel on buffer											    
****************************************************************************/
void DrawCircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color);
/****************************************************************************
* Function FillCircle()																																
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*           Set a  fill circle on buffer											    
****************************************************************************/
void FillCircle(unsigned char x0, unsigned char y0, unsigned char r, unsigned char color); 
/****************************************************************************
* Function DrawRect()																																
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*          Draw a rectangle on buffer										    
****************************************************************************/
void DrawRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color);
/****************************************************************************
* Function FillRect()								                       																			
*	  Input Parameter: x0,y0 et width,height,color(0,1) 		
*	  Output Parameter: None										
*															
*	  Description															
*	        Fill a rectangle on buffer                               		        
******************************************************************************/
void FillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color);
/****************************************************************************
* Fonction DrawLine()								                        																		
*	  Input Parameter: x0,y0 et x1,y1,color(0,1) 	
*	  Output Parameter:	None										
*														
*	  Description															
*	    Display a line                                        		        
****************************************************************************/
void DrawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char color);
/****************************************************************************
* Fonction DrawChar()								                        																			
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw character on buffer                              		        
******************************************************************************/
void DrawChar(unsigned char x,unsigned char y,str_font font,unsigned char c);
/****************************************************************************
* Fonction DrawString()								                        																			
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw string on buffer                              		        
******************************************************************************/
void DrawString(unsigned char x, unsigned char y,str_font font, unsigned char *c);
/****************************************************************************
* Fonction printfLCD()								                        																			
*	  Input Parameter: x,y,font,String,variable	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Equivalent printf for lcd                           		        
******************************************************************************/
void printfLCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...);
/****************************************************************************
* Fonction Parser()								                        																		
*	  Input Parameter: x,y,font,String,ap	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Parser for printfLCD                           		        
******************************************************************************/
void Parser(unsigned char x,unsigned char y,str_font font, const char *fmt, va_list ap);
/****************************************************************************
* Fonction Outd()								                        																			
*	  Input Parameter: x,y,font,number,bp
*	  Output Parameter:	None										
*															
*	  Description															
*	    Converts a number into a string in the base 10                         		        
******************************************************************************/
void Outd(unsigned char x ,unsigned char y,str_font font,long n);
/****************************************************************************
* Fonction Outu()								                        																			
*	  Input Parameter: x,y,font,number,base
*	  Output Parameter:	None										
*															
*	  Description															
*	    Converts a number into a string in the desired base                          		        
******************************************************************************/
void Outu(unsigned char x,unsigned char y,str_font font,unsigned long n, int base);
/****************************************************************************
* Fonction ClearBuffer()								                        																			
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Clear buffer                              		        
******************************************************************************/
void ClearBuffer();
/****************************************************************************
* Fonction InitFont()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	font										
*															
*	  Description															
*	    Init a font                            		        
******************************************************************************/
str_font InitFont(unsigned char *fontData);
#endif