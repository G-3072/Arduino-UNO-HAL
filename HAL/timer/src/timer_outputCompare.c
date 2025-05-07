#include <timer.h>
#include <registers.h>

void TIMER0_setCOMPA_Value(uint8_t value){
    OCR0A = value;
}

void TIMER0_setCOMPB_Value(uint8_t value){
    OCR0B = value;
}


void TIMER1_setCOMPA_Value(uint16_t value){
    OCR1A = value;
}

void TIMER1_setCOMPB_Value(uint16_t value){
    OCR1B = value;
}


void TIMER2_setCOMPA_Value(uint8_t value){
    OCR2A = value;
}

void TIMER2_setCOMPB_Value(uint8_t value){
    OCR2B = value;
}


bool TIMER0_COMPA_match(){
    if (TIFR0 & (1<<2))return true;
    return false;
}

bool TIMER0_COMPB_match(){
    if (TIFR0 & (1<<3))return true;
    return false;
}


bool TIMER1_COMPA_match(){
    if (TIFR1 & (1<<2))return true;
    return false;
}

bool TIMER1_COMPB_match(){
    if (TIFR1 & (1<<3))return true;
    return false;
}


bool TIMER2_COMPA_match(){
    if (TIFR2 & (1<<2))return true;
    return false;
}

bool TIMER2_COMPB_match(){
    if (TIFR2 & (1<<3))return true;
    return false;
}
