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
/****************************************************************************
* DESCRIPTION																
* 	  Chained List see chained_list.h	                        			
****************************************************************************/
//Include
#include <stdio.h>
#include <stdlib.h>
#include "chained_list.h"

/****************************************************************************
* Function CL_InsertFirst()																
*		Input Parameter: List *								            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************/
Element *CL_InsertFirst(List *list)
{
	Element *newElement = malloc(sizeof(Element));
	if (list == NULL || newElement == NULL)
	{
		return NULL;
	}
	Element *current = list->first;
	newElement->next = current;
	current->previous = newElement;
	list->first = newElement;

	list->CountElement++;
	return newElement;
}
/****************************************************************************
* Function CL_InsertLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element at the end of the list						        
*****************************************************************************/
Element *CL_InsertLast(List *list)
{
	Element *newElement = malloc(sizeof(Element));
	if (list == NULL || newElement == NULL)
	{
		return NULL;
	}
	newElement->next = NULL;
	list->last->next = newElement;
	newElement->previous = list->last;
	list->last = newElement;

	list->CountElement++;
	return newElement;
}
/****************************************************************************
* Function CL_Insert()																
*		Input Parameter: List *, Element *					            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Insert an element after the selected element						    
*****************************************************************************/
Element *CL_Insert(List *list, Element *current)
{
	Element *newElement = malloc(sizeof(Element));
	if (list == NULL || newElement == NULL || current == NULL)
	{
		return NULL;
	}
	if (current->next!=NULL)
	{
		current->next->previous = newElement;
		newElement->next = current->next;
		newElement->previous = current;
		current->next = newElement;

		list->CountElement++;
		return newElement;
	}
	return NULL;
}
/****************************************************************************
* Function CL_DeleteFirst()																
*		Input Parameter: List *								            	
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Delete first element												    
*****************************************************************************/
int CL_DeleteFirst(List *list)
{
	if (list == NULL)
	{
		return 0;
	}
	Element *deleteElement = list->first;
	list->first = list->first->next;
	list->first->previous = NULL;

	list->CountElement--;
	free(deleteElement);
	return 1;

}
/****************************************************************************
* Function CL_DeleteLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************/
int CL_DeleteLast(List *list)
{
	if (list == NULL)
	{
		return 0;
	}
	Element *deleteElement = list->last;
	list->last = list->last->previous;
	list->last->next = NULL;

	list->CountElement--;
	free(deleteElement);
	return 1;

}
/****************************************************************************
* Function CL_Delete()															
*		Input Parameter: List *, Element *						            	
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Delete the selected element										    
*****************************************************************************/
int CL_Delete(List *list,Element *element)
{
	if (list==NULL||element==NULL)
	{
		return 0;
	}
	element->previous->next = element->next;
	element->next->previous = element->previous;
	free(element);
	list->CountElement--;

	return 1;
}
/****************************************************************************
* Function CL_DeleteList()																																
*		Input Parameter: List *								            	
*		Output Parameter: Element *, returns NULL if a problem has occurred								            	
*																		
*	  	Description															
*     		Delete a list														    
****************************************************************************/
int CL_DeleteList(List *list)
{
	unsigned int i=0;
	Element *deleteElement = list->first;

	if (list == NULL)
	{
		return 0;
	}
	for (i = 0; i < list->CountElement - 1; i++)
	{
		deleteElement = list->last;
		list->last = list->last->previous;
		list->last->next = NULL;
		free(deleteElement);
	}
	free(list->first);
	free(list);
	return 1;
}
/****************************************************************************
* Function CL_SelectElement()												
*		Input Parameter: List * , Element *						            	
*		Output Parameter: int, returns 0 if a problem has occurred	
*																	
*	  	Description															
*			Select an element													
*****************************************************************************/
Element *CL_SelectElement(List *list, int Number)
{
	if (list==NULL)
	{
		return NULL;
	}
	unsigned int i;
	Element *element = list->first;
	if (Number < list->CountElement)
	{
		for (i = 0; i < Number; i++)
		{
			element = element->next;
		}
	}
	return element;
}
/****************************************************************************
* Function CL_MoveElement()													
*		Input Parameter: Element * , Element *									
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Move an element after the current element								
*****************************************************************************/
int CL_MoveElement(Element *move,Element *current)
{
	if (move ==NULL||current==NULL)
	{
		return 0;
	}
	move->previous->next = move->next;
	move->next->previous = move->previous;
	if (current->next!=NULL)
	{
		current->next->previous = move;
	}
	move->next = current->next;
	current->next = move;
	move->previous = current;

	return 1;
}
/****************************************************************************
* Function CL_SwapElement()												
*		Input Parameter: Element *, Element *								
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Swap two element														
*****************************************************************************/
int CL_SwapElement(Element *swap1, Element *swap2)
{
	if (swap1==NULL||swap2==NULL)
	{
		return 0;
	}
	Element *swap1previous = swap1->previous;
	CL_MoveElement(swap1, swap2);
	CL_MoveElement(swap2, swap1previous);
	return 1;
}
/****************************************************************************
* Function CL_ConcatList()														
*		Input Parameter: List *, List *						            		
*		Output Parameter: int, returns 0 if a problem has occurred									            	
*																			
*	  	Description															
*     		Concat the second list into the first									
****************************************************************************/
int CL_ConcatList(List *list1, List *list2)
{
	if (list1==NULL||list2==NULL)
	{
		return 0;
	}
	list1->last->next = list2->first;
	list2->first->previous = list1->last;
	list1->last = list2->first;
	return 1;

}
/****************************************************************************
* Function CL_TruncList()													
*		Input Parameter: List *, Element *						            	
*		Output Parameter: List *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Trunk a list															
*****************************************************************************/
List *CL_TruncList(List *list, Element *current)
{
	if (list==NULL||current==NULL)
	{
		return NULL;
	}
	List *newList = malloc(sizeof(List));
	current->previous->next = NULL;
	newList->last = list->last;
	list->last = current->previous;
	current->previous = NULL;
	newList->first = current;

	return newList;
}
/****************************************************************************
* Function CL_InitList()													
*		Input Parameter: None								            	
*		Output Parameter: List *, returns NULL if a problem has occurred								            	
*																			
*	  	Description															
*     		Initalize the list											        
****************************************************************************/
List *CL_InitList()
{
	List *list = malloc(sizeof(*list));
	Element *element = malloc(sizeof(Element));
	if ((list == NULL) || (element == NULL))
	{
		return NULL;
	}
	list->CountElement = 1;
	element->next = NULL;
	element->previous = NULL;
	list->first = element;
	list->last = element;
	element->Data=0;

	return list;
}
/****************************************************************************
* Function Example_CL()																				
*		Input Parameter: None								            	
*		Output Parameter: None								            	
*																			
*	  Description															
*     		Example function												        
****************************************************************************/
void Example_CL(void)
{

	//Inialize the list
	List *exampleList = CL_InitList();
	List *exampleList2 = CL_InitList();

	//Insert an element at the beginning of the list
	CL_InsertFirst(exampleList);
	CL_InsertFirst(exampleList);
	//Modify a Data
	CL_SelectElement(exampleList, 1)->Data = 10;
	//Insert at the position
	CL_Insert(exampleList, CL_SelectElement(exampleList, 1));
	
	//Move the element after the second pointer
	CL_MoveElement(CL_SelectElement(exampleList, 1), CL_SelectElement(exampleList, 0));
	//Swap element
	CL_SwapElement(CL_SelectElement(exampleList, 0),CL_SelectElement(exampleList, 3));

	CL_ConcatList(exampleList, exampleList2);

	CL_DeleteList(exampleList);
	CL_DeleteList(exampleList2);

}


