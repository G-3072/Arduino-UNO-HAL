#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

//GPIO registers
#define PINB    (*(volatile uint8_t *)0x23)
#define DDRB    (*(volatile uint8_t *)0x24)
#define PORTB   (*(volatile uint8_t *)0x25)

#define PINC    (*(volatile uint8_t *)0x26)
#define DDRC    (*(volatile uint8_t *)0x27)
#define PORTC   (*(volatile uint8_t *)0x28)

#define PIND    (*(volatile uint8_t *)0x29)
#define DDRD    (*(volatile uint8_t *)0x2A)
#define PORTD   (*(volatile uint8_t *)0x2B)

#define EIFR    (*(volatile uint8_t *)0x3D)
#define EIMSK   (*(volatile uint8_t *)0x3C)
#define EICRA  (*(volatile uint8_t *)0x69)

#define PCICR   (*(volatile uint8_t *)0x68)

#define PCMSK0  (*(volatile uint8_t *)0x6B)
#define PCMSK1  (*(volatile uint8_t *)0x6C)
#define PCMSK2  (*(volatile uint8_t *)0x6D)

//timer registers
#define TIFR1   (*(volatile uint8_t *)0x36)
#define TIFR2   (*(volatile uint8_t *)0x37)

#define GTCCR   (*(volatile uint8_t *)0x43)

#define TIFR0   (*(volatile uint8_t *)0x35)
#define TCCR0A  (*(volatile uint8_t *)0x44)
#define TCCR0B  (*(volatile uint8_t *)0x45)
#define TCMT0   (*(volatile uint8_t *)0x46)
#define OCR0A   (*(volatile uint8_t *)0x47)
#define OCR0B   (*(volatile uint8_t *)0x48)

#define TIMSK0   (*(volatile uint8_t *)0x6E)
#define TIMSK1   (*(volatile uint8_t *)0x6F)
#define TIMSK2   (*(volatile uint8_t *)0x70)

#define TCCR1A   (*(volatile uint8_t *)0x80)
#define TCCR1B   (*(volatile uint8_t *)0x81)
#define TCCR1C   (*(volatile uint8_t *)0x82)

#define TCNT1L   (*(volatile uint8_t *)0x84)
#define TCNT1H   (*(volatile uint8_t *)0x85)
#define TCNT1    (*(volatile uint16_t *)0x84)

#define ICR1L    (*(volatile uint8_t *)0x86)
#define ICR1H    (*(volatile uint8_t *)0x87)
#define ICR1     (*(volatile uint16_t *)0x86)

#define OCR1AL   (*(volatile uint8_t *)0x88)
#define OCR1AH   (*(volatile uint8_t *)0x89)
#define OCR1A    (*(volatile uint16_t *)0x88)

#define OCR1BL   (*(volatile uint8_t *)0x8A)
#define OCR1BH   (*(volatile uint8_t *)0x8B)
#define OCR1B    (*(volatile uint16_t *)0x8A)

#define TCCR2A   (*(volatile uint8_t *)0xB0)
#define TCCR2B   (*(volatile uint8_t *)0xB1)
#define TCNT2    (*(volatile uint8_t *)0xB2)
#define OCR2A    (*(volatile uint8_t *)0xB3)
#define OCR2B    (*(volatile uint8_t *)0xB4)

#define ASSR     (*(volatile uint8_t *)0xB5)


//EEPROM registers
#define EECR   (*(volatile uint8_t *)0x3F)
#define EEDR   (*(volatile uint8_t *)0x40)
#define EEARL  (*(volatile uint8_t *)0x41)
#define EEARH  (*(volatile uint8_t *)0x42)

//spi registers
#define SPCR   (*(volatile uint8_t *)0x4C)
#define SPSR   (*(volatile uint8_t *)0x4D)
#define SPDR   (*(volatile uint8_t *)0x4E)

//system registers
#define SMCR    (*(volatile uint8_t *)0x53)
#define MCUSR   (*(volatile uint8_t *)0x54)
#define MCUCR   (*(volatile uint8_t *)0x55)
#define SPMCSR  (*(volatile uint8_t *)0x57)
#define SP      (*(volatile uint16_t *)0x5D)
#define SPL     (*(volatile uint8_t *)0x5D)
#define SPH     (*(volatile uint8_t *)0x5E)
#define SREG    (*(volatile uint8_t *)0x5F)

#define WDTCSR  (*(volatile uint8_t *)0x60)
#define PRR     (*(volatile uint8_t *)0x64)

//clock registers
#define CLKPR   (*(volatile uint8_t *)0x61)
#define OSCAL   (*(volatile uint8_t *)0x66)

// ADC registers
#define ADCL    (*(volatile uint8_t *)0x78)
#define ADCH    (*(volatile uint8_t *)0x79)
#define ADC     (*(volatile uint16_t *)0x78)

#define ADCSRA  (*(volatile uint8_t *)0x7A)
#define ADCSRB  (*(volatile uint8_t *)0x7B)
#define ADMUX   (*(volatile uint8_t *)0x7C)

#define ACSR    (*(volatile uint8_t *)0x50)

#define DIDR0   (*(volatile uint8_t *)0x7E)
#define DIDR1   (*(volatile uint8_t *)0x7F)

//TWI registers
#define TWBR    (*(volatile uint8_t *)0xB8)
#define TWSR    (*(volatile uint8_t *)0xB9)
#define TWAR    (*(volatile uint8_t *)0xBA)
#define TWDR    (*(volatile uint8_t *)0xBB)
#define TWCR    (*(volatile uint8_t *)0xBC)
#define TWAMR   (*(volatile uint8_t *)0xBD)

//USART registers
#define UCSR0A    (*(volatile uint8_t *)0xC0)
#define UCSR0B    (*(volatile uint8_t *)0xC1)
#define UCSR0C    (*(volatile uint8_t *)0xC2)

#define UBRR0L    (*(volatile uint8_t *)0xC4)
#define UBRR0H    (*(volatile uint8_t *)0xC5)
#define UBRR0     (*(volatile uint16_t *)0xC4)

#define UDR0      (*(volatile uint8_t *)0xC6)

#endif