
#ifndef _LIFO_H
#define _LIFO_H
#include "platform_Types.h"
#include "stdio.h"
#define element_type  uint8
#define buff_width   5

static element_type buff[buff_width];
typedef struct{
	uint32 length;
	uint32 count;
	element_type* base;
	element_type* head;
}LIFO_t;

typedef enum {
	buff_no_error,
	buff_empty,
	buff_full,
	buff_null
}LIFO_buff_Status;


LIFO_buff_Status LIFO_init(uint32 length, element_type* buff, LIFO_t* lifo);
LIFO_buff_Status LIFO_push(LIFO_t* lifo, element_type input  );
LIFO_buff_Status LIFO_pop(LIFO_t* lifo, element_type *input  );

#endif
