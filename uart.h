#ifndef UART_H
#define UART_H
#include <stdint.h> 
#include "gpio.h"


#define UART ((NRF_UART_REG*)0x40002000) 

typedef struct {
  //Tasks
  volatile uint32_t STARTRX;
  volatile uint32_t STOPRX;
  volatile uint32_t STARTTX;
  volatile uint32_t STOPTX;
  volatile uint32_t WHATEVER0[3];
  volatile uint32_t SUSPEND;
  volatile uint32_t WHATEVER1[56];

  //Events
  volatile uint32_t CTS;
  volatile uint32_t NCTS;
  volatile uint32_t RXDRDY;
  volatile uint32_t WHATEVER2[4];
  volatile uint32_t TXDRDY;
  volatile uint32_t WHATEVER3;
  volatile uint32_t ERROR;
  volatile uint32_t WHATEVER4[7];
  volatile uint32_t RXTO;
  volatile uint32_t WHATEVER5[110];

  //Registers
  volatile uint32_t INTEN;
  volatile uint32_t INTENSET;
  volatile uint32_t INTENCLR;
  volatile uint32_t WHATEVER6[93];
  volatile uint32_t ERRORSRC;
  volatile uint32_t WHATEVER7[31];
  volatile uint32_t ENABLE;
  volatile uint32_t WHATEVER8;
  volatile uint32_t PSELRTS;
  volatile uint32_t PSELTXD;
  volatile uint32_t PSELCTS;
  volatile uint32_t PSELRXD;
  volatile uint32_t RXD;
  volatile uint32_t TXD;
  volatile uint32_t WHATEVER9;
  volatile uint32_t BAUDRATE;
  volatile uint32_t WHATEVER10[17];
  volatile uint32_t CONFIG;
} NRF_UART_REG;



void uart_init();  //konfig GPIO-pinner som input/output
void uart_send(char letter);  //tar imot bokstav og sender til data
char uart_read(); //leser bokstaven fra datamaskinen


#endif