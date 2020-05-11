/****************************************************************************
* Cava Library: LIFO													
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 06.02.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  LIFO								                        			
****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "lifo.h"
/****************************************************************************
* Function LIFO_Add()																	
*		Input Parameter: LIFO,Number								        
*		Output Parameter: LIFO_Element *, returns null if the allocation doesn't work											        
*																			
*	  	Description															
*     		Add an element to LIFO											    
****************************************************************************/
LIFO_Element *LIFO_Add(LIFO *lifo,int number)
{
	LIFO_Element *newLifo = malloc(sizeof(LIFO_Element));
	if (lifo==NULL||newLifo==NULL)
	{
		return NULL;
	}
	newLifo->Data = number;
	newLifo->next = lifo->first;
	lifo->first = newLifo;
	return newLifo;
}
/****************************************************************************
* Function LIFO_Remove()																		
*		Input Parameter: LIFO												
*		Output Parameter: Data Out										    
*																			
*	  	Description															
*     		Remove the first elment of LIFO									    
****************************************************************************/
int LIFO_Remove(LIFO *lifo)
{
	if (lifo == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int ExtractData = 0;
	LIFO_Element *remove = lifo->first;
	if (lifo != NULL && lifo->first != NULL)
	{
		ExtractData = remove->Data;
		lifo->first = remove->next;
		free(remove);
	}
	return ExtractData;
}

