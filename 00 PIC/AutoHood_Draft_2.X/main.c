#include "mcc_generated_files/mcc.h"
#include "stepper.h"

void main(void)
{
   
    SYSTEM_Initialize();

    // MICHAEL SUBSYSTEM ANNEMOMETER
    float Voltage;
    float VoltageActual;
    float Resolution = 0.34;//3.3 / (2^12);
   
    //PWM3_Initialize();
    ADCC_Initialize();
    //ADCC_DisableContinuousConversion();
   // MICHAEL SUBSYSTEM ANNEMOMETER
 
    while (1)
    {
        // Breadboard System test branch
        // Add your application code
        if(RA7 == 0)
        {    
            LED7_Toggle();
            __delay_ms(200);
            motorCW(100,5);
            motorCCW(100,5);
            
        }
        else
        {
            LED6_Toggle();
            __delay_ms(500);
            adc_result_t convertedValue;
   
   
            convertedValue = ADCC_GetSingleConversion(ANA);
            Voltage = (float) convertedValue;
   
            VoltageActual = (Resolution * Voltage);
   
            if (VoltageActual>70) //mV
            RA5=1;
            else
            {
            RA5=0;
            }
        
        }
                // MICHAEL ANNEMOMETER         
    
    }
}
/**
 End of File
*/