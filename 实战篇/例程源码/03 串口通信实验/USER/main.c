#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "string.h"

/************************************************
	高工216实验室 STM32开发板
	实验03 串口通信实验
************************************************/

// 函数声明
void dosomething(int len, char * str);
	
int main(void)
{
    u8 len;	
	u16 times=0;  
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
	uart_init(115200);				//初始化串口1，波特率为115200
    LED_Init();                     //初始化LED
	
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			USART_RX_BUF[len] = '0'; //添加字符串结束标志
			dosomething(len,(uint8_t*)USART_RX_BUF);   // 执行命令
			printf("指令已收到！\r\n");
			while(__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_TC)!=SET);		//等待发送结束
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else{
			times++;
			if(times%2000==0)
			{
				printf("输入字符串以翻转LED状态\r\n");
				printf("字符0、1、2对应LED0、1、2\r\n");
				printf("高工216实验室\r\n\r\n\r\n");
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
