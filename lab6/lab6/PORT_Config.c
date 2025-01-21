#include "PORT.h"
#include "PORT_Config.h"
#include "DIO_Private.h"

// Configure pins for LED and button
MPORT_PinCfg_t PinCfg[TOTAL_PINS] = {
	{PORTA_PIN_0, MPORT_INPUT_PULLUP}, // Button 0
	{PORTA_PIN_1, MPORT_INPUT_PULLUP}, // Button 1
	{PORTA_PIN_2, MPORT_INPUT_PULLUP}, // Button 2
	{PORTB_PIN_0, MPORT_OUTPUT}, // LED 0
	{PORTB_PIN_1, MPORT_OUTPUT}, // LED 1
	{PORTB_PIN_2, MPORT_OUTPUT} // LED 2
};