#define __AVR_ATMEGA328P__
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>

#include "arduino/sys.h"
#include "arduino/log.h"

int main(void){
    
    /* *
    * Since we need the reset pin, PC6 is unavailable. Reset also means we need the
    * SREG reference to handle the interrupt.
    * */
    uint8_t sreg = SREG;
    // check SREG value for BIT7 (global INT)
    dlog_wrap("SREG: %d", sreg);
    // define INT pins {PIN32}, INT1 is PIN1
    uint8_t irq_list[] = {INT0};
    sys_init(irq_list);
    DDRB |= (1 << 5);
    while(1){
        PORTB |= (1 << 5);
        _delay_ms(500);
        PORTB &= ~(1 << 5);
        _delay_ms(500);
    };

    return 0;
}
