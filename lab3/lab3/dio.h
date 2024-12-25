
#ifndef GPIO_H_
#define GPIO_H_


/*******************************************************************************
 *                               common macros                                 *
 *******************************************************************************/


/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))



/*******************************************************************************
 *                               standard types                                *
 *******************************************************************************/

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)
#define NULL              (0u)
typedef unsigned char         u8;          /*           0 .. 255              */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define nummber_of_ports 4
#define nummber_of_pins 32
#define number_of_pins_per_port 8


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
    // PIN_INPUT,            // Pin configured as input (0,0)
    PIN_INPUT_PULLUP =1,     // Pin configured as input with pull-up resistor enabled
    PIN_INPUT_PULLDOWN,   // Pin configured as input with pull-down resistor enabled (0,0)
    PIN_OUTPUT            // Pin configured as output
} GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

typedef enum {
    MDIO_OK,              // Operation successful
    MDIO_NOK,             // Operation failed
    MDIO_INVALID_PIN,     // Invalid pin number
    MDIO_INVALID_PORT     // Invalid port number
} MDIO_enuErrorStatus_t;



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