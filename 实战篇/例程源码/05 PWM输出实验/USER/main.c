#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

/************************************************
         高工216实验室 STM32F1开发板
       		实验05  PWM输出实验
************************************************/

int main(void)
{
	u16 led6pwmval=0;    
	u8 dir=1;
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    LED_Init();                     //初始化LED 
	TIM3_PWM_Init(899,7);			//不分频。PWM频率=72000/(899+1)/7+1=10Khz
	//TIM_SetTIM3Compare3(899);
	while(1)
	{
//		delay_ms(500);
//		TIM_SetTIM3Compare3(800);//修改比较值，修改占空比	   

		delay_ms(10);
		if(dir)led6pwmval++;  //dir==1 led6pwmval递增
		else led6pwmval--;	  //dir==0 led6pwmval递减
 		if(led6pwmval>899)dir=0;//led6pwmval到到800后，方向改为递减
		if(led6pwmval==0)dir=1;	//led6pwmval递减到0后，方向改为递增	   					 
		TIM_SetTIM3Compare3(led6pwmval);//修改比较值，修改占空比	   
	}
}

