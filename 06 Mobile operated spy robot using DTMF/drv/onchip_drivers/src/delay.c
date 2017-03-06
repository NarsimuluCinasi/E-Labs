


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