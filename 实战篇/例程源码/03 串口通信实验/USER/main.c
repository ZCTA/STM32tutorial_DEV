#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "string.h"

/************************************************
	�߹�216ʵ���� STM32������
	ʵ��03 ����ͨ��ʵ��
************************************************/

// ��������
void dosomething(int len, char * str);
	
int main(void)
{
    u8 len;	
	u16 times=0;  
	
    HAL_Init();                    	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
    delay_init(72);                 //��ʼ����ʱ����
	uart_init(115200);				//��ʼ������1��������Ϊ115200
    LED_Init();                     //��ʼ��LED
	
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			USART_RX_BUF[len] = '0'; //����ַ���������־
			dosomething(len,(uint8_t*)USART_RX_BUF);   // ִ������
			printf("ָ�����յ���\r\n");
			while(__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_TC)!=SET);		//�ȴ����ͽ���
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
		}else{
			times++;
			if(times%2000==0)
			{
				printf("�����ַ����Է�תLED״̬\r\n");
				printf("�ַ�0��1��2��ӦLED0��1��2\r\n");
				printf("�߹�216ʵ����\r\n\r\n\r\n");
			}
			delay_ms(10);   
		} 
	}
}

void dosomething(int len, char * str)
{
	for(int i = 0;i<len;i++)
	{
		switch(str[i]){
			case '0':
				LED0=!LED0;
				break;
			case '1':
				LED1=!LED1;
				break;
			case '2':
				LED2=!LED2;
				break;
		}
	}	
}
