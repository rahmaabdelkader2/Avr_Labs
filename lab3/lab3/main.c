
#define F_CPU 100000000UL // Set the clock frequency to 100 MHz (adjust if needed)

#include "dio.h"
#include <util/delay.h> // For delay function

// LED Port and Pin Definitions
#define LED1_PORT 0
#define LED2_PORT 0
#define LED3_PORT 0

#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2

// Button Port and Pin Definitions
#define BUTTON1_PORT 1
#define BUTTON2_PORT 1
#define BUTTON3_PORT 1

#define BUTTON1_PIN 0
#define BUTTON2_PIN 1
#define BUTTON3_PIN 2


// Function to debounce button presses
uint8_t debounceButton(uint8_t port, uint8_t pin) {
    uint8_t state1, state2;
    MDIO_enuGetPinValue(port, pin, &state1);
    _delay_ms(10);  // Wait for a small time
    MDIO_enuGetPinValue(port, pin, &state2);
    if (state1 == state2) {
        return state1; // Return the stable state
    }
    return 1; // Return a non-pressed state if it doesn't match
}

int main(void)
{
	MDIO_vInit();
  


    while (1)
    {
        uint8_t button1State = 0;
        uint8_t button2State = 0;
        uint8_t button3State = 0;

        // Debounce the button states
        button1State = debounceButton(BUTTON1_PORT, BUTTON1_PIN);
        button2State = debounceButton(BUTTON2_PORT, BUTTON2_PIN);
        button3State = debounceButton(BUTTON3_PORT, BUTTON3_PIN);

        // Control LEDs based on button states
        if (button1State == 0) // Button 1 pressed
        {
            MDIO_enuSetPinValue(LED1_PORT, LED1_PIN, LOGIC_HIGH);
        }
        else
        {
            MDIO_enuSetPinValue(LED1_PORT, LED1_PIN, LOGIC_LOW);
        }

        if (button2State == 0) // Button 2 pressed
        {
            MDIO_enuSetPinValue(LED2_PORT, LED2_PIN, LOGIC_HIGH);
        }
        else
        {
            MDIO_enuSetPinValue(LED2_PORT, LED2_PIN, LOGIC_LOW);
        }

        if (button3State == 0) // Button 3 pressed
        {
            MDIO_enuSetPinValue(LED3_PORT, LED3_PIN, LOGIC_HIGH);
        }
        else
        {
            MDIO_enuSetPinValue(LED3_PORT, LED3_PIN, LOGIC_LOW);
        }

        _delay_ms(10); // Small delay for debouncing
    }

    return 0;
}
