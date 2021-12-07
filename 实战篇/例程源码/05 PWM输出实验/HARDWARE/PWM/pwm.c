#include "pwm.h"
#include "led.h"

/************************************************
         �߹�216ʵ���� STM32F1������
       		ʵ��05  PWM���ʵ��
************************************************/

TIM_HandleTypeDef 	TIM3_Handler;      	//��ʱ����� 
TIM_OC_InitTypeDef 	TIM3_CH3Handler;	//��ʱ��3ͨ��3���


//TIM3 PWM���ֳ�ʼ�� 
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
void TIM3_PWM_Init(u16 arr,u16 psc)
{  
    TIM3_Handler.Instance=TIM3;         	//��ʱ��3
    TIM3_Handler.Init.Prescaler=psc;       	//��ʱ����Ƶ
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//���ϼ���ģʽ
    TIM3_Handler.Init.Period=arr;          	//�Զ���װ��ֵ
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//��Ƶ����
		TIM3_Handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;//ʹ���Զ�����
    HAL_TIM_PWM_Init(&TIM3_Handler);       	//��ʼ��PWM
    
    TIM3_CH3Handler.OCMode=TIM_OCMODE_PWM1; //ģʽѡ��PWM1
    TIM3_CH3Handler.Pulse=arr/2;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձȣ�Ĭ�ϱȽ�ֵΪ�Զ���װ��ֵ��һ��,��ռ�ձ�Ϊ50%
    TIM3_CH3Handler.OCPolarity=TIM_OCPOLARITY_LOW; //����Ƚϼ���Ϊ�� 
	
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler,&TIM3_CH3Handler,TIM_CHANNEL_3);//����TIM3ͨ��3
	
    HAL_TIM_PWM_Start(&TIM3_Handler,TIM_CHANNEL_3);//����PWMͨ��3
	 	   
}

//��ʱ���ײ�������ʱ��ʹ�ܣ���������
//�˺����ᱻHAL_TIM_PWM_Init()����
//htim:��ʱ�����
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_Initure;
    if(htim->Instance==TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();			//ʹ�ܶ�ʱ��3
		__HAL_RCC_AFIO_CLK_ENABLE();			//�����˿ڸ��ù���ʱ��
		__HAL_AFIO_REMAP_TIM3_ENABLE();		    //TIM3ͨ��������ȫ��ӳ��ʹ��
		__HAL_RCC_GPIOC_CLK_ENABLE();			//����GPIOCʱ��

		GPIO_Initure.Pin=GPIO_PIN_8;           	//PC8
		GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	//�����������
		GPIO_Initure.Pull=GPIO_PULLUP;          //����
		GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
		
		HAL_GPIO_Init(GPIOC,&GPIO_Initure); 	
	}
}

//����TIM3ͨ��3��ռ�ձ�
//compare:�Ƚ�ֵ
void TIM_SetTIM3Compare3(u32 compare)
{
	TIM3->CCR3=compare;
}

//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler);
}

