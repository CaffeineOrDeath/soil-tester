/**
 * @file interrupts.c
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "arduino/interrupts.h"

/**
 * Enable external interrupts.
 */
void irq_init(uint8_t INTs[]){
    // enable global interrupts
    sei();
}

/**
 *  Enables the respective pin of irqn and assignes a callback function to be
 *  triggered when the interrupt occurs. __VECTOR(N) can be found in interrupt.h
 *  
 *  @param irqn
 *  The N of the __VECTOR reference.
 *  @param *callback(void)
 *  The function to be executed when the interrupt is triggered.
 *  @param mode
 *  Set when the interrupt is to be triggered.
 *  Available modes are: 0=LOW, 1=RISING EDGE, 2=FALLING EDGE
 */
void irq_set(uint8_t irqn, void (*callback)(void), uint8_t mode){
    switch(irqn){
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
                    // handle invalid mode if needed
                    break;
            }
        break;
    }
}

/**
* Sets a timer
* @param irq_vector The _VECTOR being called
* @param callback Callback function before returning
*/

void irq_timer(void (*callback)(void), uint16_t compare){
        TCCR0A = (1 << WGM01); // set ctc mode
        TCCR0B = (1 << CS01) | (1 << CS00); // prescaler = 64
        OCR0A = compare;
        TIMSK0 |= (1 << OCIE0A);
}

