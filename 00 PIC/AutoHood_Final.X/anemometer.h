/*
 * Created by: Michael Reynolds
 * Integrated by: Tyler Hulson
 * Date Updated: 4/21/2022
 * Date Created: 4/14/2022
 */

#include <xc.h> 
#include "mcc_generated_files/mcc.h"

// Set Global Variables for Anemometer
float voltage;
float ADCOut;
float RESOLUTION = 0.34; // Anemometer math
/*
 * \Brief: This function takes and converts the ADCC Value
 * \This function runs once every time ADCC needs to be updated
 */
void ADCGetVal() {
    LED_P_Toggle(); // toggle P led
    __delay_ms(200);
            
    adc_result_t convertedValue; // converted thingy
   
    convertedValue = ADCC_GetSingleConversion(ANA); // get converted value from ADC
    voltage = (float) convertedValue; // convert to float
   
    ADCOut = (RESOLUTION * voltage); // apply maths
    ADCOut = ADCOut - (float) 64; // correction is 64 ish
    LED_P_Toggle(); // toggle P led
    __delay_ms(200);
}