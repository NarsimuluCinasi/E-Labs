


#include <reg52.h>

unsigned int timer_count, last_count, delay_ms;


void init_TimerChannel(char timer)
{

	TMOD = 0x10;	// Timer1 mode1

	TL1 = 0xFC;
	TH1 = 0x67;
	//TR1 = 1; 	// to turn ON T1
}


void timer_update(void)
{
	 
	if( TR1 ==0) TR1 = 1;
	
	if(TF1 == 1)
	{
	  last_count = timer_count;
	  timer_count++	;
	  TF1 =0;

	}

}


char timer_DelayMs(unsigned int delay_ms, unsigned int *app_timer)
{

	
	if(delay_ms == *app_timer)
	{
			*app_delay=0; return 1;
	}
	else
	{
	   if(timer_count-lastcount == 1)
	   {
		 	*app_timer++;
	   }

	} 
		return 0;

}
