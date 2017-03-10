
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>

#include <motor_control.h>

#define IN 1
#define OUT 0



/*Program in AT89S52 will starts executes from here */

void main()
{
	init_lcd();
	bot_Init();
	lcd_clear();

	gotoxy_lcd(1, 1);
	print_lcd("Autonomous Robot");
	gotoxy_lcd(1, 2);
	print_lcd("For Path Finding");
	
	delay_sec(1);
	lcd_clear();
	
	
	
	while(1)
	{
		
		lcd_clear();
		bot_MoveForward();	
		gotoxy_lcd(1, 1);
		print_lcd("Moving FORWARD...  ");
		delay_sec(2);

		bot_MoveForwardLeft();
		gotoxy_lcd(1, 1);
		print_lcd("Moving Left...    ");
		delay_ms(500);

		bot_MoveForward();
		gotoxy_lcd(1, 1);
		print_lcd("Moving Forward...");
		delay_ms(2000);

		bot_MoveForwardRight();
		gotoxy_lcd(1, 1);
		print_lcd("Moving Right...  ");
		delay_ms(200);

		bot_MoveForward();
		gotoxy_lcd(1, 1);
		print_lcd("Moving Forward...");
		delay_ms(2000);

		bot_Stop();
		gotoxy_lcd(1, 1);
		print_lcd("BOT Stopped.....    ");
		delay_ms(2000);
		
		bot_MoveBackward();
		gotoxy_lcd(1, 1);
		print_lcd("MOVING BACKWORD... ");
		delay_ms(2000);

		bot_MoveBackwardRight();
		gotoxy_lcd(1, 1);
		print_lcd("BACK RIGHT..... ");
		delay_ms(500);
	
	}
}