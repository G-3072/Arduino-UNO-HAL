#include <gpio.h>
#include <registers.h>
#include <stdbool.h>


void GPIO_enablePullUp(bool enabled){
    MCUCR &= ~(1<<4);
}

void GPIO_disablePullUp(bool enabled){
    MCUCR |= (1<<4);
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 * @param mode 
 */
void GPIO_setPinMode(GPIO_Port *port,  uint8_t pin, GPIO_Mode mode){
    if(port == GPIOC && pin >= 7)return;
    
    if(mode != 0){
        port->DDR |= (1<<pin);
    }else{
        port->DDR &= ~(1<<pin);
    }
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 * @param pull 
 */
void GPIO_setPinPull(GPIO_Port *port,  uint8_t pin, GPIO_Pull pull){
    if(port == GPIOC && pin >= 7)return;
    MCUCR &= ~(1<<4);

    if (pull != 0){
        port->PORT |= (1<<pin);
    }else{
        port->PORT &= ~(1<<pin);
    }
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 * @param value 
 */
void GPIO_writePin(GPIO_Port *port,  uint8_t pin, uint8_t value){
    if(port == GPIOC && pin >= 7)return;
    if (value != 0){
        port->PORT |= (1<<pin);
    }else{
        port->PORT &= ~(1<<pin);
    }
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 */
void GPIO_togglePin(GPIO_Port *port,  uint8_t pin){
    if(port == GPIOC && pin >= 7)return;
    port->PIN = (1<<pin);
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 * @return uint8_t 
 */
uint8_t GPIO_readPin(GPIO_Port *port,  uint8_t pin){
    uint8_t pinVal = port->PIN;

    pinVal &= (1<<pin);
    pinVal >>= pin;
    
    return pinVal;
}

