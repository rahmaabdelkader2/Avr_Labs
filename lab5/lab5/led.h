#ifndef LED_H
#define LED_H
#include "stdtypes.h"
typedef enum {
	LED_OK,
	LED_ERROR_INVALID_LED,
	LED_ERROR_INVALID_STATE
} LED_enuErrorStatus_t;

typedef enum {
	LED_OFF,
	LED_ON
} LED_State_t;

typedef enum {
	LED_START,
	LED_STOP,
	LED_ALERT
} LED_Name_t;

void LED_init(void);  // Function to initialize LEDs
LED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, LED_State_t Copy_u8State);  // Function to set LED state

#endif /* LED_H */



