#include<reg51.h>
//KEYPAD CONNECTION
sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;
sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
//LCD CONNECTION
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;
//MOTOR CONNECTION
sbit motp = P3^3;
sbit motn = P3^4;
//FUNCTION DECLARATION
void delay();
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddisplay(unsigned char *,unsigned char);
void check();
//GLOBAL VARIABLE
unsigned char p[8],x;
//MAIN
void main(){
	P2=0x00;
	lcdcmd(0x38);
	lcdcmd(0x01);
	lcdcmd(0x10);
	lcdcmd(0x0c);
	lcdcmd(0x81);
	lcddisplay("PASSWORD PROTECTION",19);
	lcdcmd(0xc0);
	lcddisplay("SYSTEM",6);
	lcdcmd(0x01);
	lcddisplay("ENTER PASSWORD",14);
	lcdcmd(0Xc0);
	while(1){
		r1=0;
		if(c1==0){
			p[x]='1';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0){
			p[x]='2';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0){
			p[x]='3';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		r1=1;r2=0;
		if(c1==0){
			p[x]='4';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0){
			p[x]='5';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0){
			p[x]='6';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		r2=1;r3=0;
		if(c1==0){
			p[x]='7';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0){
			p[x]='8';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0){
			p[x]='9';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		r3=1;r4=0;
		if(c1==0){
			p[x]='*';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0){
			p[x]='0';
			delay();delay();delay();delay();delay();delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0){
			check();
			delay();
			delay();
		}
		r4=1;
	}
}
//LCD CMD
void lcdcmd(unsigned char var){
	P2=var;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
//LCD DATA
void lcddat(unsigned char val){
	P2=val;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
//LCD DISPLAY
void lcddisplay(unsigned char *s,unsigned char r){
	unsigned char w;
	for(w=0;w<r;w++){
		lcddat(s[w]);
		delay();
	}
}
//DELAY
void delay(){
	unsigned int i,j;
	for(i=0;i<4000;i++);
	for(j=0;j<100;j++);
}
//CHECK
void check(){
	if(p[0]=='1' && p[1]=='3' && p[2]=='1' && p[3]=='2' && p[4]=='2' && p[5]=='0' && p[6]=='0' && p[7]=='4'){
		motp=1;
		motn=0;
	lcdcmd(0x01);
	lcddisplay("PASSWORD MATCHED",16);
	delay();
	}
	else{
		lcdcmd(0x01);
		lcddisplay("PASSWORD WRONG",14);
		delay();
	}
}