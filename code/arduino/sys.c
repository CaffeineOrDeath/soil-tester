#include "sys.h"
#include "interrupts.h"

void sys_init(int arrInterrupts[]){
  // Loop through the array and initialize each INTn
  for(int i = 0; i < sizeof(arrInterrupts)/sizeof(arrInterrupts[0]); i++){
    irq_init(arrInterrupts[i]);
  }
}
