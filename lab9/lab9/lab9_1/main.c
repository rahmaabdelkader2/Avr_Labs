#define F_CPU 16000000UL // 16 MHz clock frequency
#include "bit_math.h"
#include "stdtypes.h"
#include "DIO.h"
#include "EXT.h"
#include <avr/interrupt.h>

// Define the LED pin
#define LED_PORT MDIO_PORTB
#define LED_PIN  MDIO_PIN0

// Define the Button pin (connected to INT0)
#define BUTTON_PORT MDIO_PORTD
#define BUTTON_PIN  MDIO_PIN2

// Global variable to track LED state
volatile u8 led_state = 0; // 0 = off, 1 = on

// ISR for INT0
ISR(INT0_vect)
{

	// Toggle the LED state
	if (led_state == 0)
	{
		MDIO_enuSetPinValue(LED_PORT, LED_PIN, MDIO_HIGH); // Turn on LED
		led_state = 1; // Update state
	}
	else
	{
		MDIO_enuSetPinValue(LED_PORT, LED_PIN, MDIO_LOW); // Turn off LED
		led_state = 0; // Update state
	}
}

int main(void)
{
	// Initialize the DIO driver
	MDIO_enuSetPinConfigration(LED_PORT, LED_PIN, MDIO_OUTPUT); // Set LED pin as output
	MDIO_enuSetPinConfigration(BUTTON_PORT, BUTTON_PIN, MDIO_INPUT_PULLUP); // Set button pin as input with pull-up

	// Initialize the EXT driver
	EXT_Init();
	EXT_SetEdge(EXT_INT0, EXT_EDGE_FALLING); // Set INT0 to trigger on falling edge
	EXT0_Enable(); // Enable INT0

	while (1)
	{

	}

	return 0;
}