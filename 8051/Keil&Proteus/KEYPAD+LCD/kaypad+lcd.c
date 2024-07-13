include<reg51.h>
//KEYPAD
sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;
sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
//LCD
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;
sfr lcd = 0xa0;
//USER-DEFINED FUNC
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void delay1();
//MAIN FUNC
void main(){
	lcdcmd(0x38);
	delay();
	lcdcmd(0x01);
	delay();
	lcdcmd(0x0c);
	delay();
	lcdcmd(0x06);
	delay();
	lcdcmd(0x81);
	delay();
	while(1){
		r1=0;
			if(c1==0){lcddat('1');delay();delay1();}
			if(c2==0){lcddat('2');delay();delay1();}
			if(c3==0){lcddat('3');delay();delay1();}
		r1=1;
		r2=0;
			if(c1==0){lcddat('4');delay();delay1();}
			if(c2==0){lcddat('5');delay();delay1();}
			if(c3==0){lcddat('6');delay();delay1();}
		r2=1;
		r3=0;
			if(c1==0){lcddat('7');delay();delay1();}
			if(c2==0){lcddat('8');delay();delay1();}
			if(c3==0){lcddat('9');delay();delay1();}
		r3=1;
		r4=0;
			if(c1==0){lcddat('*');delay();delay1();}
			if(c2==0){lcddat('0');delay();delay1();}
			if(c3==0){lcddat('#');delay();delay1();}
		r4=1;
		
	}
}
void lcdcmd(unsigned char val){
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char v){
	P2=v;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void delay(){
	unsigned int i;
	for(i=0;i<10000;i++);
}
void delay1(){
	unsigned int j,k;
	for(j=0;j<200;j++)
	for(k=0;k<2000;k++);
}