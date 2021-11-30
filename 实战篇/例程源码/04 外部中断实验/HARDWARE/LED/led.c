#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//      高工216实验室 STM32F1开发板
//			实验02  按键输入实验 								  
////////////////////////////////////////////////////////////////////////////////// 	
   
//LED IO初始化
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           	//开启GPIOC时钟
	
    GPIO_Initure.Pin=GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;//PC7~9
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          	//上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//高速
	
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9,GPIO_PIN_SET);
	//PC7~9置1，默认初始化后灯灭
	
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
}


