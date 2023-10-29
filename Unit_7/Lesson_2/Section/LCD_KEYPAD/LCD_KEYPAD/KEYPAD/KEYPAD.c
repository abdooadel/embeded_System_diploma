/*
 * KEYPAD.c
 *
 * Created: 10/29/2023 1:52:52 PM
 *  Author: abdoo
 */ 
#include "KEYBAD.h"

char KEYPAD_ROW[]={R0,R1,R2,R3};
char KEYPAD_COLUM[]={C0,C1,C2,C3};
	

void KEYPAD_INIT(void){
	
	KEYPAD_DATA_DIR = 0b11110000;
	KEYPAD_PORT = 0xFF;
}


char KEYPAD_GETCHAR(void)
{
	int c=0 ,r=0;
	
	for( c=0;c<4;c++)
	{
		SetBit(KEYPAD_PORT,KEYPAD_COLUM[0]);
		SetBit(KEYPAD_PORT,KEYPAD_COLUM[1]);
		SetBit(KEYPAD_PORT,KEYPAD_COLUM[2]);
		SetBit(KEYPAD_PORT,KEYPAD_COLUM[3]);

		ClearBit(KEYPAD_PORT,KEYPAD_COLUM[c]);	
			for( r=0;r<4;r++)
			{
				if( (ReadBit(KEYPAD_PIN,KEYPAD_ROW[r] ) == 0)  )
				{
					while(ReadBit(KEYPAD_PIN,KEYPAD_ROW[r]) == 0);
					switch(c)
					{
						case 0:
						if(r==0) return '7';
						if(r==1) return '4';
						if(r==2) return '1';
						if(r==3) return 'C';
						break;
						case 1:
						if(r==0) return '8';
						if(r==1) return '5';
						if(r==2) return '2';
						if(r==3) return '0';
						break;
						case 2:
						if(r==0) return '9';
						if(r==1) return '6';
						if(r==2) return '3';
						if(r==3) return '=';
						break;
						case 3:
						if(r==0) return '/';
						if(r==1) return 'x';
						if(r==2) return '-';
						if(r==3) return '+';
						break;
					}
				}
			}

	}
	return 'A';
}