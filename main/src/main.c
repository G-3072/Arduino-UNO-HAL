#include <gpio.h>
#include <uart.h>
#include <timer.h>
#include <util/delay.h>

void main(void){
    UART_setBaudRate(57600);
    UART_setCharachterSize(8);
    UART_setParity(DISABLED_PARITY);
    UART_setStopBit(1);
    UART_enable();

    GPIO_setPinMode(GPIOB, 0, OUTPUT);

    TIMER_init(TIM1, 64);
    volatile uint8_t ovf_cnt = 0x80;
    while(1){
        // if(TIMER1_getValue(TIM1) >= 50000){
        //     ovf_cnt ++;
        //     UART_send(ovf_cnt);
        //     if (ovf_cnt >= 5){
        //         GPIO_togglePin(GPIOB, 0);
        //         ovf_cnt = 0;
        //     }
        // }
        UART_send(ovf_cnt);
        _delay_ms(500);

    }
}