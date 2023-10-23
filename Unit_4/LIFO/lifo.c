/*
 * lifo.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdoo
 */


#include "lifo.h"

LIFO_buff_Status LIFO_init(uint32 length, element_type* buff, LIFO_t* lifo){

	if  (!lifo)
		return buff_null;

	lifo->base=buff;
	lifo->head=buff;
	lifo->count=0;
	lifo->length=length;
	return buff_no_error;

}

LIFO_buff_Status LIFO_push(LIFO_t* lifo, element_type input  )
{
	if ( lifo->base==NULL || lifo->head== NULL)
		return buff_null;

	if (lifo->count == lifo->length)
		return buff_full;

	*(lifo->head)=input;
	lifo->head ++;
	lifo->count ++;
	return buff_no_error;
}


LIFO_buff_Status LIFO_pop(LIFO_t* lifo, element_type *input  ){

	if ( lifo->base==NULL || lifo->head== NULL)
		return buff_null;
	if (lifo->count == 0)
		return buff_empty;

	(lifo->head) --;
	*input= *(lifo->head) ;
	lifo->count --;
	return buff_no_error;


}
