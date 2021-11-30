#include "exti.h"
#include "delay.h"
#include "led.h"
#include "key.h"

//////////////////////////////////////////////////////////////////////////////////	 
//      �߹�216ʵ���� STM32F1������
//			ʵ��04  �ⲿ�ж�ʵ�� 										  
////////////////////////////////////////////////////////////////////////////////// 	

//�ⲿ�жϳ�ʼ��
void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();               //����GPIOAʱ��
    
    GPIO_Initure.Pin=GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7; //PA4~7
    GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;      //�½��ش���
    GPIO_Initure.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    
    //�ж���4-PA4
    HAL_NVIC_SetPriority(EXTI4_IRQn,2,2);       //��ռ���ȼ�Ϊ2�������ȼ�Ϊ2
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);             //ʹ���ж���4
    
	//�ж�5~7-PA5~7
    HAL_NVIC_SetPriority(EXTI9_5_IRQn,2,1);   	//��ռ���ȼ�Ϊ2�������ȼ�Ϊ1
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);           //ʹ���ж���5-9 
}


//�жϷ�����
void EXTI4_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);		//�����жϴ����ú���
}

void EXTI9_5_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);		//�����жϴ����ú���
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);		//�����жϴ����ú���
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);		//�����жϴ����ú���
}


//�жϷ����������Ҫ��������
//��HAL�������е��ⲿ�жϷ�����������ô˺���
//GPIO_Pin:�ж����ź�
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(10);      	//����
    switch(GPIO_Pin)
    {
        case GPIO_PIN_7:
            if(KEY3==0) 
            {
			   LED0=!LED0; //����LED0,LED1,LED2�������
			   LED1=!LED1;
               LED2=!LED2;
			}
            break;
        case GPIO_PIN_4:
            if(KEY0==0)  
            {
				LED0=!LED0;	//����LED0��ת 
            }
            break;
        case GPIO_PIN_5:
            if(KEY1==0)  
            {
				LED1=!LED1;	//����LED1��ת
            }
            break;
        case GPIO_PIN_6:
            if(KEY2==0)  
            {
				LED2=!LED2;	//����LED2��ת
            }
            break;
    }
}
