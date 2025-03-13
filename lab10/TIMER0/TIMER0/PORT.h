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




#define PORTA_PIN_0	0x00
#define PORTA_PIN_1	0x01
#define PORTA_PIN_2	0x02
#define PORTA_PIN_3	0x03
#define PORTA_PIN_4	0x04
#define PORTA_PIN_5	0x05
#define PORTA_PIN_6	0x06
#define PORTA_PIN_7	0x07


#define PORTB_PIN_0	0x10
#define PORTB_PIN_1	0x11
#define PORTB_PIN_2	0x12
#define PORTB_PIN_3	0x13
#define PORTB_PIN_4	0x14
#define PORTB_PIN_5	0x15
#define PORTB_PIN_6	0x16
#define PORTB_PIN_7	0x17


#define PORTC_PIN_0	0x20
#define PORTC_PIN_1	0x21
#define PORTC_PIN_2	0x22
#define PORTC_PIN_3	0x23
#define PORTC_PIN_4	0x24
#define PORTC_PIN_5	0x25
#define PORTC_PIN_6	0x26
#define PORTC_PIN_7	0x27


#define PORTD_PIN_0	0x30
#define PORTD_PIN_1	0x31
#define PORTD_PIN_2	0x32
#define PORTD_PIN_3	0x33
#define PORTD_PIN_4	0x34
#define PORTD_PIN_5	0x35
#define PORTD_PIN_6	0x36
#define PORTD_PIN_7	0x37


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