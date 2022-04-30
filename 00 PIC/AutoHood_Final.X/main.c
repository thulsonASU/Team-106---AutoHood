/*
 * Team 106
 * Aaron Clatone, Sage Furman, Tyler Hulson, Michael Reynolds
 * EGR 314 Embedded Sys Design II
 * Date Updated: 4/28/2022
 * Date Created: 2/1/2022
 */

#include "mcc_generated_files/mcc.h"
#include "BTN_E.h"
#include "stepper.h"
#include "anemometer.h"
#include "temphumidity.h"
#include "esp32.h"
#include "systemInit.h"

/*
 * Header File Descriptions
 * BTN_E.h: Button logic for long press and short press.
 * stepper.h: Motor GPIO logic for the H-bridge controller
 * anemometer.h: takes the analog signal and converts it to mV
 * temphumidity.h: requests humidity data from I2C sensor
 * esp32.h: receives weather station update from MQTT then transmits the on board data back to MQTT
 * systemInit.h: runs all system initialization including I2C, ADC, Interrupts, Handlers, and etc.
 */

#define BETWEEN(value, min, max) (value < max && value > min) // if a value is between a min and max range then do
#define I2C_ADDR_HIH6130 0x27 // set address for HIH6130

uint8_t address = I2C_ADDR_HIH6130; // Define as global

int hoodDeploy_f = 1; // set hood deploy flag
int hoodDeployed_f = 0; // set hood deployed flag
float humidity; // set humidity as a global double
uint8_t HUdata[2]; // Define humidity data as global

void main(void) {
   
    systemInit(); // system init
    
    // GET HUMIDITY UPDATE ---------------------------------------------
    LED_H_Toggle(); // toggle H led
    __delay_ms(20);
    I2C1_measReq(address); // Request Measurement
    __delay_ms(20);
    I2C1_dataFetch(address, HUdata, 2); // Fetch Data
    __delay_ms(20);
    LED_H_Toggle(); // toggle H led
    
    while (1) {
        
        // ------------------------------------------------------------------------------------------------------ //
        // main code loop do not change
        
        // if Current Wind Speed is in between the lower bound and upper bound of the weather station then deploy hood
        
        if(BETWEEN(ADCOut,rxDatafLower,rxDatafUpper)) { // 
            
            LED_A_SetHigh(); // Sets Analog Signal LED High for Debug and Demo
            
            // GET HUMIDITY UPDATE ---------------------------------------------
            LED_H_Toggle(); // toggle H led
            __delay_ms(20);
            I2C1_measReq(address); // Request Measurement
            __delay_ms(20);
            I2C1_dataFetch(address, HUdata, 2); // Fetch Data
            __delay_ms(20);
            LED_H_Toggle(); // toggle H led
    
            if(BETWEEN(huData0,0,90)){
                if(hoodDeploy_f == 1) { 
                    motorCCW(100,12); // Deploy Hood CCW 12 Steps 100 ms delay
                
                    // Update Hood Flags
                    hoodDeploy_f = 0;
                    hoodDeployed_f = 1; // ready to retract
                }
            }
            
            // GET WIND SPEED UPDATE -------------------------------------------
            ADCGetVal(); // Request Data and Measure from Anemometer
            // GET WIND SPEED UPDATE -------------------------------------------
            
            // SEND LOCAL WEATHER UPDATE TO MQTT -------------------------------
            if(rxDataf != 0) { // Waits for weather station update
                txWeather(ADCOut,huData0); // Sends Weather Data to MQTT
            }
            // SEND LOCAL WEATHER UPDATE TO MQTT -------------------------------
        }   
        else {
            
            LED_A_SetLow(); // Sets Analog Signal LED low for Debug and Demo
            
            if(hoodDeployed_f == 1) { 
                motorCW(100,8); // Retract Hood CW 8 Steps 100 ms Delay
                
                // update Hood Flags
                hoodDeploy_f = 1; // ready to deploy
                hoodDeployed_f = 0;
            }
            
            // GET WIND SPEED UPDATE -------------------------------------------
            ADCGetVal(); // Request Data and Measure from Annemometer
            // GET WIND SPEED UPDATE -------------------------------------------
            
            // SEND LOCAL WEATHER UPDATE TO MQTT -------------------------------
            if(rxDataf != 0) { // Waits for weather station update
                txWeather(ADCOut,huData0); // Sends Weather Data to MQTT
            }
            // SEND LOCAL WEATHER UPDATE TO MQTT -------------------------------
            
            // CHECK IF ENTERING USER MODE -------------------------------------
            getBTNPress();
            if(gotBTNVal == 2) { // Check if entering USER MODE
                gotBTNVal = 0;
                count = 0;
        
                LED_A_SetLow();
                LED_M_SetLow();
                LED_H_SetLow();
                LED_P_SetLow();
           
                LED_P_SetHigh();
                LED_A_SetHigh();
                __delay_ms(500);
        
                while(1) { // Enter USER MODE (HOOD RETRACTED STATE)

                    if(gotBTNVal == 1) { // Deploy Hood
                        gotBTNVal = 0;
                        count = 0;
                            while(1) { // HOOD DEPLOYED STATE
                                if(hoodDeploy_f == 1) {
                                    LED_H_SetLow();
                                    LED_M_SetHigh();                
                                    motorCCW(100,10); // Deploy Hood 10 Steps 100 ms Delay
                                    // Update Hood Flags
                                    hoodDeploy_f = 0;
                                    hoodDeployed_f = 1;
                                }
                            getBTNPress();
                                if(gotBTNVal == 1) { 
                                    gotBTNVal = 0;
                                    count = 0;
                                    break; // Break out of HOOD DEPLOYED STATE
                                }
                            }
                        }
                    if(hoodDeployed_f == 1) { //RETRACT HOOD
                        //motorCCW(100,10); // Deploy Hood 10 Steps 100 ms delay
                        LED_H_SetHigh();
                        LED_M_SetLow();
                        motorCW(100,8); // Retract Hood 8 Steps 100 ms Delay
                        // Update Hood Flags
                        hoodDeploy_f = 1;
                        hoodDeployed_f = 0;
                    }
                getBTNPress();
                if(gotBTNVal == 2) { 
                    gotBTNVal = 0;
                    count = 0;
                    LED_A_SetLow();
                    LED_M_SetLow();
                    LED_H_SetLow();
                    LED_P_SetLow();
            
                    break; // RETURN TO MAIN LOOP
                }
            }
        }
    }
            // CHECK IF ENTERING USER MODE -------------------------------------
}
}
