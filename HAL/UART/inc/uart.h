#ifndef UART_H
#define UART_H

#include <stdint.h>

#define DISABLED_PARITY 0
#define EVEN_PARITY 1
#define ODD_PARITY 2

struct UART_s
{
    void (*init)(uint32_t Baudrate, uint8_t CharSize, uint8_t Parity, uint8_t StopBits);
    void (*deinit)(void);
    void (*setBaudrate)(uint32_t Baudrate, uint8_t doubleSpeed);
    void (*setParity)(uint8_t Partity);
    void (*setCharSize)(uint8_t CharSize);
    void (*setStopBits)(uint8_t StopBits);

    void (*disableTx)(void);
    void (*disableRx)(void);
    void (*enableTx)(void);
    void (*enableRx)(void);

    void (*sendChar)(uint16_t Character);
    void (*send)(uint16_t *txBuffer);

    uint16_t (*recieveChar)(void);
    void (*recieve)(uint16_t *rxBuffer);

    uint8_t (*isRxDone)(void);
    uint8_t (*isTxDone)(void);
    uint8_t (*isDataEmpty)(void);
    uint8_t (*isFrameError)(void);
    uint8_t (*isDataOverrun)(void);
    uint8_t (*isParityError)(void);
};

extern const struct UART_s UART;

#endif