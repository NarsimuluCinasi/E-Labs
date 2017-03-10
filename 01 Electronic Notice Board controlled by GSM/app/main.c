
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>
#include <uart.h>
#include <gsm_modem.h>

#include <motor_control.h>


#define IN 1
#define OUT 0



/*Program in AT89S52 will starts executes from here */

char opm;

void main()
{
	char sms_data[80] = {0};

	char i=0, str=0,count=0;
	init_lcd();
	init_UART();
	lcd_clear();	

	
		lcd_20x4Position(1, 0);
		print_lcd("TKR ENGINEERING COL2");
		lcd_20x4Position(2, 0);
		print_lcd(" ELECTRONIC NOTICE ");

		
		lcd_20x4Position(3, 0);
		print_lcd("  BOARD USING GSM  ");
		lcd_20x4Position(4, 0);
		print_lcd("********************");
		delay_ms(1000);
		//init_GSMModem();

		lcd_20x4Position(3, 0);
		print_lcd("--------------------");
		lcd_20x4Position(4, 0);
		print_lcd("Initilizing GSM.....");
		transmit_UARTDataString("AT"); delay_ms(50);
		transmit_UARTDataByte(0X0D);

		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');
	
		lcd_20x4Position(4, 0);
		print_lcd("MODEM AT OK ....");

		transmit_UARTDataString("ATE0");
		transmit_UARTDataByte(0X0D);

		

		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');
		lcd_20x4Position(4, 0);
		print_lcd("MODEM ECHO OFF....");
		lcd_20x4Position(4, 0);
		print_lcd("Checking GSM Network");
		delay_ms(250);
		transmit_UARTDataString("AT+CPIN?"); delay_ms(100);transmit_UARTDataByte(0X0D);
	
		while(receive_UARTDataByte() != 'R');
		while(receive_UARTDataByte() != 'E');
		while(receive_UARTDataByte() != 'A');
		while(receive_UARTDataByte() != 'D');
		while(receive_UARTDataByte() != 'Y');

		lcd_20x4Position(4, 0);
		print_lcd("MODEM CPIN OK ......");

		transmit_UARTDataString("AT+CMGF=1");delay_ms(100); 	transmit_UARTDataByte(0X0D);
		while(receive_UARTDataByte() != 'O');
		while(receive_UARTDataByte() != 'K');

		lcd_20x4Position(4, 0);
		print_lcd("SMS TEXTM OK ...... ");

//		transmit_UARTDataString("AT+CMGS=\"+919666333695\"");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != '>');
//		transmit_UARTDataString("GSM MODULE TEST SMS");delay_ms(100);
//		transmit_UARTDataByte(0X1A);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		lcd_20x4Position(4, 0);
//		print_lcd("SMS TEST OK .....");
//		delay_ms(100);
		
		lcd_20x4Position(4, 0);
		print_lcd("LOADING INBOX.....");
		delay_ms(500);
//
//		transmit_UARTDataString("AT+CMGD=1");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=2");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=3");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=4");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=5");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=6");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=7");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=8");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=9");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//		transmit_UARTDataString("AT+CMGD=10");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		while(receive_UARTDataByte() != 'O');
//		while(receive_UARTDataByte() != 'K');
//
//		
//		
//		lcd_20x4Position(4, 0);
//		print_lcd("SMS INBOX CLEAN....");
//		delay_ms(1000);

		lcd_20x4Position(4, 0);
		print_lcd("SEND NOTICE        ");
		delay_ms(1000);


		transmit_UARTDataString("AT+CMGR=1");  delay_ms(50);	transmit_UARTDataByte(0X0D);  delay_ms(50);

			lcd_clear();

		while(1)
		{
		
		 	if(RI == 1 && count <50)
			{
				sms_data[count] = receive_UARTDataByte();
				count++;
			}
			sms_data[count] = '\0';
			print_lcd(sms_data);

			
				 
//			transmit_UARTDataString("AT+CMGR=1");  delay_ms(50);	transmit_UARTDataByte(0X0D);  delay_ms(50);
//		 
//			  if()
			
//			while(receive_UARTDataByte() != '+');
//
//			lcd_20x4Position(4, 0); print_lcd("SEND NOTICE1       ");
//
//			while(receive_UARTDataByte() != '#');
//
//			lcd_20x4Position(4, 0); print_lcd("SEND NOTICE2       ");
//			lcd_clear();
//			while(1)
//			{
//				
//		  	
//				sms_data = receive_UARTDataByte();delay_ms(100);
//				putc_lcd(sms_data);
//
//				if (sms_data == '#') break;
//				if (sms_data == '\r') break;
//				if (sms_data == '\n') break;
//				if (sms_data == '\0') break;
//			
//
//
//			}

//			transmit_UARTDataString("AT+CMGR=2");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		  	while(receive_UARTDataByte() != '#');
//		  	lcd_clear();
//			while(1)
//			{
//				sms_data = receive_UARTDataByte();
//				putc_lcd(sms_data);
//				if (sms_data == '#') break;
//				if (sms_data == '\r') break;
//				if (sms_data == '\n') break;
//				if (sms_data == '\0') break;
//			
//
//
//			}

//			transmit_UARTDataString("AT+CMGR=3");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//		  	while(receive_UARTDataByte() != '#');
//		  	lcd_clear();
//			while(1)
//			{
//				sms_data = receive_UARTDataByte();
//				putc_lcd(sms_data);
//				if (sms_data == '#') break;
//				if (sms_data == '\r') break;
//				if (sms_data == '\n') break;
//				if (sms_data == '\0') break;
//				
//
//
//			}
//			transmit_UARTDataString("AT+CMGD=1");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//				while(receive_UARTDataByte() != 'O');
//				while(receive_UARTDataByte() != 'K');
//					transmit_UARTDataString("AT+CMGD=2");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//				while(receive_UARTDataByte() != 'O');
//				while(receive_UARTDataByte() != 'K');
//					transmit_UARTDataString("AT+CMGD=3");  delay_ms(50);	transmit_UARTDataByte(0X0D);
//				while(receive_UARTDataByte() != 'O');
//				while(receive_UARTDataByte() != 'K');

		}
	

}