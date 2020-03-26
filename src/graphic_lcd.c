
#include "graphic_lcd.h"

//https://github.com/adafruit/ST7565-LCD
/***************************************************************************
* Function SetPixel()								                                       *
* Prototype: void SetPixel(uint8_t x, uint8_t y, uint8_t color)				     *
*																			                                     *
*	  Paramétres d'entrées: Coordonnées x  et y, color(0,1) 		             *
*	  Paramétres de sorties:	Aucun										                       *
*		x:column, y:line													                             *
*	  Description															                               *
*	 Display a pixel                                       		       		     *
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
void drawcircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color) 
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