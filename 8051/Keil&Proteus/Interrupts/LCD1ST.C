#include <reg51.h>
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void MSDelay(unsigned int);

 //sfr ldata = 0X90; //P3=LCD data pins 
 sbit rs= P2^0;   // register select
 sbit rw= P2^1;   // read write
 sbit en = P2^2;  // enable 
 //sbit busy = P3^7; 
 void main(){
 lcdcmd(0x38);
	MSDelay(50);
 lcdcmd(0x0F);
	 MSDelay(50);
 lcdcmd(0x01);
	 MSDelay(50);
 lcdcmd(0x06);
	 MSDelay(50);
 lcdcmd(0xC7);
MSDelay(50);   //line 1, position 6
 lcddata('J');
MSDelay(50);	 
 lcddata('O');
	 MSDelay(50);
 lcddata('Y');
	 MSDelay(50);
 }

 void lcdcmd(unsigned char value){
 P3= value;   //put the value on the pins
 rs= 0;
 rw= 0;
 en = 1;          //strobe the enable pin
 MSDelay(1);       
en = 0;
 return;
 }
 
 void lcddata(unsigned char value){ 
 P3= value;   //put the value on the pins
 rs= 1;
 rw= 0;
 en = 1;          //strobe the enable pin
 MSDelay(1);
 en = 0;
 return;
 }
 
 void MSDelay(unsigned int itime){ 
 unsigned int i, j;
 for(i=0;i<itime;i++)
 for(j=0;j<1275;j++); 
}