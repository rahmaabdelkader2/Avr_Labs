#define F_CPU 100000000UL

#include <util/delay.h>
#include "dio.h"


int main(void)
{
	// Set PB2 as output for LED
	MDIO_enuSetPinConfigration(1, 2, PIN_OUTPUT);

	// Set PB1 as input with internal pull-up for the button
	MDIO_enuSetPinConfigration(1, 1, PIN_INPUT_PULLUP);

	while (1)
	{
		uint8_t buttonState = 0;

		// Read the button state
		MDIO_enuGetPinValue(1, 1, &buttonState);

		if (buttonState == 0)  // Button pressed
		{
			// Turn the LED on (PB2 high)
			MDIO_enuSetPinValue(1, 2, LOGIC_HIGH);
		}
		else
		{
			// Turn the LED off (set PB2 low)
			MDIO_enuSetPinValue(1, 2, LOGIC_LOW);
		}

		_delay_ms(10);  // Small delay for button
	}

	return 0;
}
