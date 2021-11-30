#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

/************************************************
	高工216实验室 STM32开发板
	实验01 跑马灯实验
************************************************/

/*下面主函数是使用HAL库函数实现控制IO口输出*/

int main(void)
{
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    LED_Init();                     //初始化LED 
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//LED0亮
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2灭
		delay_ms(500);                                  //延时500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//LED1亮
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED1灭
		delay_ms(500);                                   //延时500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//LED2亮
		delay_ms(500);                                   //延时500ms
	}
}


/*下面主函数使用位带操作实现：*/

/*
int main(void)
	{ 
	HAL_Init();                    	 	//初始化HAL库    
	Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函数
	LED_Init();							//初始化LED	

	while(1)
	{
		LED0=0;			     	//LED0亮
		LED1=1;				 	//LED1灭
		LED2=1;                 //LED2灭
		delay_ms(500);

		LED0=1;					//LED0灭
		LED1=0;					//LED1亮
		LED2=1;                 //LED2灭
		delay_ms(500);
		
		LED0=1;					//LED0灭
		LED1=1;					//LED1灭
		LED2=0;                 //LED2亮
		delay_ms(500);
	]
}
*/


/*
下面主函数使用直接操作结存器方式实现
*/

/*
int main(void)
{ 
	HAL_Init();                    	 	//初始化HAL库    
	Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函数
	LED_Init();							//初始化LED	

	while(1)
	{
		GPIOC->BSRR=GPIO_PIN_7<<16; 	//LED0亮
		GPIOC->BSRR=GPIO_PIN_8;     	//LED1灭 
		GPIOC->BSRR=GPIO_PIN_9;         //LED2灭
		delay_ms(500);
		
		GPIOC->BSRR=GPIO_PIN_7;     	//LED0灭
		GPIOC->BSRR=GPIO_PIN_8<<16; 	//LED1亮 
		GPIOC->BSRR=GPIO_PIN_9;         //LED2灭
		delay_ms(500);
		
		GPIOC->BSRR=GPIO_PIN_7;     	//LED0灭
		GPIOC->BSRR=GPIO_PIN_8; 	    //LED1灭 
		GPIOC->BSRR=GPIO_PIN_9<<16;     //LED2亮
		delay_ms(500);
	}
}
*/	


	
