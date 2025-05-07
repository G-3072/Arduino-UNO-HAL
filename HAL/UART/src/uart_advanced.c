#include <uart.h>
#include <registers.h>

void UART_sendString(const uint8_t* string){
    while(*string != 0){
        while(!(UCSR0A & (1<<5)));
        UDR0 = *string++;
    }
}

void UART_sendNumber(uint16_t number){
    uint8_t numBuffer[6];
    uint8_t i = 0; 
    for(uint16_t div = 10000; div > 0; div/10){
        if(number/div){

        }
    }
}