//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32F103RCT6,正点原子MiniSTM32开发板,主频72MHZ，晶振12MHZ
//QDtech-OLED液晶驱动 for STM32
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtft.com
//淘宝网站：http://qdtech.taobao.com
//wiki技术网站：http://www.lcdwiki.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//技术支持QQ:3002773612  3002778157
//技术交流QQ群:324828016
//创建日期:2018/8/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
// OLED模块               STM32单片机
//   VCC         接       DC 5V/3.3V      //OLED屏电源正
//   GND         接          GND          //OLED屏电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为4线制SPI
// OLED模块               STM32单片机
//   D1          接          PB15        //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块               STM32单片机
//   CS          接          PB11        //OLED屏片选控制信号
//   RES         接          PB12        //OLED屏复位控制信号
//   DC          接          PB10        //OLED屏数据/命令选择控制信号
//   D0          接          PB13        //OLED屏SPI时钟信号
//=========================================触摸屏接线=========================================//
//本模块不带触摸功能，所以不需要触摸屏接线
****************************************************************************************************/	
/***************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
****************************************************************************************************/	
#ifndef __OLEDFONT_H
#define __OLEDFONT_H 	   
//常用ASCII表
//偏移量32
//ASCII字符集
//偏移量32
//大小:6*8
//逐行式，顺向（高位在前）
/************************************6*8的点阵************************************/
const unsigned char F6x8[][8] =		
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // sp
	0x10,0x10,0x10,0x10,0x00,0x10,0x00,0x00, // !
	0x28,0x28,0x28,0x00,0x00,0x00,0x00,0x00, // "
	0x28,0x28,0x7C,0x28,0x7C,0x28,0x28,0x00, // #
	0x10,0x3C,0x50,0x38,0x14,0x78,0x10,0x00, // $
	0x00,0x4C,0x2C,0x10,0x08,0x60,0x60,0x00, // %
	0x30,0x48,0x50,0x20,0x54,0x48,0x34,0x00, // &
	0x30,0x10,0x20,0x00,0x00,0x00,0x00,0x00, // '
	0x08,0x10,0x20,0x20,0x20,0x10,0x08,0x00, // (
	0x20,0x10,0x08,0x08,0x08,0x10,0x20,0x00, // )
	0x00,0x10,0x54,0x38,0x54,0x10,0x00,0x00, // *
	0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00, // +
	0x00,0x00,0x00,0x00,0x00,0x18,0x08,0x10, // ,
	0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00, // -
	0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00, // .
	0x00,0x04,0x08,0x10,0x20,0x40,0x00,0x00, // /
	0x38,0x44,0x4C,0x54,0x64,0x44,0x38,0x00, // 0
	0x10,0x30,0x10,0x10,0x10,0x10,0x38,0x00, // 1
	0x38,0x44,0x04,0x08,0x10,0x20,0x7C,0x00, // 2
	0x7C,0x08,0x10,0x08,0x04,0x44,0x38,0x00, // 3 
	0x08,0x18,0x28,0x48,0x7C,0x08,0x08,0x00, // 4
	0x7C,0x40,0x78,0x04,0x04,0x44,0x38,0x00, // 5
	0x18,0x20,0x40,0x78,0x44,0x44,0x38,0x00, // 6
	0x7C,0x04,0x08,0x10,0x20,0x20,0x20,0x00, // 7
	0x38,0x44,0x44,0x38,0x44,0x44,0x38,0x00, // 8
	0x38,0x44,0x44,0x3C,0x04,0x08,0x30,0x00, // 9
	0x00,0x30,0x30,0x00,0x30,0x30,0x00,0x00, // :
	0x00,0x30,0x30,0x00,0x30,0x10,0x20,0x00, // ;
	0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00, // <
	0x00,0x00,0x7C,0x00,0x7C,0x00,0x00,0x00, // =
	0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x00, // >
	0x38,0x44,0x04,0x08,0x10,0x00,0x10,0x00, // ?
	0x38,0x44,0x04,0x34,0x5C,0x44,0x38,0x00, // @
	0x10,0x28,0x44,0x44,0x7C,0x44,0x44,0x00, // A
	0x78,0x44,0x44,0x78,0x44,0x44,0x78,0x00, // B
	0x38,0x44,0x40,0x40,0x40,0x44,0x38,0x00, // C
	0x70,0x48,0x44,0x44,0x44,0x48,0x70,0x00, // D
	0x7C,0x40,0x40,0x78,0x40,0x40,0x7C,0x00, // E
	0x7C,0x40,0x40,0x78,0x40,0x40,0x40,0x00, // F
	0x38,0x44,0x40,0x5C,0x44,0x44,0x3C,0x00, // G
	0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x00, // H
	0x38,0x10,0x10,0x10,0x10,0x10,0x38,0x00, // I
	0x1C,0x08,0x08,0x08,0x08,0x48,0x30,0x00, // J
	0x44,0x48,0x50,0x60,0x50,0x48,0x44,0x00, // K
	0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00, // L
	0x44,0x6C,0x54,0x54,0x44,0x44,0x44,0x00, // M
	0x44,0x44,0x64,0x54,0x4C,0x44,0x44,0x00, // N
	0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00, // O
	0x78,0x44,0x44,0x78,0x40,0x40,0x40,0x00, // P
	0x38,0x44,0x44,0x44,0x54,0x48,0x34,0x00, // Q
	0x78,0x44,0x44,0x78,0x50,0x48,0x44,0x00, // R
	0x3C,0x40,0x40,0x38,0x04,0x04,0x78,0x00, // S
	0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x00, // T
	0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00, // U
	0x44,0x44,0x44,0x44,0x44,0x28,0x10,0x00, // V
	0x44,0x44,0x44,0x54,0x54,0x54,0x28,0x00, // W
	0x44,0x44,0x28,0x10,0x28,0x44,0x44,0x00, // X
	0x44,0x44,0x44,0x28,0x10,0x10,0x10,0x00, // Y
	0x7C,0x04,0x08,0x10,0x20,0x40,0x7C,0x00, // Z
	0x38,0x20,0x20,0x20,0x20,0x20,0x38,0x00, // [
	0x00,0x40,0x20,0x10,0x08,0x04,0x00,0x00, // '\'
	0x38,0x08,0x08,0x08,0x08,0x08,0x38,0x00, // ]
	0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00, // ^
	0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00, // _
	0x20,0x10,0x08,0x00,0x00,0x00,0x00,0x00, // '
	0x00,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00, // a
	0x40,0x40,0x58,0x64,0x44,0x44,0x78,0x00, // b
	0x00,0x00,0x38,0x40,0x40,0x44,0x38,0x00, // c
	0x04,0x04,0x34,0x4C,0x44,0x44,0x3C,0x00, // d
	0x00,0x00,0x38,0x44,0x7C,0x40,0x38,0x00, // e
	0x38,0x24,0x20,0x70,0x20,0x20,0x20,0x00, // f
	0x00,0x00,0x3C,0x44,0x44,0x3C,0x04,0x38, // g
	0x40,0x40,0x58,0x64,0x44,0x44,0x44,0x00, // h
	0x10,0x00,0x30,0x10,0x10,0x10,0x38,0x00, // i
	0x08,0x00,0x18,0x08,0x08,0x08,0x48,0x30, // j
	0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x00, // k
	0x30,0x10,0x10,0x10,0x10,0x10,0x38,0x00, // l
	0x00,0x00,0x68,0x54,0x54,0x44,0x44,0x00, // m
	0x00,0x00,0x58,0x64,0x44,0x44,0x44,0x00, // n
	0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00, // o
	0x00,0x00,0x58,0x64,0x64,0x58,0x40,0x40, // p
	0x00,0x00,0x34,0x4C,0x4C,0x34,0x04,0x04, // q
	0x00,0x00,0x58,0x64,0x40,0x40,0x40,0x00, // r
	0x00,0x00,0x3C,0x40,0x38,0x04,0x78,0x00, // s
	0x20,0x20,0x70,0x20,0x20,0x24,0x18,0x00, // t
	0x00,0x00,0x44,0x44,0x44,0x4C,0x34,0x00, // u
	0x00,0x00,0x44,0x44,0x44,0x28,0x10,0x00, // v
	0x00,0x00,0x44,0x44,0x54,0x54,0x28,0x00, // w
	0x00,0x00,0x44,0x28,0x10,0x28,0x44,0x00, // x
	0x00,0x00,0x44,0x44,0x44,0x3C,0x04,0x38, // y
	0x00,0x00,0x7C,0x08,0x10,0x20,0x7C,0x00, // z
	0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00, // {
	0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x00, // |
	0x20,0x10,0x10,0x08,0x10,0x10,0x20,0x00, // }
	0x00,0x00,0x00,0x20,0x54,0x08,0x00,0x00, // ~
};

