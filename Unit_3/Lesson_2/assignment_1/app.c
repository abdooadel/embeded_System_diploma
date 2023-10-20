#include "uart.h"


uint8 string_buffer[100]="learn-in-depth: Abdelrahman";

void main(void){
	UART_Send_string(string_buffer);
	
	
	
}