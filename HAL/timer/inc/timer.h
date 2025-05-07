#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>

enum Timers{
    TIMER0 = 0,
    TIMER1,
    TIMER2
};

enum Timer_Modes{
    NORMAL = 0,
    CTC
};

void TIMER0_init(uint8_t mode, uint8_t prescaler);
void TIMER1_init(uint8_t mode, uint8_t prescaler);
void TIMER2_init(uint8_t mode, uint8_t prescaler);

void TIMER0_stop(void);
void TIMER1_stop(void);
void TIMER2_stop(void);

void TIMER0_reset();
void TIMER1_reset();
void TIMER2_reset();

void TIMER0_setCOMPA_Value(uint8_t value);
void TIMER0_setCOMPB_Value(uint8_t value);

void TIMER1_setCOMPA_Value(uint16_t value);
void TIMER1_setCOMPB_Value(uint16_t value);

void TIMER2_setCOMPA_Value(uint8_t value);
void TIMER2_setCOMPB_Value(uint8_t value);

bool TIMER0_isOverflowed(void);
bool TIMER1_isOverflowed(void);
bool TIMER2_isOverflowed(void);

bool TIMER0_COMPA_match();
bool TIMER0_COMPB_match();

bool TIMER1_COMPA_match();
bool TIMER1_COMPB_match();

bool TIMER2_COMPA_match();
bool TIMER2_COMPB_match();

#endif