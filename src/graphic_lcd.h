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
*                   as the sending functions are modified.   
*    /!\ Some functions have the possibility to be modified to adapt to /!\
*                             the lcd driver                        			
*    Note: 1. The parser system for printfLCD come from this 
*                   repository https://github.com/drh/lcc
*        2. The function SetPixel,Circle and Rect come from this repository
*                       https://github.com/adafruit/ST7565-LCD
*        3. You will need to modify these functions in order for it to work 
*            with your LCD (Init_Bus,LCD_Transmit, Bus_Init and Bus_Transmit) 
*                               and maybe LCD_SetPos  
****************************************************************************/
#ifndef GRAPHIC_LCD_H
#define GRAPHIC_LCD_H
#include <stdarg.h>
/****************************************************************************
* LCD SIZE DEFINITION 	/!\ You may need modify this according to your lcd /!\															                       			
****************************************************************************/
#define LCD_SIZEX 128
#define LCD_SIZEY 64
#define LCD_SIZEPAGE 8
/****************************************************************************
* LCD COMMAND DEFINITION /!\ You may need modify this according to your lcd /!\															                       			
****************************************************************************/
//These definitions are taken from the EA DOGM128E-6 LCD
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
#define CMD_SET_POWER_CONTROL  0x2F
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLTREG 0x27
#define CMD_SET_VOLUME_FIRST  0x81
#define CMD_SET_VOLUME_SECOND  0x16
#define CMD_SET_STATIC_OFF  0xAC
#define CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_ON 0x2F
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0
/****************************************************************************
* LCD INIT PROCEDURE /!\ You may need modify this according to your lcd /!\															                       			
****************************************************************************/
//These init procedure are taken from the EA DOGM128E-6 LCD
#define NUMBER_FRAME_INIT 14
const unsigned char LCD_Init_Tab[NUMBER_FRAME_INIT]={CMD_SET_DISP_START_LINE,CMD_SET_ADC_REVERSE,CMD_SET_COM_NORMAL,
CMD_SET_DISP_NORMAL,CMD_SET_BIAS_9,CMD_SET_BOOSTER_ON,CMD_SET_BOOSTER_FIRST,0x00,
CMD_SET_VOLTREG,CMD_SET_VOLUME_FIRST,CMD_SET_VOLUME_SECOND,CMD_SET_STATIC_OFF,0x00,CMD_DISPLAY_ON};
/****************************************************************************
* INTERNAL DEFINITION  															                       			
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
*	  Input Parameter: x,y,font,character	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw character on buffer                              		        
******************************************************************************/
void DrawChar(unsigned char x,unsigned char y,str_font font,unsigned char c);
/****************************************************************************
* Fonction DrawString()								                        																			
*	  Input Parameter: x,y,string, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw string on buffer                              		        
******************************************************************************/
void DrawString(unsigned char x, unsigned char y,str_font font, unsigned char *c);
/****************************************************************************
* Fonction printfLCD()								                        																			
*	  Input Parameter: x,y,font,string,variable	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Equivalent printf for lcd                           		        
******************************************************************************/
void printfLCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...);
/****************************************************************************
* Fonction Parser()								                        																		
*	  Input Parameter: x,y,font,string,ap	
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
* Fonction Buffer_Clear()								                        																			
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Clear buffer                              		        
******************************************************************************/
void Buffer_Clear();
/****************************************************************************
* Fonction Buffer_Write()								                        																			
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Write buffer on bus                             		        
******************************************************************************/
void Buffer_Write();
/****************************************************************************
* Fonction Font_Init()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	font										
*															
*	  Description															
*	    Init a font                            		        
******************************************************************************/
str_font Font_Init(unsigned char *fontData);
/****************************************************************************
* Fonction Bus_Init()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Init the bus                            		        
******************************************************************************/
void Bus_Init();
/****************************************************************************
* Fonction LCD_Init()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Init LCD                            		        
******************************************************************************/
void LCD_Init();
/****************************************************************************
* Fonction LCD_Clear()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Clear LCD                            		        
******************************************************************************/
void LCD_Clear();
/****************************************************************************
* Fonction LCD_SetPos()								                        																		
*	  Input Parameter: x,y	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Set Position on LCD                            		        
******************************************************************************/
void LCD_SetPos(unsigned char x,unsigned char y);
/****************************************************************************
* Fonction LCD_Transmit()								                        																		
*	  Input Parameter: Data,Cd(0,1)	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Transmit a data or command on LCD                            		        
******************************************************************************/
void LCD_Transmit(unsigned char Data,unsigned Cd);
/****************************************************************************
* Fonction Bus_Transmit()								                        																		
*	  Input Parameter: Data	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Transmit data on LCD                            		        
******************************************************************************/
void Bus_Transmit(unsigned char Data);
/****************************************************************************
* Fonction Example_LCD()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    A example function                           		        
******************************************************************************/
void Example_LCD();
#endif