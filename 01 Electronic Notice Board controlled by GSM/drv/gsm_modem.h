

 char GSM_initModem(void);

 
char GSM_atCommandOperation(char *command, char *replay);
char GSM_selftest(void);
char *GSM_readSMS(char sms_no);
char GSM_sendSMS(char *mobile_no, char *sms);
char *GSM_readATCommand(void);
char GSM_deleteSMS(char *sms_no);