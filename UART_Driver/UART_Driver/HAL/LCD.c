/*
 * LCD.c
 *
 * Created: 8/28/2024 10:32:24 AM
 *  Author: USER
 */ 
#include "LCD.h"

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_KICK()
{
	LCD_CTRL &= ~(1<<EN_SWITCH);
	_delay_ms(500);
	LCD_CTRL |= (1<<EN_SWITCH);
}
void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if(line == 1)
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
	else if(line == 2)
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
}
LCD_isbusy(){ 
	#ifdef EIGHT_BIT_MODE
	DataDir_LCD_PORT =0x00;
	#endif
	#ifdef FOUR_BIT_MODE
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	#endif
	LCD_CTRL |= (1<<RW_SWITCH);
	LCD_CTRL &= ~(1<<RS_SWITCH);
	LCD_KICK();
	DataDir_LCD_PORT = 0xFF;
	LCD_CTRL &= ~(1<<RW_SWITCH);
}
void LCD_INIT()
{
	_delay_ms(20);
	LCD_isbusy();
	DataDir_LCD_CTRL |= (1<<EN_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH);
	LCD_CTRL &= ~((1<<EN_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH));
	DataDir_LCD_PORT = 0xFF;
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE 
	LCD_PORT = command;
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & (0x0F))|(command & (0xF0));
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = ((LCD_PORT & (0x0F))|(command<<4));
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	#endif
}

void LCD_WRITE_CHAR(unsigned char data)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE
	LCD_PORT = data;
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	#endif
} 
void LCD_WRITE_STRING(char* string)
{
	unsigned char count = 0;
	while(*string != 0)
	{
		LCD_WRITE_CHAR(*(string++));
		count++;
		if(count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}