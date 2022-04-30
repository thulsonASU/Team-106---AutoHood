/*
 * Created by: Sage Furman
 * Integrated & Modified by: Tyler Hulson
 * Date Updated: 4/25/2022
 * Date Created: 4/21/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include <string.h>

uint8_t rxData; // esp32 read
float rxDataf = 0; // esp32 convert to float
float boundingCondition;
float rxDatafLower;
float rxDatafUpper;

int rx_f = 1; // receive flag
int tx_f = 0; // transmit flag

/*
 * \Brief: This function is designed to take data from the subscribed weather station on the MQTT server.
 * The Humidity LED is set high for visual debugging. the rx_f flag signifies it is ready to recieve the data.
 * The flag is important to prevent data collision from the txWeather function. 
 * Function reads one character from MQTT either 1-9 and converts that data type to usable wind speed.
 * \This function runs via an interrupt that fires every time EUSART receives data.
 */
void EUSART1ISR()
{
    LED_H_SetHigh(); // Debug LED to let user know data was recieved via Interrupt
    LED_M_SetHigh(); // Debug LED to let user know data was recieved via Interrupt
    __delay_ms(100);
    LED_H_SetLow(); // Debug LED to let user know data was recieved via Interrupt
    LED_M_SetLow(); // Debug LED to let user know data was recieved via Interrupt
    
    EUSART1_Receive_ISR(); // enter ISR
    
    if(rx_f == 1){ // if rx flag is ready
    
    while(!EUSART1_DataReady); // Wait for new line to come in over UART
    
    rxData = EUSART1_Read(); // read EUSART data
            
    rxDataf = (float) rxData; // convert unasigned char to float
    __delay_ms(1);
    rxDataf = (rxDataf) * (float) 3.25; // generate a value for wind speed from the weather station
    __delay_ms(1);
    
    boundingCondition = rxDataf * (float) 0.7; // Multiply rxDataf by 70 percent to get bounding condition
    __delay_ms(1);
    rxDatafLower = rxDataf - boundingCondition; // subtract rxDataf by bounding condition to get lower limit
    __delay_ms(1);
    rxDatafUpper = rxDataf + boundingCondition; // add rxDataf by bounding condition to get upper limit
    __delay_ms(1);
    
    tx_f = 1; // update tx flag
    rx_f = 0; // update rx flag
    }
}

/*
 * \Brief: This function sends weather data from the PIC to the MQTT for user.
 * \This function must run every time after sensor data is received and processed.
 */
void txWeather(float speed,float RH) {
    if(tx_f == 1) { // if tx flag is ready
    while(!EUSART1_is_tx_ready()); // wait until tx is ready
    
    printf("Wind Speed: %1.0f mV, Humidity: %1.0f PRH", speed, RH); // print wind speed to esp32 buffer
    __delay_ms(0.5); // delay for EUSART to catch up
    printf("\r\n"); // carriage return and stuff
    
    while(!EUSART1_is_tx_done()); // wait until done transmitting
    }
}
