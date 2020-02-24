#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H
/****************************************************************************
* Cava Library: Chained List												*
*                                                                         	*
* Auteur    : A2va					                                        *
* Date      : 06.02.2020					                                *
*																			*
****************************************************************************/
/****************************************************************************
* DESCRIPTION																*
* 	  Chained List see chained_list.h	                        			*
*****************************************************************************
						Schematic diagram									*
																			*
Element																		*
|-----------|	|-----------|	|-----------|								*
| previous	|<--| previous	|<--| previous	|								*
|	next	|-->|	next	|-->|	next	|								*
|-----------|	|-----------|	|-----------|								*
	^									^									*
	|	List							|									*
	|	|-----------|					|									*
	----|	first	|					|									*
		|	last	|--------------------									*
		|-----------|														*
																			*
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
* Function CL_InsertFirst()													*
*		Prototype	:	  void CL_InsertFirst(List *list);					*
*		Input Parameter: List								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Insert an element at the beginning of the list					    *
*****************************************************************************
Function CL_InsertFirst														*
Before																		*
|-----------|	|-----------|												*
|  Element	|---|  Element	|												*
|-----------|	|-----------|												*
After																		*
|-----------|	|-----------|	|-----------|								*
|    new	|---|  Element	|---|  Element	|								*
|-----------|	|-----------|	|-----------|								*
****************************************************************************/
void CL_InsertFirst(List *list);
/****************************************************************************
* Function CL_InsertLast()													*
*		Prototype	:	  void CL_InsertLast(List *list);					*
*		Input Parameter: List								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Insert an element at the end of the list						        *
*****************************************************************************
Function CL_InsertLast()													*																	*
Before																		*
|-----------|	|-----------|												*
|  Element	|---|  Element	|												*
|-----------|	|-----------|												*
After																		*
|-----------|	|-----------|	|-----------|								*
|  Element	|---|  Element	|---|    new	|								*
|-----------|	|-----------|	|-----------|								*
****************************************************************************/
void CL_InsertLast(List *list);
/****************************************************************************
* Function CL_Insert()														*
*		Prototype	:	  void CL_Insert(List *list,Element *current);		*
*		Input Parameter: List, Element						            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Insert an element after the selected element						    *
*****************************************************************************
Function CL_Insert()  |														*																	*
Before			  	  v	  		  											*
|-----------|	|-----------| 	|-----------|								*
|  Element	|---|  Element	|---|  Element	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|	|-----------|	|-----------|	|-----------|				*
|  Element	|---|  Element	|---|    new	|---|  Element	|				*
|-----------|	|-----------|	|-----------|	|-----------|				*
****************************************************************************/
void CL_Insert(List *list, Element *current);
/****************************************************************************
* Function CL_DeleteFirst()													*
*		Prototype	:	  void CL_DeleteFirst(List *list);					*
*		Input Parameter: List								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Delete first element												    *
*****************************************************************************
Function CL_DeleteFirst														*
Before																		*
|-----------|	|-----------|	|-----------|								*
|  Element	|---|  Element	|---|  Element	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|	|-----------|												*
| Element	|---|  Element	|												*
|-----------|	|-----------|												*
****************************************************************************/
void CL_DeleteFirst(List *list);
/****************************************************************************
* Function CL_DeleteLast()													*
*		Prototype	:	  void CL_DeleteLast(List *list);					*
*		Input Parameter: List								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Insert an element at the beginning of the list					    *
*****************************************************************************
Function CL_DeleteLast														*
Before																		*
|-----------|	|-----------|	|-----------|								*
|  Element	|---|  Element	|---|  Element	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|	|-----------|												*
| Element	|---|  Element	|												*
|-----------|	|-----------|												*
****************************************************************************/
void CL_DeleteLast(List *list);
/****************************************************************************
* Function CL_Delete()														*
*		Prototype	:	  void CL_Delete(List *list,Element *current);		*
*		Input Parameter: List, Element						            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Delete the selected element										    *
*****************************************************************************
Function CL_Delete	  |														*
Before				  v														*
|-----------|	|-----------|	|-----------|								*
|  Element	|---|  Element	|---|  Element	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|					|-----------|								*
| Element	|-------------------|  Element	|								*
|-----------|					|-----------|								*
****************************************************************************/
void CL_Delete(List *list,Element *current);
/****************************************************************************
* Function CL_DeleteList()													*
*		Prototype	:	  void CL_DeleteList(List *list);					*
*																			*
*		Input Parameter: List								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Delete a list														    *
****************************************************************************/
void CL_DeleteList(List *list);
/****************************************************************************
* Function CL_SelectElement()												*
*		Prototype	:	  Element *CL_SelectElement(List *list,int Number);	*
*		Input Parameter: List, Element						            	*
*																			*
*	  Description															*
*		Select an element													*
*****************************************************************************
Function CL_SelectElement()			  |										*								  |										*
Select Element 3		  			  v										*
|-----------|	|-----------| 	|-----------|								*
|  Element1	|---|  Element2	|---|  Element3	|								*
|-----------|	|-----------|	|-----------|								*
									  |										*
									  v										*
								   Element									*
****************************************************************************/
Element *CL_SelectElement(List *list, int Number);
/****************************************************************************
* Function CL_MoveElement()													*
*	Prototype	:void CL_MoveElement(Element *moveElement,Element *current);*
*		Input Parameter: Element, Element									*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Move an element after the current element								*
*****************************************************************************
Function CL_SelectElement()			  |										*																		*
Before		  			  			  v										*
|-----------|	|-----------| 	|-----------|								*
|  move		|---|  Element	|---|  current	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|	|-----------|	|-----------|								*													
|  Element	|---|  current	|---|   move	|								*
|-----------|	|-----------|	|-----------|								*									
****************************************************************************/
void CL_MoveElement(Element *move, Element *current);
/****************************************************************************
* Function CL_SwapElement()													*
*		Prototype	:	void CL_SwapElement(Element *move,Element *current);*
*		Input Parameter: Element, Element									*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Swap two element														*
*****************************************************************************
Function CL_SelectElement()													*																		*
Before		  			  													*
|-----------|	|-----------| 	|-----------|								*
|  swap1	|---|  Element	|---|  swap2	|								*
|-----------|	|-----------|	|-----------|								*
After																		*
|-----------|	|-----------|	|-----------|								*														
|  swap2	|---|  Element	|---|  swap1	|								*
|-----------|	|-----------|	|-----------|								*									
****************************************************************************/
void CL_SwapElement(Element *swap1, Element *swap2);
/****************************************************************************
* Function CL_ConcatList()													*
*		Prototype	:	  void CL_ConcatList(List *list1,List *list2);		*
*		Input Parameter: List, List						            		*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Concat the second list into the first									*
****************************************************************************/
void CL_ConcatList(List *list1, List *list2);
/****************************************************************************
* Function CL_TruncList()													*
*		Prototype	:	  List *CL_ConcatList(List *list,Element *current);	*
*		Input Parameter: List, Element						            	*
*		Output Parameter: List								            	*
*																			*
*	  Description															*
*     Trunk a list															*
****************************************************************************/
List *CL_TruncList(List *list, Element *current);
/****************************************************************************
* Function CL_InitList()													*
*		Prototype	:	  List *CL_InitList();								*
*		Input Parameter: None								            	*
*		Output Parameter: List								            	*
*																			*
*	  Description															*
*     Initalize the list											        *
****************************************************************************/
List *CL_InitList();
/****************************************************************************
* Function Example_CL()														*
*		Prototype	:	  void Example_CL(void);							*
*		Input Parameter: None								            	*
*		Output Parameter: None								            	*
*																			*
*	  Description															*
*     Example function												        *
****************************************************************************/
void Example_CL(void);
#endif // !CHAINED_LIST_H