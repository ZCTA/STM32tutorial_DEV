#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

/************************************************
         �߹�216ʵ���� STM32F1������
       		ʵ��05  PWM���ʵ��
************************************************/	

extern TIM_HandleTypeDef TIM3_Handler;      //��ʱ����� 

void TIM3_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM_SetTIM3Compare3(u32 compare);
#endif

