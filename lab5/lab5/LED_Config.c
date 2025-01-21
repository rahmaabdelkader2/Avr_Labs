
#include "PORT.h"
#include "DIO_Private.h"
#include "LED_Config.h"

LedCfg_t ledCfg [NUM_OF_LEDS]=
{
    {PORTB_PIN_0,LED_START},
    {PORTB_PIN_1,LED_STOP},
    {PORTB_PIN_2,LED_ALERT}
};



