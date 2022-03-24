#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();

    while (1)
    {
        // Breadboard System test branch
        // Add your application code
        if(RC7 == 1)
        {    
            LED6_Toggle();
            __delay_ms(200);
        }
        else
        {
            LED6_Toggle();
            __delay_ms(500);
        }
    }
}
/**
 End of File
*/