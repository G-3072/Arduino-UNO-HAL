#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define TIM0 0
#define TIM1 1
#define TIM2 2

void TIMER_init(uint8_t timer, uint16_t prescaler);
void TIMER_deinit(uint8_t timer);

void TIMER_reset(uint8_t timer);
uint16_t TIMER_getValue(uint8_t timer);

void TIMER_delay_ms(uint16_t ms);
void TIMER_delay_us(uint16_t us);


#endif