#include "stdtypes.h"
#include "bit_math.h"
#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_Config.h"

extern KEYPAD_CONNECTION_t KEYPAD_HW_CONNECTION;

char KEYPAD_SYMBOLS[NUMBERS_OF_ROWS][NUMBERS_OF_COLS] =
{
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'o', '0', '=', '+'}};
    
void KEYPAD_init(void)
{
    MDIO_enuSetPortDir(KEYPAD_PORT, MDIO_PORT_LOW_NIBBLE_INPUT_PULL_UP_HIGH_NIBBLE_OUTPUT);
}

u8 KEYPAD_getKeyPressed(void) {
    u8 Local_u8Row, Local_u8Col;
    u8 Local_u8PressedKey = KEY_NOT_PRESSED;
    
    for (Local_u8Col = 0; Local_u8Col < NUMBERS_OF_COLS; Local_u8Col++) {
        u8 Local_u8value;
        MDIO_enuSetPinValue(KEYPAD_PORT, KEYPAD_HW_CONNECTION.KPD_u8ColPins[Local_u8Col], MDIO_LOW);
        for (Local_u8Row = 0; Local_u8Row < NUMBERS_OF_ROWS; Local_u8Row++) {
            MDIO_enuGetPinValue(KEYPAD_PORT, KEYPAD_HW_CONNECTION.KPD_u8RowPins[Local_u8Row], &Local_u8value);
            if (Local_u8value == MDIO_LOW) {
                while (Local_u8value == MDIO_LOW) {
                    MDIO_enuGetPinValue(KEYPAD_PORT, KEYPAD_HW_CONNECTION.KPD_u8RowPins[Local_u8Row], &Local_u8value);
                }
                Local_u8PressedKey = KEYPAD_SYMBOLS[Local_u8Row][Local_u8Col];
                break;
            }

        }
        MDIO_enuSetPinValue(KEYPAD_PORT, KEYPAD_HW_CONNECTION.KPD_u8ColPins[Local_u8Col], MDIO_HIGH);
        if (Local_u8PressedKey != KEY_NOT_PRESSED) {
            return Local_u8PressedKey;

        }
    }
    return Local_u8PressedKey;
}


