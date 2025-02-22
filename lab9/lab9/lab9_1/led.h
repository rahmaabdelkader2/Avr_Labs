#ifndef LED_H
#define LED_H

// #include "stdtypes.h"

typedef enum{
    LED_START,
    LED_STOP,
    LED_ALERT
}LedName_t;

typedef enum{
    NOK,
    OK
}LedRetStatus_t;



void HLED_vidINIT();

LedRetStatus_t LED_setValue(u8 LedName, u8 Value);

#endif //LED_H