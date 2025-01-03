#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "stdtypes.h"

/* Define the PinCfg array */
typedef struct {
	u8 PortNum_PinNum;
	u8 Config; // Configuration (e.g., PIN_INPUT_PULLUP, PIN_OUTPUT)
} PinConfig_t;

#define PIN_INPUT  0
#define PIN_OUTPUT 1

/* PORTA Pin Definitions */
#define PORTA_PIN_0  0x00
#define PORTA_PIN_1  0x01
#define PORTA_PIN_2  0x02
#define PORTA_PIN_3  0x03
#define PORTA_PIN_4  0x04
#define PORTA_PIN_5  0x05
#define PORTA_PIN_6  0x06
#define PORTA_PIN_7  0x07

/* PORTB Pin Definitions */
#define PORTB_PIN_0  0x10
#define PORTB_PIN_1  0x11
#define PORTB_PIN_2  0x12
#define PORTB_PIN_3  0x13
#define PORTB_PIN_4  0x14
#define PORTB_PIN_5  0x15
#define PORTB_PIN_6  0x16
#define PORTB_PIN_7  0x17

/* PORTC Pin Definitions */
#define PORTC_PIN_0  0x20
#define PORTC_PIN_1  0x21
#define PORTC_PIN_2  0x22
#define PORTC_PIN_3  0x23
#define PORTC_PIN_4  0x24
#define PORTC_PIN_5  0x25
#define PORTC_PIN_6  0x26
#define PORTC_PIN_7  0x27

/* PORTD Pin Definitions */
#define PORTD_PIN_0  0x30
#define PORTD_PIN_1  0x31
#define PORTD_PIN_2  0x32
#define PORTD_PIN_3  0x33
#define PORTD_PIN_4  0x34
#define PORTD_PIN_5  0x35
#define PORTD_PIN_6  0x36
#define PORTD_PIN_7  0x37

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)

#define DDRA (*(volatile unsigned char*)0x3A)  // Data Direction Register for PORTA
#define DDRB (*(volatile unsigned char*)0x37)  // Data Direction Register for PORTB
#define DDRC (*(volatile unsigned char*)0x34)  // Data Direction Register for PORTC
#define DDRD (*(volatile unsigned char*)0x31)  // Data Direction Register for PORTD

#define PINA (*(volatile unsigned char*)0x39)  // Input Pins for PORTA
#define PINB (*(volatile unsigned char*)0x36)  // Input Pins for PORTB
#define PINC (*(volatile unsigned char*)0x33)  // Input Pins for PORTC
#define PIND (*(volatile unsigned char*)0x30)  // Input Pins for PORTD

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
	MPORT_ERROR_UNCHANGEABLE_MODE

} MPORT_enuErrorStatus_t;

// enum for pin modes
typedef enum {
	PORT_PIN_MODE_INPUT_PULLUP,
	PORT_PIN_MODE_INPUT_PULLDOWN,
	PORT_PIN_MODE_UART,
	PORT_PIN_MODE_SPI,
	// Add other modes as needed
} MPORT_enuPinMode_t;


#endif