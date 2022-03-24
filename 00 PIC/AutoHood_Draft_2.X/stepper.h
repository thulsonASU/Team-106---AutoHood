

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
void motorCCW(int delay, int step) // --------------------------------------- //
{
    //COIL HIGHS
        //Gray = Input1B_SetHigh(); +
        //Red = Input2B_SetHigh(); +
        //Yellow = Input2A_SetHigh(); +
        //Black = Input1A_SetHigh(); +

    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    //Start Stepper Loop
    for(int i = 0; i < step; i++)
    {
    
    //Write GPIO Data
    // STEP ONE ----------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black
    
    // START STEP ONE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP TWO ----------------------------------------------------------------
    // B R-/G+
    Input2B_SetLow(); // Red
    Input1B_SetHigh(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black

    
    // START STEP TWO
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP THREE --------------------------------------------------------------
    // B R-/G+
    Input2B_SetLow(); // Red
    Input1B_SetHigh(); // Gray
    // A Y-/B+
    Input2A_SetLow(); // Yellow
    Input1A_SetHigh(); // Black

    
    // START STEP THREE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP FOUR ---------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y-/B+
    Input2A_SetLow(); // Yellow
    Input1A_SetHigh(); // Black
    
    
    // START STEP FOUR
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);    
    

    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    


    //Write GPIO Data
    // STEP FIVE ---------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black
    
    
    // START STEP FIVE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    //End Stepper Loop
    }
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

}
void motorCW(int delay, int step) // ---------------------------------------- //
{
    //COIL HIGHS
        //Gray = Input1B_SetHigh(); +
        //Red = Input2B_SetHigh(); +
        //Yellow = Input2A_SetHigh(); +
        //Black = Input1A_SetHigh(); +

    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    
    
    //Start Stepper Loop
    for( int i = 0; i < step; i++)
    {
   
    //Write GPIO Data
    // STEP ONE ----------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black
    
    // START STEP ONE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP TWO ----------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y-/B+
    Input2A_SetLow(); // Yellow
    Input1A_SetHigh(); // Black

    
    // START STEP TWO
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP THREE --------------------------------------------------------------
    // B R-/G+
    Input2B_SetLow(); // Red
    Input1B_SetHigh(); // Gray
    // A Y-/B+
    Input2A_SetLow(); // Yellow
    Input1A_SetHigh(); // Black

    
    // START STEP THREE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);
    
    
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

    
    //Write GPIO Data
    // STEP FOUR ---------------------------------------------------------------
    // B R-/G+
    Input2B_SetLow(); // Red
    Input1B_SetHigh(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black
    
    
    // START STEP FOUR
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);    
    

    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    


    //Write GPIO Data
    // STEP FIVE ---------------------------------------------------------------
    // B R+/G-
    Input2B_SetHigh(); // Red
    Input1B_SetLow(); // Gray
    // A Y+/B-
    Input2A_SetHigh(); // Yellow
    Input1A_SetLow(); // Black
    
    
    // START STEP FIVE
    EnableA_SetHigh();
    EnableB_SetHigh();
    
    delay_ms(delay);

    //End Stepper Loop
    }
    // Stop
    EnableA_SetLow();
    EnableB_SetLow();    

}