#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

/************************************************
      �߹�216ʵ���� STM32������
			ʵ��02  ��������ʵ�� 
************************************************/

int main(void)
{
    u8 key=0;    
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    LED_Init();                     //��ʼ��LED 
	KEY_Init();						//��ʼ������
	LED0=0;			                //����LED0
	
	while(1)
	{
		key=KEY_Scan(0);//�õ���ֵ
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

