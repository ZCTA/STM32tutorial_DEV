#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

/************************************************
      高工216实验室 STM32开发板
			实验02  按键输入实验 
************************************************/

int main(void)
{
    u8 key=0;    
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    LED_Init();                     //初始化LED 
	KEY_Init();						//初始化按键
	LED0=0;			                //点亮LED0
	
	while(1)
	{
		key=KEY_Scan(0);//得到键值
		switch(key)
		{
			case KEY0_PRES://KEY0
				LED0=!LED0;
				break;
			case KEY1_PRES://KEY1
				LED1=!LED1;
				break;
			case KEY2_PRES://KEY2
				LED2=!LED2;
				break;
			case KEY3_PRES://KEY3				
				LED0=!LED0;
				LED1=!LED1;
				LED2=!LED2;
				break;
			default:
				delay_ms(10);	
		}     
	}
}

