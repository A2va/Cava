/****************************************************************************
* Cava Library: FILO														
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 06.02.2020					                                
*																			
****************************************************************************/
/****************************************************************************
* DESCRIPTION																
* 	  FILO								                        			
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "filo.h"
/****************************************************************************
* Function FILO_Add()																	
*		Input Parameter: FILO * ,Number								        
*		Output Parameter: FILO_Element *, returns NULL if a problem has occurred										        
*																			
*	  	Description															
*     		Add an element to FILO											    
****************************************************************************/
FILO_Element *FILO_Add(FILO *filo, int number)
{
	FILO_Element *newFilo = malloc(sizeof(FILO_Element));

	if (filo == NULL || newFilo == NULL)
	{
		return NULL;
	}
	newFilo->Data = number;
	newFilo->next = NULL;
	if (filo->first!=NULL)
	{
		FILO_Element *current = filo->first;
		while (current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newFilo;
	}
	else
	{
		filo->first = newFilo;
	}
	return newFilo;
}
/****************************************************************************
* Function FILO_Remove()															
*		Input Parameter: FILO *								            	
*		Output Parameter: int,Data Out									        
*																			
*	  	Description															
*     		Remove an element to FILO											    
****************************************************************************/
int FILO_Remove(FILO *filo)
{
	if (filo == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int ExtractData = 0;
	if (filo->first!=NULL)
	{
		FILO_Element *remove = filo->first;
		ExtractData = remove->Data;
		filo->first = remove->next;
		free(remove);
	}
	return ExtractData;
}