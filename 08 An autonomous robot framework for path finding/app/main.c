
/*Defining all Header files */

#include<reg52.h>
#include<lcd4bit.h>
#include<delay.h>

#include <motor_control.h>

    

sfr16 DPTR =0x82;
sbit trig=P3^5;                    // conect with trigger pin
sbit echo=P3^2;                // connect with echo pin

#define IN 1
#define OUT 0

#define OFF 0
#define ON 1

sbit BUZZER = P0^1;
sbit M00 = P0^4;
sbit M01 = P0^5;
sbit M10 = P0^6;
sbit M11 = P0^7;

unsigned int a,b;
unsigned int dis=0;



/*Program in AT89S52 will starts executes from here */




void Main()
{

	BUZZER = OUT;


		bot_Init();
	lcd_clear();

	gotoxy_lcd(1, 1);
	print_lcd("Autonomous Robot");
	gotoxy_lcd(1, 2);
	print_lcd("For Path Finding");
	
	delay_sec(1);
	lcd_clear();

	
	BUZZER = OFF;
	init_lcd();
	gotoxy_lcd(1, 1);
	print_lcd("OBSTACLE ROBOT ");
	
	delay_sec(1);
	
	
	
	while(1)
	{
		   TMOD=0x19; 
    {
    TH0=0;
    TL0=0;
    TR0=1;                    // T0 intiallization 

    for(b=0; b<6000; b++)
	{
     T1M1Delay();
	}
           
	trig=1;

	for(a=0; a<10; a++)
	{
    T1M1Delay();
	}

	trig=0;

    while(INT0==0);
    while(INT0==1);      // when echo pin recieve the echo sound or reflacted sound T0 will be stop

       
    DPH=TH0;				 // shifting the value of TH0 in DPH
    DPL=TL0; 				// shifting the value of TH0 in DPL
       
 	if(DPTR<35000)		   //actually you need to use 38000 but the sensor may not work at higher levels 
	 {
	 	dis=DPTR/64;        	  // for meausring distance in cm, where rfl is actual distance from the sensor 
   	 }

		  if(dis<30)
		  {

		  	BUZZER = ON;


			M00 = ON;
			M01 = OFF;
			M10 = OFF;
			M11 = OFF;

			gotoxy_lcd(1, 2);
			print_lcd("OBSTECLE DETECTED");
			delay_ms(250);
	   	  }
		  else
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

		TR0=0;
		TF0=0;
		
	
	}


}
}





