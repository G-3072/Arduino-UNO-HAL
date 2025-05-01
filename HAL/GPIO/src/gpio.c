#include <gpio.h>

#define MCUCR (*(uint8_t *)0x35)
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 * @param mode 
 */
void GPIO_setPinMode(GPIO_Port *port,  uint8_t pin, uint8_t mode){
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
void GPIO_setPinPull(GPIO_Port *port,  uint8_t pin, uint8_t pull){
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
/**
 * @brief 
 * 
 * @param port 
 * @param mode 
 */
void GPIO_setPortMode(GPIO_Port *port, uint8_t mode){
    port->DDR = mode;
}
/**
 * @brief 
 * 
 * @param port 
 * @param pull 
 */
void GPIO_setPortPull(GPIO_Port *port, uint8_t pull){
    MCUCR &= ~(1<<4);

    port->PORT = pull;
}
/**
 * @brief 
 * 
 * @param port 
 * @param value 
 */
void GPIO_writePort(GPIO_Port *port, uint8_t value){
    port->PORT = value;
}
/**
 * @brief 
 * 
 * @param port 
 * @return uint8_t 
 */
uint8_t GPIO_readPort(GPIO_Port *port){
    uint8_t portVal = port->PIN;
    
    return portVal;
}