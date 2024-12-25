#include "dio.h"  
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
 * function to set pin value logic high/  low
 */
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuState) {
    if (Copy_enuPinNum > 7) {
        return MDIO_INVALID_PIN;  // Invalid pin number
    }

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

        default:
            return MDIO_INVALID_PORT;
    }

    return MDIO_OK;
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

/*
 * function to set port value
 */
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(u8 Copy_enuPortNum, u8 Copy_enuPortState) {
    switch (Copy_enuPortNum) {
        case 0:
            PORTA = Copy_enuPortState;
            break;

        case 1:
            PORTB = Copy_enuPortState;
            break;

        case 2:
            PORTC = Copy_enuPortState;
            break;

        case 3:
            PORTD = Copy_enuPortState;
            break;

        default:
            return MDIO_INVALID_PORT;
    }

    return MDIO_OK;
}
