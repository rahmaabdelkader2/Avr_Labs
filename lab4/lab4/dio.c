#include "dio.h"

#define number_of_pins 32 // Define number of pins
/*                              for port driver                  */


// Error Status Enum for the Port Driver
typedef enum {
	MPORT_OK = 0,
	MPORT_ERROR_INVALID_PIN = 1,
	MPORT_NOK = 2,
	MPORT_ERROR_INVALID_DIRECTION = 3,
	MPORT_ERROR_INVALID_MODE = 4,
	MPORT_ERROR_UNCHANGEABLE_MODE = 5
} MPORT_enuErrorStatus_t;


/* Define the PinCfg array */
typedef struct {
	u8 PortNum;                   // Port number (0 for PORTA, 1 for PORTB, etc.)
	u8 PinNum;                    // Pin number (0 to 7)
	GPIO_PinDirectionType Config; // Configuration (e.g., PIN_INPUT_PULLUP, PIN_OUTPUT)
} PinConfig_t;

/* Example configuration array */
const PinConfig_t PinCfg[number_of_pins] = {
	// PORTA configuration (already defined as output)
	{0, 0, PIN_OUTPUT},  // PORTA, PIN0 as output
	{0, 1, PIN_OUTPUT},  // PORTA, PIN1 as output
	{0, 2, PIN_OUTPUT},  // PORTA, PIN2 as output
	{0, 3, PIN_OUTPUT},  // PORTA, PIN3 as output
	{0, 4, PIN_OUTPUT},  // PORTA, PIN4 as output
	{0, 5, PIN_OUTPUT},  // PORTA, PIN5 as output
	{0, 6, PIN_OUTPUT},  // PORTA, PIN6 as output
	{0, 7, PIN_OUTPUT},  // PORTA, PIN7 as output

	// PORTB configuration (already defined as input with pull-up)
	{1, 0, PIN_INPUT_PULLUP},  // PORTB, PIN0 as input with pull-up
	{1, 1, PIN_INPUT_PULLUP},  // PORTB, PIN1 as input with pull-up
	{1, 2, PIN_INPUT_PULLUP},  // PORTB, PIN2 as input with pull-up
	{1, 3, PIN_INPUT_PULLUP},  // PORTB, PIN3 as input with pull-up
	{1, 4, PIN_INPUT_PULLUP},  // PORTB, PIN4 as input with pull-up
	{1, 5, PIN_INPUT_PULLUP},  // PORTB, PIN5 as input with pull-up
	{1, 6, PIN_INPUT_PULLUP},  // PORTB, PIN6 as input with pull-up
	{1, 7, PIN_INPUT_PULLUP},  // PORTB, PIN7 as input with pull-up

	// PORTC configuration (set all pins as output)
	{2, 0, PIN_OUTPUT},  // PORTC, PIN0 as output
	{2, 1, PIN_OUTPUT},  // PORTC, PIN1 as output
	{2, 2, PIN_OUTPUT},  // PORTC, PIN2 as output
	{2, 3, PIN_OUTPUT},  // PORTC, PIN3 as output
	{2, 4, PIN_OUTPUT},  // PORTC, PIN4 as output
	{2, 5, PIN_OUTPUT},  // PORTC, PIN5 as output
	{2, 6, PIN_OUTPUT},  // PORTC, PIN6 as output
	{2, 7, PIN_OUTPUT},  // PORTC, PIN7 as output

	// PORTD configuration (set all pins as input with pull-up)
	{3, 0, PIN_INPUT_PULLUP},  // PORTD, PIN0 as input with pull-up
	{3, 1, PIN_INPUT_PULLUP},  // PORTD, PIN1 as input with pull-up
	{3, 2, PIN_INPUT_PULLUP},  // PORTD, PIN2 as input with pull-up
	{3, 3, PIN_INPUT_PULLUP},  // PORTD, PIN3 as input with pull-up
	{3, 4, PIN_INPUT_PULLUP},  // PORTD, PIN4 as input with pull-up
	{3, 5, PIN_INPUT_PULLUP},  // PORTD, PIN5 as input with pull-up
	{3, 6, PIN_INPUT_PULLUP},  // PORTD, PIN6 as input with pull-up
	{3, 7, PIN_INPUT_PULLUP}   // PORTD, PIN7 as input with pull-up
};


/* Function to initialize all pins based on the PinCfg array */
void MDIO_vInit(void) {
	for (u8 i = 0; i < number_of_pins; i++) {
		MDIO_enuSetPinConfigration(PinCfg[i].PortNum, PinCfg[i].PinNum, PinCfg[i].Config);
	}
}

