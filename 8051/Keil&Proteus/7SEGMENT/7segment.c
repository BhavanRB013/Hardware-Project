#include<reg52.h>
void main(){
	unsigned int i;
	unsigned int j;
	unsigned char seg[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	P1=0x00;
	while(1){
	for(j=0;j<10;j++){
		P1=seg[j];
		for(i=0;i<60000;i++);
	}
	}
}