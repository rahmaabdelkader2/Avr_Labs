#include "stdtypes.h"
#include "bit_math.h"
#include "led.h"
#include "DIO.h"
#include "PORT.h"
#include "LED_Config.h"

extern LedCfg_t ledCfg [NUM_OF_LEDS];


void HLED_vidINIT()
{
    u8 Local_u8LedIndex;
    for(Local_u8LedIndex = 0; Local_u8LedIndex < NUM_OF_LEDS; Local_u8LedIndex++)
    {
        MPORT_enuSetPinDirection(ledCfg[Local_u8LedIndex].Port_Pin, MPORT_OUTPUT);
    }
}


LedRetStatus_t LED_setValue(u8 LedName, u8 Value)
{
    for(u8 Local_u8LedIndex = 0; Local_u8LedIndex < NUM_OF_LEDS; Local_u8LedIndex++)
    {
        if(ledCfg[Local_u8LedIndex].ledName == LedName)
        {
            u8 Local_u8PortNum = (ledCfg[Local_u8LedIndex].Port_Pin >> 4) & 0x0F;
            u8 Local_u8PinNum = ledCfg[Local_u8LedIndex].Port_Pin & 0x0F; 
            MDIO_enuSetPinValue(Local_u8PortNum,Local_u8PinNum, Value);
            return OK;
        }
    }
}