
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>
#include <uart.h>

#include <motor_control.h>

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
	print_lcd("Pick and Place");
	gotoxy_lcd(1, 2);
	print_lcd(" BT Robot");
	
	delay_sec(1);
	
	lcd_clear();
	print_lcd("Start BT :-)");
	bot_Stop();
	bot_PickStop();
	bot_ArmStop();

	while(1)
	{
		
		op = receive_UARTDataByte();
		if(op == 'F')
		{
			bot_MoveForward();	
			gotoxy_lcd(1, 1);
			print_lcd("Moving FORWARD...  ");
		
		}
		else if(op == 'B')
		{
			bot_MoveBackward();	
			gotoxy_lcd(1, 1);
			print_lcd("Moving BACKWARD...  ");
		}
		else if(op == 'L')
		{
			bot_MoveForwardLeft();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Left...    ");
		}

		else if(op == 'R')
		{
			bot_MoveForwardRight();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Right...  ");
		}
		else if(op == 'S') 
		{
			bot_Stop();
			gotoxy_lcd(1, 1);
			print_lcd("BOT Stopped.....    ");
		}

		if(op == 'D')
		{
			bot_ArmUp();
			gotoxy_lcd(1, 2);
			print_lcd("Hand Move UP.....");
		}
		else if(op == 'E')
		{	 
			bot_ArmDown();
			gotoxy_lcd(1, 2);
			print_lcd("Hand Move Down.....");
		}

		if(op == 'O')
		{
			bot_PickOpen();
			gotoxy_lcd(1, 2);
			print_lcd("Pick Open......");
		}
		else if(op == 'P')
		{
			bot_PickClose();
			gotoxy_lcd(1, 2);
			print_lcd("Pick Close......");
		}			
	
		if(op == 'Z')
		{
			bot_PickStop();
			bot_ArmStop();
			gotoxy_lcd(1, 2);
			print_lcd("ARM & PICK STPD");
		}
	
	}
}