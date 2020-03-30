/****************************************************************************
* Cava Library: Graphic LCD												
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 26.03.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  Chained List see graphic_lcd.h	                        			
****************************************************************************/
#include "graphic_lcd.h"
#include <string.h>
#include <stdlib.h>
//https://github.com/adafruit/ST7565-LCD
/****************************************************************************
* Function SetPixel()														
*		Prototype	:	  void SetPixel(unsigned char x, unsigned char  y, unsigned char  color);				
*																			
*		Input Parameter: x,y,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Set a pixel on buffer											    
****************************************************************************/
void 
SetPixel(unsigned char x, unsigned char  y, unsigned char  color)
{
	 if ((x >= LCD_SIZEX) || (y >= LCD_SIZEY))
    return;
	if (color) 
	{
		 Buffer[x+ (y/LCD_SIZEPAGE)*LCD_SIZEX] |=(0x80>>(7-(y%LCD_SIZEPAGE)));
	}
	else
	{
        Buffer[x+ (y/LCD_SIZEPAGE)*LCD_SIZEX]= ~(0x80>>(7-(y%LCD_SIZEPAGE)));
	}
}
/****************************************************************************
* Function DrawCircle()														
*		Prototype	:	  void DrawCircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color);				
*																			
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	  Description															
*     Set a circle on buffer											    
****************************************************************************/
void DrawCircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color) 
{
  char f = 1 - r;
  char ddF_x = 1;
  char ddF_y = -2 * r;
  char x = 0;
  char y = r;

  SetPixel(x0, y0+r, color);
  SetPixel(x0, y0-r, color);
  SetPixel(x0+r, y0, color);
  SetPixel(x0-r, y0, color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    SetPixel(x0 + x, y0 + y, color);
    SetPixel(x0 - x, y0 + y, color);
    SetPixel(x0 + x, y0 - y, color);
    SetPixel(x0 - x, y0 - y, color);
    
    SetPixel(x0 + y, y0 + x, color);
    SetPixel(x0 - y, y0 + x, color);
    SetPixel(x0 + y, y0 - x, color);
    SetPixel(x0 - y, y0 - x, color);
    
  }
}
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
void FillCircle(unsigned char x0, unsigned char y0, unsigned char r, unsigned char color) 
{
  
  char f = 1 - r;
  char ddF_x = 1;
  char ddF_y = -2 * r;
  char x = 0;
  char y = r;
  unsigned char i=0;

  for (i=y0-r; i<=y0+r; i++) 
  {
    SetPixel(x0, i, color);
  }

  while (x<y) 
  {
    if (f >= 0) 
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    for (i=y0-y; i<=y0+y; i++) 
    {
      SetPixel(x0+x, i, color);
      SetPixel(x0-x, i, color);
    } 
    for (i=y0-x; i<=y0+x; i++) 
    {
      SetPixel(x0+y, i, color);
      SetPixel(x0-y, i, color);
    }    
  }
}
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
void DrawRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color) 
{
	unsigned char i=0;
	for (i=x; i<(x+w); i++) 
  {
		SetPixel(i, y, color);
		SetPixel(i, y+h-1, color);
	}
	for (i=y; i<(y+h); i++) 
  {
		SetPixel(x, i, color);
		SetPixel(x+w-1, i, color);
	}
}
/****************************************************************************
* Fonction FillRect()								                        
* Prototype: void FillRect(voir en dessous);								
*																			
*	  Input Parameter: x0,y0 et width,height,color(0,1) 		
*	  Output Parameter:	None										
*															
*	  Description															
*	 Fill a rectangle on buffer                               		        
******************************************************************************/
void FillRect(unsigned char x, unsigned char y, unsigned char w, unsigned char h,unsigned char color) 
{

  unsigned char i=0;
  unsigned char j=0;
	for (i=x; i<x+w; i++) 
	{
		for (j=y; j<y+h; j++) 
		{
			SetPixel(i, j, color);
		}
	}

}
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
void DrawLine(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char color)
{

  char steep = abs(y1 - y0) > abs(x1 - x0);
  char err=0;
  char ystep=0;
  unsigned char dx, dy;
  if (steep) 
  {
    swap(x0, y0);
    swap(x1, y1);
  }

  if (x0 > x1) 
  {
    swap(x0, x1);
    swap(y0, y1);
  }

  dx = x1 - x0;
  dy = abs(y1 - y0);

  err = dx / 2;
  ystep;

  if (y0 < y1) 
  {
    ystep = 1;
  } else {
    ystep = -1;}

  for (; x0<x1; x0++) 
  {
    if (steep) 
    {
      SetPixel(y0, x0, color);
    } 
    else 
    {
      SetPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) 
    {
      y0 += ystep;
      err += dx;
    }
  }
}
/****************************************************************************
* Fonction DrawChar()								                        
* Prototype: void DrawChar(unsigned char x,unsigned char y,unsigned char *c,str_font font);							
*																			
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	 Draw character on buffer                              		        
******************************************************************************/
void DrawChar(unsigned char x,unsigned char y,unsigned char c,str_font font)
{
  unsigned char *car=font.firstChar;
  unsigned char i=0;
  unsigned char j=0;
  unsigned char WidthChar=*(font.charWidth+c-33);
  unsigned char Page=y/LCD_SIZEPAGE;
  for (i = 0; i < c-33; i++)
  {
    car=(*(font.charWidth+i)*font.numBytesinChar)+car;
  }


  for (i = 0; i < font.numBytesinChar; i++)
  {
    for (j=0; j < WidthChar; j++)
    {
      if ((i==font.numBytesinChar-1)&&(font.fontWidth%8)>0)
      {
        Buffer[x+ j+ (Page*LCD_SIZEX)]=(*car>>4)&0x0F;
      }
      else
      {
        Buffer[x+ j+ (Page*LCD_SIZEX)]=*car;
      }
      car++;
    }
    Page++;
  }
  
}
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
void DrawString(unsigned char x, unsigned char y, unsigned char *c,str_font font) 
{
  while (*c != '\0') 
  {
    DrawChar(x,y,*c,font);
    x += *(font.charWidth+(*c)-33)+2;
    c++;
    if (x  >= LCD_SIZEX) {
      x = 0;   
      y++;
    }
    if (y >= (LCD_SIZEY/8))
      return;     
  }

}
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
void ClearBuffer() 
{
  memset(&Buffer, 0, LCD_SIZEX*LCD_PAGE);
}
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
str_font InitFont(unsigned char *fontData)
{
  str_font font;
  
  font.fontWidth=*(fontData+2);
  font.fontHeight=*(fontData +3);
  font.numChar=*(fontData + 5);
  font.firstChar=fontData + font.numChar + 6;
  font.charWidth= fontData +7;
  font.numBytesinChar=(font.fontWidth /8)+1;
  return font;

}