//常用ASCII表
//偏移量32
//ASCII字符集
//偏移量32
//大小:8*16
//逐行式，顺向（高位在前）
/****************************************8*16的点阵************************************/
const unsigned char F8X16[]=	  
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x18,0x18,0x00,0x00,//! 1
  0x00,0x12,0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//" 2
  0x00,0x00,0x00,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0xFE,0x48,0x48,0x48,0x00,0x00,//# 3
  0x00,0x00,0x10,0x38,0x54,0x54,0x50,0x30,0x1C,0x14,0x14,0x54,0x54,0x38,0x10,0x10,//$ 4
  0x00,0x00,0x00,0x44,0xA4,0xA8,0xA8,0xA8,0x54,0x1A,0x2A,0x2A,0x2A,0x44,0x00,0x00,//% 5
  0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x50,0x6E,0xA4,0x94,0x88,0x89,0x76,0x00,0x00,//& 6
  0x00,0x60,0x60,0x20,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' 7
  0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,//( 8
  0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,//) 9
  0x00,0x00,0x00,0x00,0x10,0x10,0xD6,0x38,0x38,0xD6,0x10,0x10,0x00,0x00,0x00,0x00,//* 10
  0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,//+ 11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x20,0xC0,//, 12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//- 13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,//. 14
  0x00,0x00,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,/// 15
  0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,//0 16
  0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//1 17
  0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,//2 18
  0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,//3 19
  0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,//4 20
  0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,//5 21
  0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,//6 22
  0x00,0x00,0x00,0x7E,0x42,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,//7 23
  0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,//8 24
  0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,//9 25
  0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,//: 26
  0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x08,0x30,0x00,//; 27
  0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,//< 28
  0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,//= 29
  0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,//> 30
  0x00,0x00,0x00,0x3C,0x42,0x42,0x62,0x02,0x04,0x08,0x08,0x00,0x18,0x18,0x00,0x00,//? 31
  0x00,0x00,0x00,0x38,0x44,0x5A,0xAA,0xAA,0xAA,0xAA,0xB4,0x42,0x44,0x38,0x00,0x00,//@ 32
  0x00,0x00,0x00,0x10,0x10,0x18,0x28,0x28,0x24,0x3C,0x44,0x42,0x42,0xE7,0x00,0x00,//A 33
  0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x44,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,//B 34
  0x00,0x00,0x00,0x3E,0x42,0x42,0x80,0x80,0x80,0x80,0x80,0x42,0x44,0x38,0x00,0x00,//C 35
  0x00,0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,//D 36
  0x00,0x00,0x00,0xFE,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x42,0x42,0xFE,0x00,0x00,//E 37
  0x00,0x00,0x00,0xFE,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x40,0x40,0xE0,0x00,0x00,//F 38
  0x00,0x00,0x00,0x3C,0x44,0x44,0x80,0x80,0x80,0x8E,0x84,0x44,0x44,0x38,0x00,0x00,//G 39
  0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//H 40
  0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//I 41
  0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0xF0,//J 42
  0x00,0x00,0x00,0xEE,0x44,0x48,0x50,0x70,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00,//K 43
  0x00,0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0xFE,0x00,0x00,//L 44
  0x00,0x00,0x00,0xEE,0x6C,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x54,0x54,0xD6,0x00,0x00,//M 45
  0x00,0x00,0x00,0xC7,0x62,0x62,0x52,0x52,0x4A,0x4A,0x4A,0x46,0x46,0xE2,0x00,0x00,//N 46
  0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00,//O 47
  0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x40,0x40,0x40,0x40,0xE0,0x00,0x00,//P 48
  0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0xB2,0xCA,0x4C,0x38,0x06,0x00,//Q 49
  0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x48,0x48,0x44,0x44,0x42,0xE3,0x00,0x00,//R 50
  0x00,0x00,0x00,0x3E,0x42,0x42,0x40,0x20,0x18,0x04,0x02,0x42,0x42,0x7C,0x00,0x00,//S 51
  0x00,0x00,0x00,0xFE,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,//T 52
  0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,//U 53
  0x00,0x00,0x00,0xE7,0x42,0x42,0x44,0x24,0x24,0x28,0x28,0x18,0x10,0x10,0x00,0x00,//V 54
  0x00,0x00,0x00,0xD6,0x92,0x92,0x92,0x92,0xAA,0xAA,0x6C,0x44,0x44,0x44,0x00,0x00,//W 55
  0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,//X 56
  0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,//Y 57
  0x00,0x00,0x00,0x7E,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x42,0x42,0xFC,0x00,0x00,//Z 58
  0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,//[ 59
  0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x04,0x04,0x02,0x02,0x02,0x01,0x01,//\ 60
  0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,//] 61
  0x00,0x08,0x14,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^ 62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,//_ 63
  0x00,0x60,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//` 64
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x1E,0x22,0x42,0x42,0x3F,0x00,0x00,//a 65
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x00,0x00,//b 66
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x40,0x40,0x40,0x22,0x1C,0x00,0x00,//c 67
  0x00,0x00,0x00,0x06,0x02,0x02,0x02,0x1E,0x22,0x42,0x42,0x42,0x26,0x1B,0x00,0x00,//d 68
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x40,0x40,0x42,0x3C,0x00,0x00,//e 69
  0x00,0x00,0x00,0x0F,0x11,0x10,0x10,0x7E,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//f 70
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x44,0x44,0x38,0x40,0x3C,0x42,0x42,0x3C,//g 71
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//h 72
  0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//i 73
  0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x78,//j 74
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x4E,0x48,0x50,0x68,0x48,0x44,0xEE,0x00,0x00,//k 75
  0x00,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//l 76
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF6,0x49,0x49,0x49,0x49,0x49,0xED,0x00,0x00,//m 77
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//n 78
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,//o 79
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x64,0x58,0x40,0xE0,//p 80
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x22,0x42,0x42,0x42,0x26,0x1A,0x02,0x07,//q 81
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x32,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,//r 82
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x42,0x40,0x3C,0x02,0x42,0x7C,0x00,0x00,//s 83
  0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x0C,0x00,0x00,//t 84
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x46,0x3B,0x00,0x00,//u 85
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x10,0x10,0x00,0x00,//v 86
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x92,0x92,0xAA,0xAA,0x44,0x44,0x00,0x00,//w 87
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00,//x 88
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x18,0x10,0x10,0xE0,//y 89
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x08,0x10,0x10,0x22,0x7E,0x00,0x00,//z 90
  0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,//{ 91
  0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,//| 92
  0x00,0x60,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00,//} 93
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x52,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~ 94
};

