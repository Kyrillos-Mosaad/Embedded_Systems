/*
 * USART.h
 *
 * Created: 9/20/2024 5:39:39 AM
 *  Author: USER
 */ 


#ifndef USART_H_
#define USART_H_

#include "stdint.h"
#include <avr/io.h>
#include "Utils.h"
#include <avr/interrupt.h>
#define defaultStop			'\r'



void UART_Init(void);

void UART_Send(uint8_t data);

uint8_t UART_Receive(void);

void UART_SendNumber(uint32_t num);

uint32_t UART_ReceiveNumber(void);

void UART_PrintString(char *ptr);

void UART_ReceiveString(char *Ptr);

uint8_t UART_ReceivePeriodicCheck(uint8_t *ptr);

void UART_RX_InterruptEable(void);

void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEable(void);

void UART_TX_InterruptDisable(void);

void UART_SendString_Asynch(uint8_t *str);

void UART_SendNoBlock(uint8_t data);

uint8_t UART_ReceiveString_Asynch(uint8_t *str);

uint8_t UART_ReceiveNoBlock(void);

#endif /* USART_H_ */