#include<reg51.h>
sbit led1=P1^0;
sbit sw1=P2^3;
unsigned int count;

void timer0_isr(void) interrupt 1{
	count++;
}

void main(void){
	
	led1=1;
	sw1=1;
	
	TMOD=0X01;
	TH0=0X00;
	TL0=0X00;
	EA=1;
	ET0=1;
	TR0=1;
while(1){	
	if(count==845&&sw1==0){
		led1=0;
		count=0;
	}
	
}
}