/*
 * Keybad.h
 *
 * Created: 8/29/2024 9:20:10 AM
 *  Author: USER
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#define F_CPU 8000000UL
#include "STM32F103Cx6.h"
#include "STM32F103C6_GPIO_Driver.h"

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

#define KEYPAD_PORT GPIOB

void Keypad_init();
char Keypad_getkey();





#endif /* KEYBAD_H_ */
