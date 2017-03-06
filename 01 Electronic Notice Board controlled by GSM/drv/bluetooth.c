
#include <bluetooth.h>
#include <reg52.h>
#include <string.h>
#include <uart.h>

char bt_data[10];

void init_Bluetooth(void)
{
	
}

void scan_BTData(void)
{
	char i=0, data_byte=0;
	
	while(1)
	{
		data_byte = receive_UARTDataByte();	 
		
		bt_data[i]  = data_byte;

		i++;
		if(i>10)
		{
			i=0;
		}

		if (data_byte == '\r') break;
		if (data_byte == '\n') break;
		if (data_byte == '\0') break;
		if (data_byte == '#') break;
	}

	 	RI =0; RI =0;RI =0; RI =0;RI =0;   // to avoid storing junk data 

		if(i!=0) bt_data[i-1]='\0';

}

char bt_DataCompare(char *bt_db)
{
	
	if(strcmp(bt_data, bt_db) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}