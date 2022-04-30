/*
 * Created by: Tyler Hulson
 * Integrated by: Tyler Hulson
 * Date Updated: 4/25/2022
 * Date Created: 4/25/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"
#define PRESSDURATION 250
#define SHORTPRESS 1
#define LONGPRESS 2
int BTN_Val;
int gotBTNVal = 0;
unsigned char count = 0;

/*
 * \Brief: get a long press or short press from the E_BTN
 * \This function runs once every time you want a button update.
 *  Make sure to reset count and gotBTNVal to 0 after the if statement.
 *  
 *  2 is a long press
 *  1 is a short press
 * 
 * EXAMPLE: 
 * getBTNPress();
 * if(gotBTNVal == 2) {
 *      gotBTNVal = 0;
 *      count = 0;
 * }
 */
void getBTNPress() {
    BTN_Val = BTN_E_GetValue();    
    
    //gotBTNVal = 0;
    //count = 0;
        
    while (BTN_Val == 0) { 
        //LED_H_SetHigh();
        __delay_ms(1);
        count = count + 1; //increment count if key is continuously pressed  
        if (count > PRESSDURATION) {
            break;
        }
        BTN_Val = BTN_E_GetValue();
        if(BTN_Val == 1) {    
            break;
        }
    }
    
    if(count != 0) {
        if (count >= PRESSDURATION) { 
            gotBTNVal = LONGPRESS;
        }
        if (count < PRESSDURATION) { 
            gotBTNVal = SHORTPRESS;
        }
    }
}

 // More Example Code
    /*    
    if(gotBTNVal == 2) { 
        LED_A_SetHigh();
        LED_M_SetLow();
        __delay_ms(1000);
        gotBTNVal = 0;
        count = 0;
    }
    if(gotBTNVal == 1) {
        LED_A_SetLow();
        LED_M_SetHigh();
        __delay_ms(1000);
        gotBTNVal = 0;
        count = 0;
    }
        LED_A_SetLow();
        LED_M_SetLow();
    */