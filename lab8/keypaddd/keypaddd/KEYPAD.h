#ifndef KEYPAD_H
#define KEYPAD_H

typedef struct
{
	u8 port;
	u8 KPD_u8RowPins[4];
    u8 KPD_u8ColPins[4];
} KEYPAD_CONNECTION_t;


// Function prototypes
void KEYPAD_init(void);
u8 KEYPAD_getKeyPressed(void);

#endif