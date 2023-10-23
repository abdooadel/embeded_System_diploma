/*
 * lifo.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdoo
 */


#include "fifo.h"

FIFO_buff_Status FIFO_init(uint32 length, element_type* buff, FIFO_t* fifo){

	if  (!fifo)
		return buff_null;

	fifo->base=buff;
	fifo->head=buff;
	fifo->tail=buff;
	fifo->count=0;
	fifo->length=length;

	return buff_no_error;

}

FIFO_buff_Status FIFO_enqueue(FIFO_t* fifo, element_type input  )
{

	if (FIFO_status(fifo)==buff_null)
		return buff_null;
	else if  (FIFO_status(fifo)==buff_full)
		return buff_full;

	*(fifo->head)=input;
	fifo->count ++;
	if (fifo->head == (fifo->base) + (fifo->length * sizeof(element_type)))
		fifo->head =fifo->base;
	else
		fifo->head ++;

	return buff_no_error;
}


FIFO_buff_Status FIFO_dequeue(FIFO_t* fifo, element_type *input  ){

	if (FIFO_status(fifo)==buff_null)
		return buff_null;
	else if  (FIFO_status(fifo)==buff_empty)
		return buff_empty;

	*input= *(fifo->tail) ;
	fifo->count --;
	if (fifo->tail == (fifo->base) + (fifo->length * sizeof(element_type)))
		fifo->tail =fifo->base;
	else
		fifo->tail ++;

	return buff_no_error;


}

FIFO_buff_Status FIFO_status(FIFO_t* fifo){
	if ( fifo->base==NULL || fifo->head== NULL || fifo->tail==NULL )
		return buff_null;

	if (fifo->count == fifo->length)
		return buff_full;

	if (fifo->count == 0)
		return buff_empty;

	return buff_no_error;


}

void print_FIFO(FIFO_t* fifo){
	FIFO_t *temp= fifo;
	printf("\n======PRINTING BUFFER=====");
	for(int i=0; i<temp->count; i++){
		printf("\n\t %d" , *(temp->tail));
		if (temp->tail == (temp->base) + (temp->length * sizeof(element_type)))
			temp->tail =temp->base;
		else
			temp->tail ++;
	}
}
