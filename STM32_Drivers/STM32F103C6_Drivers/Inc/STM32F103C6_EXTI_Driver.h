/*
 * STM32F103C6_EXTI_Driver.h
 *
 *  Created on: Aug 30, 2024
 *      Author: USER
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

//Includes
#include "STM32F103Cx6.h"
#include "STM32F103C6_GPIO_Driver.h"


typedef struct
{
	uint16_t 		InputLineNumber ;
	GPIO_TypeDef*	GPIO_Port ;
	uint16_t 		GPIO_PIN ;
	uint8_t			IVT_IRQ_Number ;
} EXTI_GPIO_Maping_t;

typedef struct
{
	EXTI_GPIO_Maping_t EXIT_PIN ; //specifies the external interrupt GPIO Mapping
								 //This Parameter must be set based on @ref EXTI_define

	uint8_t Trigger_Case ; 		//specifies Rising or Falling or both Trigger
							   //This Parameter must be set based on @ref EXTI_Trigger_define

	uint8_t IRQ_EN ; 		//specifies Enable or Disable the EXTI IRQ (That will Enable the IRQ MASK in EXTI and also on the NVIC Interrupt)
						   //This Parameter must be set based on @ref EXTI_IRQ_define

	void(*P_IRQ_CallBack)(void) ;
} EXTI_PinConfig_t;

//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//EXTI_MACROS
//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
#define EXTI0	0
#define EXTI1	1
#define EXTI2	2
#define EXTI3	3
#define EXTI4	4
#define EXTI5	5
#define EXTI6	6
#define EXTI7	7
#define EXTI8	8
#define EXTI9	9
#define EXTI10	10
#define EXTI11	11
#define EXTI12	12
#define EXTI13	13
#define EXTI14	14
#define EXTI15	15

//Reference Macros
//@ref EXTI_define
//EXTI0
#define EXTI0_GPIOA0 (EXTI_GPIO_Maping_t){EXTI0, GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_GPIOB0 (EXTI_GPIO_Maping_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0_GPIOC0 (EXTI_GPIO_Maping_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0_GPIOD0 (EXTI_GPIO_Maping_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}
// EXTI1
#define EXTI1_GPIOA1 (EXTI_GPIO_Maping_t){EXTI1, GPIOA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_GPIOB1 (EXTI_GPIO_Maping_t){EXTI1, GPIOB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_GPIOC1 (EXTI_GPIO_Maping_t){EXTI1, GPIOC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_GPIOD1 (EXTI_GPIO_Maping_t){EXTI1, GPIOD, GPIO_PIN_1, EXTI1_IRQ}
// EXTI2
#define EXTI2_GPIOA2 (EXTI_GPIO_Maping_t){EXTI2, GPIOA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_GPIOB2 (EXTI_GPIO_Maping_t){EXTI2, GPIOB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_GPIOC2 (EXTI_GPIO_Maping_t){EXTI2, GPIOC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_GPIOD2 (EXTI_GPIO_Maping_t){EXTI2, GPIOD, GPIO_PIN_2, EXTI2_IRQ}
// EXTI3
#define EXTI3_GPIOA3 (EXTI_GPIO_Maping_t){EXTI3, GPIOA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_GPIOB3 (EXTI_GPIO_Maping_t){EXTI3, GPIOB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_GPIOC3 (EXTI_GPIO_Maping_t){EXTI3, GPIOC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_GPIOD3 (EXTI_GPIO_Maping_t){EXTI3, GPIOD, GPIO_PIN_3, EXTI3_IRQ}
// EXTI4
#define EXTI4_GPIOA4 (EXTI_GPIO_Maping_t){EXTI4, GPIOA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_GPIOB4 (EXTI_GPIO_Maping_t){EXTI4, GPIOB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_GPIOC4 (EXTI_GPIO_Maping_t){EXTI4, GPIOC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_GPIOD4 (EXTI_GPIO_Maping_t){EXTI4, GPIOD, GPIO_PIN_4, EXTI4_IRQ}
// EXTI5
#define EXTI5_GPIOA5 (EXTI_GPIO_Maping_t){EXTI5, GPIOA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_GPIOB5 (EXTI_GPIO_Maping_t){EXTI5, GPIOB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_GPIOC5 (EXTI_GPIO_Maping_t){EXTI5, GPIOC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_GPIOD5 (EXTI_GPIO_Maping_t){EXTI5, GPIOD, GPIO_PIN_5, EXTI5_IRQ}
// EXTI6
#define EXTI6_GPIOA6 (EXTI_GPIO_Maping_t){EXTI6, GPIOA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_GPIOB6 (EXTI_GPIO_Maping_t){EXTI6, GPIOB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_GPIOC6 (EXTI_GPIO_Maping_t){EXTI6, GPIOC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_GPIOD6 (EXTI_GPIO_Maping_t){EXTI6, GPIOD, GPIO_PIN_6, EXTI6_IRQ}
// EXTI7
#define EXTI7_GPIOA7 (EXTI_GPIO_Maping_t){EXTI7, GPIOA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_GPIOB7 (EXTI_GPIO_Maping_t){EXTI7, GPIOB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_GPIOC7 (EXTI_GPIO_Maping_t){EXTI7, GPIOC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_GPIOD7 (EXTI_GPIO_Maping_t){EXTI7, GPIOD, GPIO_PIN_7, EXTI7_IRQ}
// EXTI8
#define EXTI8_GPIOA8 (EXTI_GPIO_Maping_t){EXTI8, GPIOA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_GPIOB8 (EXTI_GPIO_Maping_t){EXTI8, GPIOB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_GPIOC8 (EXTI_GPIO_Maping_t){EXTI8, GPIOC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_GPIOD8 (EXTI_GPIO_Maping_t){EXTI8, GPIOD, GPIO_PIN_8, EXTI8_IRQ}
// EXTI9
#define EXTI9_GPIOA9 (EXTI_GPIO_Maping_t){EXTI9, GPIOA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_GPIOB9 (EXTI_GPIO_Maping_t){EXTI9, GPIOB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_GPIOC9 (EXTI_GPIO_Maping_t){EXTI9, GPIOC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_GPIOD9 (EXTI_GPIO_Maping_t){EXTI9, GPIOD, GPIO_PIN_9, EXTI9_IRQ}
// EXTI10
#define EXTI10_GPIOA10 (EXTI_GPIO_Maping_t){EXTI10, GPIOA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_GPIOB10 (EXTI_GPIO_Maping_t){EXTI10, GPIOB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_GPIOC10 (EXTI_GPIO_Maping_t){EXTI10, GPIOC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_GPIOD10 (EXTI_GPIO_Maping_t){EXTI10, GPIOD, GPIO_PIN_10, EXTI10_IRQ}
// EXTI11
#define EXTI11_GPIOA11 (EXTI_GPIO_Maping_t){EXTI11, GPIOA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_GPIOB11 (EXTI_GPIO_Maping_t){EXTI11, GPIOB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_GPIOC11 (EXTI_GPIO_Maping_t){EXTI11, GPIOC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_GPIOD11 (EXTI_GPIO_Maping_t){EXTI11, GPIOD, GPIO_PIN_11, EXTI11_IRQ}
// EXTI12
#define EXTI12_GPIOA12 (EXTI_GPIO_Maping_t){EXTI12, GPIOA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_GPIOB12 (EXTI_GPIO_Maping_t){EXTI12, GPIOB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_GPIOC12 (EXTI_GPIO_Maping_t){EXTI12, GPIOC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_GPIOD12 (EXTI_GPIO_Maping_t){EXTI12, GPIOD, GPIO_PIN_12, EXTI12_IRQ}
// EXTI13
#define EXTI13_GPIOA13 (EXTI_GPIO_Maping_t){EXTI13, GPIOA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_GPIOB13 (EXTI_GPIO_Maping_t){EXTI13, GPIOB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_GPIOC13 (EXTI_GPIO_Maping_t){EXTI13, GPIOC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_GPIOD13 (EXTI_GPIO_Maping_t){EXTI13, GPIOD, GPIO_PIN_13, EXTI13_IRQ}
// EXTI14
#define EXTI14_GPIOA14 (EXTI_GPIO_Maping_t){EXTI14, GPIOA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_GPIOB14 (EXTI_GPIO_Maping_t){EXTI14, GPIOB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_GPIOC14 (EXTI_GPIO_Maping_t){EXTI14, GPIOC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_GPIOD14 (EXTI_GPIO_Maping_t){EXTI14, GPIOD, GPIO_PIN_14, EXTI14_IRQ}
// EXTI15
#define EXTI15_GPIOA15 (EXTI_GPIO_Maping_t){EXTI15, GPIOA, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_GPIOB15 (EXTI_GPIO_Maping_t){EXTI15, GPIOB, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_GPIOC15 (EXTI_GPIO_Maping_t){EXTI15, GPIOC, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_GPIOD15 (EXTI_GPIO_Maping_t){EXTI15, GPIOD, GPIO_PIN_15, EXTI15_IRQ}

//=================================================================================
//EXTI_Trigger_define
#define EXTI_Trigger_RISING						0
#define EXTI_Trigger_FALLING					1
#define EXTI_Trigger_RISINGAndFALLING			2

//=================================================================================
//EXTI_Enable_define
#define EXTI_IRQ_Disable					    0
#define EXTI_IRQ_Enable					        1

//=================================================================================
//APIs Supported by MCAL GPIO Driver
//=================================================================================



void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config);
void MCAL_EXTI_GPIO_Deinit(void);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config);

#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
