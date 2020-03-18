#ifndef MISC_H
#define MISC_H
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
unsigned char *IntegerToStr(int Number);
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
unsigned char* DoubleToStr(double Number, unsigned int NumberDigit);
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
void str_Reverse(unsigned char* String);
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
void Example_Misc();
#endif

