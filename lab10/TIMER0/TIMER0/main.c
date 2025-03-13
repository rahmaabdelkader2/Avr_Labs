#define F_CPU 16000000UL
#include "stdtypes.h"
#include "bit_math.h"
#include "TIMER0.h"
#include "TIMER0_Config.h"
#include "DIO.h" // Include the DIO header
#include <util/delay.h> // For delay functions

// Callback function for Timer0 overflow interrupt
void Timer0_Overflow_Callback(void) {
	// Toggle PB0 (Port B, Pin 0)
	MDIO_enuSetPinValue(MDIO_PORTB, MDIO_PIN0, MDIO_HIGH); // Set PB0 high
	_delay_ms(100); // Small delay for visibility
	MDIO_enuSetPinValue(MDIO_PORTB, MDIO_PIN0, MDIO_LOW); // Set PB0 low
}

// Callback function for Timer0 compare match interrupt
void Timer0_CompareMatch_Callback(void) {
	// Toggle PB1 (Port B, Pin 1)
	MDIO_enuSetPinValue(MDIO_PORTB, MDIO_PIN1, MDIO_HIGH); // Set PB1 high
	_delay_ms(100); // Small delay for visibility
	MDIO_enuSetPinValue(MDIO_PORTB, MDIO_PIN1, MDIO_LOW); // Set PB1 low
}

int main(void) {
	// Initialize PB0 and PB1 as output pins
	MDIO_enuSetPinConfigration(MDIO_PORTB, MDIO_PIN0, PIN_OUTPUT); // Set PB0 as output
	MDIO_enuSetPinConfigration(MDIO_PORTB, MDIO_PIN1, PIN_OUTPUT); // Set PB1 as output

	// Test Timer0 in Normal Mode with overflow interrupt
	Timer0_Init_NormalMode(TIMER0_PRESCALER_1024); // Initialize Timer0 in Normal Mode with prescaler 1024
	Timer0_SetOverflowCallback(Timer0_Overflow_Callback); // Set overflow callback
	Timer0_EnableOverflowInterrupt(); // Enable overflow interrupt
	Timer0_Start(); // Start Timer0

	// Test Timer0 in CTC Mode with compare match interrupt
	Timer0_Init_CTCMode(TIMER0_PRESCALER_256, 125); // Initialize Timer0 in CTC Mode with prescaler 256 and compare value 125
	Timer0_SetCompareMatchCallback(Timer0_CompareMatch_Callback); // Set compare match callback
	Timer0_EnableCompareMatchInterrupt(); // Enable compare match interrupt
	Timer0_Start(); // Start Timer0

	// Main loop
	while (1) {
		// Do other tasks or keep the program running
		_delay_ms(100); // Example: Small delay
	}

	return 0;
}