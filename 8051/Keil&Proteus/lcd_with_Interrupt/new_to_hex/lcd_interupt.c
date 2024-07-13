#include<reg51.h>
#include<stdio.h>

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcddataint(unsigned int);
void lcdstring(unsigned char*);
void msdelay(unsigned int);
void lcdnumber(unsigned int);

sbit rs = P2^0;
sbit rw = P2^1;
sbit en = P2^2;

sbit sw1 = P2^3;
sbit sw2 = P2^4;

sbit led1 = P1^0;
sbit led2 = P1^4;

unsigned int count0,count1,sec0,sec1;
unsigned int i=1,j=1;

void timer0_isr(void) interrupt 1{
	count0++;
	sec0++;
	
}
void timer1_isr(void) interrupt 3{
	count1++;
	sec1++;
	
}

void main(void){
	
	sw1=1;
	sw2=1;
	led1=0;
	led2=0;
	
	TMOD = 0X11;//0001 0001 mode 1 = 16bit
	TH0 = 0X00;
	TL0 = 0X00;
	TH1 = 0X00;
	TL1 = 0X00;
	IE = 0X8A;
	
	lcdcmd(0x38);
	msdelay(5);
	lcdcmd(0x01);
	msdelay(5);
	lcdcmd(0x0C);
	msdelay(5);
	lcdcmd(0x80);
	msdelay(5);
	
	
	lcdstring("waiting..");
	lcdcmd(0X01);
	lcdcmd(0x80);
	lcdstring("LED1 BLINK:");
	lcdcmd(0xc0);
	lcdstring("LED2 BLINK:");
	
	
while(1){	
	if(sw1 == 0){
		led1 = 1;	
		TR0 = 1;		
}
	if(sec0==14){
		lcdcmd(0X8C);
		sec0=0;		
		if(i<=60){
			lcdcmd(0x8C);
			lcdnumber(i++);
		}
		else{
			i=1;
			lcdcmd(0X8D);
			lcddata(' ');
		}
		
}

	if(count0==845){		
		led1=0;			
		count0=0;
		TR0 = 0;
	}
	
	
if(sw2 == 0){
		led2 = 1;		
		TR1=1;
}

if(sec1==14){
		lcdcmd(0XCC);
		sec1=0;
	if(j<=120){
		lcdcmd(0XCC);
		lcdnumber(j++);
	}else{
			j=1;
		lcdcmd(0XCD);
		lcddata(' ');
		lcdcmd(0XCE);
		lcddata(' ');
		}
		
}

if(count1 == 1690){
		
		led2=0;
		count1=0;
		TR1=0;
	}	
}

}

void lcdcmd(unsigned char cmd){
	P3 = cmd;
	rs = 0;
	rw = 0;
	en = 1;
	msdelay(1);
	en = 0;
}


void lcddata(unsigned char value){
	P3 = value;
	rs = 1;
	rw = 0;
	en = 1;
	msdelay(1);
	en = 0;
}


void lcdstring(unsigned char *str){
	while(*str){
		lcddata(*str++);
		msdelay(5);
	}
}

void msdelay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}

void lcdnumber(unsigned int x){
		char buffer[10];
		sprintf(buffer,"%d",x);
		lcdstring(buffer);
}