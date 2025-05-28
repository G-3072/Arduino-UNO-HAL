#include <uart.h>
#include <registers.h>

void UART_init(uint32_t Baudrate, uint8_t CharSize, UART_Parity Parity, uint8_t StopBits){
    
    UART_setBaudrate(Baudrate, 0);
    UART_setCharSize(CharSize);
    UART_setParity(Parity);
    UART_setStopBits(StopBits);
    //Enable Rx and Tx
    UART_enableRx();
    UART_enableTx();
}
void UART_deinit(void){
    UART_disableRx();
    UART_disableTx();
}
void UART_setBaudrate(uint32_t Baudrate, uint8_t doubleSpeed){
    uint16_t ubrrVal = 0;
    uint8_t multiplier = 16;

    if(doubleSpeed != 0){
        UCSR0A |= (1<<1);
    }else{
        UCSR0A &= ~(1<<1);
        multiplier = 8;
    }

    ubrrVal = ((16000000UL / (multiplier*Baudrate)) - 1);

    UBRR0 = ubrrVal;

}
void UART_setParity(UART_Parity Parity){
    switch(Parity){
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
void UART_setCharSize(uint8_t CharSize){
    switch(CharSize){
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
    }
}
void UART_setStopBits(uint8_t StopBits){
    if (StopBits == 1){
        UCSR0C &= ~(1<<3);
    }else if (StopBits == 0){
        UCSR0C |= (1<<3);
    }
}

inline void UART_enableTx(void){
    UCSR0B |= (1<<3);
}
inline void UART_enableRx(void){
    UCSR0B |= (1<<4);
}
inline void UART_disableTx(void){
    UCSR0B &= ~(1<<3);
}
inline void UART_disableRx(void){
    UCSR0B &= ~(1<<4);
}

void UART_sendChar(uint8_t Character){
    while(!(UCSR0A & (1<<5)));
    if (Character & (1<<8)){
        UCSR0B |= (1<<0);
    }else{
        UCSR0B &= (1<<0);
    }
    UDR0 = Character;
}
void UART_send(uint8_t *txBuffer){
    while(*txBuffer != 0){
        UART_sendChar(*txBuffer);
        txBuffer += 2;
    }
    UART_sendChar('\0');
}

inline uint8_t UART_recieveChar(void){
    return UDR0;
}
void UART_recieve(uint8_t *rxBuffer){
    do
    {
        while(!UART_isRxDone());
        *rxBuffer = UDR0;
        rxBuffer += 2;
            
    } while (UDR0 != 0);
}

inline bool UART_isRxDone(void){
    return (UCSR0A & (1<<7));
}
inline bool UART_isTxDone(void){
    return (UCSR0A & (1<<6));
}
inline bool UART_isDataEmpty(void){
    return (UCSR0A & (1<<5));
}
inline bool UART_isFrameError(void){
    return (UCSR0A & (1<<4));
}
inline bool UART_isDataOverrun(void){
    return (UCSR0A & (1<<3));
}
inline bool UART_isParityError(void){
    return (UCSR0A & (1<<2));
}