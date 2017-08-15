#include "bsp_key.h"
#include "stm32f4xx_it.h"

void Key_Init(void)
{
        GPIO_InitTypeDef   GPIO_InitStructure;
        __HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
        GPIO_InitStructure.Pull = GPIO_NOPULL;
        GPIO_InitStructure.Pin = GPIO_PIN_0;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
        HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
        if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET)
        {
                __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
                if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6))
                {
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
                }
                else
                {
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
                }
        }
}