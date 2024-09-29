#include <avr/interrupt.h>
#include <util/atomic.h>
#include "interrupts.h"

void irq_set(unsigned int irqn){

}

void *irq_handle((void*) irq_vector, (void*) callback(void)){
    // make sure its atomic  
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        /* handle interrupt */
    }
    // return SP to before interrupt
    reti();
}
