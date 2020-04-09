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
*		Output Parameter: None										        
*																			
*	  	Description															
*     		Add an element to LIFO											    
****************************************************************************/
void LIFO_Add(LIFO *lifo,int number)
{
	LIFO_Element *newLifo = malloc(sizeof(*newLifo));
	if (lifo==NULL||newLifo==NULL)
	{
		exit(EXIT_FAILURE);
	}
	newLifo->Data = number;
	newLifo->next = lifo->first;
	lifo->first = newLifo;
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

