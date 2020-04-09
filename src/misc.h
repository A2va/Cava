#ifndef MISC_H
#define MISC_H
/****************************************************************************
* Cava Library: Misc														
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 24.02.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  Misc library							                        			
****************************************************************************/

/****************************************************************************
* Function IntegerToStr()																																	
*		Input Parameter: Number								            	
*		Output Parameter: None								            	
*																			
*       Description															
*           Convert an integer into a String										
*	        /!\	Don't forget to free memory at the end of programm /!\				
****************************************************************************/
unsigned char *IntegerToStr(int Number);
/****************************************************************************
* Function DoubleToStr()														
*		Input Parameter: Number								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           Convert a double into a String										
*	        /!\ Don't forget to free memory at the end of programm /!\				
****************************************************************************/
unsigned char* DoubleToStr(double Number, unsigned int NumberDigit);
/****************************************************************************
* Function str_Reverse()																
*		Input Parameter: String								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           Reverse a string              										
****************************************************************************/
void str_Reverse(unsigned char* String);
/****************************************************************************
* Function Example_Misc()													               																					
*		Input Parameter: None								            	
*		Output Parameter: None								            	
*																			
*	    Description															
*           A example function               										
****************************************************************************/
void Example_Misc();
#endif

