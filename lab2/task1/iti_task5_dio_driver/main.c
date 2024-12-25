#define F_CPU 100000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set all PORTA pins as output for 8 LEDs
	DDRA = 0xFF;  


	DDRC &= ~(1 << PC0);  // Set PC0 as input
	PORTC |= (1 << PC0);   // Enable pull-up resistor on PC0

	uint8_t counter = 0;  // 8-bit binary counter
	uint8_t counting = 0; // Flag to check if counting has started

	while (1)
	{
		// Check if the button is pressed (PC0 is low)
		if (!(PINC & (1 << PC0)) && !counting) 
		{
		

			if (!(PINC & (1 << PC0)))  // Check if the button is still pressed after debounce
			{
				counting = 1;  
				PORTA = 0x01;  
				_delay_ms(100);  // Keep the LED on for visual feedback
				PORTA = 0x00;  // Turn off LED 
			}
		}

		// If wait untill the led counts to 255 and reset
		if (counting)
		{
			_delay_ms(100);  // Wait for 100ms

		
			counter++;

	
			if (counter == 256)
			{
				counter = 0;  // Reset the counter to 0
			}

			// Display the counter value on PORTA (LEDs)
			PORTA = counter; 
		}
	}

	return 0;
}
