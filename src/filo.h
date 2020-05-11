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
struct FILO_Element
{
	int Data;
	FILO_Element *next;
};
typedef struct FILO_Element FILO_Element;
struct FILO
{
	FILO_Element *first;
};
typedef struct FILO FILO;
/****************************************************************************
* Function FILO_Add()																	
*		Input Parameter: FILO * ,Number								        
*		Output Parameter: None										        
*																			
*	  	Description															
*     		Add an element to FILO											    
****************************************************************************/
void FILO_Add(FILO *filo, int number);
/****************************************************************************
* Function FILO_Remove()															
*		Input Parameter: FILO *								            	
*		Output Parameter: Data Out									        
*																			
*	  	Description															
*     		Remove an element to FILO											    
****************************************************************************/
int FILO_Remove(FILO *filo);
#endif // !FILO_H