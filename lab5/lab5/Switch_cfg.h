#include "stdtypes.h"

#define NUM_OF_SWITCHES 3

#define SWITCH_START    0
#define SWITCH_STOP     1
#define SWITCH_ALERT    2

typedef struct {
	u8 port;
	u8 pin;
	u8 mode;    // Pin mode (e.g., PIN_INPUT, PIN_OUTPUT)
} SwitchCfg_t;
