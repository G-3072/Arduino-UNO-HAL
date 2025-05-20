#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

#define INPUT 0
#define OUTPUT 255

#define PullUp 255
#define PullDown 0

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

void GPIO_setPinMode(GPIO_Port *port, uint8_t pin, uint8_t mode);
void GPIO_setPinPull(GPIO_Port *port, uint8_t pin, uint8_t pull);

void GPIO_writePin(GPIO_Port *port, uint8_t pin, uint8_t value);
void GPIO_togglePin(GPIO_Port *port,  uint8_t pin);
 
uint8_t GPIO_readPin(GPIO_Port *port, uint8_t pin);

//external interrupt functions


#endif