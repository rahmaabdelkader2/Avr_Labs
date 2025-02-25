#include "stdtypes.h"
#include "DIO_Private.h"
#include "SEVEN_SEG_Config.h"


u8 SevenSegPins[HSEVENSEG_MAX_DISPLAYS][7] = {
	{PORTA_PIN_0, PORTA_PIN_1, PORTA_PIN_2, PORTA_PIN_3, PORTA_PIN_4, PORTA_PIN_5, PORTA_PIN_6}, // Display 1
	{PORTB_PIN_0, PORTB_PIN_1, PORTB_PIN_2, PORTB_PIN_3, PORTB_PIN_4, PORTB_PIN_5, PORTB_PIN_6}, // Display 2
	{PORTC_PIN_0, PORTC_PIN_1, PORTC_PIN_2, PORTC_PIN_3, PORTC_PIN_4, PORTC_PIN_5, PORTC_PIN_6}, // Display 3
	{PORTD_PIN_0, PORTD_PIN_1, PORTD_PIN_2, PORTD_PIN_3, PORTD_PIN_4, PORTD_PIN_5, PORTD_PIN_6}  // Display 4
};