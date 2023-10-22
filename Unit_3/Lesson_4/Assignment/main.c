/*
 ============================================================================
 Name        : cortex_M4_main.c
 Author      :Abdelrahman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_Types.h"

#define SYSCTL_base	 0X400FE000
#define GPIO_base	 0X40025000

#define SYSCTL_RCGC2_R 		((vuint32_t *)(0X400FE108))
#define GPIO_PORTF_DIR_R 	((vuint32_t *)(0X40025400))
#define GPIO_PORTF_DATA_R 	((vuint32_t *)(0X400253FC))
#define GPIO_PORTF_DEN_R 	((vuint32_t *)(0X4002551C)) 

typedef union {
	vuint32_t All_port;
	struct 
	{
		vuint32_t P_0:1;
		vuint32_t P_1:1;
		vuint32_t P_2:1 ;
		vuint32_t P_3:1;
		vuint32_t P_4:1 ;
		vuint32_t P_5:1;
		vuint32_t P_6:1 ;
		vuint32_t P_7:1;
		vuint32_t P_8:1 ;
		vuint32_t P_9:1;
		vuint32_t P_10:1 ;
		vuint32_t P_11:1;
		vuint32_t P_12:1 ;
		vuint32_t P_13:1;
		vuint32_t P_14:1 ;
		vuint32_t P_15:1;
		vuint32_t P_16:1 ;
		vuint32_t P_17:1;
		vuint32_t P_18:1 ;
		vuint32_t P_19:1;
		vuint32_t P_20:1 ;
		vuint32_t P_21:1;
		vuint32_t P_22:1 ;
		vuint32_t P_23:1;
		vuint32_t P_24:1 ;
		vuint32_t P_25:1;
		vuint32_t P_26:1 ;
		vuint32_t P_27:1;
		vuint32_t P_28:1 ;
		vuint32_t P_29:1;
		vuint32_t P_30:1 ;
		vuint32_t P_31:1;
	}bits;
}GPIO_PORTF;

int main()
{
	volatile GPIO_PORTF *P_DIR_R = (volatile GPIO_PORTF *) GPIO_PORTF_DIR_R;
	volatile GPIO_PORTF *P_DATA_R =(volatile GPIO_PORTF *) GPIO_PORTF_DATA_R;
	volatile GPIO_PORTF *P_DEN_R = (volatile GPIO_PORTF *) GPIO_PORTF_DEN_R;
	volatile GPIO_PORTF *P_SYSCTL_RCGC2_R = (volatile GPIO_PORTF *) SYSCTL_RCGC2_R;

	vint32_t delay_counter=200;
	P_SYSCTL_RCGC2_R->All_port = 0x00000020;
	for (delay_counter=0; delay_counter < 200; delay_counter++);
	

	P_DIR_R->bits.P_3=1;
	P_DEN_R->bits.P_3=1;

	while(1){
	for (delay_counter=0; delay_counter < 300000; delay_counter++);
	P_DATA_R->bits.P_3=1;
	for (delay_counter=0; delay_counter < 300000; delay_counter++);
	P_DATA_R->bits.P_3=0;

	}
	
	
	
	
	return 0;
}

