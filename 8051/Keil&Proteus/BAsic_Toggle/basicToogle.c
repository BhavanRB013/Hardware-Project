#include<reg52.h>
	unsigned int a;
void main(void){
	while(1){
		P1 = 0X55;
		for(a=0;a<400;a++);
		P1 = 0xAA;
		for(a=0;a<400;a++);
	}
}