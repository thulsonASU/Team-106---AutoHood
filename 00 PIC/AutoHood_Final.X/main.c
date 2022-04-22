#include "mcc_generated_files/mcc.h"
#include "stepper.h"
// stepper.h includes the following functions
// motorCW(delay, steps); moves stepper x amount of steps Clockwise
// motorCCW(delay, steps); moves stepper x amount of steps Counter-Clockwise
// hoodStepperDemo(); deploys the hood from a neutral position 8 steps then retracts the hood another 8 steps. neutral is parallel to the shoulder pads.

    // Tested functions
    // Amperage Draw 0.8A from power supply
    // Max Fuse 1.5A
    // hoodStepperDemo();
#include "anemometer.h"
// anemometer.h includes the following functions
// ADCGetVal(); returns ADCOut
#include "temphumidity.h"
// temphumidity.h includes the following functions and definitions
// I2C1_measReq(i2c1_address_t address);
// I2C1_dataFetch(i2c1_address_t address, uint8_t *data, size_t len); returns humidity
#include "esp32.h"
// esp32.h includes the following functions and definitions
// EUSART1ISR() uses interrupts to update rxData from ESP32 from MQTT server
// txWindSpeed(float speed) transmits wind speed from ADC to esp32 to MQTT server

#define BETWEEN(value, min, max) (value < max && value > min)
#define I2C_ADDR_HIH6130 0x27 // set address for HIH6130 0x27
double humidity; // set humidity as a global double
uint8_t HUdata[2]; // Define as global

uint8_t address = I2C_ADDR_HIH6130; // Define as global

float currentWind = 301; // place holder wind speed

void main(void) {
   
    SYSTEM_Initialize();
    I2C1_Initialize();
    ADCC_Initialize();
           
    EUSART1_SetRxInterruptHandler(EUSART1ISR);
 
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    // Power Up LED
    
    LED_A_SetHigh();
    __delay_ms(200);
    
    LED_H_SetHigh();
    __delay_ms(200);
    
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    LED_M_SetHigh();
    __delay_ms(200);
    
    LED_P_SetHigh();
    __delay_ms(200);
    
    // Power Down LED
    
    LED_A_SetLow();
    __delay_ms(200);
    
    LED_H_SetLow();
    __delay_ms(200);
    
    LED_M_SetLow();
    __delay_ms(200);
    
    LED_P_SetLow();
    __delay_ms(200);
    
    while (1) {
        
        // ------------------------------------------------------------------------------------------------------ //
        // main code loop do not change
        
        if(rxDataf != 0){ // Waits for weather station update
        txWindSpeed(currentWind); // Sends Wind Speed to MQTT
        }
        
        // if Current Wind Speed is in between the lower bound and upper bound of the weather station then deploy hood
        if(BETWEEN(currentWind,rxDatafLower,rxDatafUpper)) // && BETWEEN(currentHumidity,50,90)
        {
            LED_A_SetHigh(); // test LED for analog sensor (basically before hood deployment)
        }
        
        LED_A_SetLow(); // set LED low in main loop
        
        // main code loop do not change
        // ---------------------------------------------------------------------------------------------------- //
        
        // ---------------------------------------------------------------------------------------------------- //
        // test code
        
        // MIKE ANNEMOMETER TEST
        // ADCGetVal();
        
        // TYLER STEPPER MOTOR DEMO
        // hoodStepperDemo();
        
        /** AARON HUMIDITY SENSOR TEST
        LED_A_Toggle();
        __delay_ms(100);
    
        I2C1_measReq(address);
        I2C1_dataFetch(address, HUdata, 2);
        
        humidity = ((((HUdata[0] & 0x3F) * 256) + HUdata[1]) * 100) / 16383;
        
        if (humidity >= 0) {
        LED_H_Toggle();
        __delay_ms(100);
        LED_A_Toggle();
        __delay_ms(100);
        }
        */
        
        
        }  
    }