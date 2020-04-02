//This file are only using for test
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "src/graphic_lcd.h"
#include "src/font10x12.h"
#include "src/font20x18.h"
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
    
    printf("\nEnd");
}
void printf_LCD(unsigned char x,unsigned char y,str_font font,const char *fmt, ...) 
{
	va_list ap;

	va_start(ap, fmt);
	vfprint(x,y,font, NULL, fmt, ap);
	va_end(ap);
}
static char *outs(unsigned char x,unsigned char y,str_font font,const char *str, char *bp) 
{
	DrawString(x,y,font,str);
	return bp;
}
static char *outd(unsigned char x ,unsigned char y,str_font font,long n, char *bp) 
{
	unsigned long m;
	char buf[25], *s = buf + sizeof buf;

	*--s = '\0';
	if (n < 0)
		m = -n;
	else
		m = n;
	do
		*--s = m%10 + '0';
	while ((m /= 10) != 0);
	if (n < 0)
		*--s = '-';
	return outs(x,y,font,s,bp);
}
static char *outu(unsigned char x,unsigned char y,str_font font,unsigned long n, int base, char *bp) 
{
	char buf[25], *s = buf + sizeof buf;

	*--s = '\0';
	do
		*--s = "0123456789abcdef"[n%base];
	while ((n /= base) != 0);
	return outs(x,y,font,s,bp);
}
//void putc(unsigned char x ,unsigned char y, str_font font,const char *fmt)
void vfprint(unsigned char x,unsigned char y,str_font font, char *bp, const char *fmt, va_list ap) 
{
    static char format[] = "%f";
	char buf[128];
    int n=0;
	for (; *fmt; fmt++)
    {
		if (*fmt == '%')
		{	
            switch (*++fmt) 
			{
				case 'd': bp = outd(x,y,font,va_arg(ap, int), bp); break;
				case 'D': bp = outd(x,y,font,va_arg(ap, long), bp); break;
				case 'U': bp = outu(x,y,font,va_arg(ap, unsigned long), 10, bp); break;
				case 'u': bp = outu(x,y,font,va_arg(ap, unsigned), 10, bp); break;
				case 'o': bp = outu(x,y,font,va_arg(ap, unsigned), 8, bp); break;
				case 'X': bp = outu(x,y,font,va_arg(ap, unsigned long), 16, bp); break;
				case 'x': bp = outu(x,y,font,va_arg(ap, unsigned), 16,bp); break;
				case 'f': case 'e':
				case 'g': {
							format[1] = *fmt;
							sprintf(buf, format, va_arg(ap, double));
							bp = outs(x,y,font,buf, bp);
						  } break;
						case 's': bp = outs(x,y,font,va_arg(ap, char *), bp); break;
						case 'p': {
									void *p = va_arg(ap, void *);
									if (p)
										bp = outs(x,y,font,"0x", bp);
									bp = outu(x,y,font,(unsigned long)p, 16, bp);
								  } break;
						case 'c': 
                                    n=va_arg(ap, int);
                                    DrawChar(x,y,font,&n); 
                            break;
					
			            default:  
                        break;
			}
		}
        else
        {
            DrawChar(x,y,font,fmt);
        }
        x += *(font.charWidth+(*fmt)-33)+2;
    }
}
int main()
{
    printf("\n");
    str_font str_font10x12=InitFont(font10x12);
    str_font str_font20x18 =InitFont(font20x18);
    //DrawChar(10,0,'%',str_font10x12);
    unsigned char String[]={"Salut\0"};
    printf_LCD(0,0,str_font10x12,"%c",'t');
    printLCD();

    printf("\n-------------------------------------------------------");
    return 0;
}