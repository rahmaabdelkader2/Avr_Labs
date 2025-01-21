#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

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

#endif /* SEVEN_SEG_CONFIG_H_ */