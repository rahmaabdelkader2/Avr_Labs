#include "SWITCH_Config.h"
#include "stdtypes.h"
#include "PORT.h"



SWITCH_t SWITCH_AstrSwitches[NUM_OF_SWITCHES] =
{
    {HSWITCH_1, PORTA_PIN_0, MPORT_INPUT},
    {HSWITCH_2, PORTA_PIN_1,MPORT_INPUT},
    {HSWITCH_3, PORTA_PIN_2, MPORT_INPUT}
};