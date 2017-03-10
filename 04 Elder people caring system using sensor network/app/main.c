
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>
#include<adc.h>

#define IN 1
#define OUT 0
#define OFF 0
#define ON 1

sbit BUZZER = P1^0;
sbit BIKE = P1^1;

unsigned char  alchohal = 0;



/*Program in AT89S52 will starts executes from here */




void Main()
{


	init_lcd();
	adc_init();
	lcd_clear();
	BUZZER = OUT;
	M0 = OUT;

	
	BUZZER = OFF;
	M0 = OFF;

	gotoxy_lcd(1, 1);
	print_lcd("Helmet For Raod");

	
	delay_sec(1);
	lcd_clear();
	delay_ms(250);
	BUZZER = OFF;
	M0 = OFF;
	gotoxy_lcd(1, 1);
	print_lcd("SMOKE:   PPM");
	gotoxy_lcd(1, 2);
	print_lcd("BUZZER:");
	
	
	while(1)
	{
		
		
		smoke = adc_read(0,0,0);
		
		gotoxy_lcd(7, 1);
		print_num_lcd(smoke);
		
		if(smoke>80 || SMK==1)
		{
			
			BUZZER = ON; 
			M0 = ON;
			gotoxy_lcd(8, 2);
			print_lcd("ON ");
			delay_ms(250);
			
		}
		else
		{
			BUZZER = OFF;
			M0 = OFF;
				gotoxy_lcd(8, 2);
				print_lcd("OFF");
		}
   }

}