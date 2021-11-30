#include "exti.h"
#include "delay.h"
#include "led.h"
#include "key.h"

//////////////////////////////////////////////////////////////////////////////////	 
//      高工216实验室 STM32F1开发板
//			实验04  外部中断实验 										  
////////////////////////////////////////////////////////////////////////////////// 	

//外部中断初始化
void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();               //开启GPIOA时钟
    
    GPIO_Initure.Pin=GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7; //PA4~7
    GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;      //下降沿触发
    GPIO_Initure.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    
    //中断线4-PA4
    HAL_NVIC_SetPriority(EXTI4_IRQn,2,2);       //抢占优先级为2，子优先级为2
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);             //使能中断线4
    
	//中断5~7-PA5~7
    HAL_NVIC_SetPriority(EXTI9_5_IRQn,2,1);   	//抢占优先级为2，子优先级为1
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);           //使能中断线5-9 
}


//中断服务函数
void EXTI4_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);		//调用中断处理公用函数
}

void EXTI9_5_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);		//调用中断处理公用函数
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);		//调用中断处理公用函数
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);		//调用中断处理公用函数
}


//中断服务程序中需要做的事情
//在HAL库中所有的外部中断服务函数都会调用此函数
//GPIO_Pin:中断引脚号
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(10);      	//消抖
    switch(GPIO_Pin)
    {
        case GPIO_PIN_7:
            if(KEY3==0) 
            {
			   LED0=!LED0; //控制LED0,LED1,LED2互斥点亮
			   LED1=!LED1;
               LED2=!LED2;
			}
            break;
        case GPIO_PIN_4:
            if(KEY0==0)  
            {
				LED0=!LED0;	//控制LED0翻转 
            }
            break;
        case GPIO_PIN_5:
            if(KEY1==0)  
            {
				LED1=!LED1;	//控制LED1翻转
            }
            break;
        case GPIO_PIN_6:
            if(KEY2==0)  
            {
				LED2=!LED2;	//控制LED2翻转
            }
            break;
    }
}
