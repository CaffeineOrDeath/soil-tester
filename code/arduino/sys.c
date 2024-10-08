#include "arduino/sys.h"
#include "arduino/interrupts.h"

void sys_init(uint8_t arrInterrupts[]){
    // Loop through the array and initialize each INTn
    for(int i = 0; i < ((sizeof *arrInterrupts) / (sizeof arrInterrupts[0])); i++){
        // init irqs
        irq_init();
  }
}
