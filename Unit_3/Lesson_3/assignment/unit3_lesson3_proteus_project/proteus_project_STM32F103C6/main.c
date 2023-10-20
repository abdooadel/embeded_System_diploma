/*
 ============================================================================
 Name        : Toggle_led.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_Types.h"

#define RCC_base		0x40021000
#define GPIOA_base		0x40010800

#define RCC_APB2ENR			*(vuint32*)( RCC_base+ 0X18)
#define	GPIOA_CRH		 	*(vuint32*)( GPIOA_base+ 0X04)
#define	GPIOA_ODR			*(vuint32*)( GPIOA_base+ 0x0c)

typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t pin0:1 ;
		vuint32_t pin1:1 ;
		vuint32_t pin2:1 ;
		vuint32_t pin3:1 ;
		vuint32_t pin4:1 ;
		vuint32_t pin5:1 ;
		vuint32_t pin6:1 ;
		vuint32_t pin7:1 ;
		vuint32_t pin8:1 ;
		vuint32_t pin9:1 ;
		vuint32_t pin10:1 ;
		vuint32_t pin11:1 ;
		vuint32_t pin12:1 ;
		vuint32_t pin13:1 ;
		vuint32_t pin14:1 ;
		vuint32_t pin15:1 ;
		vuint32_t pin16:1 ;
		vuint32_t pin17:1 ;
		vuint32_t pin18:1 ;
		vuint32_t pin19:1 ;
		vuint32_t pin20:1 ;
		vuint32_t pin21:1 ;
		vuint32_t pin22:1 ;
		vuint32_t pin23:1 ;
		vuint32_t pin24:1 ;
		vuint32_t pin25:1 ;
		vuint32_t pin26:1 ;
		vuint32_t pin27:1 ;
		vuint32_t pin28:1 ;
		vuint32_t pin29:1 ;
		vuint32_t pin30:1 ;
		vuint32_t pin31:1 ;
	}pin;
}R_ODR_t;
typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t pin0:1 ;
		vuint32_t pin1:1 ;
		vuint32_t pin2:1 ;
		vuint32_t pin3:1 ;
		vuint32_t pin4:1 ;
		vuint32_t pin5:1 ;
		vuint32_t pin6:1 ;
		vuint32_t pin7:1 ;
		vuint32_t pin8:1 ;
		vuint32_t pin9:1 ;
		vuint32_t pin10:1 ;
		vuint32_t pin11:1 ;
		vuint32_t pin12:1 ;
		vuint32_t pin13:1 ;
		vuint32_t pin14:1 ;
		vuint32_t pin15:1 ;
		vuint32_t pin16:1 ;
		vuint32_t pin17:1 ;
		vuint32_t pin18:1 ;
		vuint32_t pin19:1 ;
		vuint32_t pin20:1 ;
		vuint32_t pin21:1 ;
		vuint32_t pin22:1 ;
		vuint32_t pin23:1 ;
		vuint32_t pin24:1 ;
		vuint32_t pin25:1 ;
		vuint32_t pin26:1 ;
		vuint32_t pin27:1 ;
		vuint32_t pin28:1 ;
		vuint32_t pin29:1 ;
		vuint32_t pin30:1 ;
		vuint32_t pin31:1 ;
	}pin;
}R_CRH_t;
typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t pin0:1 ;
		vuint32_t pin1:1 ;
		vuint32_t pin2:1 ;
		vuint32_t pin3:1 ;
		vuint32_t pin4:1 ;
		vuint32_t pin5:1 ;
		vuint32_t pin6:1 ;
		vuint32_t pin7:1 ;
		vuint32_t pin8:1 ;
		vuint32_t pin9:1 ;
		vuint32_t pin10:1 ;
		vuint32_t pin11:1 ;
		vuint32_t pin12:1 ;
		vuint32_t pin13:1 ;
		vuint32_t pin14:1 ;
		vuint32_t pin15:1 ;
		vuint32_t pin16:1 ;
		vuint32_t pin17:1 ;
		vuint32_t pin18:1 ;
		vuint32_t pin19:1 ;
		vuint32_t pin20:1 ;
		vuint32_t pin21:1 ;
		vuint32_t pin22:1 ;
		vuint32_t pin23:1 ;
		vuint32_t pin24:1 ;
		vuint32_t pin25:1 ;
		vuint32_t pin26:1 ;
		vuint32_t pin27:1 ;
		vuint32_t pin28:1 ;
		vuint32_t pin29:1 ;
		vuint32_t pin30:1 ;
		vuint32_t pin31:1 ;
	}pin;
}R_APB2ENR_t;


volatile R_ODR_t *R_ODR = (volatile R_ODR_t *) ( GPIOA_base+ 0x0c) ;
volatile R_CRH_t *R_CRH = (volatile R_CRH_t *) ( GPIOA_base+ 0X04);
volatile R_APB2ENR_t* R_APB2ENR= (volatile R_APB2ENR_t *) ( RCC_base+ 0X18);

int main(void) {

	R_APB2ENR->pin.pin2=1;
	R_CRH->pin.pin20=0;
	R_CRH->pin.pin21=1;
	R_CRH->pin.pin22=0;
	R_CRH->pin.pin23=0;
	int i;
	while(1){
		R_ODR->pin.pin13=1;
		for( i=0;i<5000;i++)
		{

		}
		R_ODR->pin.pin13=0;
		for( i=0;i<5000;i++)
		{

		}
	}


	return EXIT_SUCCESS;
}

