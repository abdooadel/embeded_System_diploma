
#ifndef _LIFO_H
#define _LIFO_H
#include "platform_Types.h"

#define element_type  uint8
#define buff_width   5

static element_type buff[buff_width];
typedef struct{
	uint32 length;
	uint32 count;
	element_type* base;
	element_type* head;
	element_type* tail;

}FIFO_t;

typedef enum {
	buff_no_error,
	buff_empty,
	buff_full,
	buff_null
}FIFO_buff_Status;


FIFO_buff_Status FIFO_init(uint32 length, element_type* buff, FIFO_t* lifo);
FIFO_buff_Status FIFO_enqueue(FIFO_t* fifo, element_type input  );
FIFO_buff_Status FIFO_dequeue(FIFO_t* fifo, element_type *input  );
FIFO_buff_Status FIFO_status(FIFO_t* fifo);
void print_FIFO(FIFO_t* fifo);

#endif
