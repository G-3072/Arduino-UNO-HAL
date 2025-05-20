#ifndef UART_H
#define UART_H

#include <stdint.h>

#define DISABLED_PARITY 0
#define EVEN_PARITY 1
#define ODD_PARITY 2

void UART_init(uint32_t Baudrate, uint8_t CharSize, uint8_t Parity, uint8_t StopBits);
void UART_deinit(void);
void UART_setBaudrate(uint32_t Baudrate, uint8_t doubleSpeed);
void UART_setParity(uint8_t Parity);
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

uint8_t UART_isRxDone(void);
uint8_t UART_isTxDone(void);
uint8_t UART_isDataEmpty(void);
uint8_t UART_isFrameError(void);
uint8_t UART_isDataOverrun(void);
uint8_t UART_isParityError(void);

#endif