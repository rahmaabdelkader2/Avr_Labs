#include "switch.h"
#include "Switch_cfg.h"
#include "private.h"


extern SwitchCfg_t switchCfg[];

void SWITCH_init(void) {
	u8 currPinPort = 0;
	for (u8 iter = 0; iter < NUM_OF_SWITCHES; iter++) {
		currPinPort = (switchCfg[iter].port << 4) + switchCfg[iter].pin;
		MPORT_enuSetPinDirection(currPinPort, PIN_INPUT);
	}
}

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State) {
	SWITCH_enuErrorStatus_t Ret_enuErrorStatus = SWITCH_ERROR_INVALID;

	// Validate the input parameters
	if (Copy_u8SwitchName >= NUM_OF_SWITCHES || Add_pu8State == NULL) {
		Ret_enuErrorStatus = SWITCH_ERROR_INVALID;
		} else {
		// Retrieve the switch state
		Ret_enuErrorStatus = SWITCH_OK;

		// Ensure the mode is set to input
		if (switchCfg[Copy_u8SwitchName].mode == PIN_INPUT) {
			MDIO_enuGetPinValue(switchCfg[Copy_u8SwitchName].port,
			switchCfg[Copy_u8SwitchName].pin,
			Add_pu8State);
			} else {
			Ret_enuErrorStatus = SWITCH_ERROR_INVALID;
		}
	}

	return Ret_enuErrorStatus;
}
