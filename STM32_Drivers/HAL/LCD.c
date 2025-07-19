
/*
 * LCD.c
 *
 * Created: 8/28/2024 10:32:24 AM
 *  Author: USER
 */
#include "LCD.h"
#include "STM32F103C6_GPIO_Driver.h"
GPIO_PinConfig_t PinCfg ;
void my_wait(int x)
{
	uint32_t y,z;
	for(y=0;y<x;y++)
		for(z=0;z<255;z++);
}
void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_KICK()
{
	//LCD_CTRL &= ~(1<<EN_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	my_wait(50);
	//LCD_CTRL |= (1<<EN_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}
void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
LCD_isbusy(){
#ifdef EIGHT_BIT_MODE
	//DataDir_LCD_PORT =0x00;
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
#endif
#ifdef FOUR_BIT_MODE
	//DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
#endif
	//LCD_CTRL |= (1<<RW_SWITCH);
	//LCD_CTRL &= ~(1<<RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL,RW_SWITCH,GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	LCD_KICK();
	//DataDir_LCD_PORT = 0xFF;
	//LCD_CTRL &= ~(1<<RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL,RW_SWITCH,GPIO_PIN_RESET);
}
void LCD_INIT() {

	my_wait(20);
	// SET THE FIRST 3 PINS AS OUPUT
	LCD_GPIO_init();
//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
//	DataDir_LCD_PORT = 0xFF;
	my_wait(15);

	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_GPIO_init()
{
	my_wait(20);
	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);
	//=================================================
	PinCfg.GPIO_PinNumber= GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber= GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	LCD_clear_screen();
#ifdef EIGHT_BIT_MODE
	//LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif
//	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
//	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
//	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	//LCD_isbusy();
#ifdef EIGHT_BIT_MODE
	//LCD_PORT = command;
	MCAL_GPIO_WritePort(LCD_PORT, command);
	//LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	MCAL_GPIO_WritePin(LCD_PORT,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT,RS_SWITCH,GPIO_PIN_RESET);
	my_wait(1);
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & (0x0F))|(command & (0xF0));
	//LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	MCAL_GPIO_WritePin(GPIOA,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(GPIOA,RS_SWITCH,GPIO_PIN_SET);
	my_wait(1);
	LCD_KICK();
	LCD_PORT = ((LCD_PORT & (0x0F))|(command<<4));
	//LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	MCAL_GPIO_WritePin(GPIOA,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(GPIOA,RS_SWITCH,GPIO_PIN_SET);
	my_wait(1);
	LCD_KICK();
#endif
}

void LCD_WRITE_CHAR(unsigned char data)
{
	//LCD_isbusy();
#ifdef EIGHT_BIT_MODE
	//LCD_PORT = data;
	MCAL_GPIO_WritePort(LCD_PORT, data);
	//LCD_CTRL &= ~(1<<RW_SWITCH);
	//LCD_CTRL |= (1<<RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_PORT,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT,RS_SWITCH,GPIO_PIN_SET);
	my_wait(1);
	LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	my_wait(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	my_wait(1);
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
