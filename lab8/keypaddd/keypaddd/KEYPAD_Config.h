#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define NUMBERS_OF_ROWS  4
#define NUMBERS_OF_COLS  4

#define KEYPAD_PORT MDIO_PORTC 




// ROWS MAPPING
#define ROW_Start MDIO_PIN0
#define ROW_END MDIO_PIN3

// COLUMNS MAPPING
#define Column_start MDIO_PIN4
#define Column_End MDIO_PIN7


#define KEY_NOT_PRESSED 0xFF
#define KEYPAD_PRESSED 0x00

#endif