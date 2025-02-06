#ifndef PORT_H_
#define PORT_H_


/* Error Status Enum */
typedef enum {
	MPORT_OK,              // Operation successful
	MPORT_NOK,             // Operation failed
	MPORT_INVALID_PIN,     // Invalid pin number
	MPORT_INVALID_PORT,     // Invalid port number
	MPORT_INVALID_PIN_MODE, // invalid mode for pin
	MPORT_INVALID_PIN_CONFIG,
	MPORT_ERROR_INVALID_PIN,
	MPORT_ERROR_INVALID_DIRECTION,
	MPORT_ERROR_INVALID_MODE,
	MPORT_ERROR_UNCHANGEABLE_MODE,
    MPORT_INVALID_PARAM

} MPORT_enuErrorStatus_t;

// enum for pin modes
typedef enum {
	PORT_PIN_MODE_INPUT_PULLUP,
	PORT_PIN_MODE_INPUT_PULLDOWN,
	PORT_PIN_MODE_UART,
	PORT_PIN_MODE_SPI,
	// Add other modes as needed
} MPORT_enuPinMode_t;


#define MPORT_INPUT 0
#define MPORT_OUTPUT 1
#define MPORT_INPUT_PULLUP 2


/* Bit Manipulation Macros */

#define MPORT_HIGH 1
#define MPORT_LOW  0
#define MPORT_ENABLED 1
#define MPORT_DISABLED 0


/* Public Functions */

/*********************************************************************/
//function name: MPORT_vINIT
//function arguments: void
//function return: void
//function functionality: initialize the port
/*********************************************************************/
void MPORT_vINIT();

/*********************************************************************/
//function name: MPORT_enuSetPinDirection
//function arguments: u8 Copy_enuPinNum, u8 Copy_enuPinDirection
//function return: MPORT_enuErrorStatus_t
//function functionality: set the direction of the pin
/*********************************************************************/
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum, u8 Copy_enuPinDirection);

MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(u8 Copy_enuPortNum_PinNum, u8 Copy_enuConfigration);
MPORT_enuErrorStatus_t MPORT_enuSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8PortDirection);
#endif //PORT_H_