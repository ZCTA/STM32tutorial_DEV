#include "sys.h"
#include "main.h"

 int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	HAL_Init(); //初始化 HAL 库 
	Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
	delay_init(72); 
	__HAL_RCC_GPIOC_CLK_ENABLE(); //开启 GPIOC 时钟
	GPIO_Initure.Pin=GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9; //PC7、PC8、PC9
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; //推挽输出
	GPIO_Initure.Pull=GPIO_PULLUP; //上拉
	GPIO_Initure.Speed= GPIO_SPEED_HIGH; //高速
	HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//LED0亮
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2灭
		delay_ms(500);                                     //延时500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//LED1亮
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);  //LED2灭
		delay_ms(500);                                     //延时500ms
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);  //LED0灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);  //LED1灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//LED2亮
		delay_ms(500);                                     //延时500ms
	}
}
