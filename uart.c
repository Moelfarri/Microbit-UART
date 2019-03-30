#include <stdint.h>
#include "uart.h" 
#include "gpio.h"



//NRF_UART_REG;


void uart_init(){
    GPIO->PIN_CNF[24] = 1; //Pinne TXD / output
	GPIO->PIN_CNF[25] = 0; //Pinne RXD / input
	UART->PSELTXD=24;
	UART->PSELRXD=25;
	
	UART->BAUDRATE=0x00275000;

	UART->PSELCTS = 0xFFFFFFFF;
	UART->PSELRTS = 0xFFFFFFFF;

	UART->STARTRX = 1;
	UART->ENABLE = 4;
}


void uart_send(char letter){ //tar imot bokstav og sender til data
	UART->STARTTX = 1; //ta imot meldinger
	UART->TXD = letter;
	while (!(UART->TXDRDY));
	UART->TXDRDY=0;

	
	
	UART->STOPTX=1; 
} 


char uart_read(){ //leser bokstaven fra datamaskinen
	if(!(UART->RXDRDY)){
		return '\0';
	}
	UART->RXDRDY=0;
	char letter;
	letter = UART->RXD;
	return letter;
} 