#include "bit_math.h"
#include "stdtypes.h"
#include "DIO.h"
#include "PORT.h"
#include "LCD.h"
#include "LCD_config.h"
#include "LCD_Private.h"
#include <util/delay.h>


void LCD_Init(void){
    // Set data port as output (Full port for 8-bit, Upper 4 bits for 4-bit)
    #if LCD_MODE == MODE_8BIT
        MPORT_enuSetPortDirection(LCD_DATA_PORT, MPORT_OUTPUT);
    #elif LCD_MODE == MODE_4BIT
        MPORT_enuSetPortDirection(LCD_DATA_PORT, 0xF0); // Upper 4 bits as output
    #endif
    
    MDIO_enuSetPinConfigration(LCD_CTRL_PORT, LCD_RS, MDIO_OUTPUT);
    MDIO_enuSetPinConfigration(LCD_CTRL_PORT, LCD_RW, MDIO_OUTPUT);
    MDIO_enuSetPinConfigration(LCD_CTRL_PORT, LCD_EN, MDIO_OUTPUT);

    // Set control pins as output
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RS, 1);
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RW, 1);
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_EN, 1);

    _delay_ms(50); // Allow LCD to power up

    // Initialize LCD in the selected mode
    #if LCD_MODE == MODE_8BIT
        LCD_Command(LCD_TWO_LINES_EIGHT_BITS_MODE); // 8-bit mode, 2-line, 5x8 font
    #elif LCD_MODE == MODE_4BIT
        // 4-bit initialization sequence
        LCD_Command(LCD_GO_TO_HOME);
        LCD_Command(LCD_TWO_LINES_FOUR_BITS_MODE); // 4-bit mode, 2-line, 5x8 font
    #endif

    LCD_Command(LCD_CURSOR_BLINK); 
    LCD_Command(LCD_CLEAR_COMMAND); // Clear display
    LCD_Command(LCD_ENTRY_MODE); // Entry mode: Increment cursor
}

void LCD_EnablePulse(void){
	MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_EN, MDIO_HIGH); // Enable HIGH
	_delay_us(1); // Short delay to let LCD latch data
	MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_EN, MDIO_LOW); // Enable LOW (Data Latches)
	_delay_ms(1); // Delay for command execution
}

void LCD_Command(u8 command){
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RS, MDIO_LOW); // RS = 0 for command
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RW, MDIO_LOW); // RW = 0 for write

    #if LCD_MODE == MODE_8BIT
        MDIO_enuSetPortValue(LCD_DATA_PORT, command);
        LCD_EnablePulse();
    #elif LCD_MODE == MODE_4BIT
        MDIO_enuSetPortValue(LCD_DATA_PORT, (command & 0xF0)); // Send upper nibble
        LCD_EnablePulse();
        MDIO_enuSetPortValue(LCD_DATA_PORT, ((command << 4) & 0xF0)); // Send lower nibble
        LCD_EnablePulse();
    #endif

    _delay_ms(2); // Command execution delay
}


void LCD_SendString(u8 *str){
    while(*str != '\0'){
        LCD_SendChar(*str);
        str++;
    }
}


void LCD_SendChar(u8 data){
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RS, MDIO_HIGH); // RS = 1 for data
    MDIO_enuSetPinValue(LCD_CTRL_PORT, LCD_RW, MDIO_LOW);  // RW = 0 for write

    #if LCD_MODE == MODE_8BIT
        MDIO_enuSetPortValue(LCD_DATA_PORT, data);
        LCD_EnablePulse();
    #elif LCD_MODE == MODE_4BIT
        MDIO_enuSetPortValue(LCD_DATA_PORT, (data & 0xF0)); // Send upper nibble
        LCD_EnablePulse();
        MDIO_enuSetPortValue(LCD_DATA_PORT, ((data << 4) & 0xF0)); // Send lower nibble
        LCD_EnablePulse();
    #endif

    _delay_ms(1);
}
void LCD_Clear(void){
    LCD_Command(LCD_CLEAR_COMMAND);
}

void LCD_GoTo(u8 row, u8 col){
    if(row == 0){
        LCD_Command(0x80 + col);
    }else if(row == 1){
        LCD_Command(0xc0 + col);
    }
}

void LCD_Goto_CGRAM(u8 BlockNumber){
    LCD_Command(0x40 + (BlockNumber * 8));
}

void StoreSpecialChar(u8 *pattern,u8 BlockNumber){
    LCD_Goto_CGRAM(BlockNumber);
    for(u8 i = 0; i < 8; i++){
        LCD_SendChar(pattern[i]);
    }
}

void LCD_WriteSpecialChar(u8 BlockNumber, u8 X, u8 Y) {
	LCD_GoTo(X, Y);      // Move cursor to desired position
	LCD_SendChar(BlockNumber); // Send the CGRAM block number (0 to 7) to display the stored character
}

