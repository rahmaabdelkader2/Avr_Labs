#include "stdtypes.h"
#include "bit_math.h"
#include "SWITCH.h"
#include "PORT.h"
#include "DIO.h"
#include "SWITCH_Config.h"

extern SWITCH_t SWITCH_AstrSwitches[NUM_OF_SWITCHES];



void SWITCH_init()
{
    u8 Local_u8SwitchIndex;
    for(Local_u8SwitchIndex = 0; Local_u8SwitchIndex < NUM_OF_SWITCHES; Local_u8SwitchIndex++)
    {
        MPORT_enuSetPinDirection(SWITCH_AstrSwitches[Local_u8SwitchIndex].SwitchPortPin, SWITCH_AstrSwitches[Local_u8SwitchIndex].SwitchConnectionType);
    }
}

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State)
{

    SWITCH_enuErrorStatus_t Local_enuErrorStatus = SW_NOK;
    u8 Local_u8SwitchIndex;

    for(Local_u8SwitchIndex = 0; Local_u8SwitchIndex < NUM_OF_SWITCHES; Local_u8SwitchIndex++)
    {
        if(SWITCH_AstrSwitches[Local_u8SwitchIndex].SwitchName == Copy_u8SwitchName)
        {
            u8 Local_u8PortValue = (SWITCH_AstrSwitches[Local_u8SwitchIndex].SwitchPortPin >> 4) & 0x0F;
            u8 Local_u8PinValue = SWITCH_AstrSwitches[Local_u8SwitchIndex].SwitchPortPin & 0x0F;
            if(Local_u8PortValue <= MDIO_PORTD && Local_u8PinValue <= MDIO_PIN7)
            {
                MDIO_enuGetPinValue(Local_u8PortValue, Local_u8PinValue, Add_pu8State);
                Local_enuErrorStatus = SW_OK;        
            }
            break;
        }
    }
    return Local_enuErrorStatus;
}
