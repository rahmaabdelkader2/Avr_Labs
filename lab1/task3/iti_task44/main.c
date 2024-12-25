#define F_CPU 100000000  
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set PA0, PA1, PA2, PA3 as output for the 4 LEDs
	DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);

	
	DDRA &= ~(1 << PA4);      // Set PA4 as input
	PORTA |= (1 << PA4);      // Enable pull-up resistor on PA4

	uint8_t counter = 0;  // 4-bit counter

	while (1)
	{

		if (!(PINA & (1 << PA4))) 
		{
			

			if (!(PINA & (1 << PA4)))
			{
				counter++;  
				if (counter > 15)  
				counter = 0;

			
				PORTA = (PORTA & 0xF0) | (counter & 0x0F);  

		
				while (!(PINA & (1 << PA4))) {
				
				}
			}
		}

	}

	return 0;
}
