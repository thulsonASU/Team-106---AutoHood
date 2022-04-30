/*
 * Created by: Tyler Hulson
 * Integrated by: Tyler Hulson
 * Date Updated: 4/26/2022
 * Date Created: 4/14/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"
// CW is Retracting Hood
// CCW is Deploying Hood

/*
 * \Brief: This function is a custom delay function that had to be created due to __delay_ms not allowing a variable
 * \This function runs every time it is required to delay for a rough amount of ms
 */
void delay_ms(int milliseconds) // unsigned char milliseconds
{
   while(milliseconds > 0)
   {
      milliseconds--;
       __delay_us(990);
   }
}
/*
 * \Brief: This function moves the stepper motor CW with a delay between step and step amount variables
 * Wire sequence is as follows from left to right with header in bottom right hand corner facing up:
 * POS1: Yellow
 * POS2: Black
 * POS3: Red
 * POS4: Gray
 */
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
    }
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
/*
 * \Brief: This function moves the stepper motor CCW with a delay between step and step amount variables
 * Wire sequence is as follows from left to right with header in bottom right hand corner facing up:
 * POS1: Yellow
 * POS2: Black
 * POS3: Red
 * POS4: Gray
 */
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
    Input1A_SetHigh(); // Black
    
    Input2B_SetLow(); // Red
    Input1B_SetHigh(); // Gray 
    
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
    
    }
    
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