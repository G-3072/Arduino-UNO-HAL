#include <timer.h>
#include <registers.h>

#include <stdbool.h>

static uint8_t getCSvalTIMER01(uint16_t prescaler){
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

static uint8_t getCSvalTIMER2(uint16_t prescaler){
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

void TIMER0_init(uint8_t mode, uint8_t prescaler){
    TCCR0B = getCSvalTIMER01(prescaler);
    switch(mode){
        case CTC:
            TCCR0A = 0b10;
            TCCR0B &= ~(1<<3);
            break;
        default:    //Normal mode is default
            TCCR0A = 0b00;
            TCCR0B &= ~(1<<3);
            break;
    }
}
void TIMER1_init(uint8_t mode, uint8_t prescaler){
    TCCR1B = getCSvalTIMER01(prescaler);
    switch(mode){
        case CTC:
            TCCR1A = 0b00;
            TCCR1B |= (1<<3);
            TCCR1B &= ~(1<<4);
            break;
        default:    //Normal mode is default
            TCCR1A = 0b00;
            TCCR1B &= ~(1<<3);
            break;
    }
}
void TIMER2_init(uint8_t mode, uint8_t prescaler){
    TCCR2B = getCSvalTIMER2(prescaler);
    switch(mode){
        case CTC:
            TCCR2A = 0b10;
            TCCR2B &= ~(1<<3);
            break;
        default:    //Normal mode is default
            TCCR2A = 0b00;
            TCCR2B &= ~((1<<3)|(1<<4));
            break;
    }
}

void TIMER0_stop(void){
    TCCR0B &= ~((1<<0)|(1<<1)|(1<<2));
}
void TIMER1_stop(void){
    TCCR1B &= ~((1<<0)|(1<<1)|(1<<2));
}
void TIMER2_stop(void){
    TCCR2B &= ~((1<<0)|(1<<1)|(1<<2));
}

void TIMER0_reset(){
    TCNT0 = 0;
}
void TIMER1_reset(){
    TCNT1 = 0;
}
void TIMER2_reset(){
    TCNT2 = 0;
}

bool TIMER0_isOverflowed(void){
    
}
bool TIMER1_isOverflowed(void){

}
bool TIMER2_isOverflowed(void){

}