typedef struct 
{
	unsigned char Index[2];	
	char Msk[32];
}typFNT_GB16; 

//宋体
//16*16大小
//逐行式，顺向（高位在前）
const typFNT_GB16 cfont16[] = 
{
	"全",0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x10,0x10,0x2F,0xE8,0xC1,0x06,
	0x01,0x00,0x01,0x00,0x1F,0xF0,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFC,0x00,0x00,/*"全",0*/
	"动",0x00,0x40,0x00,0x40,0x7C,0x40,0x00,0x40,0x01,0xFC,0x00,0x44,0xFE,0x44,0x20,0x44,
	0x20,0x44,0x20,0x84,0x48,0x84,0x44,0x84,0xFD,0x04,0x45,0x04,0x02,0x28,0x04,0x10,/*"动",1*/
	"电",0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,
	0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x0A,0x01,0x02,0x01,0x02,0x00,0xFE,/*"电",0*/
	"子",0x00,0x00,0x7F,0xF8,0x00,0x10,0x00,0x20,0x00,0x40,0x01,0x80,0x01,0x00,0xFF,0xFE,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,/*"子",1*/
	"技",0x10,0x20,0x10,0x20,0x10,0x20,0x13,0xFE,0xFC,0x20,0x10,0x20,0x10,0x20,0x15,0xFC,
	0x18,0x84,0x30,0x88,0xD0,0x48,0x10,0x50,0x10,0x20,0x10,0x50,0x51,0x88,0x26,0x06,/*"技",2*/
	"术",0x01,0x00,0x01,0x20,0x01,0x10,0x01,0x10,0x7F,0xFC,0x03,0x80,0x05,0x40,0x05,0x40,
	0x09,0x20,0x11,0x10,0x21,0x08,0x41,0x04,0x81,0x02,0x01,0x00,0x01,0x00,0x01,0x00,/*"术",3*/
	"系",0x00,0xF8,0x3F,0x00,0x04,0x00,0x08,0x20,0x10,0x40,0x3F,0x80,0x01,0x00,0x06,0x10,
	0x18,0x08,0x7F,0xFC,0x01,0x04,0x09,0x20,0x11,0x10,0x21,0x08,0x45,0x04,0x02,0x00,/*"系",0*/
	"统",0x10,0x40,0x10,0x20,0x20,0x20,0x23,0xFE,0x48,0x40,0xF8,0x88,0x11,0x04,0x23,0xFE,
	0x40,0x92,0xF8,0x90,0x40,0x90,0x00,0x90,0x19,0x12,0xE1,0x12,0x42,0x0E,0x04,0x00,/*"统",1*/
	"设",0x00,0x00,0x21,0xF0,0x11,0x10,0x11,0x10,0x01,0x10,0x02,0x0E,0xF4,0x00,0x13,0xF8,
	0x11,0x08,0x11,0x10,0x10,0x90,0x14,0xA0,0x18,0x40,0x10,0xA0,0x03,0x18,0x0C,0x06,/*"设",2*/
	"置",0x7F,0xFC,0x44,0x44,0x7F,0xFC,0x01,0x00,0x7F,0xFC,0x01,0x00,0x1F,0xF0,0x10,0x10,
	0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0xFF,0xFE,0x00,0x00,/*"置",3*/
	"音",0x02,0x00,0x01,0x00,0x3F,0xF8,0x00,0x00,0x08,0x20,0x04,0x40,0xFF,0xFE,0x00,0x00,
	0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,/*"音",4*/
	"量",0x00,0x00,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0xFF,0xFE,0x00,0x00,0x1F,0xF0,
	0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,0x01,0x00,0x1F,0xF0,0x01,0x00,0x7F,0xFC,/*"量",5*/
	"颜",0x10,0x00,0x08,0xFE,0x7F,0x10,0x22,0x20,0x14,0x7C,0x7F,0x44,0x44,0x54,0x48,0x54,
	0x52,0x54,0x44,0x54,0x48,0x54,0x51,0x54,0x42,0x28,0x44,0x24,0x88,0x42,0x30,0x82,/*"颜",6*/
	"色",0x08,0x00,0x08,0x00,0x1F,0xE0,0x20,0x20,0x40,0x40,0xBF,0xF8,0x21,0x08,0x21,0x08,
	0x21,0x08,0x3F,0xF8,0x20,0x00,0x20,0x02,0x20,0x02,0x20,0x02,0x1F,0xFE,0x00,0x00,/*"色",7*/
	"网",0x00,0x00,0x7F,0xFC,0x40,0x04,0x40,0x04,0x42,0x14,0x52,0x94,0x4A,0x54,0x44,0x24,
	0x44,0x24,0x4A,0x54,0x4A,0x54,0x52,0x94,0x61,0x04,0x40,0x04,0x40,0x14,0x40,0x08,/*"网",8*/
	"络",0x10,0x80,0x10,0x80,0x20,0xF8,0x21,0x08,0x4B,0x10,0xFC,0xA0,0x10,0x40,0x20,0xA0,
	0x41,0x18,0xFA,0x06,0x45,0xF8,0x01,0x08,0x19,0x08,0xE1,0x08,0x41,0xF8,0x01,0x08,/*"络",9*/
	"李",0x01,0x00,0x01,0x80,0x7F,0xFC,0x01,0x00,0x05,0x40,0x09,0x30,0x31,0x0E,0xC1,0x04,
	0x0F,0xE0,0x00,0x40,0x01,0x88,0x7F,0xFC,0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,
	"哈",0x00,0x40,0x00,0x40,0x00,0xA0,0x78,0xA0,0x49,0x10,0x49,0x08,0x4A,0x0E,0x4D,0xF4,
	0x48,0x00,0x48,0x00,0x7B,0xF8,0x4A,0x08,0x02,0x08,0x02,0x08,0x03,0xF8,0x02,0x08,
	"莉",0x04,0x40,0x04,0x44,0xFF,0xFE,0x04,0x40,0x06,0x08,0x78,0x08,0x08,0x48,0x08,0x48,
	0xFF,0x48,0x08,0x48,0x1C,0x48,0x1A,0x48,0x2A,0x48,0x48,0x08,0x88,0x28,0x08,0x10,
	"特",0x10,0x40,0x10,0x40,0x50,0x48,0x53,0xFC,0x7C,0x40,0x50,0x44,0x97,0xFE,0x18,0x10,
	0x30,0x10,0xD7,0xFE,0x11,0x10,0x10,0x90,0x10,0x90,0x10,0x10,0x10,0x50,0x10,0x20,
	"凌",0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x9F,0xC0,0x42,0x00,0x3F,0xE0,0x08,0x80,
  0x14,0x40,0x07,0x80,0x28,0x80,0x55,0x00,0x82,0x00,0x0D,0x80,0x30,0x60,0x00,0x00,
   "南",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0xFF,0xE0,0x04,0x00,0x7F,0xC0,0x51,0x40,
0x4A,0x40,0x5F,0x40,0x44,0x40,0x7F,0xC0,0x44,0x40,0x44,0x40,0x41,0xC0,0x00,0x00,
  "震",0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x04,0x00,0xFF,0xE0,0x84,0x20,0x75,0xC0,
  0x00,0x00,0x7F,0xE0,0x40,0x00,0x7F,0xE0,0x52,0x40,0x51,0x80,0x98,0x60,0x00,0x00,
//U+6B22(欢)
"欢",0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0xFA,0x00,0x0B,0xE0,0x8C,0x20,0x58,0x40,
0x51,0x00,0x21,0x00,0x21,0x00,0x52,0x80,0x52,0x80,0x84,0x40,0x08,0x20,0x00,0x00,

//U+8FCE(迎)
"迎",0x00,0x00,0x00,0x00,0x00,0x00,0x84,0x00,0x59,0xE0,0x11,0x20,0x11,0x20,0xD1,0x20,
0x51,0x20,0x55,0x20,0x59,0x20,0x51,0x60,0x41,0x00,0x41,0x00,0xBF,0xE0,0x00,0x00,

//U+6765(来)
"来",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,0x7F,0xC0,0x04,0x00,0x24,0x80,
0x15,0x00,0xFF,0xE0,0x0E,0x00,0x15,0x00,0x24,0x80,0xC4,0x60,0x04,0x00,0x00,0x00,

//U+5230(到)
"到",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xFE,0x20,0x20,0xA0,0x44,0xA0,0xFE,0xA0,
0x12,0xA0,0x10,0xA0,0xFE,0xA0,0x10,0xA0,0x10,0x20,0x1E,0x20,0xE0,0x60,0x00,0x00,

//U+91CD(重)
"重",0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x7C,0x00,0x04,0x00,0xFF,0xE0,0x44,0x40,
0x7F,0xC0,0x44,0x40,0x7F,0xC0,0x04,0x00,0x7F,0xC0,0x04,0x00,0xFF,0xE0,0x00,0x00,

//U+5E86(庆)
"庆",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x02,0x00,0x7F,0xE0,0x40,0x00,0x42,0x00,
0x42,0x00,0x5F,0xE0,0x42,0x00,0x45,0x00,0x45,0x00,0x48,0x80,0x90,0x60,0x00,0x00,

//U+4EA4(交)
"交",0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x04,0x00,0xFF,0xE0,0x00,0x00,0x11,0x00,
0x20,0x80,0x51,0x40,0x0A,0x00,0x04,0x00,0x0A,0x00,0x31,0x80,0xC0,0x60,0x00,0x00,

//U+901A(通)
"通",0x00,0x00,0x00,0x00,0x00,0x00,0x9F,0x80,0x44,0x80,0x03,0x00,0x1F,0xC0,0xD2,0x40,
0x5F,0xC0,0x52,0x40,0x5F,0xC0,0x52,0x40,0x52,0xC0,0x40,0x00,0xBF,0xE0,0x00,0x00,

//U+5927(大)
"大",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0xFF,0xE0,
0x04,0x00,0x0A,0x00,0x0A,0x00,0x11,0x00,0x11,0x00,0x20,0x80,0xC0,0x60,0x00,0x00,

//U+5B66(学)
"学",0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x40,0x24,0x80,0xFF,0xE0,0x80,0x20,0x3F,0x80,
0x01,0x00,0x02,0x00,0xFF,0xE0,0x04,0x00,0x04,0x00,0x04,0x00,0x1C,0x00,0x00,0x00,

//U+7269(物)
"物",0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0x24,0x00,0xA7,0xE0,0xFA,0xA0,0xA2,0xA0,
0x22,0xA0,0x34,0xA0,0xE5,0x20,0x29,0x20,0x22,0x20,0x24,0x20,0x28,0xC0,0x00,0x00,

//U+8054(联)
"联",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x40,0xFA,0x80,0x50,0x00,0x57,0xC0,0x71,0x00,
0x51,0x00,0x7F,0xE0,0x51,0x00,0x5A,0x80,0xF2,0x80,0x14,0x40,0x18,0x20,0x00,0x00,

//U+7F51(网)
"网",0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xE0,0x80,0x20,0x80,0x20,0xC4,0x60,0xAA,0xA0,
0x91,0x20,0x91,0x20,0xAA,0xA0,0xC4,0x60,0x80,0x20,0x80,0x20,0x80,0xE0,0x00,0x00,

//U+0032(2)
"2",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x90,0x00,0x90,0x00,0x20,0x00,
0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0030(0)
"0",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x90,0x00,0x90,0x00,0x90,0x00,
0x90,0x00,0x90,0x00,0x90,0x00,0x90,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0035(5)
"5",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0xE0,0x00,0x10,0x00,0x10,0x00,0x90,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+5B9E(实)
"实",0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0xFF,0xE0,0x80,0x20,0x12,0x00,0x0A,0x00,
0x22,0x00,0x12,0x00,0xFF,0xE0,0x04,0x00,0x09,0x80,0x30,0x40,0xC0,0x20,0x00,0x00,

//U+8BAD(训)
"训",0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x20,0x29,0x20,0x09,0x20,0x09,0x20,0xC9,0x20,
0x49,0x20,0x49,0x20,0x49,0x20,0x59,0x20,0x69,0x20,0x51,0x20,0x20,0x20,0x00,0x00,

"室",//U+5BA4(室)
0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x04,0x00,0xFF,0xE0,0x80,0x20,0xBF,0xA0,
0x08,0x00,0x11,0x00,0x3F,0x80,0x04,0x00,0x7F,0xC0,0x04,0x00,0xFF,0xE0,0x00,0x00,

//U+FF01(！)
"!",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
0x30,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"H",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x00,0x90,0x00,0x90,0x00,0x90,0x00,
0xF0,0x00,0x90,0x00,0x90,0x00,0x90,0x00,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0065(e)
"e",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,
0xA0,0x00,0xE0,0x00,0x80,0x00,0xA0,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+006C(l)
"l",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


//U+006F(o)
"o",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,
0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,



};

