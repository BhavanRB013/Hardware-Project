#include<reg51.h>

sbit led1 = P2^0;
unsigned int i;



void timer0_isr(void) interrupt 1{
	if(i==845){
			led1=~led1;
			i=0;
		}
	i++;
}

void main(void){
	led1 = 0;
	TMOD = 0X11;

	TR0 = 1;
	EA  = 1;
	ET0 = 1;
	
	while(1);
		
	
}












/*generate interrupt 50ms to blink at P0.0
Use timer 0 interrupt and tmer 1 mode 1

50000/1.085 = 46.0829
65535-46.0829 = 19453
4BFD*/