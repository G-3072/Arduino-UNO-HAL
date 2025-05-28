#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>
#include <stdbool.h>
#include <gpio.h>

typedef void (*intFuncPtr)(void);

typedef enum{
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
}Interrupt_ID;

typedef enum {
    LOW = 0,
    CHANGE,
    FALLING_EDGE,
    RISING_EDGE
}EXTINT_Mode;

void INT_enableGlobalInterrupts();
void INT_disableGlobalInterrupts();

void INT_enableInterrupt(Interrupt_ID interrupt);
void INT_disableInterrupt(Interrupt_ID interrupt);

void INT_interruptAttach(Interrupt_ID interrupt, intFuncPtr Callback);
void INT_interruptDetach(Interrupt_ID interrupt);

void EXTINT_setMode(Interrupt_ID EXTINT, EXTINT_Mode mode);

void PCINT_enable(GPIO_Port *port, uint8_t pin);
void PCINT_disable(GPIO_Port *port, uint8_t pin);

#endif