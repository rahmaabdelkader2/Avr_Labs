#include "stdtypes.h"

/* Error Status enum */
typedef enum {
	HSEVENSEG_enuOK,
	HSEVENSEG_enuSevenSegLimitError
} HSEVENSEG_enuErrorStatus_t;

/* Functions Prototypes */
void HSEVENSEG_vInit(void);
void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value);
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);

