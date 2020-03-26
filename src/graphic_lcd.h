#ifndef GRAPHIC_LCD_H
#define GRAPHIC_LCD_H

#define LCD_SIZEX 128
#define LCD_SIZEY 64
#define LCD_SIZEPAGE 8
#define LCD_PAGE (LCD_SIZEY /LCD_SIZEPAGE)

unsigned char Buffer[LCD_SIZEX*LCD_PAGE];

void SetPixel(unsigned char x, unsigned char  y, unsigned char  color);
void drawcircle(unsigned char x0, unsigned char y0, unsigned char r,unsigned char color);

#endif