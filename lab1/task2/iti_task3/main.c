#define F_CPU 100000000UL  
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set PB2 output 
	DDRB |= (1 << PB2);


	DDRB &= ~(1 << PB1);      // Set PB1 as input
	PORTB |= (1 << PB1);      // Enable pull-up resistor on PB1

	while (1)
	{
		// Check 3ala el zero
		if (!(PINB & (1 << PB1)))  // Button pressed 
		{
			PORTB |= (1 << PB2);  // Turn LED on
		}
		else
		{
			PORTB &= ~(1 << PB2); // Turn LED off
		}

		_delay_ms(10);  // Small delay to debounce the button
	}

	return 0;  
}
