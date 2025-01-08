
#include "stdtypes.h"

/* Define Seven-Segment Configuration */
#define HSEVENSEG_MAX_DISPLAYS 4
/* Define segment type here */
#define SEVEN_SEG_TYPE COMMON_CATHODE

/* enum for segment type */
typedef enum {
	COMMON_CATHODE,
	COMMON_ANODE
} SevenSegType_t;

