#ifndef FILO_H
#define FILO_H
/****************************************************************************
* Cava Library: LIFO														
*                                                                         	
* Auteur    : A2va					                                        
* Date      : 06.02.2020					                                
*																			
****************************************************************************/
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