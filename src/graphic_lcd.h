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
****************************************************************************/
#ifndef GRAPHIC_LCD_H
#define GRAPHIC_LCD_H
#include <stdarg.h>
//Swap
#define swap(a, b) { unsigned char t = a; a = b; b = t; }

/****************************************************************************
* LCD SIZE DEFINITION 																                       			
****************************************************************************/
#define LCD_SIZEX 128
#define LCD_SIZEY 64
#define LCD_SIZEPAGE 8


/****************************************************************************
* INZERNAL DEFINITION  															                       			
****************************************************************************/
#define LCD_PAGE (LCD_SIZEY /LCD_SIZEPAGE)
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
*		Prototype	:void SetPixel(unsigned char x, unsigned char  y, unsigned char  color);				
*																			
*		Input Parameter: x,y,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Set a pixel on buffer											    
****************************************************************************/
void SetPixel(unsigned char x, unsigned char  y, unsigned char  color);
/****************************************************************************
* Function DrawCircle()														
*		Prototype	:	  void DrawCircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color);				
*																			
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Set a pixel on buffer											    
****************************************************************************/
void DrawCircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color);
/****************************************************************************
* Function DrawCircle()														
*		Prototype	:	  void FillCircle(unsigned char x0, unsigned char y0, unsigned char r, unsigned char color);				
*																			
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Set a  fill circle on buffer											    
****************************************************************************/
void FillCircle(unsigned char x0, unsigned char y0, unsigned char r, unsigned char color); 
/****************************************************************************
* Function DrawRect()														
*		Prototype	:	  void DrawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h,uint8_t color);			
*																			
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Draw a rectangle on buffer										    
****************************************************************************/
void DrawRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color);
/****************************************************************************
* Function FillRect()								                        
* Prototype: void FillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color);								
*																			
*	  Input Parameter: x0,y0 et width,height,color(0,1) 		
*	  Output Parameter: None										
*															
*	  Description															
*	 Fill a rectangle on buffer                               		        
******************************************************************************/
void FillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color);
/****************************************************************************
* Fonction DrawLine()								                        
* Prototype: void DrawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char color);								
*																			
*	  Input Parameter: x0,y0 et x1,y1,color(0,1) 	
*	  Output Parameter:	None										
*														
*	  Description															
*	 Affiche un ligne                                        		        
****************************************************************************/
void DrawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char color);
/****************************************************************************
* Fonction DrawChar()								                        
* Prototype: void DrawChar(unsigned char x,unsigned char y,unsigned char c,str_font font);								
*																			
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Draw character on buffer                              		        
******************************************************************************/
void DrawChar(unsigned char x,unsigned char y,str_font font,unsigned char c);
/****************************************************************************
* Fonction DrawString()								                        
* Prototype: void DrawString(unsigned char x, unsigned char y, unsigned char *c,str_font font);							
*																			
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Draw string on buffer                              		        
******************************************************************************/
void DrawString(unsigned char x, unsigned char y,str_font font, unsigned char *c);
/****************************************************************************
* Fonction printfLCD()								                        
* Prototype: void printfLCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...);								
*																			
*	  Input Parameter: x,y,font,String,variable	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Equivalent printf for lcd                           		        
******************************************************************************/
void printfLCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...);
/****************************************************************************
* Fonction Parser()								                        
* Prototype: Parser(unsigned char x,unsigned char y,str_font font, const char *fmt, va_list ap);								
*																			
*	  Input Parameter: x,y,font,bp,String,ap	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Equivalent printf for lcd                           		        
******************************************************************************/
void Parser(unsigned char x,unsigned char y,str_font font, const char *fmt, va_list ap);
/****************************************************************************
* Fonction Outd()								                        
* Prototype: void Outd(unsigned char x ,unsigned char y,str_font font,long n, char *bp);								
*																			
*	  Input Parameter: x,y,font,number,bp
*	  Output Parameter:	None										
*															
*	  Description															
*	 Converts a number into a string in the base 10                         		        
******************************************************************************/
void Outd(unsigned char x ,unsigned char y,str_font font,long n);
/****************************************************************************
* Fonction Outu()								                        
* Prototype: void Outu(unsigned char x,unsigned char y,str_font font,unsigned long n, int base, char *bp);							
*																			
*	  Input Parameter: x,y,font,number,base,bp
*	  Output Parameter:	None										
*															
*	  Description															
*	 Converts a number into a string in the desired base                          		        
******************************************************************************/
void Outu(unsigned char x,unsigned char y,str_font font,unsigned long n, int base);
/****************************************************************************
* Fonction ClearBuffer()								                        
* Prototype: void ClearBuffer(voir en dessous);								
*																			
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Clear buffer                              		        
******************************************************************************/
void ClearBuffer();
/****************************************************************************
* Fonction InitFont()								                        
* Prototype: str_font InitFont();								
*																			
*	  Input Parameter: None	
*	  Output Parameter:	font										
*															
*	  Description															
*	 Init a font                            		        
******************************************************************************/
str_font InitFont(unsigned char *fontData);
#endif