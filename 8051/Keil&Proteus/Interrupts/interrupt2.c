#include<reg52.h>

#define unit unsigned int
#define uchar unsigned char

unsigned int i;

sbit SW1   =P3^7;
sbit SW2 = P3^6; 
sbit IND  =P3^4; 
sbit WAVE =P3^5; 

unsigned int tim0,tim1;

void timer0(void) interrupt 1 
{ 
WAVE=1;
tim0++;
 } 

 void timer1(void) interrupt 3 
{ 
IND=1;
tim1++;
 } 

 
 void main() 
 {
 
 SW1=1;
 SW2=1;
 WAVE=0;
 IND=0;
	 
	 TMOD = 0X11;
	 TL0 = 0X00;
	 TH0 = 0X00;
	 TL1 = 0X00;
	 TH1 = 0X00;
	 IE = 0X8A;
 	
 while (1) 
 { 	
   if(SW1 == 0){
		 TR0=1;
	 }
	 if(tim0 == 1000){
		tim0=0;
		 WAVE =0;
		 		TR0=0;
	 }
		` 
	 if(SW2 == 0){
		TR1=1;
		 
	 }
	 if(tim1==2000){
		 tim1=0;
		 IND =0;
		 TR1=0;
	 }
		 
		 
 }
 }