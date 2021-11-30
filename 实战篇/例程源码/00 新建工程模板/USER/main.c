#include "sys.h"
#include "main.h"

 int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	HAL_Init(); //��ʼ�� HAL �� 
	Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	delay_init(72); 
	__HAL_RCC_GPIOC_CLK_ENABLE(); //���� GPIOC ʱ��
	GPIO_Initure.Pin=GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9; //PC7��PC8��PC9
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; //�������
	GPIO_Initure.Pull=GPIO_PULLUP; //����
	GPIO_Initure.Speed= GPIO_SPEED_HIGH; //����
	HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2��
		delay_ms(500);                                     //��ʱ500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2��
		delay_ms(500);                                     //��ʱ500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1��
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//LED2��
		delay_ms(500);                                     //��ʱ500ms
	}
}
