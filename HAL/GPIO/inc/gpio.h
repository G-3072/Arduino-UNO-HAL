#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

typedef enum{
    INPUT = 0,
    OUTPUT
}GPIO_Mode;

typedef enum{
    PullDown = 0,
    PullUp
}GPIO_Pull;

typedef struct
{
    volatile uint8_t PIN;
    volatile uint8_t DDR;
    volatile uint8_t PORT;
}GPIO_Port;

#define GPIOB ((GPIO_Port *)0x23)
#define GPIOC ((GPIO_Port *)0x26)
#define GPIOD ((GPIO_Port *)0x29)


//base functions
void GPIO_enablePullUp(bool enabled);
void GPIO_disablePullUp(bool enabled);

void GPIO_setPinMode(GPIO_Port *port, uint8_t pin, GPIO_Mode mode);
void GPIO_setPinPull(GPIO_Port *port, uint8_t pin, GPIO_Pull pull);

void GPIO_writePin(GPIO_Port *port, uint8_t pin, uint8_t value);
void GPIO_togglePin(GPIO_Port *port,  uint8_t pin);
 
uint8_t GPIO_readPin(GPIO_Port *port, uint8_t pin);

//external interrupt functions


#endif