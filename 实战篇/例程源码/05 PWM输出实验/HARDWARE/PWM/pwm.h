#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

/************************************************
         高工216实验室 STM32F1开发板
       		实验05  PWM输出实验
************************************************/	

extern TIM_HandleTypeDef TIM3_Handler;      //定时器句柄 

void TIM3_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM_SetTIM3Compare3(u32 compare);
#endif

