
#include <xc.h> 
#include "mcc_generated_files/mcc.h"

// Set Global Variables for Anemometer
float voltage;
float ADCOut;
float RESOLUTION = 0.34; // Anemometer math

void ADCGetVal() {
    LED_P_Toggle(); // toggle P led?
    __delay_ms(200);
            
    adc_result_t convertedValue; // converted thingy
   
    convertedValue = ADCC_GetSingleConversion(ANA); // get converted value from ADC
    voltage = (float) convertedValue; // convert to float
   
    ADCOut = (RESOLUTION * voltage); // apply maths
}