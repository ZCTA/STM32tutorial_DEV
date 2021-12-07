#include "pwm.h"
#include "led.h"

/************************************************
         高工216实验室 STM32F1开发板
       		实验05  PWM输出实验
************************************************/

TIM_HandleTypeDef 	TIM3_Handler;      	//定时器句柄 
TIM_OC_InitTypeDef 	TIM3_CH3Handler;	//定时器3通道3句柄


//TIM3 PWM部分初始化 
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
void TIM3_PWM_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;         	//定时器3
    TIM3_Handler.Init.Prescaler=psc;       	//定时器分频
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//向上计数模式
    TIM3_Handler.Init.Period=arr;          	//自动重装载值
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//分频因子
		TIM3_Handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;//使能自动重载
    HAL_TIM_PWM_Init(&TIM3_Handler);       	//初始化PWM
    
    TIM3_CH3Handler.OCMode=TIM_OCMODE_PWM1; //模式选择PWM1
    TIM3_CH3Handler.Pulse=arr/2;            //设置比较值,此值用来确定占空比，默认比较值为自动重装载值的一半,即占空比为50%
    TIM3_CH3Handler.OCPolarity=TIM_OCPOLARITY_LOW; //输出比较极性为低 
	
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler,&TIM3_CH3Handler,TIM_CHANNEL_3);//配置TIM3通道3
	
    HAL_TIM_PWM_Start(&TIM3_Handler,TIM_CHANNEL_3);//开启PWM通道3
	 	   
}

//定时器底层驱动，时钟使能，引脚配置
//此函数会被HAL_TIM_PWM_Init()调用
//htim:定时器句柄
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_Initure;
    if(htim->Instance==TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();			//使能定时器3
		__HAL_RCC_AFIO_CLK_ENABLE();			//开启端口复用功能时钟
		__HAL_AFIO_REMAP_TIM3_ENABLE();		    //TIM3通道引脚完全重映射使能
		__HAL_RCC_GPIOC_CLK_ENABLE();			//开启GPIOC时钟

		GPIO_Initure.Pin=GPIO_PIN_8;           	//PC8
		GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	//复用推挽输出
		GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
		GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
		
		HAL_GPIO_Init(GPIOC,&GPIO_Initure); 	
	}
}

//设置TIM3通道3的占空比
//compare:比较值
void TIM_SetTIM3Compare3(u32 compare)
{
	TIM3->CCR3=compare;
}

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