typedef struct 
{
	unsigned char Index[2];	
	char Msk[72];
}typFNT_GB24; 


//宋体
//24*24大小
//逐行式，顺向（高位在前）
const typFNT_GB24 cfont24[] = 
{
	"全",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x30,0x00,0x00,0x68,0x00,0x00,
	0x44,0x00,0x00,0xC2,0x00,0x01,0x81,0x00,0x03,0x00,0xC0,0x06,0x00,0x70,0x0F,0xFF,
	0xFE,0x10,0x18,0x08,0x60,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x60,
	0x03,0xFF,0x80,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x08,0x1F,
	0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,/*"全",0*/
	"动",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x01,0x00,0x00,0x61,0x00,0x3F,
	0x81,0x00,0x00,0x01,0x00,0x00,0x01,0x0C,0x00,0x07,0xFC,0x00,0x31,0x0C,0x3F,0xC1,
	0x0C,0x06,0x01,0x0C,0x04,0x01,0x0C,0x0C,0x81,0x08,0x08,0x43,0x08,0x10,0x62,0x08,
	0x10,0x22,0x08,0x2F,0xF4,0x08,0x38,0x14,0x08,0x00,0x08,0x08,0x00,0x11,0x18,0x00,
	0x20,0xF8,0x00,0x40,0x30,0x00,0x00,0x00,/*"动",1*/
	"电",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,
	0x10,0x00,0x0F,0xFF,0xF0,0x08,0x10,0x20,0x08,0x10,0x20,0x08,0x10,0x20,0x08,0x10,
	0x20,0x0F,0xFF,0xE0,0x08,0x10,0x20,0x08,0x10,0x20,0x08,0x10,0x20,0x08,0x10,0x20,
	0x0F,0xFF,0xE0,0x08,0x10,0x00,0x00,0x10,0x08,0x00,0x10,0x08,0x00,0x10,0x04,0x00,
	0x18,0x0C,0x00,0x0F,0xF8,0x00,0x00,0x00,/*"电",2*/
	"子",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x0F,0xFF,0xF0,0x00,0x00,0x60,0x00,
	0x00,0x80,0x00,0x03,0x00,0x00,0x14,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,
	0x0C,0x7F,0xFF,0xFE,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,
	0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,
	0xF8,0x00,0x00,0x30,0x00,0x00,0x00,0x00,/*"子",3*/
	"技",0x00,0x00,0x00,0x04,0x00,0x00,0x07,0x01,0x80,0x06,0x01,0x00,0x06,0x01,0x00,0x06,
	0x01,0x00,0x06,0xC1,0x0C,0x3F,0x3F,0xF0,0x06,0x01,0x00,0x06,0x01,0x00,0x06,0x01,
	0x00,0x06,0xFF,0xF8,0x07,0x08,0x10,0x3E,0x08,0x30,0x26,0x04,0x20,0x06,0x04,0x60,
	0x06,0x02,0x40,0x06,0x02,0xC0,0x06,0x01,0x80,0x06,0x03,0x80,0x06,0x0C,0x60,0x1E,
	0x10,0x3E,0x0C,0xE0,0x0C,0x00,0x00,0x00,/*"技",4*/
	"术",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x19,0x80,0x00,0x18,0xE0,0x00,
	0x18,0x60,0x00,0x18,0x28,0x00,0x18,0x1C,0x3F,0xFF,0xE0,0x00,0x3C,0x00,0x00,0x7C,
	0x00,0x00,0x5A,0x00,0x00,0xDA,0x00,0x00,0x99,0x00,0x01,0x19,0x80,0x03,0x18,0xC0,
	0x06,0x18,0x60,0x04,0x18,0x38,0x08,0x18,0x1E,0x30,0x18,0x08,0x40,0x18,0x00,0x00,
	0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,/*"术",5*/
};

