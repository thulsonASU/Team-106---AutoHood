#include "mcc_generated_files/mcc.h"

void main(void)
{
   
    SYSTEM_Initialize();

    while (1)
    {
        // Breadboard System test
        // Add your application code
        LED6_Toggle();
        __delay_ms(500);
    }
}
/**
 End of File
*/