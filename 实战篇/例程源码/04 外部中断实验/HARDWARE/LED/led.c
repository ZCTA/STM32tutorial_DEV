#include "led.h"
//////////////////////////////////////////////////////////////////////////////////	 
//      �߹�216ʵ���� STM32F1������
//			ʵ��02  ��������ʵ�� 								  
////////////////////////////////////////////////////////////////////////////////// 	
   
//LED IO��ʼ��
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           	//����GPIOCʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;//PC7~9
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//����
	
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9,GPIO_PIN_SET);
	//PC7~9��1��Ĭ�ϳ�ʼ�������
	
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
}


