#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
// #include <string.h>

uint8_t rxData; // esp32 read
float rxDataf = 0; // esp32 convert to float
float boundingCondition;
float rxDatafLower;
float rxDatafUpper;

void EUSART1ISR()
{
    EUSART1_Receive_ISR(); // enter ISR
    
    if(EUSART1_is_rx_ready()) { // wait until rx is ready
        rxData = EUSART1_Read(); // read from esp32 buffer
    }
            
    rxDataf = (float)rxData; // convert unasigned char to float
    rxDataf = (rxDataf - 48)*100; // generate a value for wind speed from the weather station
    
    boundingCondition = rxDataf*0.2; // Multiply rxDataf by 20 percent to get bounding condition
    rxDatafLower = rxDataf - boundingCondition; // subtract rxDataf by bounding condition to get lower limit
    rxDatafUpper = rxDataf + boundingCondition; // add rxDataf by bounding condition to get upper limit
}

void txWindSpeed(float speed) {
    while(!EUSART1_is_tx_ready()); // wait until tx is ready

    printf("Wind Speed: %1.0f", speed); // print wind speed to esp32 buffer
    __delay_ms(0.5); // delay for eusart to catch up
    printf("\r\n"); // carriage return and stuff
    
    while(!EUSART1_is_tx_done()); // wait until done transmitting
}
