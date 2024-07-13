#include<reg51.h>
sbit motpo=P1^0;
sbit motneg=P1^1;

void main()
{
	unsigned int i;
	motpo=motneg=0;
	
	while(1){
		
		motpo=1;
		motneg=0;
		for(i=0;i<60000;i++);
	
		motpo=0;
		motneg=1;
		for(i=0;i<60000;i++);
	}
}