void delay_lcd(void);
void init_lcd(void);
void lcd_clear(void);
void putc_lcd(unsigned char byte);
void print_lcd(char String[]);
void write_lcd(unsigned char Val);
void write_nibble_lcd(unsigned char Val);
void gotoxy_lcd(unsigned char col,unsigned char line);
void print_num_lcd(int num);