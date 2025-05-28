#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>

static uint8_t timer0_csVal = 0;
static uint8_t timer1_csVal = 0;
static uint8_t timer2_csVal = 0;

typedef enum {
    TIMER0 = 0,
    TIMER1,
    TIMER2
}TIMER_ID;

typedef enum {
    TIMER_NORMAL_MODE = 0,
    TIMER_CTC_MODE
}TIMER_Mode;

void TIMER_init(TIMER_ID timer, TIMER_Mode mode, uint16_t prescaler);
void TIMER_setMode(TIMER_ID timer, TIMER_Mode mode);
void TIMER_setPrescaler(TIMER_ID timer, uint16_t prescaler);

void TIMER_start(TIMER_ID timer);
void TIMER_stop(TIMER_ID timer);

void TIMER_reset(TIMER_ID timer);

void TIMER_COMPA_setValue(TIMER_ID timer, uint16_t value);
void TIMER_COMPB_setValue(TIMER_ID timer, uint16_t value);

bool TIMER_isOverflowed(TIMER_ID timer);
bool TIMER_COMPA_isMatch(TIMER_ID timer);
bool TIMER_COMPB_isMatch(TIMER_ID timer);

#endif