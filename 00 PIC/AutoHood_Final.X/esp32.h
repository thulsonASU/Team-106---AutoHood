#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include <string.h>

uint8_t rxData; // esp32 read
float rxDataf = 0; // esp32 convert to float
float boundingCondition;
float rxDatafLower;
float rxDatafUpper;

int rx_f = 1; // recieve flag
int tx_f = 0; // transmit flag

void EUSART1ISR()
{
    LED_H_Toggle();
    
    EUSART1_Receive_ISR(); // enter ISR
    
    if(rx_f == 1){
    
//    while (EUSART1_Read() != 0x24);
    while(!EUSART1_DataReady); // Wait for new line to come in over UART
    
    rxData = EUSART1_Read();
    
    //if(EUSART1_is_rx_ready()) { // wait until rx is ready
        //for(int k = 0; k<= 50;k++) { 
            //if(eusart1RxCount == 0) {
                //break;
            //}
        //}
        // rxData = EUSART1_Read(); // read from esp32 buffer
    //}
            
    rxDataf = (float) rxData; // convert unasigned char to float
    __delay_ms(1);
    rxDataf = (rxDataf) * (float) 1; // generate a value for wind speed from the weather station
    __delay_ms(1);
    
    // debug math: rxDataf = (rxDataf - 48) * (float) 100;
    
    boundingCondition = rxDataf * (float) 0.5; // Multiply rxDataf by 70 percent to get bounding condition
    __delay_ms(1);
    rxDatafLower = rxDataf - boundingCondition; // subtract rxDataf by bounding condition to get lower limit
    __delay_ms(1);
    rxDatafUpper = rxDataf + boundingCondition; // add rxDataf by bounding condition to get upper limit
    __delay_ms(1);
    
    tx_f = 1;
    rx_f = 0;
    }
}

void txWindSpeed(float speed) {
    if(tx_f == 1) {
    while(!EUSART1_is_tx_ready()); // wait until tx is ready
    
    printf("Wind Speed: %1.0f", speed); // print wind speed to esp32 buffer
    __delay_ms(0.5); // delay for eusart to catch up
    printf("\r\n"); // carriage return and stuff
    
    while(!EUSART1_is_tx_done()); // wait until done transmitting
    rx_f = 0;
    }
}