/*
 * function to set pin configuration
 */
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuConfigration) {
    if (Copy_enuPinNum > 7) {
        return MDIO_INVALID_PIN;  // Invalid pin number
    }

    switch (Copy_enuPortNum) {
        case 0: /* PORTA */
            if (Copy_enuConfigration == PIN_OUTPUT) {
                DDRA |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLUP) {
                DDRA &= ~(1 << Copy_enuPinNum);
                PORTA |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLDOWN) {
                DDRA &= ~(1 << Copy_enuPinNum);
                PORTA &= ~(1 << Copy_enuPinNum);
            } else {
                return MDIO_NOK;
            }
            break;

        case 1: /* PORTB */
            if (Copy_enuConfigration == PIN_OUTPUT) {
                DDRB |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLUP) {
                DDRB &= ~(1 << Copy_enuPinNum);
                PORTB |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLDOWN) {
                DDRB &= ~(1 << Copy_enuPinNum);
                PORTB &= ~(1 << Copy_enuPinNum);
            } else {
                return MDIO_NOK;
            }
            break;

        case 2: /* PORTC */
            if (Copy_enuConfigration == PIN_OUTPUT) {
                DDRC |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLUP) {
                DDRC &= ~(1 << Copy_enuPinNum);
                PORTC |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLDOWN) {
                DDRC &= ~(1 << Copy_enuPinNum);
                PORTC &= ~(1 << Copy_enuPinNum);
            } else {
                return MDIO_NOK;
            }
            break;

        case 3: /* PORTD */
            if (Copy_enuConfigration == PIN_OUTPUT) {
                DDRD |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLUP) {
                DDRD &= ~(1 << Copy_enuPinNum);
                PORTD |= (1 << Copy_enuPinNum);
            } else if (Copy_enuConfigration == PIN_INPUT_PULLDOWN) {
                DDRD &= ~(1 << Copy_enuPinNum);
                PORTD &= ~(1 << Copy_enuPinNum);
            } else {
                return MDIO_NOK;
            }
            break;

        default:
            return MDIO_INVALID_PORT;  // Invalid port number
    }

    return MDIO_OK;
}

/*
 * function to set pin value logic high/low
 */
void MDIO_enuSetPinValue(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuState) {
    switch (Copy_enuPortNum) {
        case 0:
            if (Copy_enuState) PORTA |= (1 << Copy_enuPinNum);
            else PORTA &= ~(1 << Copy_enuPinNum);
            break;

        case 1:
            if (Copy_enuState) PORTB |= (1 << Copy_enuPinNum);
            else PORTB &= ~(1 << Copy_enuPinNum);
            break;

        case 2:
            if (Copy_enuState) PORTC |= (1 << Copy_enuPinNum);
            else PORTC &= ~(1 << Copy_enuPinNum);
            break;

        case 3:
            if (Copy_enuState) PORTD |= (1 << Copy_enuPinNum);
            else PORTD &= ~(1 << Copy_enuPinNum);
            break;
    }
}

/*
 * function to get and check on pin value low/high
 */
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8* Add_pu8PinValue) {
    if (Copy_enuPinNum > 7 || Add_pu8PinValue == NULL) {
        return MDIO_INVALID_PIN;
    }

    switch (Copy_enuPortNum) {
        case 0:
            *Add_pu8PinValue = (PINA >> Copy_enuPinNum) & 0x01;
            break;

        case 1:
            *Add_pu8PinValue = (PINB >> Copy_enuPinNum) & 0x01;
            break;

        case 2:
            *Add_pu8PinValue = (PINC >> Copy_enuPinNum) & 0x01;
            break;

        case 3:
            *Add_pu8PinValue = (PIND >> Copy_enuPinNum) & 0x01;
            break;

        default:
            return MDIO_INVALID_PORT;
    }

    return MDIO_OK;
}

/*
 * function to set port configuration
 */
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(u8 Copy_enuPortNum, u8 Copy_enuConfigration) {
    switch (Copy_enuPortNum) {
        case 0: /* PORTA */
            if (Copy_enuConfigration == PORT_OUTPUT) {
                DDRA = 0xFF;  // All pins as output
            } else if (Copy_enuConfigration == PORT_INPUT) {
                DDRA = 0x00;  // All pins as input
                PORTA = 0x00; // Disable pull-up resistors
            } else {
                return MDIO_NOK;
            }
            break;

        case 1: /* PORTB */
            if (Copy_enuConfigration == PORT_OUTPUT) {
                DDRB = 0xFF;
            } else if (Copy_enuConfigration == PORT_INPUT) {
                DDRB = 0x00;
                PORTB = 0x00;
            } else {
                return MDIO_NOK;
            }
            break;

        case 2: /* PORTC */
            if (Copy_enuConfigration == PORT_OUTPUT) {
                DDRC = 0xFF;
            } else if (Copy_enuConfigration == PORT_INPUT) {
                DDRC = 0x00;
                PORTC = 0x00;
            } else {
                return MDIO_NOK;
            }
            break;

        case 3: /* PORTD */
            if (Copy_enuConfigration == PORT_OUTPUT) {
                DDRD = 0xFF;
            } else if (Copy_enuConfigration == PORT_INPUT) {
                DDRD = 0x00;
                PORTD = 0x00;
            } else {
                return MDIO_NOK;
            }
            break;

        default:
            return MDIO_INVALID_PORT;
    }

    return MDIO_OK;
}
