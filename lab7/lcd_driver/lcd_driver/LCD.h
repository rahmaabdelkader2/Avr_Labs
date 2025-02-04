#ifndef  LCD_H
#define  LCD_H

#include "stdtypes.h"
#include "LCD_config.h"
#include "LCD_private.h"

// error status
typedef struct{
    u8 Error;
    u8 Error_code;
}Error_stat;

void LCD_Init(void); // tmm
void LCD_Command(u8 command); //tmm
void LCD_SendData(u8 data); //tmm
void LCD_SendString(u8 *str); //tmm
void LCD_SendChar(u8 data); //tmm
void LCD_Clear(void); //tmm
void LCD_GoTo(u8 row, u8 col); //tmm
void LCD_Goto_CGRAM(u8 BlockNumber);
void StoreSpecialChar(u8 *pattern,u8 BlockNumber);
void LCD_WriteSpecialChar(u8 BlockNumber, u8 X, u8 Y);
#endif