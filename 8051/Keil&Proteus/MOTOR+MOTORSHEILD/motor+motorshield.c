#include<reg51.h>
//MOTOR CONNECTION
sbit mot1p = P1^0;
sbit mot1n = P1^1;
sbit mot2p = P1^2;
sbit mot2n = P1^3;
//SWITCH
sbit sw1 = P2^0;
sbit sw2 = P2^1;
sbit sw3 = P2^2;
sbit sw4 = P2^3;
sbit sw5 = P2^4;
//MAIN
void main(){
	mot1p=mot1n=mot2p=mot2n=0;
	while(1){
		if(sw1==0){
			mot1p = 1;
			mot1n = 0;
			mot2p = 1;
			mot2n = 0;
		}
		if(sw2==0){
			mot1p = 0;
			mot1n = 1;
			mot2p = 0;
			mot2n = 1;
		}
		if(sw3==0){
			mot1p = 0;
			mot1n = 1;
			mot2p = 1;
			mot2n = 0;
		}
		if(sw4==0){
			mot1p = 1;
			mot1n = 0;
			mot2p = 0;
			mot2n = 1;
		}
		if(sw5==0){
			mot1p = 0;
			mot1n = 0;
			mot2p = 0;
			mot2n = 0;
		}
	}
}