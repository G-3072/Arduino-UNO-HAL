#ifndef UART_H
#define UART_H

#include <registers.h>

#define DISABLED_PARITY 0
#define EVEN_PARITY 1
#define ODD_PARITY 2

#define UART_MAX_ARRAY_LENGTH 50

void UART_doubleSpeed(uint8_t enable);

void UART_enable(void);
void UART_disable(void);

void UART_setCharachterSize(uint8_t size);
void UART_setParity(uint8_t parity);
void UART_setStopBit(uint8_t bits);
void UART_setBaudRate(uint32_t baudRate);

uint8_t UART_is_rx_ready(void);

void UART_send(uint8_t value);
void UART_send_string(const uint8_t* string);

uint8_t UART_recieve(void);

#endif