#include <gpio.h>
#include <uart.h>
#include <timer.h>
#include <interrupt.h>
#include <util/delay.h>

void tim1_ovf_isr(void);

void main(void){

    // INT_enableGlobalInterrupts();
    // INT_enable(TIM2_OVF);
    // INT_setISR(TIM2_OVF, tim1_ovf_isr);

    GPIO_setPinMode(GPIOB, 0, OUTPUT);

    // TIMER_init(TIM2, 8);
    while(1){
        // PINB = (1<<0);
        // _delay_us(1);
        GPIO_togglePin(GPIOB, 0);
    }
}

void tim1_ovf_isr(void){
    PINB = (1<<0);
}
