#ifndef SW_CFG_H
#define SW_CFG_H

#include "stdtypes.h"

#define NUM_OF_SWITCHES 3

#define HSWITCH_1 0
#define HSWITCH_2 1
#define HSWITCH_3 2


typedef struct
{
    u8 SwitchName;
    u8 SwitchPortPin;
    u8 SwitchConnectionType;
}SWITCH_t;





#endif //SW_CFG_H
