/*
 * Created by: Tyler Hulson
 * Integrated by: Tyler Hulson
 * Date Updated: 4/26/2022
 * Date Created: 4/26/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"

/*
 * \Brief: Initializes system variables, functions, and LEDs
 * \This runs once in void main @ system start
 */
void systemInit() { 
    
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
}