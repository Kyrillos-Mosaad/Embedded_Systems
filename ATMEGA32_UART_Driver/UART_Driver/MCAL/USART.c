/*
 * USART.c
 *
 * Created: 9/20/2024 5:40:59 AM
 *  Author: USER
 */ 
#include "USART.h"
static uint8_t* TX_Str ;
static uint8_t* RX_Str ;
static uint8_t flag_send = 1;
static uint8_t flag_receive = 1;
ISR(USART_TXC_vect)
{
	static uint8_t i = 1;
	if(TX_Str[i] != 0)
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i = 1;
		
		flag_send = 1;
		
	}
}

void UART_Init(void)
{
	//baud rate
	UBRRL = 51;
	CLEARBIT(UCSRA,U2X);
	//frame
	//SetBit(UCSRC,URSEL); //Q1
	//CLEARBIT(UCSRC,UMSEL);
	//CLEARBIT(UCSRC,UPM0);
	//CLEARBIT(UCSRC,UPM1);
	//8-bit data
	//SetBit(UCSRC,UCSZ0);
	//SetBit(UCSRC,UCSZ1);
//	CLEARBIT(UCSRC,UCSZ2);
	//Enable
	SetBit(UCSRB,RXEN);
	SetBit(UCSRB,TXEN);
}

uint8_t UART_Receive()
{
	while(!READBIT(UCSRA,RXC));
	return UDR;
}

void UART_Send(uint8_t data)
{
	while(!READBIT(UCSRA,UDRE));
	UDR = data;
	
}

void UART_SendNumber(uint32_t num)
{
	uint8_t *Ptr = &num; // Explicit cast to uint8_t pointer
	UART_Send(Ptr[0]);
	UART_Send(Ptr[1]);
	UART_Send(Ptr[2]);
	UART_Send(Ptr[3]);
	
}

uint32_t UART_ReceiveNumber(void)
{
	uint32_t num;
	uint8_t *ptr = &num;
	ptr[0] = UART_Receive();
	ptr[1] = UART_Receive();
	ptr[2] = UART_Receive();
	ptr[3] = UART_Receive();
	return num;
	
}
void UART_PrintString(char *ptr)
{
	while(*ptr)
	{
		UART_Send(*ptr);
		ptr++;
	}
	UART_Send(defaultStop);
}

void UART_ReceiveString(char *Ptr)
{ 
	
	uint8_t i = 0;
	Ptr[i] = UART_Receive();
	while(Ptr[i] != defaultStop)
	{
		i++;
		Ptr[i] = UART_Receive();
	}
	Ptr[i] = '\0';
}
uint8_t UART_ReceivePeriodicCheck(uint8_t *ptr)
{
	if(READBIT(UCSRA,RXC))
	{
		*ptr = UDR;
		return 1;
	}
	
	return 0;
}

UART_RX_InterruptEable(void)
{
	sei();
	SetBit(UCSRB,RXCIE);
}

UART_RX_InterruptDisable(void)
{
	CLEARBIT(UCSRB,RXCIE);
}
UART_TX_InterruptEable(void)
{
	sei();
	SetBit(UCSRB,TXCIE);
}

UART_TX_InterruptDisable(void)
{
	CLEARBIT(UCSRB,TXCIE);
}

void UART_SendString_Asynch(uint8_t *str)
{
	if(flag_send == 1)
	{
		TX_Str = str;
		UART_TX_InterruptEable();
		UART_SendNoBlock(str[0]);
		flag_send = 0;
	}
}

void UART_SendNoBlock(uint8_t data)
{
	UDR = data;
}

uint8_t UART_ReceiveString_Asynch(uint8_t *str)
{
		RX_Str = str;
		
		UART_RX_InterruptEable();	
		//*RX_Str = UART_ReceiveNoBlock();
		
	return READBIT(UCSRA,RXC);
}

uint8_t UART_ReceiveNoBlock(void)
{
	return UDR;
}