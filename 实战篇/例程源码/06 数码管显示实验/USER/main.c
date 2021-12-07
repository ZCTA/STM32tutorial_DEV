#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "smg.h"
#include "timer.h"

/************************************************
 STM32F103������ ʵ��12
 �������ʾʵ��-HAL��汾
//��������:2019/4/26
//�汾��V1.8	
************************************************/

//������������
//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,ȫ��
u8 smg_num[]=
{0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e,0x01,0x00};

int main(void)
{
		
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
    LED_Init();                     //��ʼ��LED
    LED_SMG_Init();  //����ܳ�ʼ��	
    TIM3_Init(19,7199);//2ms��ʱ��ʾ	
	while(1)
	{	
		
	}
}

u8 smg_wei=0;//�����λѡ
u8 smg_duan=17;//����ܶ�ѡ
u16 t=0;

//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==(&TIM3_Handler))
    {
      LED_Write_Data(smg_num[smg_duan],smg_wei);//�������ʾ
	    LED_Refresh();//ˢ����ʾ
	    smg_wei++;
			if(smg_wei==8)  smg_wei=0;	
			t++;
			if(t==500)//�����ÿ�����
			{
				t=0;
				LED0=!LED0;
				if(smg_duan==0) smg_duan=18;
				smg_duan--;
			}
    }
}



