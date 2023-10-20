
#include "uart.h"


#define UART0  *((vuint32_t *)((uint32 *) 0x101f1000))

void UART_Send_string(uint8 *P_tx_string){
	while(*P_tx_string !=0){
		UART0= (uint32)(*P_tx_string);
		P_tx_string++;
		
	}
}