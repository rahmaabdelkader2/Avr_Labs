
#ifndef GPIO_H_
#define GPIO_H_

#include "stdtypes.h"
typedef enum {
    MDIO_OK,              // Operation successful
    MDIO_NOK,             // Operation failed
    MDIO_INVALID_PIN,     // Invalid pin number
    MDIO_INVALID_PORT     // Invalid port number
} MDIO_enuErrorStatus_t;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;



/*******************************************************************************
 *                          Functions' Prototypes                              *
 *******************************************************************************/

void MDIO_vInit (void);

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuConfigration);


void MDIO_enuSetPinValue(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuState);


MDIO_enuErrorStatus_t MDIO_enuGetPinValue(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8* Add_pu8PinValue);


MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(u8 Copy_enuPortNum, u8 Copy_enuConfigration);


MDIO_enuErrorStatus_t MDIO_enuSetPortValue(u8 Copy_enuPortNum, u8 Copy_enuPortState);

#endif /* GPIO_H_ */