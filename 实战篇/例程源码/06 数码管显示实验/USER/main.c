#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "smg.h"
#include "timer.h"

/************************************************
 STM32F103开发板 实验12
 数码管显示实验-HAL库版本
//创建日期:2019/4/26
//版本：V1.8	
************************************************/

//共阴数字数组
//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,全灭
u8 smg_num[]=
{0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e,0x01,0x00};

int main(void)
{
		
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    LED_Init();                     //初始化LED
    LED_SMG_Init();  //数码管初始化	
    TIM3_Init(19,7199);//2ms定时显示	
	while(1)
	{	
		
	}
}

u8 smg_wei=0;//数码管位选
u8 smg_duan=17;//数码管段选
u16 t=0;

//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM3_Handler))
    {
      LED_Write_Data(smg_num[smg_duan],smg_wei);//数码管显示
	    LED_Refresh();//刷新显示
	    smg_wei++;
			if(smg_wei==8)  smg_wei=0;	
			t++;
			if(t==500)//数码管每秒更新
			{
				t=0;
				LED0=!LED0;
				if(smg_duan==0) smg_duan=18;
				smg_duan--;
			}
    }
}



