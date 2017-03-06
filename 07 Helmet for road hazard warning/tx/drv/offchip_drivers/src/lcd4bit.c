

#include<reg52.h>

#define LCD_Port P1
#define High 1
#define Low 0

static lcd_timer;

sbit RS = P1^0;
sbit En = P1^1;
sbit D0 = P1^4;
sbit D1 = P1^5;
sbit D2 = P1^6;
sbit D3 = P1^7;

void delay_lcd (void)
{
	int del1,del2;
  	for(del1=0;del1<10;del1++)
  	{		    
    	for(del2=0;del2<200;del2++);
  	}
}


void write_nibble_lcd(unsigned char Val)
{
	En = High;
	D0 = D1 = D2 = D3 = 0;
	if(Val & 0x01)
		D0 = 1;
	if(Val & 0x02)
		D1 = 1;
	if(Val & 0x04)
		D2 = 1;
	if(Val & 0x08)
		D3 = 1;
	En = Low;
}


void write_lcd(unsigned char Val)
{
	write_nibble_lcd(Val >> 4);
	write_nibble_lcd(Val);
	delay_lcd();
}



void lcd_clear(void)
{
RS = Low;
write_lcd(0x01);
write_lcd(0x01);
delay_lcd();delay_lcd();

}



void init_lcd(void)
{
  RS = Low;
  write_nibble_lcd(0x03);	delay_lcd();
  write_nibble_lcd(0x03);	delay_lcd();
  write_nibble_lcd(0x02);	delay_lcd();
  write_lcd(0x28);
  write_lcd(0x06);
  write_lcd(0x0c);
  write_lcd(0x01);
 
} 

 

void gotoxy_lcd(unsigned char col,unsigned char line)
{
	RS = Low;
	if (line == 1)
		write_lcd(0x7f+col);
	if (line == 2)
		write_lcd(0xbf+col);
}



void putc_lcd(unsigned char byte)
{
   RS = High;
   write_lcd(byte);
}

void print_lcd(char String[])
{
	int i = 0;
	do
   	{
		putc_lcd(String[i]);
		
    	i++;
	}
	while(String[i] != '\0');
}



void print_num_lcd(int num)
{
	unsigned int temp;
	temp = num/10;
	putc_lcd(((num/100) + 0x30));
	putc_lcd(((temp%10) + 0x30));
	putc_lcd(((num%10) + 0x30));
}





