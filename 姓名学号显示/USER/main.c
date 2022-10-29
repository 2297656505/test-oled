
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"
int main(void)
{	
	delay_init();	    	       //延时函数初始化	  
	NVIC_Configuration(); 	   //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	
	OLED_Init();			         //初始化OLED  
	OLED_Clear(0);             //清屏（全黑
	while(1) 
	{	
	//	TEST_MainPage();         //主界面显示测试
	//	GUI_ShowCHinese(16,20,16,"全动电子技术",1);
		GUI_ShowString(25,0,"632007030327",8,1);
  GUI_ShowCHinese(25,20,16,"凌震南",1);

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		//		
//GUI_ShowCHinese(20,20,16,"温度",1);
	
		
//	











		/*OLED_Clear(0); 
		Test_Color();            //刷屏测试
		OLED_Clear(0); 
		Test_Rectangular();      //矩形绘制测试
		OLED_Clear(0); 
		Test_Circle();           //圆形绘制测试
		OLED_Clear(0); 
		Test_Triangle();         //三角形绘制测试
		OLED_Clear(0);  
		
		TEST_English();          //英文显示测试
		OLED_Clear(0);
		TEST_Number_Character(); //数字和符号显示测试
		OLED_Clear(0); 
		
		TEST_Chinese();          //中文显示测试
		OLED_Clear(0); 
		TEST_BMP();              //BMP单色图片显示测试
		OLED_Clear(0); 
		TEST_Menu1();            //菜单1显示测试
		OLED_Clear(0); 
		TEST_Menu2();            //菜单2显示测试
		OLED_Clear(0); */
	}
}
