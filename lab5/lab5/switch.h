#include "stdtypes.h"
typedef enum {
	SWITCH_OK,
	SWITCH_ERROR_INVALID,
	SWITCH_ERROR_INVALID_STATE
} SWITCH_enuErrorStatus_t;


void SWITCH_init(void);
SWITCH_enuErrorStatus_t SWITCH_getValue(u8 SwitchName, u8 * ptr);
