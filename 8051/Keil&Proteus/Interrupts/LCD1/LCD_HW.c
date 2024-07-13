#include<reg51.h>

sbit rs = P2^0;
sbit rw = P2^1;
sbit en = P2^2;

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcdstring(unsigned char*);

void msdelay(unsigned int); 

void main(){
	lcdcmd(0x38);
	msdelay(5);
	lcdcmd(0x0C);
	msdelay(5);
	lcdcmd(0x0E);
	msdelay(5);
	lcdcmd(0x01);
	msdelay(5);
	lcdcmd(0x80);
	msdelay(5);
	
	lcdstring("BHAVAN RB");
}

void lcdcmd(unsigned char cmd){
	P3 = cmd;
	rs = 0;
	rw = 0;
	en = 1;
	msdelay(1);
	en=0;
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
		msdelay(50);
	}
	
}

void msdelay(unsigned int ui){
	unsigned int i,j;
	for(i=0;i<ui;i++)
	for(j=0;j<1275;j++);
}