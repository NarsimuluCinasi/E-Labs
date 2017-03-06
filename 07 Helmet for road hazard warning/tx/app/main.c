
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
#define MOBILE_SMSNO "AT+CMGS=\"+919989369233\""



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

	TX433_D0 = OUT;
	TX433_D1 = OUT;
	TX433_D2 = OUT;
	TX433_D3 = OUT;

	BUZZER = OUT;
	BUZZER = OFF;
		lcd_clear();
	gotoxy_lcd(1, 1);
	print_lcd("Helmet For Road");
	gotoxy_lcd(1, 2);
	print_lcd("   Safety");
	BUZZER = ON;

	transmit_UARTDataString("AT"); delay_ms(50);
	transmit_UARTDataByte(0X0D);

	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');

	transmit_UARTDataString("ATE0"); delay_ms(50);
	transmit_UARTDataByte(0X0D);

	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');

	transmit_UARTDataString("AT+CPIN?"); delay_ms(100);transmit_UARTDataByte(0X0D);
	
	while(receive_UARTDataByte() != 'R');
	while(receive_UARTDataByte() != 'E');
	while(receive_UARTDataByte() != 'A');
	while(receive_UARTDataByte() != 'D');
	while(receive_UARTDataByte() != 'Y');


	transmit_UARTDataString("AT+CMGF=1");delay_ms(100); 	transmit_UARTDataByte(0X0D);
	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');

	transmit_UARTDataString(MOBILE_SMSNO);  delay_ms(50);	transmit_UARTDataByte(0X0D);
	while(receive_UARTDataByte() != '>');
	transmit_UARTDataString("BIKE[AP xx TK 001] : STARTED WORKING");delay_ms(100);
	transmit_UARTDataByte(0X1A);
	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');
	
	BUZZER = OFF;		lcd_clear();
	
	while(1)
	{
	
		
		helmet_status = HELMET;
	   	alcohol_status  = ALCOHOL;
			tilt_status = TILT;

		if(error == 0)
		{
			BUZZER = OFF;
			TX433_D0 = 0;
			TX433_D1 = 0;
			TX433_D2 = 0;
			TX433_D3 = 0;
				gotoxy_lcd(1, 1); print_lcd("Everthing OK");

		 
		}												



	
		if(helmet_status == 0 && tilt_status ==1 && error ==0)
		{
			BUZZER = ON;
			TX433_D2 = 1;
			TX433_D3 = 1; error = 1;  	lcd_clear(); print_lcd("Fall detected");


	transmit_UARTDataString(MOBILE_SMSNO);  delay_ms(50);	transmit_UARTDataByte(0X0D);
	while(receive_UARTDataByte() != '>');
	transmit_UARTDataString("BIKE[AP xx TK 001] : EMERGENCY FALL DETECTED");delay_ms(100);
	transmit_UARTDataByte(0X1A);
	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');
			delay_ms(250);
		}

			if(helmet_status == 0 && alcohol_status == 1 && error ==0)
		{
			BUZZER = ON;
			TX433_D1 = 1;	TX433_D3 = 1;  error =1;   	lcd_clear(); print_lcd("Alcohol detected");



	transmit_UARTDataString(MOBILE_SMSNO);  delay_ms(50);	transmit_UARTDataByte(0X0D);
	while(receive_UARTDataByte() != '>');
	transmit_UARTDataString("BIKE[AP xx TK 001]: ALCOHOL DETECTED");delay_ms(100);
	transmit_UARTDataByte(0X1A);
	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');

			delay_ms(250);
		}

		if(helmet_status == 1)
		{
			
			BUZZER = ON; 
			TX433_D0 = 1; 	TX433_D3 = 1;  	lcd_clear(); print_lcd("No helmet");

			delay_ms(250);	 error = 0;
			
		}

   }

}