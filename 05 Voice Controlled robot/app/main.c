
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>
#include <uart.h>

#include <motor_control.h>
#include <bluetooth.h>

#define IN 1
#define OUT 0



/*Program in AT89S52 will starts executes from here */

char op;

void main()
{


	init_lcd();
	bot_Init();
	lcd_clear();
	init_UART();

	gotoxy_lcd(1, 1);
	print_lcd("Voice Controlled");
	gotoxy_lcd(1, 2);
	print_lcd("   BT Robot");
	
	delay_sec(1);
	
	lcd_clear();
	print_lcd("Start Speaking :-)");
	bot_Stop();
	bot_PickStop();
	bot_ArmStop();

	while(1)
	{
		scan_BTData();

		if(bt_DataCompare("*start") || bt_DataCompare("*forward"))
		{
			bot_MoveForward();	
			gotoxy_lcd(1, 1);
			print_lcd("Moving Forward...  ");
		
		}
		else if(bt_DataCompare("*backward"))
		{
			bot_MoveBackward();	
			gotoxy_lcd(1, 1);
			print_lcd("Moving Backward...  ");
		}
		else if(bt_DataCompare("*left"))
		{
			bot_MoveForwardLeft();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Left...    ");
		}

		else if(bt_DataCompare("*right"))
		{
			bot_MoveForwardRight();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Right...  ");
		}
		else if(bt_DataCompare("*stop")) 
		{
			bot_Stop();
			gotoxy_lcd(1, 1);
			print_lcd("Bot Stopped.....    ");
		}
//		else 
//		{
//			bot_Stop();
//			gotoxy_lcd(1, 1);
//			print_lcd("Wrong Command....");
//			delay_ms(500);
//			gotoxy_lcd(1, 1);
//			print_lcd("Start Speaking :-)");
//		}
	
	}
}