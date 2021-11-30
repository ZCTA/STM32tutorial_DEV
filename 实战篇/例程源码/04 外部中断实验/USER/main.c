#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"

/************************************************
         �߹�216ʵ���� STM32F1������
       			ʵ��02  ��������ʵ�� 				
************************************************/

int main(void)
{
	
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
	uart_init(115200);				//��ʼ������115200
    LED_Init();                     //��ʼ��LED 
  	EXTI_Init();				    //��ʼ���ⲿ�ж�
	while(1)
	{

	}
}

