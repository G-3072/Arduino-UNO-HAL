#include <uart.h>
#include <registers.h>

static void init(uint32_t Baudrate, uint8_t CharSize, uint8_t Parity, uint8_t StopBits);
static void deinit(void);
static void setBaudrate(uint32_t Baudrate, uint8_t doubleSpeed);
static void setParity(uint8_t Parity);
static void setCharSize(uint8_t CharSize);
static void setStopBits(uint8_t StopBits);

static void enableTx(void);
static void enableRx(void);
static void disableTx(void);
static void disableRx(void);

static void sendChar(uint16_t Character);
static void send(uint16_t *txBuffer);

static uint16_t recieveChar(void);
static void recieve(uint16_t *rxBuffer);

static uint8_t isRxDone(void);
static uint8_t isTxDone(void);
static uint8_t isDataEmpty(void);
static uint8_t isFrameError(void);
static uint8_t isDataOverrun(void);
static uint8_t isParityError(void);

const struct UART_s UART = {
    init,
    deinit,
    setBaudrate,
    setParity,
    setCharSize,
    setStopBits,
    disableTx,
    disableRx,
    enableTx,
    enableRx,
    sendChar,
    send,
    recieveChar,
    recieve,
    isRxDone,
    isTxDone,
    isDataEmpty,
    isFrameError,
    isDataOverrun,
    isParityError,
};


static void init(uint32_t Baudrate, uint8_t CharSize, uint8_t Parity, uint8_t StopBits){
    
    setBaudrate(Baudrate, 0);
    setCharSize(CharSize);
    setParity(Parity);
    setStopBits(StopBits);
    //Enable Rx and Tx
    enableRx();
    enableTx();
}
static void deinit(void){
    disableRx();
    disableTx();
}
static void setBaudrate(uint32_t Baudrate, uint8_t doubleSpeed){
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
static void setParity(uint8_t Parity){
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
static void setCharSize(uint8_t CharSize){
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
        case 9:
            UCSR0C |= (1<<1);
            UCSR0C |= (1<<2);
            UCSR0B |= (1<<2);
            break;
    }
}
static void setStopBits(uint8_t StopBits){
    if (StopBits == 1){
        UCSR0C &= ~(1<<3);
    }else if (StopBits == 0){
        UCSR0C |= (1<<3);
    }
}

static inline void enableTx(void){
    UCSR0B |= (1<<3);
}
static inline void enableRx(void){
    UCSR0B |= (1<<4);
}
static inline void disableTx(void){
    UCSR0B &= ~(1<<3);
}
static inline void disableRx(void){
    UCSR0B &= ~(1<<4);
}

static void sendChar(uint16_t Character){
    while(!(UCSR0A & (1<<5)));
    if (Character & (1<<8)){
        UCSR0B |= (1<<0);
    }else{
        UCSR0B &= (1<<0);
    }
    UDR0 = Character;
}
static void send(uint16_t *txBuffer){
    while(*txBuffer != 0){
        sendChar(*txBuffer);
        txBuffer += 2;
    }
    sendChar('\0');
}

static inline uint16_t recieveChar(void){
    return UDR0;
}
static void recieve(uint16_t *rxBuffer){
    do
    {
        while(!isRxDone());
        *rxBuffer = UDR0;
        rxBuffer += 2;
            
    } while (UDR0 != 0);
}

static inline uint8_t isRxDone(void){
    return (UCSR0A & (1<<7));
}
static inline uint8_t isTxDone(void){
    return (UCSR0A & (1<<6));
}
static inline uint8_t isDataEmpty(void){
    return (UCSR0A & (1<<5));
}
static inline uint8_t isFrameError(void){
    return (UCSR0A & (1<<4));
}
static inline uint8_t isDataOverrun(void){
    return (UCSR0A & (1<<3));
}
static inline uint8_t isParityError(void){
    return (UCSR0A & (1<<2));
}