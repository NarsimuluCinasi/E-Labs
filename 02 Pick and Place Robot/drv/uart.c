
#include<reg52.h>
#include <uart.h>

char uart_rxbuffer[50];
char uart_rxbufferold[50];
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
		
		transmit_UARTDataByte('\0');
		
}


char receive_UARTDataByte(void)
{
	char data_rec=0;
	
	while(RI==0);
	data_rec=SBUF;
	RI=0;
	return data_rec;
	
}

char* receive_UARTDataString(void)
{
	char data_byte=0, i=0;
	do
	{
			data_byte = receive_UARTDataByte();	
			uart_rxbuffer[i] = data_byte;
			i++;
		
	}while(data_byte != '\0');

	return uart_rxbuffer;	
	
}

char *UART_RxDataString(void)
{
	return uart_rxbuffer;
}

