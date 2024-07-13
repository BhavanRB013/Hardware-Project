#include<reg51.h>
sbit seg1 = P1^0;
sbit seg2 = P1^1;
sbit seg3 = P1^2;
sbit seg4 = P1^3;
void delay();
void main(){
	P2=0x00;
	seg1=seg2=seg3=seg4=0;
	
	seg1=1;
	P2=0xF9;
	delay();
	
	seg1=0;
	seg2=1;
	P2=0xB0;
	delay();
	
	seg2=0;
	seg3=1;
	P2=0xF9;
	delay();
	
	seg3=0;seg4=1;
	P2=0x99;
	delay();
	seg4=0;
	

}
void delay(){
	unsigned int i;
	for(i=0;i<60000;i++);
}