#ifndef SWITCH_H
#define SWITCH_H

#include "stdtypes.h"
#include "DIO.h"
#include "PORT.h"

#define NUM_OF_SWITCHES 3
#define SWITCH_0 0
#define SWITCH_1 1
#define SWITCH_2 2



typedef enum
{
    SW_NOK,
    SW_OK
} SWITCH_enuErrorStatus_t;



void SWITCH_init();

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);

#endif /* SWITCH_H */