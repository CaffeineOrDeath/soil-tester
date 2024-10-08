#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include "arduino/interrupts.h"
#include "arduino/log.h"

void irq_init(){
    sei();
}

void irq_set(uint8_t irqn, void (*callback)(void), uint8_t mode){
    switch(irqn){
        // TODO: Add all IRQs
        case 0:
            EIMSK |= _BV(1 << INT0);
            switch(mode){
                // low
                case 0:
                    EICRA &= ~_BV((1 << ISC00) | (1 << ISC01));
                    break;
                // rising edge
                case 1:
                    EICRA = _BV(EICRA & ~(1 << ISC01) | (1 << ISC00));
                    break;
                // falling edge
                case 2:
                    EICRA = _BV(EICRA & ~(1 << ISC00) | (1 << ISC01));
                    break;
                default:
                    // TODO: Add logging of invalid mode
                    return; // exit function if invalid mode
                // If invalid mode, exit program
                }
            break;
        case 1:
            EIMSK |= _BV(1 << INT1);
            switch(mode){
                // low
                case 0:
                    EICRA &= ~_BV((1 << ISC00) | (1 << ISC01));
                    break;
                // rising edge
                case 1:
                    EICRA = _BV(EICRA & ~(1 << ISC01) | (1 << ISC00));
                    break;
                // falling edge
                case 2:
                    EICRA = _BV(EICRA & ~(1 << ISC00) | (1 << ISC01));
                    break;
                default:
                    // TODO: Add logging of invalid mode
                    return; // exit function if invalid mode
                // If invalid mode, exit program
                }
            break;

        default:
            break;
    }
}

void irq_timer(void (*callback)(void), uint16_t compare){
        TCCR0A = (1 << WGM01); // set ctc mode
        TCCR0B = (1 << CS01) | (1 << CS00); // prescaler = 64
        OCR0A = compare;
        TIMSK0 |= (1 << OCIE0A);
}

// if an interrupt is triggered on a pin that should not have been an interrupt
// this will log it and return. 
ISR(BADISR_vect){
    // TODO: Add logging of bad IRQ
    reti();
}

