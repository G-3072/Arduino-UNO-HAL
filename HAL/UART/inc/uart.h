#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

typedef enum{
    DISABLED_PARITY = 0,
    EVEN_PARITY,
    ODD_PARITY
}UART_Parity;

// typedef enum{
//     UART_8N1 = 0,
// }UART_Configs;

void UART_init(uint32_t Baudrate, uint8_t CharSize, UART_Parity Parity, uint8_t StopBits);
void UART_deinit(void);
void UART_setBaudrate(uint32_t Baudrate, uint8_t doubleSpeed);
void UART_setParity(UART_Parity Parity);
void UART_setCharSize(uint8_t CharSize);
void UART_setStopBits(uint8_t StopBits);

void UART_enableTx(void);
void UART_enableRx(void);
void UART_disableTx(void);
void UART_disableRx(void);

void UART_sendChar(uint16_t Character);
void UART_send(uint16_t *txBuffer);

uint16_t UART_recieveChar(void);
void UART_recieve(uint16_t *rxBuffer);

bool UART_isRxDone(void);
bool UART_isTxDone(void);
bool UART_isDataEmpty(void);
bool UART_isFrameError(void);
bool UART_isDataOverrun(void);
bool UART_isParityError(void);

#endif