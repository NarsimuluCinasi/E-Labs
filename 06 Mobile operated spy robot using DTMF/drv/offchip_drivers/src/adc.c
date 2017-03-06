

#include<delay.h>
#include<reg52.h>
#include<adc.h>
#define adc_data P0
sbit ALE	=P2^0;
sbit SC		=P2^1;
sbit EOC	=P2^2;
sbit OE		=P2^3;
sbit A0		=P2^4;
sbit A1		=P2^5;
sbit A2		=P2^6;

unsigned int out;

unsigned char adc_read(unsigned char a, unsigned char b, unsigned char c)

{

	A0=a;
	A1=b;
	A2=c;
	ALE=1;
	SC=1;
	ALE=0;
	SC=0;
	while(EOC==0);
	OE=1;
	out=adc_data;
	OE=0;

	out = reverse(out);
	return(out);
}

void adc_init(void)
{
	adc_data=0xff;
	ALE=0;
	SC=0;
	EOC=1;
	OE=0;
}

unsigned char reverse(unsigned char num)
{
	unsigned char i, rev = 0;

	for(i=0; i<=8;i++)
	{
		if((num&(1<<i)))
		{
			rev =rev|(1<<(8-i));
		}
	}
	
	return rev;

}