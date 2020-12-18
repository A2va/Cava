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
* 	  Misc library							                        			
****************************************************************************/
#ifndef MISC_H
#define MISC_H
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

