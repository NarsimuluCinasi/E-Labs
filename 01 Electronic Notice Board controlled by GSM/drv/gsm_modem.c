
#include <gsm_modem.h>
#include <reg52.h>
#include <string.h>
#include <uart.h>
#include <delay.h>

 char *sms;
 
char GSM_initModem(void)
{	   char status = 0;

		init_UART();
		status = GSM_selftest();
		GSM_sendSMS("+91966333695", "GSM TEST SMS");


		GSM_deleteSMS("1");
		GSM_deleteSMS("2");
		GSM_deleteSMS("3");


		return status;


}

char GSM_atCommandOperation(char *command, char *replay)
{		  
	char status = 0;
	  
	 transmit_UARTDataString(command);
		
	delay_ms(1);

	if(strcmp(replay,GSM_readATCommand()) == 0)
	{
			return 1;
	}
	else
	{
			return 0;
	}




}

char *GSM_readATCommand(void)
{
	  
	  
	   char cmd_buffer[20] = {0};
	   
	   	char i=0, data_byte=0;
		 while(1)
		 {

		 	data_byte = receive_UARTDataByte();	 
			cmd_buffer[i]  = data_byte;
			i++;
			if(i>20)
			{
				i=0;
			}
		   	if (data_byte == '\r') break;
			if (data_byte == '\n') break;
			if (data_byte == '\0') break;
			if (data_byte == '#') break;
		 }
			if(i!=0) cmd_buffer[i-1]='\0';


		 return cmd_buffer;
	
}

char GSM_selftest(void)
{
	char status = 0;

	status =  GSM_atCommandOperation("ATEO/r/n", "OK");
	status =  GSM_atCommandOperation("AT/r/n", "OK");
	status =  GSM_atCommandOperation("AT+CPIN?/r/n", "+CPIN:READY");
	status =  GSM_atCommandOperation("AT+CMGF=1/r/n", "OK");
		
	return status;

}

char GSM_deleteSMS(char *sms_no)
{
	char status = 0;
		
	status =  GSM_atCommandOperation("AT+CMGD=","");
	status =  GSM_atCommandOperation(sms_no,"");
	status =  GSM_atCommandOperation("/r/n","OK");

	return status;	
}

char *GSM_readSMS(char sms_no)
{
	  char i=0, data_byte=0;
	
//	if (data_byte == '\r') break;
//		if (data_byte == '\n') break;
//		if (data_byte == '\0') break;
//		if (data_byte == '#') break;


		 return sms;
	
}




char GSM_sendSMS(char *mobile_no, char *sms)
{
	char status = 0;
	status = GSM_atCommandOperation("AT+CMGS=","");
	status = GSM_atCommandOperation(mobile_no,"");
	status = GSM_atCommandOperation("/r/n",">");

	status = GSM_atCommandOperation(sms,"");
	transmit_UARTDataByte(0x1A);


			
	return status;		
}