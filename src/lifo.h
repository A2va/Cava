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
/****************************************************************************
* DESCRIPTION															
* 	  LIFO library								                        			
****************************************************************************/
#ifndef LIFO_H
#define LIFO_H
typedef struct LIFO_Element LIFO_Element;
struct LIFO_Element
{
	int Data;
	LIFO_Element *next;
};
typedef struct LIFO LIFO;
struct LIFO
{
	LIFO_Element *first;
};
/****************************************************************************
* Function LIFO_Add()																	
*		Input Parameter: LIFO,Number								        
*		Output Parameter: LIFO_Element *, returns NULL if a problem has occurred										        
*																			
*	  	Description															
*     		Add an element to LIFO											    
****************************************************************************/
LIFO_Element *LIFO_Add(LIFO *lifo,int number);
/****************************************************************************
* Function LIFO_Remove()																		
*		Input Parameter: LIFO												
*		Output Parameter: int,Data Out										    
*																			
*	  	Description															
*     		Remove the first elment of LIFO									    
****************************************************************************/
int LIFO_Remove(LIFO *lifo);
#endif // !LIFO_H