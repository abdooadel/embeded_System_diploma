/* C Start_up CortxM
Eng. Abdelrahman */

#include "platform_Types.h"

extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;
extern uint32 _stack_top;

void reset_handler(void);

void default_handler(void);

extern int main(void);

void MNI_handler(void) __attribute__((weak,alias("default_handler")));;
void H_fault_handler(void) __attribute__((weak,alias("default_handler")));;
void MM_fault_handler(void) __attribute__((weak,alias("default_handler")));;
void Bus_fault_handler(void) __attribute__((weak,alias("default_handler")));;
void Usage_fault_handler(void) __attribute__((weak,alias("default_handler")));;



uint32 vectors[] __attribute__((section(".vectors")))={
	(uint32) &_stack_top,
	(uint32) &reset_handler,
	(uint32) &MNI_handler,
	(uint32) &H_fault_handler,
	(uint32) &MM_fault_handler,
	(uint32) &Bus_fault_handler,
	(uint32) &Usage_fault_handler
};




void reset_handler(void){
	//copy .data from flash to sram
	uint8	* P_dsn=(uint8 *)(&_S_DATA);
	uint8* P_src=(uint8 *)(&_E_text);
	uint32 Data_size =  (uint8 *)&_E_DATA - (uint8 *)&_S_DATA;
	for(int i =0; i< Data_size ; i++)
	{
		*((uint8 *)(P_dsn++)) = *((uint8 *)(P_src++));
	}

	//initialize .bss
	P_dsn =(uint8 *)(&_S_BSS);
	Data_size =  (uint8 *)&_E_BSS - (uint8 *)&_S_BSS;
	for(int i =0; i< Data_size ; i++)
	{
		*((uint8 *)(P_dsn++)) = (uint8)0;
	}
	
	main();
}

void default_handler(void){
	main();
}
