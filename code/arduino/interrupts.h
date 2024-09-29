#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <avr/interrupt.h>
/**
 * List of available _VECTOR for m328p
 * % will signify what is used in this project
 * ? will signify possible use
 * whitespace is available for emacs/vim users
 * _VECTOR(N) __vector_ ##      (#)         Used (%/?)
 * INT0_vect _VECTOR            (1)             % 
 * INT1_vect _VECTOR            (2)             % 
 * PCINT0_vect _VECTOR          (3)             % 
 * PCINT1_vect _VECTOR          (4)             ? 
 * PCINT2_vect _VECTOR          (5)             ? 
 * WDT_vect _VECTOR             (6)             % 
 * TIMER2_COMPA_vect _VECTOR    (7)               
 * TIMER2_COMPB_vect _VECTOR    (8)               
 * TIMER2_OVF_vect _VECTOR      (9)               
 * TIMER1_CAPT_vect _VECTOR     (10)              
 * TIMER1_COMPA_vect _VECTOR    (11)              
 * TIMER1_COMPB_vect _VECTOR    (12)              
 * TIMER1_OVF_vect _VECTOR      (13)              
 * TIMER0_COMPA_vect _VECTOR    (14)              
 * TIMER0_COMPB_vect _VECTOR    (15)              
 * TIMER0_OVF_vect _VECTOR      (16)              
 * SPI_STC_vect _VECTOR         (17)              
 * USART_RX_vect _VECTOR        (18)             
 * USART_UDRE_vect _VECTOR      (19)             
 * USART_TX_vect _VECTOR        (20)             
 * ADC_vect _VECTOR             (21)              
 * EE_READY_vect _VECTOR        (22)            ?  
 * ANALOG_COMP_vect _VECTOR     (23)            % 
 * TWI_vect _VECTOR             (24)              
 * SPM_READY_vect _VECTOR       (25)            % 
 * _VECTORS_SIZE              (26 * 4)
 */

/**
 *  void irq_set()
 *
 *  irq_set will assign the correct bit to the correct register.
 *  Example:
 *  irq_set(23) will set ISER |= (1 << 8)
 */
void irq_set(unsigned int irqn);
/**
* (void*) irq_handler()
*
* irq_handler will be passed when certain parts of the circuit are activated.
* For example, using a contact switch. When it is depressed it will activate a
* pin. When that pin is activted, it will send an IRQ to stop the current
* process and return with a callback function.
* @param (void*) irq_vector The _VECTOR being called
* @param (void*) callback Callback function before returning
*/
(void*) irq_handler((void*) irq_vector, (void*) callback);
#endif
