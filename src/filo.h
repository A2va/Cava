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
* Cava Library: LIFO														
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 06.02.2020					                                
*																			
****************************************************************************/
#ifndef FILO_H
#define FILO_H
/****************************************************************************
* DESCRIPTION																
* 	  FILO	Library							                        			
****************************************************************************/
typedef struct FILO_Element FILO_Element;
struct FILO_Element
{
	int Data;
	FILO_Element *next;
};
typedef struct FILO FILO;
struct FILO
{
	FILO_Element *first;
};
/****************************************************************************
* Function FILO_Add()																	
*		Input Parameter: FILO * ,Number								        
*		Output Parameter: FILO_Element *, returns NULL if a problem has occurred										        
*																			
*	  	Description															
*     		Add an element to FILO											    
****************************************************************************/
FILO_Element *FILO_Add(FILO *filo, int number);
/****************************************************************************
* Function FILO_Remove()															
*		Input Parameter: FILO *								            	
*		Output Parameter: int,Data Out									        
*																			
*	  	Description															
*     		Remove an element to FILO											    
****************************************************************************/
int FILO_Remove(FILO *filo);
#endif // !FILO_H