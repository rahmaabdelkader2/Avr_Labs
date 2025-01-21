#include "stdtypes.h"
#include "DIO.h"
#include "PORT.h"
#include "SWITCH.h"
#include "SWITCH_Config.h"
#include "led.h"
#include "LED_Config.h"
#include "PORT_Config.h"
#include "bit_math.h"


int main()
{
    HLID_vidINIT();
    SWITCH_init();
    u8 Local_u8SwitchState;
    LED_setValue(LED_START, 0);
    LED_setValue(LED_STOP, 0);
    LED_setValue(LED_ALERT, 0);

    while(1)
    {
        SWITCH_enuGetSwitchState(HSWITCH_1, &Local_u8SwitchState);
        Local_u8SwitchState ==1 ? LED_setValue(LED_START, 1) : LED_setValue(LED_START, 0);
        SWITCH_enuGetSwitchState(HSWITCH_2, &Local_u8SwitchState);
        Local_u8SwitchState ==1 ? LED_setValue(LED_STOP, 1) : LED_setValue(LED_STOP, 0);
        SWITCH_enuGetSwitchState(HSWITCH_3, &Local_u8SwitchState);
        Local_u8SwitchState ==1 ? LED_setValue(LED_ALERT, 1) : LED_setValue(LED_ALERT, 0);
    }

}

