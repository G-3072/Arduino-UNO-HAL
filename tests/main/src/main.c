#include <gpio.h>
#include <timer.h>
#include <interrupt.h>
#include <registers.h>

void timOvf(void);

void main(void){
    
    GPIO_setPinMode(GPIOB, 0, OUTPUT);

    TIMER_init(TIMER2, TIMER_NORMAL_MODE, 1);

    INT_enableGlobalInterrupts();
    INT_enableInterrupt(TIM2_OVF);
    INT_interruptAttach(TIM2_OVF, timOvf);


    while(1){
        
    }
}

void timOvf(void){
    PINB |= (1<<0);
}
