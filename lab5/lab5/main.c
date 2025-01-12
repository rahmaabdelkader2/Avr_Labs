#define F_CPU 10000000UL
#include "led.h"
#include "switch.h"
#include "Switch_cfg.h"
#include <util/delay.h> // For delay

int main(void) {
	// Initialize LED and Switch
	LED_init();
	SWITCH_init();

	u8 switchState = 0; // To store the state of the switch
	u8 ledState = LED_OFF; // To toggle LED state

	while (1){
	//if (SWITCH_enuGetSwitchState(0, &switchState) == SWITCH_OK) {
		//_delay_ms(50); // Debounce delay
		//if (SWITCH_enuGetSwitchState(0, &switchState) == SWITCH_OK && switchState == SWITCH_PRESSED) {
			// Toggle LED
			//ledState = (ledState == LED_OFF) ? LED_ON : LED_OFF;
			//LED_setValue(1, LED_ON);
			//_delay_ms(500); // Prevent rapid toggling
		//}
	//}
	
	if (SWITCH_enuGetSwitchState(0, &switchState) == SWITCH_OK) {
	//	_delay_ms(50); // Debounce delay
		if (SWITCH_enuGetSwitchState(0, &switchState) == SWITCH_OK && switchState == SWITCH_PRESSED) {
			// Toggle LED
			LED_setValue(1, LED_ON);
			if (SWITCH_enuGetSwitchState(0, &switchState) == SWITCH_NOK && switchState == SWITCH_NOT_PRESSED)
			LED_setValue(1, LED_OFF);
			_delay_ms(500); // Prevent rapid toggling
		}
	}
	}

	return 0;
}
