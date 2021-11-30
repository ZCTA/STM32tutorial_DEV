#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

/************************************************
         �߹�216ʵ���� STM32F1������
       		ʵ��05  PWM���ʵ��
************************************************/

int main(void)
{
	u16 led6pwmval=0;    
	u8 dir=1;
	
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    LED_Init();                     //��ʼ��LED 
	TIM3_PWM_Init(899,7);			//����Ƶ��PWMƵ��=72000/(899+1)/7+1=10Khz
	//TIM_SetTIM3Compare3(899);
	while(1)
	{
//		delay_ms(500);
//		TIM_SetTIM3Compare3(800);//�޸ıȽ�ֵ���޸�ռ�ձ�	   

		delay_ms(10);
		if(dir)led6pwmval++;  //dir==1 led6pwmval����
		else led6pwmval--;	  //dir==0 led6pwmval�ݼ�
 		if(led6pwmval>899)dir=0;//led6pwmval����800�󣬷����Ϊ�ݼ�
		if(led6pwmval==0)dir=1;	//led6pwmval�ݼ���0�󣬷����Ϊ����	   					 
		TIM_SetTIM3Compare3(led6pwmval);//�޸ıȽ�ֵ���޸�ռ�ձ�	   
	}
}

