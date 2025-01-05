#include "led.h"
#include "private.h"
#include "led_cfg.h" // Include configuration header

extern  LedCfg_t ledCfg[];  // Declare the external LED configuration array

void LED_init(void) {
	u8 currPinPort = 0;
	for (u8 iter = 0; iter < NUM_OF_LEDS; iter++) {
		currPinPort = (ledCfg[iter].port << 4) + ledCfg[iter].pin;
		MPORT_enuSetPinDirection(currPinPort, PIN_OUTPUT);
	}
}

LED_enuErrorStatus_t LED_setValue(u8 LedName, u8 Value) {
	// Check for invalid LED index
	if (LedName >= NUM_OF_LEDS) {
		return LED_ERROR_INVALID_LED;
	}

	// Check for invalid state
	if (Value > LED_ON) {
		return LED_ERROR_INVALID_STATE;
	}

	// Set the pin value based on the connection type
	if (ledCfg[LedName].connection == Forward) {
		MDIO_enuSetPinValue(ledCfg[LedName].port, ledCfg[LedName].pin, Value);
		} else { // Reverse connection
		MDIO_enuSetPinValue(ledCfg[LedName].port, ledCfg[LedName].pin, !Value);
	}

	return LED_OK;
}
