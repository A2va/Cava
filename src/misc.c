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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "misc.h"
/****************************************************************************
* Function intTostr()														*
*		Prototype	:	  unsigned char *intTostr(int Number)				*
*																			*
*		Input Parameter: String								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Convert an integer into  a String										*
*		Don't forget to free memory at the end								*
****************************************************************************/
unsigned char *intTostr(int Number)
{
	int NumberFrame = log10(fabs(Number))+1;//Calculation of the number of boxes in the table
	int Modulo =pow(10,NumberFrame);//Modulo for loop
	int i = 0;
	unsigned char *String = malloc(sizeof(*String) * (NumberFrame + 1));//String Declaration
	if (Number<0)//If the Number are below to 0
	{
		String = realloc(String,1);//A realloc a frame
		i = 1;
		NumberFrame++;//Add a frame
		String[0] = '-';//Set the minus
	}
	Number = fabs(Number);
	while (i<NumberFrame)
	{
		String[i] = ((Number%Modulo) / (Modulo/10))+48;//Store the number
		Modulo /= 10;
		i++;
	}
	String[i] = '\0';//Set the end of String
	return String;
}