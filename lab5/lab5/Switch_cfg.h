#include "stdtypes.h"

#define NUM_OF_SWITCHES 3

typedef struct {
	u8 portpin;
	u8 mode;    // Pin mode (e.g., PIN_INPUT, PIN_OUTPUT)
} SwitchCfg_t;

typedef enum{
	SWITCH_PRESSED,
	SWITCH_NOT_PRESSED
	}switchstate;