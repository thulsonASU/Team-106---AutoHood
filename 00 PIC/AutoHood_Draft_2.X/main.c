#include "mcc_generated_files/mcc.h"
#include "stepper.h"

void main(void)
{
   
    SYSTEM_Initialize();

    // Power Up LED
    
    LED_A_SetHigh();
    __delay_ms(200);
    
    LED_H_SetHigh();
    __delay_ms(200);
    
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
            LED_M_SetHigh();
            __delay_ms(200);
            
            motorCW(100,5);
            motorCCW(100,5);
            
            LED_M_SetLow();
            __delay_ms(200);
        }
        else
        {
            LED_P_Toggle();
            __delay_ms(200);
            
            adc_result_t convertedValue;
   
            convertedValue = ADCC_GetSingleConversion(ANA);
            Voltage = (float) convertedValue;
   
            VoltageActual = (Resolution * Voltage);
            
            if (VoltageActual>70) //mV
            {
                LED_A_SetHigh();
            }
            else
            {
                LED_A_SetLow();
            }
        }
                // MICHAEL ANNEMOMETER         
    }
}
/**
 End of File
*/