#ifndef INTERRUPTS_H
#define INTERRUPTS_H

/**
 * List of available _VECTOR for m328p  
 * % will signify what is used in this project  
 * ? will signify possible use  
 * whitespace is available for emacs/[n]vim users if you choose to use this repo as
 * a starting point
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

void irq_init(unsigned int INTs);
void irq_set(uint8_t irqn, void (*callback)(void), uint8_t mode);
void irq_timer(void (*callback)(void), uint16_t compare);
#endif
