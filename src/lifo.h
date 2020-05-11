#ifndef LIFO_H
#define LIFO_H
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
struct LIFO_Element
{
	int Data;
	LIFO_Element *next;
};
typedef struct LIFO_Element LIFO_Element;
struct LIFO
{
	LIFO_Element *first;
};
typedef struct LIFO LIFO;
/****************************************************************************
* Function LIFO_Add()																	
*		Input Parameter: LIFO,Number								        
*		Output Parameter: None										        
*																			
*	  	Description															
*     		Add an element to LIFO											    
****************************************************************************/
void LIFO_Add(LIFO *lifo, int number);
/****************************************************************************
* Function LIFO_Remove()																		
*		Input Parameter: LIFO												
*		Output Parameter: Data Out										    
*																			
*	  	Description															
*     		Remove the first elment of LIFO									    
****************************************************************************/
int LIFO_Remove(LIFO *lifo);
#endif // !LIFO_H