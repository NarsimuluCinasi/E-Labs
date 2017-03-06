

#include<delay.h>
#include<reg52.h>
#include<adc.h>


#define adc_data P0
#define ADC_CONTROL P2

sbit ALE	=P2^3;
sbit SC		=P2^6;
sbit EOC	=P2^4;
sbit OE		=P2^5;

sbit A0		=P2^0;
sbit A1		=P2^1;
sbit A2		=P2^2;


void adc_0808ClockInit()
{
	
}

void adc_0808Init(void)
{
	adc_data=0xff;
	ALE=0;
	SC=0;
	EOC=1;
	OE=0;
}

unsigned char adc_0808GetChannelData(unsigned char adc_channel)
{
	unsigned int out=0;
//	A0=a;
//	A1=b;
//	A2=c;

	 P2 |= (0x07 & adc_channel);


	ALE=1;
	SC=1;
	ALE=0;
	SC=0;
	while(EOC==0);
	OE=1;
	out=adc_data;
	OE=0;
	return out;
}





