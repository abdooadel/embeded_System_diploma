/*
 * UART.c
 *
 * Created: 10/31/2023 9:23:55 PM
 *  Author: abdoo
 */ 

#include "UART.h"

void UART_Init(void)
{
	// baudrate 9600 
	UART_UBRRL = 51;
	
	//Normal Mode
	UART_UCSRA &= ~(1<<1);
	
	// Frame
	
	// No Parity
	
	// 8-bit data 
	// To write on UCSRC or UBRRH , selector on bit 7 must be set high or low
	// high --------> UCSRC   low-------->UBRRH
	
	//UART_UCSRC |= 1<<7;
	//UART_UCSRC |= 0b11 << 1;    //select 8 bit data
	
	
	// Enable UART
	
	UART_UCSRB |= 0b11 <<3 ; 
	
	
	
	
}




void Uart_Send(uint8_t	data ){
	
	//check for UDR is empty first before start sending
	while ( (UART_UCSRA & (1<<5)) ==0);

	
	// put data in UDR----------> send register
	UART_UDR=data;
	
}







uint8_t	Uart_Recieve(void)
{
	
	while ( (UART_UCSRA & (1<<7)) == 0);
	
	return UART_UDR;
	
	
	
}


void UART_Send_Number(uint32_t numm)
{
	uint8_t * P_numm =&numm;
	Uart_Send(P_numm[0]);
	while ( (UART_UCSRA & (1<<5)) ==0);
	Uart_Send(P_numm[1]);
	while ( (UART_UCSRA & (1<<5)) ==0);
	Uart_Send(P_numm[2]);
	while ( (UART_UCSRA & (1<<5)) ==0);
	Uart_Send(P_numm[3]);
	while ( (UART_UCSRA & (1<<5)) ==0);
	
	
}


uint32_t  Uart_Recieve_Nummber(void)
{
	uint8_t * P_numm;
	uint32_t Numm;
	P_numm =  &Numm;
	P_numm[0] = Uart_Recieve();
	P_numm[1] = Uart_Recieve();
	P_numm[2] = Uart_Recieve();
	P_numm[3] = Uart_Recieve();
	return Numm;

}

void UART_Send_String(uint8_t *string)
{
	uint8_t u=0;
	while(string[u] !='\0')
	{
		Uart_Send(string[u]);
		u++;
	}
}




void   Uart_Recieve_String (uint8_t* P)
{
	uint8_t u=0;
	*P = Uart_Recieve();
	while ( P[u] != '#')
	{
		u++;
		P[u] = Uart_Recieve();
		
	}
	P[u]='\0';

}