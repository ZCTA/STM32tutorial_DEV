#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"

/************************************************
         高工216实验室 STM32F1开发板
       			实验02  按键输入实验 				
************************************************/

int main(void)
{
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
	uart_init(115200);				//初始化串口115200
    LED_Init();                     //初始化LED 
  	EXTI_Init();				    //初始化外部中断
	while(1)
	{

	}
}

