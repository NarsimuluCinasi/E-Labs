
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>

#include <motor_control.h>

#define IN 1
#define OUT 0

sbit DTMF_EST = P2^0;
sbit DTMF_D0 = P2^1;
sbit DTMF_D1 = P2^2;
sbit DTMF_D2 = P2^3;
sbit DTMF_D3 = P2^4;
/*Program in AT89S52 will starts executes from here */


char dtmf_data;
void main()
{
	init_lcd();
	bot_Init();
	lcd_clear();

	  DTMF_EST = IN;
	  DTMF_D0 =  IN;
	  DTMF_D0 = IN;
	  DTMF_D0 = IN;	
	  DTMF_D0 = IN;

	gotoxy_lcd(1, 1);
	print_lcd("Mobile Operated");
	gotoxy_lcd(1, 2);
	print_lcd("DTMF Spy Robot");
	
	delay_sec(1);
	lcd_clear();
	
	
	
	while(1)
	{

			
			if(DTMF_D0 == 1 || DTMF_D1 == 1 || DTMF_D1 == 1 || DTMF_D1 == 1)
			{
			
			if(DTMF_D1 == 1)
			{
				dtmf_data |= 1;	 
			}
			 if(DTMF_D1 == 1)
			{
				dtmf_data |= 1<<1;	 
			}
			if(DTMF_D2 == 1)
			{
				dtmf_data |= 1<<2;	 
			}
		   	if(DTMF_D3 == 1)
			{
				dtmf_data |= 1<<3;	 
			}
			 	dtmf_data &= 0x0F;
			}
		
	

		if(dtmf_data == 1)
		{
			bot_MoveForward();	
			gotoxy_lcd(1, 1);
			print_lcd("Moving FORWARD...  ");
		}

		else if(dtmf_data == 2)
		{
			bot_MoveForwardLeft();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Left...    ");
		}

		else if(dtmf_data == 3)
		{
			bot_MoveForwardRight();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Right...  ");
		}

		else if(dtmf_data == 4)
		{
			bot_MoveBackward();
			gotoxy_lcd(1, 1);
			print_lcd("Moving Right...  ");
		}
	   	else if(dtmf_data == 5)
		{
			bot_MoveBackward();
			gotoxy_lcd(1, 1);
			print_lcd("Bot Stopped...  ");
		}
	   	else
		{
			bot_Stop();
			gotoxy_lcd(1, 1);
			print_lcd("BOT Stopped.....    ");
		}
	
	}
}