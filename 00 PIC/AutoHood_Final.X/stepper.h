

#include <xc.h> 
#include "mcc_generated_files/mcc.h"
void delay_ms(int milliseconds) // unsigned char milliseconds
{
   while(milliseconds > 0)
   {
      milliseconds--;
       __delay_us(990);
   }
}
void motorCW(int delay, int step) // --------------------------------------- //
{
        // Yellow = Input2A_SetHigh(); +
        // Black = Input1A_SetHigh(); +
        // Red = Input2B_SetHigh(); +
        // Gray = Input1B_SetHigh(); +
 
    //Start Stepper Loop
    for(int i = 0; i < step; i++)
    {

    //Write GPIO Data
    // STEP ONE ----------------------------------------------------------------

    Input2A_SetHigh(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);

    Input2B_SetHigh(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1); 
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP TWO ----------------------------------------------------------------

    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetHigh(); // Black
    __delay_ms(1);

    Input2B_SetHigh(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP THREE ----------------------------------------------------------------

    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetHigh(); // Black
    __delay_ms(1);

    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetHigh(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP FOUR ----------------------------------------------------------------

    Input2A_SetHigh(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);

    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetHigh(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    // SET ALL COILS TO LOW
    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);

    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1); 
    }
}
void motorCCW(int delay, int step) // --------------------------------------- //
{
        // Yellow = Input2A_SetHigh(); +
        // Black = Input1A_SetHigh(); +
        // Red = Input2B_SetHigh(); +
        // Gray = Input1B_SetHigh(); +
 
    //Start Stepper Loop
    for(int i = 0; i < step; i++)
    {
    
    //Write GPIO Data
    // STEP ONE ----------------------------------------------------------------
   
    Input2A_SetHigh(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);
  
    Input2B_SetHigh(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1); 
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP TWO ----------------------------------------------------------------
 
    Input2A_SetHigh(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);
 
    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetHigh(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP THREE ----------------------------------------------------------------
    
    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetHigh(); // Black
    __delay_ms(1);
    
    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetHigh(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    //Write GPIO Data
    // STEP FOUR ----------------------------------------------------------------

    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetHigh(); // Black
    __delay_ms(1);

    Input2B_SetHigh(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1);
    
    LED_M_Toggle();
    delay_ms(delay);
    LED_M_Toggle();
    
    // SET ALL COILS TO LOW
    Input2A_SetLow(); // Yellow
    __delay_ms(1);
    Input1A_SetLow(); // Black
    __delay_ms(1);

    Input2B_SetLow(); // Red
    __delay_ms(1);
    Input1B_SetLow(); // Gray 
    __delay_ms(1); 
    
    }
}
void hoodStepperDemo() {

        motorCW(50,8);
        
        LED_M_SetHigh();
        __delay_ms(200);
        LED_M_SetLow();
        
        motorCCW(50,8);
        
}