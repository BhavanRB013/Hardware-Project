#include<reg51.h>

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcdstring(unsigned char*);
void msdelay(unsigned int);

sbit rs = P2^0;
sbit rw = P2^1;
sbit en = P2^2;

sbit sw1 = P2^3;
sbit sw2 = P2^4;

sbit led1 = P1^0;
sbit led2 = P1^1;

unsigned int count,signal_led1,signal_led2;

void timer0_isr(void) interrupt 1{
	count++;
	if(signal_led1==1 && count==845){
		led1=~led1;
		count=0;
	}
	else if(signal_led2==1 && count == 1690){
a		led2=~led2;
		count=0;
	}
}

void main(void){
	
	sw1,sw2 = 1;
	led1, led2 = 0;
	
	lcdcmd(0x38);
	msdelay(5);
	lcdcmd(0x0C);
	msdelay(5);
	lcdcmd(0x80);
	msdelay(5);
	lcdcmd(0x01);
	msdelay(5);
	
	lcdstring("waiting for input...");
	
	TMOD = 0X01;
	TH0 = 0X00;
	TL0 = 0X00;
	EA = 1;
	ET0 = 1;
	
	if(sw1 == 0){
		signal_led1 = 1;
		//led1 = 1;
		TR0 = 1;
		lcdcmd(0X01);
		msdelay(50);
		lcdcmd(0X80);
		msdelay(50);
		lcdstring("LED blinking for: ");
		lcdcmd(0XC0);
		lcdstring("60 seconds");		
		
	}
	if(sw2 == 0){
		signal_led2 = 1;
		//led2 = 1;
		TR0 = 1;
		lcdcmd(0X01);
		msdelay(50);
		lcdcmd(0X80);
		msdelay(50);
		lcdstring("LED blinking for: ");
		lcdcmd(0XC0);
		lcdstring("120 seconds");
		
	}
	
	
	
}


void lcdcmd(unsigned char cmd){
	P1 = cmd;
	rs = 0;
	rw = 0;
	en = 1;
	msdelay(1);
	en = 0;
}


void lcddata(unsigned char value){
	P1 = value;
	rs = 1;
	rw = 0;
	en = 1;
	msdelay(1);
	en = 0;
}

void lcdstring(unsigned char *str){
	while(*str){
		lcddata(*str++);
		msdelay(50);
	}
}

void msdelay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}