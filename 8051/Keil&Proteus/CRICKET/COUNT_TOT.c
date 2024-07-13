#include<reg51.h>
#include<stdio.h>

void lcdcmd(unsigned char);
void msdelay(unsigned int);
void lcdstring(unsigned char*);
void lcddata(unsigned char);
void lcdnumber(unsigned int);

unsigned char runs[] = {'0','1','2','3','4','6'};//array for cricket runs
unsigned int i,count_of_balls;
unsigned char j;

sbit sw2 = P1^3;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void timer0_isr(void) interrupt 1{
	if(sw2==0){
		lcdcmd(0xCB);
		lcddata(j);
		
	}
}

//------------------------------------------------
void main(void){//main function
		sw2 = 1;
	
		TMOD = 0x01;
		TH0 = 0X00;
		TL0 = 0X00;
		EA = 1;
		ET0 = 1;
	
		lcdcmd(0x38);
		msdelay(5);
		lcdcmd(0x0C);
		msdelay(5);
		lcdcmd(0x80);
	
		lcdstring("1st over");
	
		while(1){
			
				for(i=0;i<6;i++){						
					TR0=1;				
					j=runs[i];
						if(i>5){
							i=0;
						}
				}
			
			/*else{
				lcdcmd(0x01);
				lcdcmd(0x0E);
				lcdcmd(0x80);
				lcdstring("Match over");
			}*/
			
			
			
		}
		
}
//---------------------------------------------------
void lcdcmd(unsigned char hexacode){//declaration for cmds 
	P3=hexacode;
	rs=0;
	rw=0;
	en=1;
	msdelay(1);
	en=0;
}

void lcddata(unsigned char value){//declaration for data to print
	P3=value;
	rs=1;
	rw=0;
	en=1;
	msdelay(1);
	en=0;
}

void lcdstring(unsigned char *str){//using pointer to send string as char
	while(*str){//checking if the str is null or not
		lcddata(*str++);
		msdelay(10);
	}
}

void msdelay(unsigned int time){
		unsigned int i,j;
		for(i=0;i<time;i++)
		for(j=0;j<1275;j++);
}

void lcdnumber(unsigned int x){
	char buffer[10];
	sprintf(buffer,"%d",x);
	lcdstring(buffer);
}