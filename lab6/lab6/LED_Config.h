#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "stdtypes.h"

#define NUM_OF_LEDS 3

#define LED_START 0
#define LED_STOP 1
#define LED_ALERT 2



typedef struct{
    u8  Port_Pin;
    u8 ledName;
}LedCfg_t;

#endif //LED_CONFIG_H