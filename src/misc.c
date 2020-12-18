// Copyright (C) 2020  A2va

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

/****************************************************************************
* Cava Library: Misc														
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 24.02.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  Misc								                        			
****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "misc.h"
/****************************************************************************
* Function IntegerToStr()																																	
*		Input Parameter: Number								            	
*		Output Parameter: None								            	
*																			
*       Description															
*           Convert an integer into a String										
*	        /!\	Don't forget to free memory at the end of programm /!\				
****************************************************************************/
unsigned char *IntegerToStr(int Number)
{
    int NumBack = Number;
    unsigned int i = 0;
    do
    {
        i++;
        NumBack /= 10;
    } while (NumBack != 0);
    unsigned char* String = malloc((sizeof(unsigned char)*i)+1);//String Declaration
    if (String == NULL)
    {
        return 0;
    }
    i = 0;
    NumBack = Number;
    Number = fabs(Number);

    while(Number !=0)
    {
        String[i]=(Number %10)+48;
        Number = Number /10;
        i++;
    }
    if (NumBack < 0)
    {
        String = realloc(String, sizeof(unsigned char) * i + 2);//Realloc a frame
        if(String == NULL)
        {
            return 0;
        }
        String[i] = '-';
        String[i + 1] = '\0';
    }
    else
    {
        String[i] = '\0';
    }
    str_Reverse(String);
    return String;

}
/****************************************************************************
* Function DoubleToStr()														
*		Input Parameter: Number								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           Convert a double into a String										
*	        /!\ Don't forget to free memory at the end of programm /!\				
****************************************************************************/
unsigned char* DoubleToStr(double Number,unsigned int NumberDigit)
{
    unsigned int i = 0;
    int NumberRel = Number;
    unsigned char* String1 = IntegerToStr((int)Number);
    NumberRel = (fabs(Number) - fabs(NumberRel)) * pow(10, NumberDigit);
    int NumBack = NumberRel;
    do
    {
        i++;
        NumBack /= 10;
    } while (NumBack != 0);

    unsigned char* String2 = malloc((sizeof(unsigned char)*i)+1);//String Declaration
    if(String2==NULL)
    {
       return 0;
    }
    i=0;
    while (NumberRel != 0)
    {
        String2[i] = (NumberRel % 10) + 48;
        NumberRel = NumberRel / 10;
        i++;
    }
    String2 = realloc(String2, sizeof(*String2) * (i + 2));//Realloc a frame
    if(String2==NULL)
    {
       return 0;
    }
    String2[i] = '.';
    String2[i + 1] = '\0';
   
    str_Reverse(String2);
    String1 = realloc(String1, sizeof(*String1) * (strlen(String1) + i+2));
    if(String1==NULL)
    {
       return 0;
    }
    strcat(String1, String2);
    return String1;
}
/****************************************************************************
* Function str_Reverse()																
*		Input Parameter: String								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           Reverse a string              										
****************************************************************************/
void str_Reverse(unsigned char* String)
{
    int length, c;
    unsigned char* begin, * end, temp;

    length = strlen(String);
    begin = String;
    end = String + (length - 1);

    for (c = 0; c < length / 2; c++)
    {
        temp = *end;
        *end = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}
/****************************************************************************
* Function Example_Misc()													               																					
*		Input Parameter: None								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           A example function               										
****************************************************************************/
void Example_Misc()
{
    double ExampleDouble = -12.125;
    int ExampleInt = -12;
    unsigned char* StringDouble = DoubleToStr(ExampleDouble, 2);
    unsigned char* StringInt = IntegerToStr(ExampleInt);

    free(StringDouble);
    free(StringInt);
}
