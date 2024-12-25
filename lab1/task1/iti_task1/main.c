#define F_CPU 100000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1 << PB0);  // Set PB0 as output

	while (1)
	{
		PORTB |= (1 << PB0);   // Set PB0 HIGH
		_delay_ms(200);        // Delay 200 ms

		PORTB &= ~(1 << PB0);  // Set PB0 LOW
		_delay_ms(200);        // Delay 200 ms
	}

	return 0;
}
