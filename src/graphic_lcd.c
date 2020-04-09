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
#include <stdio.h>
#include <stdlib.h>
//https://github.com/adafruit/ST7565-LCD
/****************************************************************************
* Function SetPixel()														
*		Input Parameter: x,y,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*         Set a pixel on buffer											    
****************************************************************************/
void SetPixel(unsigned char x, unsigned char  y, unsigned char  color)
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
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*          Set a pixel on buffer											    
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
* Function FillCircle()																																
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*           Set a  fill circle on buffer											    
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
*		Input Parameter: x0,y0,radius,color(0,1)								            	
*		Output Parameter: None									        
*																			
*	    Description															
*          Draw a rectangle on buffer										    
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
* Function FillRect()								                       																			
*	  Input Parameter: x0,y0 et width,height,color(0,1) 		
*	  Output Parameter: None										
*															
*	  Description															
*	        Fill a rectangle on buffer                               		        
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
*	  Input Parameter: x0,y0 et x1,y1,color(0,1) 	
*	  Output Parameter:	None										
*														
*	  Description															
*	    Display a line                                        		        
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
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw character on buffer                              		        
******************************************************************************/
void DrawChar(unsigned char x,unsigned char y,str_font font,unsigned char c)
{
  unsigned char *car=font.firstChar;
  unsigned char i=0;
  unsigned char j=0;
  unsigned char WidthChar=*(font.charWidth+c-font.Char0);
  unsigned char Page=y/LCD_SIZEPAGE;
  for (i = 0; i < c-font.Char0; i++)
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
*	  Input Parameter: x,y,charecter, font	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Draw string on buffer                              		        
******************************************************************************/
void DrawString(unsigned char x, unsigned char y,str_font font, unsigned char *s) 
{
  while (*s != '\0') 
  {
    DrawChar(x,y,font,*s);
    x += *(font.charWidth+(*s)-font.Char0)+2;
    s++;
    if (x  >= LCD_SIZEX) {
      x = 0;   
      y++;
    }
    if (y >= (LCD_SIZEY/8))
      return;     
  }

}
/****************************************************************************
* Fonction printfLCD()								                        																			
*	  Input Parameter: x,y,font,String,variable	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Equivalent printf for lcd                           		        
******************************************************************************/
void printfLCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...) 
{
	va_list ap;

	va_start(ap, fmt);
	Parser(x,y,font, fmt, ap);
	va_end(ap);
}
/****************************************************************************
* Fonction Parser()								                        																		
*	  Input Parameter: x,y,font,String,ap	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Parser for printfLCD                           		        
******************************************************************************/
void Parser(unsigned char x,unsigned char y,str_font font, const char *fmt, va_list ap) 
{
  static char format[] = "%f";
	char buf[128];
  char n=0;
  void *p;
	for (; *fmt; fmt++)
  {
      if (*fmt == '%')
      {	
        switch (*++fmt) 
        {
            case 'd': Outd(x,y,font,va_arg(ap, int)); break;
            case 'D': Outd(x,y,font,va_arg(ap, long)); break;
            case 'U': Outu(x,y,font,va_arg(ap, unsigned long), 10); break;
            case 'u': Outu(x,y,font,va_arg(ap, unsigned), 10); break;
            case 'o': Outu(x,y,font,va_arg(ap, unsigned), 8); break;
            case 'X': Outu(x,y,font,va_arg(ap, unsigned long), 16); break;
            case 'x': Outu(x,y,font,va_arg(ap, unsigned), 16); break;
            case 'f': 
            case 'e':
            case 'g': 
                format[1] = *fmt;
                sprintf(buf, format, va_arg(ap, double));
                DrawString(x,y,font,buf);
            break;
            case 'p': 
            
              p = va_arg(ap, void *);
              if (p)
              {
                  Outu(x,y,font,(unsigned long)p, 16);
              }

            break;
            case 's': 
                  DrawString(x,y,font,va_arg(ap, char *)); 
            break;
            case 'c':
                  DrawChar(x,y,font,va_arg(ap, int)); 
            break;
              
            default:  
            break;
        }
      }
      else
      {
          DrawChar(x,y,font,*fmt);
      }
      x += *(font.charWidth+(*fmt)-font.Char0)+2;
    }
}
/****************************************************************************
* Fonction Outd()								                        																			
*	  Input Parameter: x,y,font,number
*	  Output Parameter:	None										
*															
*	  Description															
*	    Converts a number into a string in the base 10                         		        
******************************************************************************/
void Outd(unsigned char x ,unsigned char y,str_font font,long n) 
{
	unsigned long m;
	char buf[25], *s = buf + sizeof buf;

	*--s = '\0';
	if (n < 0)
  {
		m = -n;
  }
	else
  {
		m = n;
  }
	do
  {
		*--s = m%10 + '0';
  }while ((m /= 10) != 0);
	if (n < 0)
  {
		*--s = '-';
  }
  DrawString(x,y,font,s);
}
/****************************************************************************
* Fonction Outu()								                        																			
*	  Input Parameter: x,y,font,number,base
*	  Output Parameter:	None										
*															
*	  Description															
*	    Converts a number into a string in the desired base                          		        
******************************************************************************/
void Outu(unsigned char x,unsigned char y,str_font font,unsigned long n, int base) 
{
	char buf[25], *s = buf + sizeof buf;

	*--s = '\0';
	do
  {
		*--s = "0123456789ABCDEF"[n%base];
  }while ((n /= base) != 0);

   DrawString(x,y,font,s);
}
/****************************************************************************
* Fonction ClearBuffer()								                        																			
*	  Input Parameter: None	
*	  Output Parameter:	None										
*															
*	  Description															
*	    Clear buffer                              		        
******************************************************************************/
void ClearBuffer() 
{
  memset(&Buffer, 0, LCD_SIZEX*LCD_PAGE);
}
/****************************************************************************
* Fonction InitFont()								                        																		
*	  Input Parameter: None	
*	  Output Parameter:	font										
*															
*	  Description															
*	    Init a font                            		        
******************************************************************************/
str_font InitFont(unsigned char *fontData)
{
  str_font font;
  
  font.fontWidth=*(fontData+FONT_WIDTH_FRAME);
  font.fontHeight=*(fontData +FONT_HEIGHT_FRAME);
  font.Char0=*(fontData+FONT_CHAR0_FRAME)+1;
  font.numChar=*(fontData + FONT_NUMCHAR_FRAME);
  font.firstChar=fontData + font.numChar + FONT_FIRSTCHAR_FRAME;
  font.charWidth= fontData +FONT_CHARWIDTH_FRAME;
  font.numBytesinChar=(font.fontWidth /8)+1;
  return font;

}