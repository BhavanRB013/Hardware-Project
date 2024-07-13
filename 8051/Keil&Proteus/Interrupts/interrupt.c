#include <reg51.h>  // Include the 8051 register definitions
unsigned int count;
sbit led1=P2^1;

// Define the interrupt service routine for Timer 0
void timer0_ISR(void) interrupt 1 {
    TH0 = 0x00;  // Reload high byte for 1ms delay
    TL0 = 0x00;  // Reload low byte for 1ms delay
			
	count++;
      // Toggle the state of Port 1
}

void main(void) {
    IE = 0x82;    // Enable Timer 0 interrupt (ET0) and global interrupt (EA)
		TMOD = 0x01;  // Set Timer 0 in mode 1 (16-bit timer mode)
    TH0 = 0x00;  // Reload high byte for 1ms delay
    TL0 = 0x00;
    TR0 = 1;      // Start Timer 0
		
    while (1) {
        // Main loop can perform other tasks
			if(count==43){
				led1 = ~led1;
				P1 = ~P1;
			count=0;
			}
    }
}