/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 30, 2024
 *      Author: USER
 */
#include "STM32F103C6_GPIO_Driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;


	}
	return 0;

}
/**================================================================
 * @Fn					-MCAL_GPIO_Init
 * @brief				-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinConfig pointer to a GPIO_pinconfig_t structure that contains
 * 							the configuration information for the specified GPIO peripheral.
 * @retval 				-none
 * Note					-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 							But LQFP48 Package has only GPIO A,B,PART OF C/D exported as external PINs from MCU
 */
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) Configure PINS from 0 >>> 7
	//Port configuration register High (GPIOx_CRH) Configure PINS from 8 >>> 15

	volatile uint32_t *ConfigRegister= NULL ;
	volatile uint8_t Pin_Config = 0 ;
	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8 )? &GPIOx->CRL :&GPIOx->CRH ;

	//clear CNF8[1:0] MODE8[1:0]

	(*ConfigRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;

	//if Pin is output
	if (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP|| PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)
	{
		Pin_Config = ((((PinConfig->GPIO_MODE - 4) << 2 ) | (PinConfig->GPIO_Output_Speed))) & 0x0F ;
	}
	//if Pin is input
	else
	{
		//if  analog mode of input floating
		if (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG || PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) //if  analog mode of input floating
		{
			Pin_Config = ((((PinConfig->GPIO_MODE << 2 )) | 0x0) & 0x0F) ;
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_INPUT) //if mode is Alternative input it considered as input floating
		{
			Pin_Config = ((((GPIO_MODE_INPUT_FLO << 2 )) | 0x0) & 0x0F) ;
		}
		else //then mode is PP or PU
		{
			Pin_Config = ((((GPIO_MODE_INPUT_PU << 2 )) | 0x0) & 0x0F) ;
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber) ;
			}
			else
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}

	//write on the CRL or CRH
	(*ConfigRegister) |= (Pin_Config << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;
}

/**================================================================
 * @Fn					-MCAL_GPIO_DeInit
 * @brief				-reset all the GPIO Registers
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{

	if(GPIOx == GPIOA)
		RCC->APB2RSTR |= (1<<2);
	else if(GPIOx == GPIOB)
		RCC->APB2RSTR |= (1<<3);
	else if(GPIOx == GPIOC)
		RCC->APB2RSTR |= (1<<4);
	else if(GPIOx == GPIOD)
		RCC->APB2RSTR |= (1<<5);
	else if(GPIOx == GPIOE)
		RCC->APB2RSTR |= (1<<6);
}
/**================================================================
 * @Fn					-MCAL_GPIO_ReadPin
 * @brief				-read specific PIN
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: Set Pin Number according @ref GPIO_PINS_define
 * @retval				-The input pin value (two values based on @ref GPIO_PIN_state )
 * Note					-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	uint8_t Bit_State ;
	if ((GPIOx->IDR & PinNumber) != (uint16_t)GPIO_PIN_RESET)
	{
		Bit_State = GPIO_PIN_SET ;
	}
	else
	{
		Bit_State = GPIO_PIN_RESET ;
	}

	return Bit_State ;
}
/**================================================================
 * @Fn					-MCAL_GPIO_ReadPort
 * @brief				-read specific PORT
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval				-The input port value
 * Note					-none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}
/**================================================================
 * @Fn					-MCAL_GPIO_WritePin
 * @brief				-write on output PORT
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval				-none
 * Note					-none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber,uint8_t value)
{
	if (value != (uint8_t)GPIO_PIN_RESET)
	{
		//GPIOx->ODR |= PinNumber ;
		//or
		GPIOx->BSRR = PinNumber ;
	}
	else
	{
		//GPIOx->ODR &= ~PinNumber;
		//or
		GPIOx->BRR = PinNumber ;
	}
}
/**================================================================
 * @Fn					-MCAL_GPIO_WritePort
 * @brief				-Write on specific PORT
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval				-none
 * Note					-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx,uint16_t value)
{
	GPIOx->ODR = (uint16_t) value;
}
/**================================================================
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief				-Toggle the specificed GPIO pin
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in]			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval				-none
 * Note					-none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber ;
}
/**================================================================
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief				-Toggle the specificed GPIO pin
 * @param [in] 			-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in]			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval				-Ok if bin is locked or error if bin is not locked (Ok & Error are defined @ref GPIO_RETURN_LOCK)
 * Note					-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->LCKR |= PinNumber;
	uint32_t temp = (uint16_t)(1<<16);
	GPIOx->LCKR = temp;
	GPIOx->LCKR &= ~temp ;
	GPIOx->LCKR |= temp ;
	temp = GPIOx->LCKR ;

	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_Enabled ;
	}
	else
	{
		return GPIO_RETURN_LOCK_Error ;
	}

}
