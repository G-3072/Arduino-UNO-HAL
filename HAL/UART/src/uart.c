#include <uart.h>
#include <registers.h>

void UART_doubleSpeed(uint8_t enable){
    if(enable){
        UCSR0A |= (1<<1);
    }else{
        UCSR0A &= ~(1<<1);
    }
}

void UART_enable(void){
    UCSR0B |= ((1<<3)|(1<<4));
}
void UART_disable(void){
    UCSR0B &= ~((1<<3)|(1<<4));
}

void UART_setCharachterSize(uint8_t size){
    switch(size){
        case 5:
            UCSR0C &= ~(1<<1);
            UCSR0C &= ~(1<<2);
            UCSR0B &= ~(1<<2);
            break;
        case 6:
            UCSR0C |= (1<<1);
            UCSR0C &= ~(1<<2);
            UCSR0B &= ~(1<<2);
            break;
        case 7:
            UCSR0C &= ~(1<<1);
            UCSR0C |= (1<<2);
            UCSR0B &= ~(1<<2);
            break;
        case 8:
            UCSR0C |= (1<<1);
            UCSR0C |= (1<<2);
            UCSR0B &= ~(1<<2);
            break;
        case 9:
            UCSR0C |= (1<<1);
            UCSR0C |= (1<<2);
            UCSR0B |= (1<<2);
            break;
    }
}
void UART_setParity(uint8_t parity){
    switch(parity){
        case DISABLED_PARITY:
            UCSR0C &= ~((1<<4)|(1<<5));
            break;
        case EVEN_PARITY:
            UCSR0C &= ~(1<<4);
            UCSR0C |= (1<<5);
            break;
        case ODD_PARITY:
            UCSR0C |= ((1<<4)|(1<<5));
            break;
    }
}

void UART_setStopBit(uint8_t bits){
    if (bits == 1){
        UCSR0C &= ~(1<<3);
    }else if (bits == 0){
        UCSR0C |= (1<<3);
    }
}

void UART_setBaudRate(uint32_t baudRate){

    uint16_t ubrr = 0;
    uint8_t multiplier = 16;

    if (UCSR0A & (1<<1)){
        multiplier = 8;
    }
    
    ubrr = ((16000000U / (multiplier*baudRate)) -1);

    UBRR0H = (uint8_t)(ubrr >> 8);   // High byte
    UBRR0L = (uint8_t)ubrr;
}

void UART_send(uint8_t value){
    while(!(UCSR0A & (1<<5)));      //wait until buffer empty
    UDR0 = value;
}

void UART_send_string(const uint8_t* string){
    while(*string != 0){
        while(!(UCSR0A & (1<<5)));
        UDR0 = *string++;
    }
}

uint8_t UART_recieve(void){
    return UDR0;
}

uint8_t UART_is_rx_ready(void){
    if(UCSR0A & (1<<7)){
        return 1;
    }
    return 0;
}