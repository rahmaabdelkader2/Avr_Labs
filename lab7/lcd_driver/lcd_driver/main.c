#define  F_CPU 1000000UL
#include "stdtypes.h"
#include "LCD.h"
#include "DIO.h"
#include "PORT.h"
#include <util/delay.h>

int main(void)
{
	LCD_Init();
	
	LCD_SendChar('A');
	_delay_ms(500);
	
	LCD_Command(0x01); // Clear display
	_delay_ms(500);
	
	LCD_GoTo(0,7);
	LCD_SendString((u8*)"Hello");
	
	u8 smiley[8] = {0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00, 0x00}; // Define a custom character pattern (example: a smiley face)
	StoreSpecialChar(smiley, 0); // 0:block number
	LCD_WriteSpecialChar(0, 1, 1);
	
	_delay_ms(1000);
	LCD_Clear();

	
	while (1)
	{
	}
}
