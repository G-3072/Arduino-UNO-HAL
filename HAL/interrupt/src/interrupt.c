#include <interrupt.h>
#include <registers.h>

static intFuncPtr interruptVectors[25];

void INT_enableGlobalInterrupts(){
    SREG |= (1<<7);
}
void INT_disableGlobalInterrupts(){
    SREG &= (1<<7);
}
void INT_interruptAttach(Interrupt_ID interrupt, intFuncPtr Callback){
    interruptVectors[interrupt] = Callback;
}
void INT_enableInterrupt(Interrupt_ID interrupt){
    switch (interrupt) {
        case INT0:
            EIMSK |= (1<<0);
            break;
        case INT1:
            EIMSK |= (1<<1);
            break;
        case PCINT0:
            PCICR |= (1<<0);
            break;
        case PCINT1:
            PCICR |= (1<<1); // PCINT1
            break;
        case PCINT2:
            PCICR |= (1<<2); // PCINT2
            break;
        case WDT:
            WDTCSR |= (1<<6);
            break;
        case TIM2_COMPA:
            TIMSK2 |= (1<<1);
            break;
        case TIM2_COMPB:
            TIMSK2 |= (1<<2);
            break;
        case TIM2_OVF:
            TIMSK2 |= (1<<0);
            break;
        case TIM1_CAPT:
            TIMSK1 |= (1<<5); // TIM1_CAPT
            break;
        case TIM1_COMPA:
            TIMSK1 |= (1<<1);
            break;
        case TIM1_COMPB:
            TIMSK1 |= (1<<2);
            break;
        case TIM1_OVF:
            TIMSK1 |= (1<<0);
            break;
        case TIM0_COMPA:
            TIMSK0 |= (1<<1);
            break;
        case TIM0_COMPB:
            TIMSK0 |= (1<<2);
            break;
        case TIM0_OVF:
            TIMSK0 |= (1<<0);
            break;
        case SPI_STC:
            SPCR |= (1<<7);
            break;
        case USART_RX:
            UCSR0B |= (1<<7);
            break;
        case USART_UDRE:
            UCSR0B |= (1<<5);
            break;
        case USART_TX:
            UCSR0B |= (1<<6);
            break;
        case ADCINT:
            ADCSRA |= (1<<3);
            break;
        case EE_READY:
            EECR |= (1<<3);
            break;
        case AN_COMP:
            ACSR |= (1<<3);
            break;
        case TWI:
            TWCR |= (1<<0);
            break;
        case SPM_READY:
            SPMCSR |= (1<<7);
            break;
        default:
            break;
    }
}
void INT_disableInterrupt(Interrupt_ID interrupt){
    switch (interrupt) {
        case INT0:
            EIMSK &= ~(1<<0);
            break;
        case INT1:
            EIMSK &= ~(1<<1);
            break;
        case PCINT0:
            PCICR &= ~(1<<0);
            break;
        case PCINT1:
            PCICR &= ~(1<<1); // PCINT1
            break;
        case PCINT2:
            PCICR &= ~(1<<2); // PCINT2
            break;
        case WDT:
            WDTCSR &= ~(1<<6);
            break;
        case TIM2_COMPA:
            TIMSK2 &= ~(1<<1);
            break;
        case TIM2_COMPB:
            TIMSK2 &= ~(1<<2);
            break;
        case TIM2_OVF:
            TIMSK2 &= ~(1<<0);
            break;
        case TIM1_CAPT:
            TIMSK1 &= ~(1<<5); // TIM1_CAPT
            break;
        case TIM1_COMPA:
            TIMSK1 &= ~(1<<1);
            break;
        case TIM1_COMPB:
            TIMSK1 &= ~(1<<2);
            break;
        case TIM1_OVF:
            TIMSK1 &= ~(1<<0);
            break;
        case TIM0_COMPA:
            TIMSK0 &= ~(1<<1);
            break;
        case TIM0_COMPB:
            TIMSK0 &= ~(1<<2);
            break;
        case TIM0_OVF:
            TIMSK0 &= ~(1<<0);
            break;
        case SPI_STC:
            SPCR &= ~(1<<7);
            break;
        case USART_RX:
            UCSR0B &= ~(1<<7);
            break;
        case USART_UDRE:
            UCSR0B &= ~(1<<5);
            break;
        case USART_TX:
            UCSR0B &= ~(1<<6);
            break;
        case ADCINT:
            ADCSRA &= ~(1<<3);
            break;
        case EE_READY:
            EECR &= ~(1<<3);
            break;
        case AN_COMP:
            ACSR &= ~(1<<3);
            break;
        case TWI:
            TWCR &= ~(1<<0);
            break;
        case SPM_READY:
            SPMCSR &= ~(1<<7);
            break;
        default:
            break;
    }
}

