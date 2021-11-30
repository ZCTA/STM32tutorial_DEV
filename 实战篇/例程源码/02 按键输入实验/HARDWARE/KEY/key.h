#ifndef _KEY_H
#define _KEY_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//      �߹�216ʵ���� STM32F1������
//			ʵ��02  ��������ʵ�� 							 								  
//////////////////////////////////////////////////////////////////////////////////

//����ķ�ʽ��ͨ��λ��������ʽ��ȡIO
//#define KEY0   PAin(4)   	
//#define KEY1   PAin(5)
//#define KEY2   PAin(6)	 
//#define KEY3   PAin(7)	


//����ķ�ʽ��ͨ��ֱ�Ӳ���HAL�⺯����ʽ��ȡIO
#define KEY0        HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)  //KEY0����PA4
#define KEY1        HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)  //KEY1����PA5
#define KEY2        HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)  //KEY2����PA6
#define KEY3        HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)  //KEY3����PA7

#define KEY0_PRES	1	//KEY0  
#define KEY1_PRES	2	//KEY1 
#define KEY2_PRES	3	//KEY2
#define KEY3_PRES	4	//KEY3 

void KEY_Init(void);
u8 KEY_Scan(u8 mode);
#endif
