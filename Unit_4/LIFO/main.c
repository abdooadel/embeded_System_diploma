/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdoo
 */


#include "lifo.h"

void main(void){
	LIFO_t uart_buff;
	element_type i=0,status=0;
	if (LIFO_init(5,buff,&uart_buff) == buff_no_error)
		printf("\n======Initialization Done======== ");

	for(i=0; i<7;i++)
	{
		status=LIFO_push(&uart_buff,i);
		switch (status){
		case(buff_no_error):
			printf("\n\t ========pushed successfully======== %d",i);
		break;
		case(buff_empty):
			printf("\n\t ========Buffer is empty========");
		break;
		case(buff_full):
			printf("\n\t ========Buffer is full========");
		break;
		case(buff_null):
			printf("\n\t ========Buffer is not existing======== %d",i);
		break;
		default:
		break;
		}


	}

	for(int z=0; z<7; z++)
	{
		status=LIFO_pop(&uart_buff,&i);
		switch (status){
		case(buff_no_error):
			printf("\n\t ========poped successfully======== %d",i);
		break;
		case(buff_empty):
				printf("\n\t ========Buffer is empty========");
		break;
		case(buff_full):
				printf("\n\t ========Buffer is full========");
		break;
		case(buff_null):
				printf("\n\t ========Buffer is not existing======== ");
		break;

		default:
		break;
		}
	}










}
