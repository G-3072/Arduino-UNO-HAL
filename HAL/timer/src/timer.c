#include <timer.h>
#include <registers.h>

#include <stdbool.h>

static uint8_t TIMER_getCSValue(TIMER_ID timer, uint16_t prescaler){
    switch(prescaler){
        case 1:
            return 1;
        case 8:
            return 2;
        case 32:
            if (timer == TIMER2) return 3;
            else return 2;
        case 64:
            if (timer == TIMER2) return 4;
            else return 3;
        case 128:
            if (timer == TIMER2) return 5;
            else return 3;
        case 256:
            if (timer == TIMER2) return 6;
            else return 4;
        case 1024:
            if (timer == TIMER2) return 7;
            else return 5;
        default:
            return 0;
    }
}

void TIMER_init(TIMER_ID timer, TIMER_Mode mode, uint16_t prescaler){
    TIMER_setMode(timer, mode);
    TIMER_setPrescaler(timer, prescaler);
}

void TIMER_setMode(TIMER_ID timer, TIMER_Mode mode){
    switch(timer){
        case TIMER0:
            switch(mode){
                case TIMER_NORMAL_MODE:
                    TCCR0A &= ~((1<<0)|(1<<1));
                    TCCR0B &= ~(1<<3);
                    break;
                case TIMER_CTC_MODE:
                    TCCR0A &= ~(1<<0);
                    TCCR0A |= (1<<1);
                    TCCR0B &= ~(1<<3);
                    break;
            }
            break;
        case TIMER1:
            switch(mode){
                case TIMER_NORMAL_MODE:
                    TCCR1A &= ~((1<<0)|(1<<1));
                    TCCR1B &= ~(1<<4);
                    break;
                case TIMER_CTC_MODE:
                    TCCR1A &= ~((1<<0)|(1<<1));
                    TCCR1B &= ~(1<<4);
                    TCCR1B &= ~(1<<3);
                    break;
            }
            break;
        case TIMER2:
            switch(mode){
                case TIMER_NORMAL_MODE:
                    TCCR2A &= ~((1<<0)|(1<<1));
                    TCCR2B &= ~(1<<3);
                    break;
                case TIMER_CTC_MODE:
                    TCCR2A &= ~(1<<0);
                    TCCR2A |= (1<<1);
                    TCCR2B &= ~(1<<3);
                    break;
            }
            break;
    }
}
void TIMER_setPrescaler(TIMER_ID timer, uint16_t prescaler){
    switch(timer){
        case TIMER0:
            timer0_csVal = TIMER_getCSValue(TIMER0, prescaler);
            break;
        case TIMER1:
            timer1_csVal = TIMER_getCSValue(TIMER1, prescaler);
            break;
        case TIMER2:
            timer2_csVal = TIMER_getCSValue(TIMER2, prescaler);
            break;
    }
}
void TIMER_start(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            TCCR0B = timer0_csVal;
            return;
        case TIMER1:
            TCCR1B = timer1_csVal;
            return;
        case TIMER2:
            TCCR2B = timer2_csVal;
            return;
    }
}

void TIMER_stop(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            TCCR0B &= ~((1<<0)|(1<<1)|(1<<2));
            break;
        case TIMER1:
            TCCR1B &= ~((1<<0)|(1<<1)|(1<<2));
            break;
        case TIMER2:
            TCCR2B &= ~((1<<0)|(1<<1)|(1<<2));
            break;
    }
}

void TIMER_reset(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            TCNT0 = 0;
            break;
        case TIMER1:
            TCNT1 = 0;
            break;
        case TIMER2:
            TCNT2 = 0;
            break;
    }
}

void TIMER_COMPA_setValue(TIMER_ID timer, uint16_t value){
    switch(timer){
        case TIMER0:
            OCR0A = value;
            break;
        case TIMER1:
            OCR1A = value;
            break;
        case TIMER2:
            OCR2A = value;
            break;
    }
}
void TIMER_COMPB_setValue(TIMER_ID timer, uint16_t value){
    switch(timer){
        case TIMER0:
            OCR0B = value;
            break;
        case TIMER1:
            OCR1B = value;
            break;
        case TIMER2:
            OCR2B = value;
            break;
    }
}

bool TIMER_isOverflowed(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            return (TIFR0 & (1<<0));
        case TIMER1:
            return (TIFR1 & (1<<0));
        case TIMER2:
            return (TIFR2 & (1<<0));
    }
}
bool TIMER_COMPA_isMatch(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            return (TIFR0 & (1<<1));
        case TIMER1:
            return (TIFR1 & (1<<1));
        case TIMER2:
            return (TIFR2 & (1<<1));
    }
}
bool TIMER_COMPB_isMatch(TIMER_ID timer){
    switch(timer){
        case TIMER0:
            return (TIFR0 & (1<<2));
        case TIMER1:
            return (TIFR1 & (1<<2));
        case TIMER2:
            return (TIFR2 & (1<<2));
    }
}