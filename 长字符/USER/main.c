
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"
int main(void)
{	
	delay_init();	    	       //��ʱ������ʼ��	  
	NVIC_Configuration(); 	   //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	
	OLED_Init();			         //��ʼ��OLED  
	OLED_Clear(0);             //������ȫ��
	while(1) 
	{	
	//	TEST_MainPage();         //��������ʾ����
	//	GUI_ShowCHinese(16,20,16,"ȫ�����Ӽ���",1);
//		GUI_ShowString(25,0,"632007030327",8,1);
//   GUI_ShowCHinese(25,20,16,"������",1);
//		

	
		GUI_ShowCHinese(20,20,16,"��ӭ��������",1);
		
		delay_ms(1000);
		GUI_ShowCHinese(20,20,16,"�������콻ͨ",1);
			delay_ms(1000);
	  GUI_ShowCHinese(20,20,16,"���콻ͨ��ѧ",1);
       delay_ms(1000);
		 GUI_ShowCHinese(20,20,16,"��ͨ��ѧʵѵ",1);
		
       delay_ms(1000);
		 GUI_ShowCHinese(20,20,16,"��ѧʵѵ��!",1);
  delay_ms(1000);
	 GUI_ShowCHinese(20,20,16,"ʵѵ��!",1);
  delay_ms(1000);
//	











		/*OLED_Clear(0); 
		Test_Color();            //ˢ������
		OLED_Clear(0); 
		Test_Rectangular();      //���λ��Ʋ���
		OLED_Clear(0); 
		Test_Circle();           //Բ�λ��Ʋ���
		OLED_Clear(0); 
		Test_Triangle();         //�����λ��Ʋ���
		OLED_Clear(0);  
		
		TEST_English();          //Ӣ����ʾ����
		OLED_Clear(0);
		TEST_Number_Character(); //���ֺͷ�����ʾ����
		OLED_Clear(0); 
		
		TEST_Chinese();          //������ʾ����
		OLED_Clear(0); 
		TEST_BMP();              //BMP��ɫͼƬ��ʾ����
		OLED_Clear(0); 
		TEST_Menu1();            //�˵�1��ʾ����
		OLED_Clear(0); 
		TEST_Menu2();            //�˵�2��ʾ����
		OLED_Clear(0); */
	}
}
