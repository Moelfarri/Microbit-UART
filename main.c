#include <stdint.h>
#include <stdio.h>
#include "gpio.h"
#include "uart.h"


ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
     	return count;
    }


int main(){
	uart_init();
	int lightOn = 0;

	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);

    }

	// Configure buttons
	GPIO->PIN_CNF[17] = 0; //Pinne A
	GPIO->PIN_CNF[26] = 0; //Pinne B

	int sleep = 0;
	while(1){

		/* Check if button B is pressed;*/
        if(!(GPIO->IN & (1 << 26))){
			//uart_send('B');
			iprintf("Norway has %d counties. \n\r",18);  //press B to Breakdance!
           
        }


        
        /* Check if button A is pressed; */
       if(!(GPIO->IN & (1 << 17))){
           uart_send('A');
       } 

       if(uart_read()!= '\0'){
       	    if (lightOn){
        	    for(int j=13; j<=15; j++){
                   GPIO->OUTCLR = (1 << j);
                }
            lightOn=0;
        }
       	    else{ 
       		    for(int j=13; j<=15; j++){
            	   GPIO->OUTSET = (1 << j);
                }

            lightOn=1;
        }



       	}



		sleep = 10000;
		while(--sleep);

    }














	return 0;
}