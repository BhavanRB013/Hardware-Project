#include <reg51.h>

void T0Delay(void);
 
void main(void){
	
 while (1) {
 P1=0x55;

 T0Delay();

 P1=0xAA;

 T0Delay();

 }
}
void T0Delay(){
unsigned int i;
	for(i=0;i<42;i++){
	
 TMOD=0x01;
 TL0=0x00;
 TH0=0x00;
 TR0=1;
 while (TF0==0);
 TR0=0;
 TF0=0;
	}	
}