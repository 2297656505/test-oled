#include "delay.h"
#include "usart.h"
#include "bsp_i2c.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"

int main(void)
{	
	delay_init();     
	NVIC_Configuration(); 	   //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	
	OLED_Init();			         //��ʼ��OLED  
	OLED_Clear(0);             //������ȫ��
	uart_init(115200);	 
	IIC_Init();
		while(1)
	{
		read_AHT20_once();
		delay_ms(50);
  }
}
