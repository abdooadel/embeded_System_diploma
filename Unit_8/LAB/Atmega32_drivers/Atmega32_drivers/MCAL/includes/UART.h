/*
 * UART.h
 *
 * Created: 10/31/2023 9:23:36 PM
 *  Author: abdoo
 */ 


#ifndef UART_H_
#define UART_H_
#include "atmega32_driver.h"
#include <string.h>




















void UART_Init(void);
void Uart_Send(uint8_t	data );
uint8_t	Uart_Recieve(void);
void UART_Send_Number(uint32_t numm);
uint32_t  Uart_Recieve_Nummber (void);
void UART_Send_String(uint8_t *string);
 void Uart_Recieve_String (uint8_t *);



#endif /* UART_H_ */