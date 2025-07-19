/*
 * UART_Driver.c
 *
 * Created: 9/20/2024 9:24:45 AM
 * Author : USER
 */ 

#include "HAL/LCD.h"
#include "MCAL/USART.h"
#include "stdio.h"
#include <avr/interrupt.h>
ISR(USART_RXC_vect)
{
	LCD_WRITE_CHAR(UDR);
}
int main(void)
{
	uint32_t num;
	LCD_INIT();
	UART_Init();
//	UART_Send('1');
	//UART_Send('2');
//	UART_Send('3');
	//UART_PrintString("Kyrillos");
	//LCD_WRITE_CHAR(UART_Receive());
	char Name[20];
	char chr;
	/*UART_SendString_Asynch("Kerolos");
	_delay_ms(1000);
	UART_SendString_Asynch("dddddd");
	/* Replace with your application code */
	sei();
	SetBit(UCSRB,RXCIE);
    while (1) 
    {
		
		/*UART_ReceiveString(Name);
		LCD_WRITE_STRING(Name);
		if(UART_ReceivePeriodicCheck(&chr))
		{
			LCD_GOTO_XY(0,0);
			LCD_WRITE_CHAR(chr);
			_delay_ms(100);
		}*/
		}
}

