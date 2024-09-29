# Ardunio
This directory contains all of the system code. Considering this is 8 bit
(extremely limited), I'm planning on this for being a dev board with the
potential to upgrade to a STM32 Nucleo board (already have) which 32 bits.
However, at this time, using 8 bit for testing, is probably the simplest
solution.

## Needed
I'm going to try to keep this in order as it needs to be called. This will
allow for  continuous development.

### TIMER
This is necessary for 2 BIG reasons. 
1. Race conditions which can become a problem once we get to the 32 bit system.
2. Once this progresses far enough, setting the time it needs to go deep enough,
   can be done manually. 

Alternatively, we can use photo-optics to read marks on the tube to measure
the depth. 

System Clock (SCK) is located in Port B, PIN 5.


### RESET
AVR recommends a system reset after the clock is started. This is to ensure the
clock is stable and accurate. 

### EEPROM
Unsure if this will be needed as no write commands are planned at this time.

### INTERRUPTS
This will be necessary as it will manage when specific actions occur. For
example, when the tube reaches the required depth, an interrup can be triggered
to make sure it comes to a halt and does not continue driving it down.
Potentially, a trigger switch may solve this as it would require a single IO pin
to check for depression.
