#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


// Ports
#define LCD_DATA_PORT MDIO_PORTA
#define LCD_CTRL_PORT MDIO_PORTB

// Control Pins
#define LCD_RS MDIO_PIN0  
#define LCD_RW MDIO_PIN1  
#define LCD_EN MDIO_PIN2  

// Data Pins
#define D0 MDIO_PIN0
#define D1 MDIO_PIN1
#define D2 MDIO_PIN2
#define D3 MDIO_PIN3
#define D4 MDIO_PIN4
#define D5 MDIO_PIN5
#define D6 MDIO_PIN6
#define D7 MDIO_PIN7


// LCD Mode
#define MODE_4BIT 0
#define MODE_8BIT 1

#define LCD_MODE    MODE_8BIT 


//macros for LCD commands
#define LCD_CURSOR_ON     0x0E  // Display ON, Cursor ON, Blink OFF
#define LCD_CURSOR_OFF    0x0C  // Display ON, Cursor OFF, Blink OFF
#define LCD_CURSOR_BLINK  0x0F  // Display ON, Cursor ON, Blink ON

#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_SET_CURSOR_LOCATION        0x80
#define LCD_ENTRY_MODE                 0x06

#endif