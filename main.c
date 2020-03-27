//This file are only using for test
#include <stdio.h>
#include <stdlib.h>
#include "src/graphic_lcd.h"
unsigned char Buffer_Print[LCD_SIZEX*LCD_PAGE][8];
void printLCD()
{
    unsigned int x=0;
    unsigned int y=0;
    unsigned int i=0;
    unsigned char Data=0;
    unsigned char Case=0;
    for (y = 0; y < LCD_PAGE; y++)
    {
       for (x = 0; x < LCD_SIZEX; x++)
       {
            Data=Buffer[(LCD_SIZEX*y)+x];
            for ( i = 0; i < 8; i++)
            {
                Buffer_Print[(LCD_SIZEX*y)+x][i]=Data&0x01;
                Data=Data>>1;
            }
       }   
    }
    for ( y = 0; y < LCD_PAGE; y++)
    {
        for(i = 0; i < 8; i++)
        {
            for(x = 0; x < LCD_SIZEX; x++)
            {
                
                Case =Buffer_Print[(LCD_SIZEX*y)+x][i];
                if (Case==0x01)
                {
                    printf("n");
                }
                else
                {
                    printf(" ");
                }         
            }
            printf("\n");   
        }
    }
    
}
int main()
{
    printf("\n");
    printLCD();
    printf("\nEnd");
    return 0;
}