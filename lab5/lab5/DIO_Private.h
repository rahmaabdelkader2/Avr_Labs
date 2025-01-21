

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






#define PORTA_REG (*(volatile unsigned char*)0x3B)
#define PORTB_REG (*(volatile unsigned char*)0x38)
#define PORTC_REG (*(volatile unsigned char*)0x35)
#define PORTD_REG (*(volatile unsigned char*)0x32)

#define DDRA_REG (*(volatile unsigned char*)0x3A)  // Data Direction Register for PORTA
#define DDRB_REG (*(volatile unsigned char*)0x37)  // Data Direction Register for PORTB
#define DDRC_REG (*(volatile unsigned char*)0x34)  // Data Direction Register for PORTC
#define DDRD_REG (*(volatile unsigned char*)0x31)  // Data Direction Register for PORTD

#define PINA_REG (*(volatile unsigned char*)0x39)  // Input Pins for PORTA
#define PINB_REG (*(volatile unsigned char*)0x36)  // Input Pins for PORTB
#define PINC_REG (*(volatile unsigned char*)0x33)  // Input Pins for PORTC
#define PIND_REG (*(volatile unsigned char*)0x30)  // Input Pins for PORTD
