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
	u16 led1pwmval=0;    
	u8 dir=1;
	
	HAL_Init();                    	//��ʼ��HAL��    
	Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	delay_init(72);                 //��ʼ����ʱ����                  
	TIM3_PWM_Init(899,7);			//����Ƶ��PWMƵ��=72000/(899+1)/7+1=10Khz
	while(1)
	{
		delay_ms(10);
		if(dir)led1pwmval++;  //dir==1 led1pwmval����
		else led1pwmval--;	  //dir==0 led1pwmval�ݼ�
 		if(led1pwmval>300)dir=0;//led1pwmval����800�󣬷����Ϊ�ݼ�
		if(led1pwmval==0)dir=1;	//led1pwmval�ݼ���0�󣬷����Ϊ����	   					 
		TIM_SetTIM3Compare3(led1pwmval);//�޸ıȽ�ֵ���޸�ռ�ձ�	   
	}
}

