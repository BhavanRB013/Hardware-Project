#include<reg51.h>
sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;

void cmd(unsigned char);
void datas(unsigned char);
void delay();

void main(){
P2=0x00;
	cmd(0x38);
	delay();
	cmd(0x01);
	delay();
	cmd(0x10);
	delay();
	cmd(0x0c);
	delay();
	cmd(0x81);
	delay();
	datas('B');
	delay();
	datas('H');
	delay();
	datas('A');
	delay();
	
	
}

void cmd(unsigned char v){
	P2=v;
	rs=0;rw=0;
	en=1;
	delay();
	en=0;
}

void datas(unsigned char val){
	P2=val;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}

void delay(){
	unsigned int i;
	for(i=0;i<1200;i++);
}