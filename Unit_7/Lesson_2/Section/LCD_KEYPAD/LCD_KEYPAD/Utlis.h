/*
 * Utlis.h
 *
 * Created: 10/28/2023 9:13:48 PM
 *  Author: abdoo
 */ 


#ifndef UTLIS_H_
#define UTLIS_H_

#define SetBit(reg,bit)	reg |= 1<<bit;
#define ClearBit(reg,bit)	reg &= ~(1<<bit)
#define ToggleBit(reg,bit)	reg ^= (1<<bit)
#define ReadBit1(reg,bit)	reg = ((reg<<bit)>> bit)
#define ReadBit(reg,bit)	reg = ((reg>>bit) &1 )



#endif /* UTLIS_H_ */