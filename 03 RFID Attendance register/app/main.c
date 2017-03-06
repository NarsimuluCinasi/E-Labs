
/*Defining all Header files */
#include <reg52.h>
#include <lcd4bit.h>
#include <delay.h>
#include <uart.h>
#include <rfid.h>
#include <stdio.h>
#include <stdlib.h>

/*********** Macros are declared **************/

#define RFID_TAG1 "4C006F28CCC7"
#define RFID_TAG2 "4C006E8B9831"
#define RFID_TAG3 "4C006E9F78C5"


/*********** labels are declared **************/

#define IN 1
#define OUT 0

/*********** PINS are defined **************/

sbit RELAY1 = P0^0;

/*********** Functions are declared **************/

/*********** Global varibles are declared **************/

/*Program in AT89S52 will starts executes from here */

void main()
{
	unsigned char number =10, status =0;
	init_lcd();
	init_UART();

	/**********123456789ABCDEF************ character sequence in 16x2 LCD Module*/
	RELAY1 = 1;
	RELAY1 =0;
	print_lcd("RFID STUDENTEXAM");
	gotoxy_lcd(1, 2);
	print_lcd("ATTENDACE SYSTEM");
	delay_ms(1000);
	
	lcd_clear();
	
	while(1)
	{	
	
		gotoxy_lcd(1, 1);	
		print_lcd("WELCOME TKR EXAM");
		gotoxy_lcd(1, 2);
		print_lcd("SWIPE YOUR RFID");
		scan_RFID();	
			
		if(rfid_compare(RFID_TAG1))
		{
			
			lcd_clear();
			print_lcd("17001 PRESENT");
			delay_ms(1000);
			status =1;
		}
		else if(rfid_compare(RFID_TAG2))
		{
			lcd_clear();
			print_lcd("17002 PRESENT");
			delay_ms(1000);
		
			status =1;
		}
	
		else
		{
			lcd_clear();
			print_lcd("Invalid ID .....");
			delay_ms(1000);
		}
		 
		if(status == 1)
		{
			number++;
			number = number%8;
			RELAY1 = 1;
			lcd_clear();
			
			print_lcd("PLEASE TAKE");
			gotoxy_lcd(1, 2);
			if(number == 1)
				print_lcd("SEAT NO: 5");
			else if(number == 2)
				print_lcd("SEAT NO: 1");
			else if(number == 3)
				print_lcd("SEAT NO: 8");
			else if(number == 4)
				print_lcd("SEAT NO: 10");
			else if(number == 5)
				print_lcd("SEAT NO: 15");
			else if(number == 6)
				print_lcd("SEAT NO: 22");
			else if(number == 7)
				print_lcd("SEAT NO: 36");
			else if(number == 7)
				print_lcd("SEAT NO: 42");
			else
				print_lcd("SEAT NO: 49");
			delay_ms(500);
			RELAY1 = 0;
			status =0;
			

		}
		
	}
}


