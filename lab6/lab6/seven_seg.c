#include "stdtypes.h"
#include "dio.h"
#include "port.h"
#include "seven_seg.h"
#include "seven_seg_config.h"

extern u8 SevenSegPins[HSEVENSEG_MAX_DISPLAYS][7];

/* Segment encoding for digits 0-9 */
u8 SevenSegDigitEncoding[10] = {
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
	0xC0, // 0
	0xF9, // 1
	0xA4, // 2
	0xB0, // 3
	0x99, // 4
	0x92, // 5
	0x82, // 6
	0xF8, // 7
	0x80, // 8
	0x90  // 9
	#endif
};

/* Initialization Function */
void HSEVENSEG_vInit(void) {
	for (u8 display = 0; display < HSEVENSEG_MAX_DISPLAYS; display++) {
		for (u8 segment = 0; segment < 7; segment++) {
			MPORT_enuSetPortConfigration(SevenSegPins[display][segment] , PIN_OUTPUT);
		}
	}
}

/* Set Value on a Single Seven-Segment Display */
void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value) {
	if (Copy_enuSevenSegNum >= HSEVENSEG_MAX_DISPLAYS || Copy_u8Value > 9) {
		return; // Invalid input
	}

	u8 encodedValue = SevenSegDigitEncoding[Copy_u8Value];

	for (u8 segment = 0; segment < 7; segment++) {
		u8 pinState = (encodedValue >> segment) & 0x01;
		MDIO_enuSetPinValue((SevenSegPins[Copy_enuSevenSegNum][segment] >> 4)&0x0F, SevenSegPins[Copy_enuSevenSegNum][segment] & 0x0F, pinState);
	}
}

/* Display Multi-Digit Value Across Multiple Seven-Segment Displays */
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value) {
    u16 reversedValue = 0;
    u8 digitCount = 0;

    // Reverse the digits of Copy_u16Value
    while (Copy_u16Value > 0) {
        reversedValue = (reversedValue * 10) + (Copy_u16Value % 10);
        Copy_u16Value /= 10;
        digitCount++;
    }

    // Pad the remaining digits with 0 if necessary
    for (u8 display = 0; display < HSEVENSEG_MAX_DISPLAYS; display++) {
        if (display < digitCount) {
            u8 digit = reversedValue % 10;
            reversedValue /= 10;
            HSEVENSEG_vSetValue(display, digit);
        } else {
            HSEVENSEG_vSetValue(display, 0); // Fill remaining displays with 0
        }
    }

    return HSEVENSEG_enuOK;
}

