#ifndef LIFO_H
#define LIFO_H
/****************************************************************************
* Cava Library: LIFO															*
*                                                                         	*
* Auteur    : A2va					                                        *
* Date      : 06.02.2020					                                *
*																			*
****************************************************************************/
/****************************************************************************
* DESCRIPTION																*
* 	  LIFO								                        			*
****************************************************************************/
typedef struct LIFO_Element LIFO_Element;
struct LIFO_Element
{
	int Data;
	LIFO_Element *next;
};
typedef struct LIFO LIFO;
struct LIFO
{
	LIFO_Element *first;
};
/****************************************************************************
* Function LIFO_Add()														*
*		Prototype	:	  void LIFO_Add(LIFO *lifo,int number);				*
*		Input Parameter: LIFO,Number								        *
*		Output Parameter: None										        *
*																			*
*	  Description															*
*     Add an element to LIFO											    *
****************************************************************************/
void LIFO_Add(LIFO *lifo, int number);
/****************************************************************************
* Function LIFO_Remove()													*
*		Prototype	:	  void LIFO_Remove(LIFO *lifo);						*
*		Input Parameter: LIFO												*
*		Output Parameter: Data Out										    *
*																			*
*	  Description															*
*     Remove the first elment of LIFO									    *
****************************************************************************/
int LIFO_Remove(LIFO *lifo);
#endif // !LIFO_H