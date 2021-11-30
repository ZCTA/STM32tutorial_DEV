#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

/************************************************
	�߹�216ʵ���� STM32������
	ʵ��01 �����ʵ��
************************************************/

/*������������ʹ��HAL�⺯��ʵ�ֿ���IO�����*/

int main(void)
{
	
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    LED_Init();                     //��ʼ��LED 
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2��
		delay_ms(500);                                  //��ʱ500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED1��
		delay_ms(500);                                   //��ʱ500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//LED2��
		delay_ms(500);                                   //��ʱ500ms
	}
}


/*����������ʹ��λ������ʵ�֣�*/

/*
int main(void)
	{ 
	HAL_Init();                    	 	//��ʼ��HAL��    
	Stm32_Clock_Init(RCC_PLL_MUL9);   	//����ʱ��,72M
	delay_init(72);               		//��ʼ����ʱ����
	LED_Init();							//��ʼ��LED	

	while(1)
	{
		LED0=0;			     	//LED0��
		LED1=1;				 	//LED1��
		LED2=1;                 //LED2��
		delay_ms(500);

		LED0=1;					//LED0��
		LED1=0;					//LED1��
		LED2=1;                 //LED2��
		delay_ms(500);
		
		LED0=1;					//LED0��
		LED1=1;					//LED1��
		LED2=0;                 //LED2��
		delay_ms(500);
	]
}
*/


/*
����������ʹ��ֱ�Ӳ����������ʽʵ��
*/

/*
int main(void)
{ 
	HAL_Init();                    	 	//��ʼ��HAL��    
	Stm32_Clock_Init(RCC_PLL_MUL9);   	//����ʱ��,72M
	delay_init(72);               		//��ʼ����ʱ����
	LED_Init();							//��ʼ��LED	

	while(1)
	{
		GPIOC->BSRR=GPIO_PIN_7<<16; 	//LED0��
		GPIOC->BSRR=GPIO_PIN_8;     	//LED1�� 
		GPIOC->BSRR=GPIO_PIN_9;         //LED2��
		delay_ms(500);
		
		GPIOC->BSRR=GPIO_PIN_7;     	//LED0��
		GPIOC->BSRR=GPIO_PIN_8<<16; 	//LED1�� 
		GPIOC->BSRR=GPIO_PIN_9;         //LED2��
		delay_ms(500);
		
		GPIOC->BSRR=GPIO_PIN_7;     	//LED0��
		GPIOC->BSRR=GPIO_PIN_8; 	    //LED1�� 
		GPIOC->BSRR=GPIO_PIN_9<<16;     //LED2��
		delay_ms(500);
	}
}
*/	


	
