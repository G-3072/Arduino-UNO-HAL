#include <timer.h>
#include <registers.h>

static uint8_t getCSvalTIM01(uint16_t prescaler){
    switch(prescaler){
        case 8:
            return 2;
        case 64:
            return 3;
        case 256:
            return 4;
        case 1024:
            return 5;
        default:
            return 1;
    }
}

static uint8_t getCSvalTIM2(uint16_t prescaler){
    switch(prescaler){
        case 8:
            return 2;
        case 32:
            return 3;
        case 64:
            return 4;
        case 128:
            return 5;
        case 256:
            return 6;
        case 1024:
            return 7;
        default:
            return 1;
    }
}

void TIMER_init(uint8_t timer, uint16_t prescaler){
    switch(timer){
        case TIM0:
            TCCR0A = ~((1<<0)|(1<<1));
            TCCR0B = getCSvalTIM01(prescaler);
            TCNT0 = 0;
            break;
        case TIM1:
            TCCR1A = ~((1<<0)|(1<<1));
            TCCR1B = getCSvalTIM01(prescaler);
            TCNT1 = 0;
            break;
        case TIM2:
            TCCR2A = ~((1<<0)|(1<<1));
            TCCR2B = getCSvalTIM2(prescaler);
            TCNT2 = 0;
            break;
    }
}
void TIMER_deinit(uint8_t timer){
    switch(timer){
        case TIM0:
            TCCR0B &= 0b111;
            break;
        case TIM1:
            TCCR0B &= 0b111;
            break;
        case TIM2:
            TCCR0B &= 0b111;
            break;
    }
}

void TIMER_reset(uint8_t timer){
    switch(timer){
        case TIM0:
            TCNT0 = 0;
            break;
        case TIM1:
            TCNT1 = 0;
            break;
        case TIM2:
            TCNT2 = 0;
            break;
    }
}

uint8_t TIMER0_getValue(){
    return TCNT0;
}
uint16_t TIMER1_getValue(){
    return TCNT1;
}
uint8_t TIMER2_getValue(){
    return TCNT2;
}

uint8_t TIMER_isOverflowed(uint8_t timer){
    switch(timer){
        case TIM0:
            if(TIFR0 & (1<<2)) return 1;
            break;
        case TIM1:
            if(TIFR1 & (1<<2)) return 1;
            break;
        case TIM2:
            if(TIFR1 & (1<<2)) return 1;
            break;
    }
}

void TIMER_delay_ms(uint16_t ms){

}
void TIMER_delay_us(uint16_t us){

}
