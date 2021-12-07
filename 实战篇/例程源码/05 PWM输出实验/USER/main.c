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
	u16 led1pwmval=0;    
	u8 dir=1;
	
	HAL_Init();                    	//初始化HAL库    
	Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
	delay_init(72);                 //初始化延时函数                  
	TIM3_PWM_Init(899,7);			//不分频。PWM频率=72000/(899+1)/7+1=10Khz
	while(1)
	{
		delay_ms(10);
		if(dir)led1pwmval++;  //dir==1 led1pwmval递增
		else led1pwmval--;	  //dir==0 led1pwmval递减
 		if(led1pwmval>300)dir=0;//led1pwmval到到800后，方向改为递减
		if(led1pwmval==0)dir=1;	//led1pwmval递减到0后，方向改为递增	   					 
		TIM_SetTIM3Compare3(led1pwmval);//修改比较值，修改占空比	   
	}
}

