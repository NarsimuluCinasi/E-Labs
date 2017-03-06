
#include<reg52.h>
#include<delay.h>

/*Delay function is seperatly declared here */
unsigned int set_delay_temp=0;

int delay_ms(unsigned int msec)
{
unsigned int x,y;
for(x=0;x<msec;x++)
for(y=0;y<1000;y++);
return 0;
}
int delay_sec(unsigned char sec)
{

set_delay_temp = 1000*sec;
delay_ms(set_delay_temp);
return 0;
}

int delay_min(unsigned char min)
{
set_delay_temp = 60*min;
delay_sec(set_delay_temp);
return 0;
}
void delay_us(void)
{

TMOD = 0x01;
TH0 = 0xFF;
TL0 = 0xF6;
TR0 = 1;
while(TF0==0);
TR0 = 0;
TF0 = 0;

}

  void T1M1Delay(void)    // for time delay
{
  TH1=0xFF;
  TL1=0xFE;
  TR1=1;
  while(TF1==0);
  TR1=0;
  TF1=0;
}