void INT_EXTINT_setMode(Interrupt_ID EXTINT, EXTINT_Mode mode){
    if (EXTINT == INT0){
        switch(mode){
            case LOW:
                EICRA &= ~((1<<0)|(1<<1));
                break;
            case CHANGE:
                EICRA &= ~(1<<1);
                EICRA |= (1<<0);
                break;
            case FALLING_EDGE:
                EICRA |= (1<<1);
                EICRA &= ~(1<<0);
                break;
            case RISING_EDGE:
                EICRA |= ((1<<0)|(1<<1));
                break;
            default:
                break;
    }
    }else if(EXTINT == INT1){
        switch(mode){
            case LOW:
                EICRA &= ~((1<<2)|(1<<3));
                break;
            case CHANGE:
                EICRA &= ~(1<<3);
                EICRA |= (1<<2);
                break;
            case FALLING_EDGE:
                EICRA |= (1<<3);
                EICRA &= ~(1<<2);
                break;
            case RISING_EDGE:
                EICRA |= ((1<<2)|(1<<3));
                break;
            default:
                break;
    }
    }else{
        return;
    }
}

void INT_PCINT_enable(GPIO_Port *port, uint8_t pin){
    if (pin > 7)return;

    if (port == GPIOB){
        PCMSK0 |= (1<<pin);
    }else if(port = GPIOC){
        if (pin < 7){
            PCMSK1 |= (1<<pin);
        }
    }else if(port == GPIOD){
        PCMSK2 |= (1<<pin);
    }

}
void INT_PCINT_disable(GPIO_Port *port, uint8_t pin){
    if (pin > 7)return;

    if (port == GPIOB){
        PCMSK0 &= ~(1<<pin);
    }else if(port = GPIOC){
        if (pin < 7){
            PCMSK1 &= ~(1<<pin);
        }
    }else if(port == GPIOD){
        PCMSK2 &= ~(1<<pin);
    }
}

void __vector_1(void) __attribute((signal, used));
void __vector_2(void) __attribute((signal, used));
void __vector_3(void) __attribute((signal, used));
void __vector_4(void) __attribute((signal, used));
void __vector_5(void) __attribute((signal, used));
void __vector_6(void) __attribute((signal, used));
void __vector_7(void) __attribute((signal, used));
void __vector_8(void) __attribute((signal, used));
void __vector_9(void) __attribute((signal, used));
void __vector_10(void) __attribute((signal, used));
void __vector_11(void) __attribute((signal, used));
void __vector_12(void) __attribute((signal, used));
void __vector_13(void) __attribute((signal, used));
void __vector_14(void) __attribute((signal, used));
void __vector_15(void) __attribute((signal, used));
void __vector_16(void) __attribute((signal, used));
void __vector_17(void) __attribute((signal, used));
void __vector_18(void) __attribute((signal, used));
void __vector_19(void) __attribute((signal, used));
void __vector_20(void) __attribute((signal, used));
void __vector_21(void) __attribute((signal, used));
void __vector_22(void) __attribute((signal, used));
void __vector_23(void) __attribute((signal, used));
void __vector_24(void) __attribute((signal, used));
void __vector_25(void) __attribute((signal, used));

void __vector_1(void) {
    if(interruptVectors[0]) interruptVectors[0]();
}
void __vector_2(void) {
    if(interruptVectors[1]) interruptVectors[1]();
}
void __vector_3(void) {
    if(interruptVectors[2]) interruptVectors[2]();
}
void __vector_4(void) {
    if(interruptVectors[3]) interruptVectors[3]();
}
void __vector_5(void) {
    if(interruptVectors[4]) interruptVectors[4]();
}
void __vector_6(void) {
    if(interruptVectors[5]) interruptVectors[5]();
}
void __vector_7(void) {
    if(interruptVectors[6]) interruptVectors[6]();
}
void __vector_8(void) {
    if(interruptVectors[7]) interruptVectors[7]();
}
void __vector_9(void) {
    if(interruptVectors[8]) interruptVectors[8]();
}
void __vector_10(void) {
    if(interruptVectors[9]) interruptVectors[9]();
}
void __vector_11(void) {
    if(interruptVectors[10]) interruptVectors[10]();
}
void __vector_12(void) {
    if(interruptVectors[11]) interruptVectors[11]();
}
void __vector_13(void) {
    if(interruptVectors[12]) interruptVectors[12]();
}
void __vector_14(void) {
    if(interruptVectors[13]) interruptVectors[13]();
}
void __vector_15(void) {
    if(interruptVectors[14]) interruptVectors[14]();
}
void __vector_16(void) {
    if(interruptVectors[15]) interruptVectors[15]();
}
void __vector_17(void) {
    if(interruptVectors[16]) interruptVectors[16]();
}
void __vector_18(void) {
    if(interruptVectors[17]) interruptVectors[17]();
}
void __vector_19(void) {
    if(interruptVectors[18]) interruptVectors[18]();
}
void __vector_20(void) {
    if(interruptVectors[19]) interruptVectors[19]();
}
void __vector_21(void) {
    if(interruptVectors[20]) interruptVectors[20]();
}
void __vector_22(void) {
    if(interruptVectors[21]) interruptVectors[21]();
}
void __vector_23(void) {
    if(interruptVectors[22]) interruptVectors[22]();
}
void __vector_24(void) {
    if(interruptVectors[23]) interruptVectors[23]();
}
void __vector_25(void) {
    if(interruptVectors[24]) interruptVectors[24]();
}