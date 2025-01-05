#include "stdtypes.h"
#define NUM_OF_LEDS    3

typedef enum
{
	Forward,
	Reverse
} LED_Connection_t;

typedef struct
{
	u8 port;
	u8 pin;
	LED_Connection_t connection;
} LedCfg_t;


