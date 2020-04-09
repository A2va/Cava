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
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************/
void CL_InsertFirst(List *list)
{
	Element *newElement = malloc(sizeof(*newElement));
	if (list == NULL || newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *current = list->first;
	newElement->next = current;
	current->previous = newElement;
	list->first = newElement;

	list->CountElement++;
}
/****************************************************************************
* Function CL_InsertLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Insert an element at the end of the list						        
*****************************************************************************/
void CL_InsertLast(List *list)
{
	Element *newElement = malloc(sizeof(*newElement));
	if (list == NULL || newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}
	newElement->next = NULL;
	list->last->next = newElement;
	newElement->previous = list->last;
	list->last = newElement;

	list->CountElement++;
}
/****************************************************************************
* Function CL_Insert()																
*		Input Parameter: List *, Element *					            	
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Insert an element after the selected element						    
*****************************************************************************/
void CL_Insert(List *list, Element *current)
{
	Element *newElement = malloc(sizeof(*newElement));
	if (list == NULL || newElement == NULL || current == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (current->next!=NULL)
	{
		current->next->previous = newElement;
		newElement->next = current->next;
		newElement->previous = current;
		current->next = newElement;

		list->CountElement++;
	}
}
/****************************************************************************
* Function CL_DeleteFirst()																
*		Input Parameter: List *								            	
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Delete first element												    
*****************************************************************************/
void CL_DeleteFirst(List *list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *deleteElement = list->first;
	list->first = list->first->next;
	list->first->previous = NULL;

	list->CountElement--;
	free(deleteElement);

}
/****************************************************************************
* Function CL_DeleteLast()																	
*		Input Parameter: List *								            	
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Insert an element at the beginning of the list					    
*****************************************************************************/
void CL_DeleteLast(List *list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *deleteElement = list->last;
	list->last = list->last->previous;
	list->last->next = NULL;

	list->CountElement--;
	free(deleteElement);

}
/****************************************************************************
* Function CL_Delete()															
*		Input Parameter: List *, Element *						            	
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Delete the selected element										    
*****************************************************************************/
void CL_Delete(List *list,Element *element)
{
	if (list==NULL||element==NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->previous->next = element->next;
	element->next->previous = element->previous;
	free(element);
	list->CountElement--;
}
/****************************************************************************
* Function CL_DeleteList()																																
*		Input Parameter: List *								            	
*		Output Parameter: None								            	
*																		
*	  	Description															
*     		Delete a list														    
****************************************************************************/
void CL_DeleteList(List *list)
{
	unsigned int i=0;
	Element *deleteElement = list->first;

	if (list == NULL)
	{
		exit(EXIT_FAILURE);
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
}
/****************************************************************************
* Function CL_SelectElement()												
*		Input Parameter: List * , Element *						            	
*																			
*	  	Description															
*			Select an element													
*****************************************************************************/
Element *CL_SelectElement(List *list, int Number)
{
	if (list==NULL)
	{
		exit(EXIT_FAILURE);
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
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Move an element after the current element								
*****************************************************************************/
void CL_MoveElement(Element *move,Element *current)
{
	if (move ==NULL||current==NULL)
	{
		exit(EXIT_FAILURE);
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
}
/****************************************************************************
* Function CL_SwapElement()												
*		Input Parameter: Element *, Element *								
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Swap two element														
*****************************************************************************/
void CL_SwapElement(Element *swap1, Element *swap2)
{
	if (swap1==NULL||swap2==NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *swap1previous = swap1->previous;
	CL_MoveElement(swap1, swap2);
	CL_MoveElement(swap2, swap1previous);
}
/****************************************************************************
* Function CL_ConcatList()														
*		Input Parameter: List *, List *						            		
*		Output Parameter: None								            	
*																			
*	  	Description															
*     		Concat the second list into the first									
****************************************************************************/
void CL_ConcatList(List *list1, List *list2)
{
	list1->last->next = list2->first;
	list2->first->previous = list1->last;
	list1->last = list2->first;

}
/****************************************************************************
* Function CL_TruncList()													
*		Input Parameter: List *, Element *						            	
*		Output Parameter: List								            	
*																			
*	  	Description															
*     		Trunk a list															
*****************************************************************************/
List *CL_TruncList(List *list, Element *current)
{
	List *newList = malloc(sizeof(*list));
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
*		Output Parameter: List *								            	
*																			
*	  	Description															
*     		Initalize the list											        
****************************************************************************/
List *CL_InitList()
{
	List *list = malloc(sizeof(*list));
	Element *element = malloc(sizeof(*element));
	if ((list == NULL) || (element == NULL))
	{
		exit(EXIT_FAILURE);
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


