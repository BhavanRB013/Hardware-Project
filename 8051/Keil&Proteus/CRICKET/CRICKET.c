#include<reg51.h>

void lcdcmd(unsigned char);
void msdelay(unsigned int);
void lcdstring(unsigned char*);
void lcddata(unsigned char);

sbit sw1=P1^0;//declaration of P1 0 bit
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

unsigned int count_of_press;

void timer0_isr(void) interrupt 1{
	
}

//------------------------------------------------
void main(void){//main function
		
		sw1=1;//switch as input
	
		TMOD = 0x01;
		TH0 = 0X00;
		TL0 = 0X00;
		EA = 1;
		ET0 = 1;
	
		lcdcmd(0X38);//5x7 matrix
		msdelay(5);//give delay 5ms
		lcdcmd(0x0C);//display on cursor blinking off
		msdelay(5);
		lcdcmd(0x80);//to first line and first col of lcd
		msdelay(5);
	
		lcdstring("Cricket game");//to print on lcd
	
		while(1){
			if(sw1==0){//first time pressed
				count_of_press+=1;
				if(count_of_press == 1){
					lcdcmd(0X01);//clear screen
					lcdcmd(0X80);
					lcdstring("Game started");
					msdelay(5);
					lcdcmd(0X01);
					lcdstring("1st over: ");
				}
				
			}
			
			if(count_of_press==2){//check more time sw1 pressed 3rd time
					lcdcmd(0X80);
					lcdstring("2nd over: ");
					
			}
			
			if(count_of_press==3){//check more time sw1 pressed 4th time
					lcdcmd(0X80);
					lcdstring("3rd over: ");
					
			}
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