#include "config.h"
#include "private.h"
#include "stdtypes.h"


/* Example configuration array */
PinConfig_t MPORT_ArrPinConfig[nummber_of_ports*number_of_pins_per_port] = {
	// PORTA configuration ( defined as output)
	{PORTA_PIN_0, PIN_OUTPUT},  // PORTA, PIN0 as output
	{PORTA_PIN_1, PIN_OUTPUT},  // PORTA, PIN1 as output
	{PORTA_PIN_2, PIN_OUTPUT},  // PORTA, PIN2 as output
	{PORTA_PIN_3, PIN_OUTPUT},  // PORTA, PIN3 as output
	{PORTA_PIN_4, PIN_OUTPUT},  // PORTA, PIN4 as output
	{PORTA_PIN_5, PIN_OUTPUT},  // PORTA, PIN5 as output
	{PORTA_PIN_6, PIN_OUTPUT},  // PORTA, PIN6 as output
	{PORTA_PIN_7, PIN_OUTPUT},  // PORTA, PIN7 as output

	// PORTB configuration ( defined as input)
	{PORTB_PIN_0, PIN_INPUT},  // PORTB, PIN0 as input 
	{PORTB_PIN_1, PIN_INPUT},  // PORTB, PIN1 as input 
	{PORTB_PIN_2, PIN_INPUT},  // PORTB, PIN2 as input
	{PORTB_PIN_3, PIN_INPUT},  // PORTB, PIN3 as input 
	{PORTB_PIN_4, PIN_INPUT},  // PORTB, PIN4 as input 
	{PORTB_PIN_5, PIN_INPUT},  // PORTB, PIN5 as input 
	{PORTB_PIN_6, PIN_INPUT},  // PORTB, PIN6 as input 
	{PORTB_PIN_7, PIN_INPUT},  // PORTB, PIN7 as input 

	// PORTC configuration (set all pins as output)
	{PORTC_PIN_0, PIN_OUTPUT},  // PORTC, PIN0 as output
	{PORTC_PIN_1, PIN_OUTPUT},  // PORTC, PIN1 as output
	{PORTC_PIN_2, PIN_OUTPUT},  // PORTC, PIN2 as output
	{PORTC_PIN_3, PIN_OUTPUT},  // PORTC, PIN3 as output
	{PORTC_PIN_4, PIN_OUTPUT},  // PORTC, PIN4 as output
	{PORTC_PIN_5, PIN_OUTPUT},  // PORTC, PIN5 as output
	{PORTC_PIN_6, PIN_OUTPUT},  // PORTC, PIN6 as output
	{PORTC_PIN_7, PIN_OUTPUT},  // PORTC, PIN7 as output

	// PORTD configuration (set all pins as input )
	{PORTD_PIN_0, PIN_INPUT},  
	{PORTD_PIN_1, PIN_INPUT},
	{PORTD_PIN_2, PIN_INPUT}, 
	{PORTD_PIN_3, PIN_INPUT},  
	{PORTD_PIN_4, PIN_INPUT},  
	{PORTD_PIN_5, PIN_INPUT},  
	{PORTD_PIN_6, PIN_INPUT}, 
	{PORTD_PIN_7, PIN_INPUT}  
};
