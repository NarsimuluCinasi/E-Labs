
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>
#include<uart.h>

#define IN 1
#define OUT 0
#define OFF 0
#define ON 1
#define MOBILE_SMSNO "AT+CMGS=\"+919666333695\""



sbit BUZZER = P0^0;
sbit TX433_D0 = P0^4;
sbit TX433_D1 = P0^5;
sbit TX433_D2 = P0^6;
sbit TX433_D3 = P0^7;

sbit HELMET = P0^1;
sbit ALCOHOL = P0^2;
sbit TILT = P0^3;
unsigned char  alchohal = 0;

/*Program in AT89S52 will starts executes from here */

void Main()
{

	unsigned char helmet_status =0,alcohol_status = 0, tilt_status = 0,error =0;
	init_lcd();	 
	init_UART();


	HELMET = 1;
	ALCOHOL = 1;
	TILT = 1;

	TX433_D0 = 1;
	TX433_D1 = 1;
	TX433_D2 = 1;
	TX433_D3 = 1;

	BUZZER = OUT;
	BUZZER = OFF;
		lcd_clear();
	gotoxy_lcd(1, 1);
	print_lcd("Helmet For Road");
	gotoxy_lcd(1, 2);
	print_lcd("   Safety");	delay_ms(1000);
	BUZZER = ON;






	
	BUZZER = OFF;		lcd_clear();
	
	while(1)
	{
	
		
		helmet_status = HELMET;
		if(error == 0)
		{
			BUZZER = OFF;
				gotoxy_lcd(1, 1); print_lcd("Everthing OK");  delay_ms(1000);

		 
		}												
		if(helmet_status == 1)
		{
			
			BUZZER = ON; 
			TX433_D0 = 1; 	TX433_D3 = 1;  	gotoxy_lcd(1, 1); print_lcd("No helmet.......");

			delay_ms(250);	 error = 1;
			
		}else error = 0;

   }

}