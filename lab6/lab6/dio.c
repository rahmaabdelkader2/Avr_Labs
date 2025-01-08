#include "dio.h"
#include "stdtypes.h"
#include "private.h"
#define number_of_pins 32 // Define number of pins

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