typedef struct 
{
       unsigned char Index[2];	
       char Msk[128];
}typFNT_GB32; 

//宋体
//32*32大小
//逐行式，顺向（高位在前）
const typFNT_GB32 cfont32[] = 
{
	"全",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x80,0x00,
	0x00,0x07,0x80,0x00,0x00,0x06,0x80,0x00,0x00,0x0C,0x40,0x00,0x00,0x1C,0x20,0x00,
	0x00,0x18,0x30,0x00,0x00,0x30,0x18,0x00,0x00,0x60,0x0C,0x00,0x00,0xC0,0x07,0x00,
	0x01,0x80,0x03,0xC0,0x03,0x00,0x02,0xF8,0x07,0xFF,0xFF,0x7C,0x08,0x01,0x80,0x90,
	0x30,0x01,0x80,0x00,0x40,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x81,0x00,
	0x00,0x01,0x83,0x80,0x01,0xFF,0xFF,0xC0,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x10,
	0x00,0x01,0x80,0x38,0x1F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"全",0*/
	"动",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x0E,0x00,
	0x00,0x00,0x0C,0x00,0x00,0x0C,0x0C,0x00,0x3F,0xFE,0x0C,0x00,0x10,0x00,0x0C,0x00,
	0x00,0x00,0x0C,0x00,0x00,0x00,0x0C,0x18,0x00,0x00,0xFF,0xFC,0x00,0x02,0x0C,0x18,
	0x00,0x07,0x0C,0x18,0x3F,0xFF,0x8C,0x18,0x01,0xC0,0x0C,0x18,0x01,0xC0,0x0C,0x18,
	0x01,0x80,0x08,0x18,0x03,0x00,0x08,0x18,0x02,0x10,0x18,0x18,0x06,0x08,0x18,0x18,
	0x04,0x0C,0x10,0x18,0x08,0x06,0x10,0x18,0x10,0x06,0x30,0x10,0x2F,0xFB,0x20,0x10,
	0x3E,0x03,0x60,0x10,0x10,0x02,0xC0,0x30,0x00,0x00,0x80,0x30,0x00,0x01,0x0C,0x30,
	0x00,0x02,0x03,0xE0,0x00,0x0C,0x01,0xE0,0x00,0x10,0x00,0x80,0x00,0x00,0x00,0x00,/*"动",1*/
	"电",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x80,0x00,
	0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,
	0x07,0xFF,0xFF,0xC0,0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,
	0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,0x07,0xFF,0xFF,0xC0,
	0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,0x06,0x03,0x00,0xC0,
	0x06,0x03,0x00,0xC0,0x07,0xFF,0xFF,0xC0,0x06,0x03,0x00,0x80,0x06,0x03,0x00,0x00,
	0x00,0x03,0x00,0x10,0x00,0x03,0x00,0x08,0x00,0x03,0x00,0x08,0x00,0x03,0x00,0x18,
	0x00,0x03,0x80,0x1C,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"电",2*/
	"子",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,
	0x03,0xFF,0xFF,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x03,0x00,0x00,0x00,0x06,0x00,
	0x00,0x00,0x18,0x00,0x00,0x00,0x30,0x00,0x00,0x01,0xC0,0x00,0x00,0x01,0xC0,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x10,0x00,0x01,0x80,0x38,0x3F,0xFF,0xFF,0xFC,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
	0x00,0x3F,0x80,0x00,0x00,0x07,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,/*"子",3*/
	"技",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x08,0x00,0x01,0xC0,0x0E,0x00,
	0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,
	0x01,0x98,0x0C,0x18,0x3F,0xFF,0xFF,0xFC,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,
	0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x8C,0x0C,0x20,0x01,0xB3,0xFF,0xF0,
	0x01,0xC0,0x80,0x60,0x0F,0x80,0x80,0x60,0x3D,0x80,0x40,0xC0,0x31,0x80,0x40,0xC0,
	0x01,0x80,0x21,0x80,0x01,0x80,0x21,0x80,0x01,0x80,0x33,0x00,0x01,0x80,0x1E,0x00,
	0x01,0x80,0x0C,0x00,0x01,0x80,0x1E,0x00,0x01,0x80,0x37,0x00,0x01,0x80,0xE3,0xC0,
	0x1F,0x83,0x80,0xF8,0x07,0x8E,0x00,0x7C,0x02,0x30,0x00,0x00,0x00,0x00,0x00,0x00,/*"技",4*/
	"术",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0xC0,0x00,
	0x00,0x01,0x8C,0x00,0x00,0x01,0x87,0x00,0x00,0x01,0x83,0x80,0x00,0x01,0x81,0x80,
	0x00,0x01,0x80,0x80,0x00,0x01,0x80,0x30,0x3F,0xFF,0xFF,0xF8,0x10,0x03,0xC0,0x00,
	0x00,0x07,0xC0,0x00,0x00,0x07,0xA0,0x00,0x00,0x0D,0xA0,0x00,0x00,0x0D,0x90,0x00,
	0x00,0x19,0x90,0x00,0x00,0x19,0x98,0x00,0x00,0x31,0x8C,0x00,0x00,0x61,0x86,0x00,
	0x00,0xC1,0x87,0x00,0x00,0x81,0x83,0x80,0x01,0x81,0x81,0xC0,0x03,0x01,0x80,0xF0,
	0x04,0x01,0x80,0x7C,0x08,0x01,0x80,0x38,0x10,0x01,0x80,0x10,0x60,0x01,0x80,0x00,
	0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,/*"术",5*/
};

#endif


