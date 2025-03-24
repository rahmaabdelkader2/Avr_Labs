#define F_CPU 16000000UL
#include "stdtypes.h"
#include "bit_math.h"
#include "TIMER0.h"
#include "TIMER0_Config.h"
#include "DIO.h"

// Define the LED pin (assuming it's connected to PD6, which is OC0A for Timer0 PWM)
#define LED_PORT MDIO_PORTD
#define LED_PIN  MDIO_PIN6

// Callback function for Timer0 overflow
void Timer0_OverflowCallback(void) {
	// Toggle the LED on overflow
	static u8 ledState = 0;
	ledState ^= 1; // Toggle LED state
	MDIO_enuSetPinValue(LED_PORT, LED_PIN, ledState);
}

// Callback function for Timer0 compare match
void Timer0_CompareMatchCallback(void) {
	// Toggle the LED on compare match
	static u8 ledState = 0;
	ledState ^= 1; // Toggle LED state
	MDIO_enuSetPinValue(LED_PORT, LED_PIN, ledState);
}

int main(void) {
	// Initialize the LED pin as output
	MDIO_enuSetPinConfigration(LED_PORT, LED_PIN, MDIO_OUTPUT);

	// Normal mode with prescaler 1024
	Timer0_Init_NormalMode(TIMER0_PRESCALER_1024);
	Timer0_SetOverflowCallback(Timer0_OverflowCallback);
	
	/*	Fast PWM mode */
	//Timer0_Init_FastPWM(TIMER0_PRESCALER_1024, 50); // Initialize Timer0 in Fast PWM Mode with prescaler 1024 and 50% duty cycle
	//Timer0_SetOverflowCallback(Timer0_OverflowCallback);
	 
	/*	Phase Correction mode */
	//Timer0_Init_PhaseCorrectPWM(TIMER0_PRESCALER_1024, 50); // Initialize Timer0 in Phase Correct PWM Mode with prescaler 1024 and 50% duty cycle
    //Timer0_SetOverflowCallback(Timer0_OverflowCallback);
	
	/*	CTC mode */
    //Timer0_Init_CTCMode(TIMER0_PRESCALER_1024, 156); // Initialize Timer0 in CTC Mode with prescaler 1024 and compare value 156
	//Timer0_SetCompareMatchCallback(Timer0_CompareMatchCallback); // Set compare match callback to toggle LED

	// Enable overflow interrupt
	Timer0_EnableOverflowInterrupt();

	// Start Timer0
	Timer0_Start();

	while (1) {
	}

	return 0;
}









