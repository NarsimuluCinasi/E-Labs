
#include<reg52.h>
#include <uart.h>

void init_UART(void)
{
	TMOD=0x20; // Timer 1 8 bit auto reload mode
	TH1=0xFD; // Baud rate 9600
	SCON=0x50;
	TR1=1;
	
}

void transmit_UARTDataByte(char tx_char)
{ 
		SBUF	=	tx_char;
		while(TI==0);
		TI=0;
}

void transmit_UARTDataString(char *data_string)
{
	
		while(*data_string != '\0')
		{
			transmit_UARTDataByte(*data_string);	
			data_string++;
		}
		
		//transmit_UARTDataByte('\0');	// Biggest Mistake I Did :CN
		
}


char receive_UARTDataByte(void)
{
	char data_rec=0;
	
	while(RI==0);
	data_rec=SBUF;
	RI=0;
	return data_rec;
	
}

