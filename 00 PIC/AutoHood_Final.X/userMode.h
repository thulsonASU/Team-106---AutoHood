#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#include "BTN_E.h"

// USER MODE IMPLEMENTATION --------------------------------------------
void UserMode() {        
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
                        //motorCCW(100,10); // Deploy Hood 10 Steps 100 ms delay
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
            motorCW(100,10); // Retract Hood 10 Steps 100 ms Delay
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