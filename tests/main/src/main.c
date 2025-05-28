// #include <test_uart.h>
#include <uart.h>
#include <util/delay.h>

void main(void){
    
    UART_init(9600, 8, DISABLED_PARITY, 1);


    while(1){
        UART_sendChar('A');
        _delay_ms(1000);
    }
    // TEST_UART_sendChar();

}
