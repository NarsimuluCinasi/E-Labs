
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

			
			if(DTMF_D2 ==0 && DTMF_D1 == 0 && DTMF_D0 == 1)
			{
				dtmf_data = 1;	 
			}					  

			else if(DTMF_D2 ==0 && DTMF_D1 == 1 && DTMF_D0 == 0)
			{
				dtmf_data = 2;	 
			}
			else if(DTMF_D2 ==0 && DTMF_D1 == 1 && DTMF_D0 == 1)
			{
				dtmf_data = 3;	 
			}
		   	else if(DTMF_D2 ==1 && DTMF_D1 ==0  && DTMF_D0 == 0)
			{
				dtmf_data = 4;	 
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

	   	else
		{
			bot_Stop();
			gotoxy_lcd(1, 1);
			print_lcd("BOT Stopped.....    ");
		}
	
	}
}