#define F_CPU 100000000

#include "seven_seg.h"
#include <util/delay.h>

int main(void) {
	// Initialize the seven-segment displays
	HSEVENSEG_vInit();

	// Test single-digit display on the first seven-segment
	// HSEVENSEG_vSetValue(0, 5); // Display 5 on the first seven-segment

	// // Wait for some time to observe the output
	// _delay_ms(500);
	HSEVENSEG_enuSetMultiDigitValue(1234);
	// Infinite loop to keep the program running
	while (1) {
		// Add logic for further tests or keep the display on
	}

	return 0;
}
