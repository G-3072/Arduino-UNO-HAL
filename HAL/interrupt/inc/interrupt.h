#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

enum InterruptNum{
    INT0 = 0,
    INT1,
    PCINT0,
    PCINT1,
    PCINT2,
    WDT,
    TIM2_COMPA,
    TIM2_COMPB,
    TIM2_OVF,
    TIM1_CAPT,
    TIM1_COMPA,
    TIM1_COMPB,
    TIM1_OVF,
    TIM0_COMPA,
    TIM0_COMPB,
    TIM0_OVF,
    SPI_STC,
    USART_RX,
    USART_UDRE,
    USART_TX,
    ADCINT,
    EE_READY,
    AN_COMP,
    TWI,
    SPM_READY
};

typedef enum{
    LOW = 0,
    CHANGE,
    FALLING_EDGE,
    RISING_EDGE
} extINTsenseMode;
void INT_enableGlobalInterrupts();
void INT_disableGlobalInterrupts();

void INT_enable(uint8_t interrupt);
void INT_disable(uint8_t interrupt);

void INT_setISR(uint8_t interrupt, void (*function)(void));

#endif