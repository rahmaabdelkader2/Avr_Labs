#include "switch.h"
#include "Switch_cfg.h"
#include "private.h"


extern SwitchCfg_t switchCfg[];

void SWITCH_init(void) {
	
	for (u8 iter = 0; iter < NUM_OF_SWITCHES; iter++) {
		MPORT_enuSetPinDirection(switchCfg[iter].portpin, PIN_INPUT);
	}
}

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State) {
	SWITCH_enuErrorStatus_t Ret_enuErrorStatus = SWITCH_ERROR_INVALID;
    	u8 port_Number = (Copy_u8SwitchName >> 4) & 0x0F; // Extract port number
    	u8 pin_Number = Copy_u8SwitchName & 0x0F;        // Extract pin number
	// Validate the input parameters
	if (Copy_u8SwitchName >= NUM_OF_SWITCHES || Add_pu8State == NULL) {
		Ret_enuErrorStatus = SWITCH_ERROR_INVALID;
		} else {
		// Retrieve the switch state
		Ret_enuErrorStatus = SWITCH_OK;

		// Ensure the mode is set to input
		if (switchCfg[Copy_u8SwitchName].mode == PIN_INPUT) {
			
			MDIO_enuGetPinValue(port_Number,pin_Number,Add_pu8State);
			} else {
			Ret_enuErrorStatus = SWITCH_NOK;
		}
	}

	return Ret_enuErrorStatus;
}
