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
* Cava Library: Chained List												
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 06.02.2020					                                
*																			
****************************************************************************/
#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H
/****************************************************************************
* DESCRIPTION																
* 	  A chained list library	                        			
*****************************************************************************
						Schematic diagram									
																			
Element																		
|-----------|	|-----------|	|-----------|								
| previous	|<--| previous	|<--| previous	|								
|	next	|-->|	next	|-->|	next	|								
|-----------|	|-----------|	|-----------|								
	^									^									
	|	List							|									
	|	|-----------|					|									
	----|	first	|					|									
		|	last	|--------------------									
		|-----------|														
																			
****************************************************************************/
typedef struct Element Element;
struct Element
{
	int Data;
	Element *next;
	Element *previous;
};
typedef struct List List;
struct List
{
	int CountElement;
	Element *first;
	Element *last;
};
/****************************************************************************
* Function CL_InsertFirst()																
*		Input Parameter: List *								            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************
Function CL_InsertFirst														
Before																		
|-----------|	|-----------|												
|  Element	|---|  Element	|												
|-----------|	|-----------|												
After																		
|-----------|	|-----------|	|-----------|								
|    new	|---|  Element	|---|  Element	|								
|-----------|	|-----------|	|-----------|								
****************************************************************************/
Element *CL_InsertFirst(List *list);
/****************************************************************************
* Function CL_InsertLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element at the end of the list						        
*****************************************************************************
Function CL_InsertLast()																										
Before																		
|-----------|	|-----------|												
|  Element	|---|  Element	|												
|-----------|	|-----------|												
After																		
|-----------|	|-----------|	|-----------|								
|  Element	|---|  Element	|---|    new	|								
|-----------|	|-----------|	|-----------|								
****************************************************************************/
Element *CL_InsertLast(List *list);
/****************************************************************************
* Function CL_Insert()																
*		Input Parameter: List *, Element *					            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element after the selected element						    
*****************************************************************************
Function CL_Insert()  |																													
Before			  	  v	  		  											
|-----------|	|-----------| 	|-----------|								
|  Element	|---|  Element	|---|  Element	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|	|-----------|	|-----------|	|-----------|				
|  Element	|---|  Element	|---|    new	|---|  Element	|				
|-----------|	|-----------|	|-----------|	|-----------|				
****************************************************************************/
Element *CL_Insert(List *list, Element *current);
/****************************************************************************
* Function CL_DeleteFirst()																
*		Input Parameter: List *								            	
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																			
*	  	Description															
*     		Delete first element												    
*****************************************************************************
Function CL_DeleteFirst														
Before																		
|-----------|	|-----------|	|-----------|								
|  Element	|---|  Element	|---|  Element	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|	|-----------|												
| Element	|---|  Element	|												
|-----------|	|-----------|												
****************************************************************************/
int CL_DeleteFirst(List *list);
/****************************************************************************
* Function CL_DeleteLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************
Function CL_DeleteLast														
Before																		
|-----------|	|-----------|	|-----------|								
|  Element	|---|  Element	|---|  Element	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|	|-----------|												
| Element	|---|  Element	|												
|-----------|	|-----------|												
****************************************************************************/
int CL_DeleteLast(List *list);
/****************************************************************************
* Function CL_Delete()															
*		Input Parameter: List *, Element *						            	
*		Output Parameter: Return 0,1 (0->Problem,1->Any problem)								            	
*																			
*	  	Description															
*     		Delete the selected element										    
*****************************************************************************
Function CL_Delete    |														
Before				  v														
|-----------|	|-----------|	|-----------|								
|  Element	|---|  Element	|---|  Element	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|					|-----------|								
| Element	|-------------------|  Element	|								
|-----------|					|-----------|								
****************************************************************************/
int CL_Delete(List *list,Element *element);
/****************************************************************************
* Function CL_DeleteList()																																
*		Input Parameter: List *								            	
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																		
*	  	Description															
*     		Delete a list														    
****************************************************************************/
int CL_DeleteList(List *list);
/****************************************************************************
* Function CL_SelectElement()												
*		Input Parameter: List * , Element *						            	
*		Output Parameter: int, returns 0 if a problem has occurred
*																			
*	  	Description															
*			Select an element													
*****************************************************************************
Function CL_SelectElement()			  |																		  										
Select Element 3		  			  v										
|-----------|	|-----------| 	|-----------|								
|  Element1	|---|  Element2	|---|  Element3	|								
|-----------|	|-----------|	|-----------|								
									  |										
									  v										
								   Element									
****************************************************************************/
Element *CL_SelectElement(List *list, int Number);
/****************************************************************************
* Function CL_MoveElement()													
*		Input Parameter: Element * , Element *									
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																			
*	  	Description															
*     		Move an element after the current element								
*****************************************************************************
Function CL_SelectElement()			  |																									
Before		  			  			  v									
|-----------|	|-----------| 	|-----------|							
|  move		|---|  Element	|---|  current	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|	|-----------|	|-----------|																				
|  Element	|---|  current	|---|   move	|								
|-----------|	|-----------|	|-----------|																	
****************************************************************************/
int CL_MoveElement(Element *move,Element *current);
/****************************************************************************
* Function CL_SwapElement()												
*		Input Parameter: Element *, Element *								
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																			
*	  	Description															
*     		Swap two element														
*****************************************************************************
Function CL_SelectElement()																													
Before		  			  													
|-----------|	|-----------| 	|-----------|								
|  swap1	|---|  Element	|---|  swap2	|								
|-----------|	|-----------|	|-----------|								
After																		
|-----------|	|-----------|	|-----------|																					
|  swap2	|---|  Element	|---|  swap1	|								
|-----------|	|-----------|	|-----------|																
****************************************************************************/
int CL_SwapElement(Element *swap1, Element *swap2);
/****************************************************************************
* Function CL_ConcatList()														
*		Input Parameter: List *, List *						            		
*		Output Parameter: int, returns 0 if a problem has occurred								            	
*																			
*	  	Description															
*     		Concat the second list into the first									
****************************************************************************/
int CL_ConcatList(List *list1, List *list2);
/****************************************************************************
* Function CL_TruncList()													
*		Input Parameter: List *, Element *						            	
*		Output Parameter: List *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Trunk a list															
****************************************************************************/
List *CL_TruncList(List *list, Element *current);
/****************************************************************************
* Function CL_InitList()													
*		Input Parameter: None								            	
*		Output Parameter: List *, returns NULL if a problem has occurred							            	
*																			
*	  	Description															
*     		Initalize the list											        
****************************************************************************/
List *CL_InitList();
/****************************************************************************
* Function Example_CL()																				
*		Input Parameter: None								            	
*		Output Parameter: None								            	
*																			
*	  Description															
*     		Example function												        
****************************************************************************/
void Example_CL(void);
#endif // !CHAINED_LIST_H