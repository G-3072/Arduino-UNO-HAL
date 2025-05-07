#include <gpio.h>
#include <registers.h>

void GPIO_senseControl_INT0(uint8_t sense){
    switch(sense){
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
}

void GPIO_senseControl_INT1(uint8_t sense){
    switch(sense){
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
}


void GPIO_PCINT0_set(uint8_t pin){
    PCMSK0 |= (1<<pin);
}

void GPIO_PCINT1_set(uint8_t pin){
    if(pin == 7)return;
    PCMSK1 |= (1<<pin);
}

void GPIO_PCINT2_set(uint8_t pin){
    PCMSK2 |= (1<<pin);
}
void GPIO_PCINT0_clear(uint8_t pin){
    PCMSK2 &= ~(1<<pin);
}
void GPIO_PCINT1_clear(uint8_t pin){
    if(pin == 7)return;
    PCMSK1 &= ~(1<<pin);
}
void GPIO_PCINT2_clear(uint8_t pin){
    PCMSK2 &= ~(1<<pin);
}