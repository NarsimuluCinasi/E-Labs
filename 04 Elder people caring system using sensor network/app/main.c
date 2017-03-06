
/*Defining all Header files */

#include <reg52.h>
#include <lcd4bit.h>
#include <delay.h>
#include <adc.h>
#include <uart.h>

#define IN 1
#define OUT 0
#define OFF 0
#define ON 1

#define MOBILE_SMS "AT+CMGS=\"+919666333695\""

sbit BUZZER = P1^0;



unsigned char axisx, axisy, axisz, body_temp, heartrate;



/*Program in AT89S52 will starts executes from here */




void Main()
{

	init_lcd();
	adc_0808Init();
	lcd_clear();
	

	gotoxy_lcd(1, 1);
	print_lcd("Elder people caring");
	gotoxy_lcd(1, 2);
	print_lcd("using sensor network");
	
	delay_sec(1);

		init_UART();
	lcd_clear();
		
	print_lcd("Initilizing GSM.....");
	transmit_UARTDataString("AT"); delay_ms(50);
	transmit_UARTDataByte(0X0D);

	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');
	
	lcd_clear();
	print_lcd("MODEM AT OK ....");

	transmit_UARTDataString("ATE0");
	transmit_UARTDataByte(0X0D);
	while(receive_UARTDataByte() != 'O');
	while(receive_UARTDataByte() != 'K');
	lcd_clear();
	print_lcd("MODEM ECHO OFF....");

	lcd_clear();
	print_lcd("Checking GSM Network");
	delay_ms(250);
	transmit_UARTDataString("AT+CPIN?"); delay_ms(100);transmit_UARTDataByte(0X0D);
	
		while(receive_UARTDataByte() != 'R');
		while(receive_UARTDataByte() != 'E');
		while(receive_UARTDataByte() != 'A');
		while(receive_UARTDataByte() != 'D');
		while(receive_UARTDataByte() != 'Y');

	lcd_clear();
		print_lcd("MODEM CPIN OK ......");

		transmit_UARTDataString("AT+CMGD=1");delay_ms(100); 	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');

	lcd_clear();
		print_lcd("SMS TEXTM OK ...... ");

		transmit_UARTDataString(MOBILE_SMS);  delay_ms(50);	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != '>');
		transmit_UARTDataString("GSM MODULE TEST SMS");delay_ms(100);
		transmit_UARTDataByte(0X1A);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');
		print_lcd("SMS TEST OK .....");
		delay_ms(100);

lcd_clear();
	
	while(1)
	{
		
		
		axisx = adc_0808GetChannelData(0);
		axisy = adc_0808GetChannelData(1);
		axisz = adc_0808GetChannelData(2);
		body_temp = adc_0808GetChannelData(3);
		heartrate = adc_0808GetChannelData(4);
		
		gotoxy_lcd(1, 1);
//		print_num_lcd(axisx); delay_ms(500);
		if(axisx>80 || axisy>80 || axisz>80)
		{
			
	
			 
			lcd_clear();
			gotoxy_lcd(1, 1);
			print_lcd("Person Fallen");		delay_ms(500);

					transmit_UARTDataString(MOBILE_SMS);  delay_ms(50);	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != '>');
		transmit_UARTDataString("PERSON FALLEN");delay_ms(100);
		transmit_UARTDataByte(0X1A);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K'); lcd_clear(); print_lcd("SMS Sent ...");		delay_ms(500);
			
		}
		else if(body_temp > 20)
		{
			
		
			 
			lcd_clear();
			gotoxy_lcd(1, 1);
			print_lcd("Person body");
			gotoxy_lcd(1, 2);
			print_lcd("Temperature Increased");
			delay_ms(500);

					transmit_UARTDataString(MOBILE_SMS);  delay_ms(50);	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != '>');
		transmit_UARTDataString("PERSON BODY Temperature increased");delay_ms(100);
		transmit_UARTDataByte(0X1A);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K'); lcd_clear(); print_lcd("SMS Sent ...");		delay_ms(500);
			
		}
		else if(heartrate > 80)
		{
			lcd_clear();
			gotoxy_lcd(1, 1);
			print_lcd("Person Heart rate");
			gotoxy_lcd(1, 2);
			print_lcd(" Increased");
			delay_ms(500);

					transmit_UARTDataString(MOBILE_SMS);  delay_ms(50);	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != '>');
		transmit_UARTDataString("Person Heart Rate increased");delay_ms(100);
		transmit_UARTDataByte(0X1A);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');  		lcd_clear(); print_lcd("SMS Sent ...");		delay_ms(500);
			
		}
		else
		{
			BUZZER = OFF;
			
			gotoxy_lcd(1, 1);
				lcd_clear();print_lcd("Normal .....");
			gotoxy_lcd(1, 2);
			delay_ms(500);
		}
   }

}