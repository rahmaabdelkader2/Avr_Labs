#define F_CPU 1000000UL
#include <util/delay.h>
#include "stdtypes.h"
#include "bit_math.h"
#include "DIO.h"
#include "PORT.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "KEYPAD_Config.h"

int main(void)
{
	LCD_Init();
	KEYPAD_init();

	u8 Local_u8PressedKey;
	while (1)
	{
		Local_u8PressedKey = KEYPAD_getKeyPressed();
		if (Local_u8PressedKey != KEY_NOT_PRESSED)
		{
			LCD_SendChar(Local_u8PressedKey);
		}
	}
	return 0;
}