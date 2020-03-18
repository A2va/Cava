/****************************************************************************
* Cava Library: Misc														*
*                                                                         	*
* Auteur    : A2va					                                        *
* Date      : 24.02.2020					                                *
*																			*
****************************************************************************/
/****************************************************************************
* DESCRIPTION																*
* 	  Misc								                        			*
****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "misc.h"

/****************************************************************************
* Function IntegerToStr()													*
*		Prototype	:	  unsigned char *IntegerToStr(int Number)			*
*																			*
*		Input Parameter: Number								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Convert an integer into a String										*
*	/!\	Don't forget to free memory at the end of programm /!\				*
****************************************************************************/
unsigned char *IntegerToStr(int Number)
{
    unsigned int i=0;
    int NumBack = 0;
    NumBack = Number;
    unsigned char* String = malloc(sizeof(*String));//String Declaration
    if(String==NULL)
    {
        exit(EXIT_FAILURE);
    }
    Number = fabs(Number);
    while(Number !=0)
    {
        String[i]=(Number %10)+48;
        Number = Number /10;
        String = realloc(String,sizeof(*String)*(i+2));//Realloc a frame
        if (String == NULL)
        {
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (NumBack < 0)
    {
        String = realloc(String, sizeof(*String) * (i + 2));//Realloc a frame
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
* Function DoubleToStr()													*
*		Prototype	:	  unsigned char *DoubleToStr(double Number)			*
*																			*
*		Input Parameter: Number								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Convert a double into a String										*
*	/!\ Don't forget to free memory at the end of programm /!\				*
****************************************************************************/
unsigned char* DoubleToStr(double Number,unsigned int NumberDigit)
{
    unsigned int i = 0;
    int NumberRel = Number;
    unsigned char* String1 = malloc(sizeof(*String1));//String Declaration
    String1 = IntegerToStr(Number);
    unsigned char* String2 = malloc(sizeof(*String2));//String Declaration
    if (String2==NULL)
    {
       exit(EXIT_FAILURE);
    }
    NumberRel = (fabs(Number) - fabs(NumberRel)) * pow(10,NumberDigit);
    while (NumberRel != 0)
    {
        String2[i] = (NumberRel % 10) + 48;
        NumberRel = NumberRel / 10;
        String2 = realloc(String2, sizeof(*String2) * (i + 2));//Realloc a frame
        if (String2 == NULL)
        {
            exit(EXIT_FAILURE);
        }
        i++;
    }
    String2 = realloc(String2, sizeof(*String2) * (i + 2));//Realloc a frame
    String2[i] = '.';
    String2[i + 1] = '\0';
   
    str_Reverse(String2);
    String1 = realloc(String1, sizeof(*String1) * (strlen(String1) + i+2));
    strcat(String1, String2);
    return String1;
}
/****************************************************************************
* Function str_Reverse()													*
*		Prototype	:	  void str_Reverse(unsigned char *String)			*
*																			*
*		Input Parameter: String								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Reverse a string              										*
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
* Function Example_Misc()													*
*		Prototype	:	  void Example_Misc()                   			*
*																			*
*		Input Parameter: None								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     A example function               										*
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
