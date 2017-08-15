#include "stm32f4xx.h"
#include "bsp_led.h"

void LED_Init(void)
{
        GPIO_InitTypeDef GPIO_InitStruct;
      
        __HAL_RCC_GPIOG_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        __HAL_RCC_GPIOK_CLK_ENABLE();
        
        GPIO_InitStruct.Pin = GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
        HAL_GPIO_Init(GPIOG,&GPIO_InitStruct);
        
        GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
        
        GPIO_InitStruct.Pin = GPIO_PIN_3;
        HAL_GPIO_Init(GPIOK,&GPIO_InitStruct);
}
