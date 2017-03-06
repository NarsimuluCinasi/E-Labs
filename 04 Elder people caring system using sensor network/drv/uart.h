



void uart_RxStringBuffer(char *data_buffer);

void transmit_UARTDataString(char *data_string);
void transmit_UARTDataByte(char tx_char);
void init_UART(void);
char receive_UARTDataByte(void);
char *receive_UARTDataString(void);
char *UART_RxDataString(void);