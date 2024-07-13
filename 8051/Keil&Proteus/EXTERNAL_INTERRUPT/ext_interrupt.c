#include <reg51.h>
sbit a = P3^0;
unsigned int i;

// Define interrupt service routines
void external_interrupt_0() interrupt 0 {
    P1 = ~P1; // Toggle all bits of Port 1
}

void external_interrupt_1() interrupt 2 {
    P2 = ~P2; // Toggle all bits of Port 2
}

// Function to initialize external interrupts
void init_external_interrupts() {
    // Enable external interrupts INT0 and INT1
    IE = 0x85; // Enable EX0 and EX1 and global interrupt enable

    // Configure INT0 and INT1 for falling edge triggered
    TCON = 0x05; // IT0 = 1, IT1 = 1
}

void main() {
    P1 = 0x00; // Initialize Port 1 to 0
    P2 = 0x00; // Initialize Port 2 to 0
    init_external_interrupts(); // Initialize external interrupts

    while (1) {
        // Main loop
			
			a=0;
			for(i=0;i<19999;i++);
			a=1;
			for(i=0;i<19999;i++);
    }
}