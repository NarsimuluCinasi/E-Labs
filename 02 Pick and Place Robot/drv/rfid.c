
#include <rfid.h>
#include <string.h>
#include <uart.h>
#include <stdio.h>
#include <reg52.h>
#include <delay.h>

char rfid_data[12];

void load_InitRFID(void)
{
	
}
void scan_RFID(void)
{
	char i;
	RI=0;delay_ms(1); RI=0;RI=0;RI=0;delay_ms(1);RI=0;
	for(i=0;i<=12;i++)
	{
		rfid_data[i]= receive_UARTDataByte();
	}
	rfid_data[12]='\0';
}


char rfid_compare(char *rfid_db)
{
	
	if(strcmp(rfid_db, rfid_data) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}