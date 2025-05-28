#include <test_uart.h>
#include <uart.h>
#include <util/delay.h>
#include <gpio.h>

void TEST_UART_sendChar(void){
    GPIO_setPinMode(GPIOB, 5, OUTPUT);
    GPIO_writePin(GPIOB, 5, 0);

    UART_setBaudrate(9600, 0);
    UART_setCharSize(8);
    UART_setParity(DISABLED_PARITY);
    UART_setStopBits(1);

    UART_enableRx();
    UART_enableTx();

    while(1){
        UART_sendChar('A');
        _delay_ms(1000);
    }
}
void TEST_UART_send(void){
    uint8_t message[] = "UART SENDING";

    UART_init(9600, 8, DISABLED_PARITY, 1);

    while(1){
        UART_send(message);
        _delay_ms(1000);
    }
}

void TEST_UART_recieveChar(void){

    UART_init(9600, 8, DISABLED_PARITY, 1);

    while(1){
        if (UART_isRxDone()){
            if(UART_recieveChar() == 'A'){
                UART_sendChar('B');
            }
        }
    }
    
}
void TEST_UART_recieve(void){
    uint8_t rxBuffer[5];
    

    UART_init(9600, 8, DISABLED_PARITY, 1);

    while(1){
        UART_recieve(rxBuffer);
        if(rxBuffer[0] == 'T' && rxBuffer[1] == 'E' && rxBuffer[2] == 'S' && rxBuffer[3] == 'T'){
            UART_send("ACK");
        }
    }

}