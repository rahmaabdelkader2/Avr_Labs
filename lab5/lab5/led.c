#include "led.h"
#include "private.h"
#include "led_cfg.h" // Include configuration header

extern  LedCfg_t ledCfg[];  // Declare the external LED configuration array

void LED_init(void) {
	u8 currPin=0;
	u8 currPort=0;


	for (u8 iter = 0; iter < NUM_OF_LEDS; iter++) {
		// check the next line to extract pin and port into two different u8 variables
		currPin = (ledCfg[iter].portpin & 0x0F);
		currPort = (ledCfg[iter].portpin >> 4);

		//currPinPort = (ledCfg[iter].port << 4) + ledCfg[iter].pin;
		MPORT_enuSetPinDirection(currPin, PIN_OUTPUT);
	}
}

LED_enuErrorStatus_t LED_setValue(u8 LedName, u8 Value) {
	
	u8 port_Number = (LedName >> 4) & 0x0F; // Extract port number
	u8 pin_Number = LedName & 0x0F;        // Extract pin number
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
		MDIO_enuSetPinValue(port_Number, pin_Number, Value);
		} else { // Reverse connection
		MDIO_enuSetPinValue(port_Number,pin_Number, !Value);
	}

	return LED_OK;
}
