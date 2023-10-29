


#include "../LCD_driver/LCD.h"
#include "../KEYPAD/KEYBAD.h"
int main (void)
{
	LCD_init();
	KEYPAD_INIT();
	char x=0;
	while(1){
		
		x=KEYPAD_GETCHAR();
		if (x== 'C')
			LCD_clear_screen();
		else if (x == 'A');
		else
			LCD_WRITE_CHAR(x);
			
	}

}
