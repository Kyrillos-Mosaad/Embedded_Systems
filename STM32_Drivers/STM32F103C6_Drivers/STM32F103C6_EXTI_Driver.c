/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 30, 2024
 *      Author: USER
 */
#include "STM32F103C6_GPIO_Driver.h"

#include "STM32F103C6_EXTI_Driver.h"
//================================================================
//Generic Varibles
//================================================================
void (*GP_IRQ_CALLBACK[16])(void);
//================================================================
//Generic Macros
//================================================================

#define AFIO_GPIO_EXTI_Mapping(x)	(	(x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:0	)
//================================================================
//Generic Function
//================================================================
void Enable_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;

	}
}
void Disable_NVIC(uint8_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;

	}
}

void Update_EXTI(EXTI_PinConfig_t *EXTI_Config)
{
	// 1- configure GPIO to be AF Input -> Floating INPUT
	GPIO_PinConfig_t PinCfg ;
	//Update GPIO Pin to be floating input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXIT_PIN.GPIO_PIN ;
	PinCfg.GPIO_MODE	   = GPIO_MODE_INPUT_FLO ;
    MCAL_GPIO_Init(EXTI_Config->EXIT_PIN.GPIO_Port, &PinCfg);

	// 2- update AFIO Pin To Route Between EXTI Line with PORT A,B,C,D

	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXIT_PIN.InputLineNumber / 4 ;
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXIT_PIN.InputLineNumber % 4 ) * 4 ;

	// Clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXIT_PIN.GPIO_Port) & 0xF)<<AFIO_EXTICR_Position);
	// Update Rising and Falling Edge
	EXTI->RTSR &= ~(1<<EXTI_Config->EXIT_PIN.InputLineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXIT_PIN.InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXIT_PIN.InputLineNumber);

	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXIT_PIN.InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_RISINGAndFALLING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXIT_PIN.InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXIT_PIN.InputLineNumber);
	}

	//=====================================================================
	// 4-Update IRQ Handling CALLBACK

	GP_IRQ_CALLBACK[EXTI_Config->EXIT_PIN.InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

	//=====================================================================
	// 5-Enable or Disable For IRQ and NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXIT_PIN.InputLineNumber);
		Enable_NVIC(EXTI_Config->EXIT_PIN.InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~ (1<<EXTI_Config->EXIT_PIN.InputLineNumber);
		Disable_NVIC(EXTI_Config->EXIT_PIN.InputLineNumber);
	}
}
/**================================================================
 * @Fn					-MCAL_EXTI_GPIO_Deinit
 * @brief				-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinConfig pointer to a GPIO_pinconfig_t structure that contains
 * 							the configuration information for the specified GPIO peripheral.
 * @retval 				-none
 * Note					-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 							But LQFP48 Package has only GPIO A,B,PART OF C/D exported as external PINs from MCU
===================================================================
 */

void MCAL_EXTI_GPIO_Deinit(void)
{
	EXTI->IMR 	=  0x00000000;
	EXTI->EMR 	=  0x00000000;
	EXTI->RTSR 	=  0x00000000;
	EXTI->FTSR  =  0x00000000;
	EXTI->SWIER =  0x00000000;
	EXTI->PR    =  0xFFFFFFFF;
	//Disable IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable ;
	NVIC_IRQ7_EXTI1_Disable ;
	NVIC_IRQ8_EXTI2_Disable ;
	NVIC_IRQ9_EXTI3_Disable ;
	NVIC_IRQ10_EXTI4_Disable ;
	NVIC_IRQ23_EXTI5_9_Disable ;
	NVIC_IRQ40_EXTI10_15_Disable ;

}
/**================================================================
 * @Fn					-MCAL_EXTI_GPIO_Init
 * @brief				-this is used to initialize EXTI from specific GPIO PIN and specify Mask and Trigger and IRQ Callback
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinConfig pointer to a GPIO_pinconfig_t structure that contains
 * 							the configuration information for the specified GPIO peripheral.
 * @retval 				-none
 * Note					-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 							But LQFP48 Package has only GPIO A,B,PART OF C/D exported as external PINs from MCU
===================================================================
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn					-MCAL_EXTI_GPIO_Update
 * @brief				-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinConfig pointer to a GPIO_pinconfig_t structure that contains
 * 							the configuration information for the specified GPIO peripheral.
 * @retval 				-none
 * Note					-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 							But LQFP48 Package has only GPIO A,B,PART OF C/D exported as external PINs from MCU
===================================================================
 */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

//=================================================================
//====================== ISR Functions ============================
//=================================================================

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= 1<<0 ;
	GP_IRQ_CALLBACK[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= 1<<1 ;
	GP_IRQ_CALLBACK[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= 1<<2 ;
	GP_IRQ_CALLBACK[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= 1<<3 ;
	GP_IRQ_CALLBACK[3]();
}
void EXTI4_IRQHandler(void)
{
	EXTI->PR |= 1<<4 ;
	GP_IRQ_CALLBACK[4]();
}

void EXTI5_9_IRQHandler(void)
{
	if(EXTI->PR & (1<<5)) {EXTI->PR |= 1<<5 ; GP_IRQ_CALLBACK[5]();}
	else if(EXTI->PR & (1<<6)) {EXTI->PR |= 1<<6 ; GP_IRQ_CALLBACK[6]();}
	else if(EXTI->PR & (1<<7)) {EXTI->PR |= 1<<7 ; GP_IRQ_CALLBACK[7]();}
	else if(EXTI->PR & (1<<8)) {EXTI->PR |= 1<<8 ; GP_IRQ_CALLBACK[8]();}
	else if(EXTI->PR & (1<<9)) {EXTI->PR |= 1<<9 ; GP_IRQ_CALLBACK[9]();}
}

void EXTI10_15_IRQHandler(void)
{
	if(EXTI->PR & (1<<10)) {EXTI->PR |= 1<<10 ; GP_IRQ_CALLBACK[10]();}
	else if(EXTI->PR & (1<<11)) {EXTI->PR |= 1<<11 ; GP_IRQ_CALLBACK[11]();}
	else if(EXTI->PR & (1<<12)) {EXTI->PR |= 1<<12 ; GP_IRQ_CALLBACK[12]();}
	else if(EXTI->PR & (1<<13)) {EXTI->PR |= 1<<13 ; GP_IRQ_CALLBACK[13]();}
	else if(EXTI->PR & (1<<14)) {EXTI->PR |= 1<<14 ; GP_IRQ_CALLBACK[14]();}
	else if(EXTI->PR & (1<<15)) {EXTI->PR |= 1<<15 ; GP_IRQ_CALLBACK[15]();}

}

