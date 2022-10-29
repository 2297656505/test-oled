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
	NVIC_Configuration(); 	   //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	
	OLED_Init();			         //初始化OLED  
	OLED_Clear(0);             //清屏（全黑
	uart_init(115200);	 
	IIC_Init();
		while(1)
	{
		read_AHT20_once();
		delay_ms(50);
  }
}
