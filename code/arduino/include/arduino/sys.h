#ifndef SYS_H
#define SYS_H

#include <stdint.h>
/**
 * sys_init
 *
 * This is basic system initialization function. It will initialize the other
 * systems as well make the irq_init() call.
 *
 * @param arrInterrupts
 * An array of PINx
 */
void sys_init(uint8_t arrInterrupts[]);

#endif
