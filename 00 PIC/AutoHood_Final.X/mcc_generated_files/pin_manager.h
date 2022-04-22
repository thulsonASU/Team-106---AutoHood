/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18LF26K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ANA aliases
#define ANA_TRIS                 TRISAbits.TRISA0
#define ANA_LAT                  LATAbits.LATA0
#define ANA_PORT                 PORTAbits.RA0
#define ANA_WPU                  WPUAbits.WPUA0
#define ANA_OD                   ODCONAbits.ODCA0
#define ANA_ANS                  ANSELAbits.ANSELA0
#define ANA_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ANA_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ANA_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ANA_GetValue()           PORTAbits.RA0
#define ANA_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ANA_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ANA_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ANA_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ANA_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ANA_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ANA_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define ANA_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LED_A aliases
#define LED_A_TRIS                 TRISAbits.TRISA1
#define LED_A_LAT                  LATAbits.LATA1
#define LED_A_PORT                 PORTAbits.RA1
#define LED_A_WPU                  WPUAbits.WPUA1
#define LED_A_OD                   ODCONAbits.ODCA1
#define LED_A_ANS                  ANSELAbits.ANSELA1
#define LED_A_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_A_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_A_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_A_GetValue()           PORTAbits.RA1
#define LED_A_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_A_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_A_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_A_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_A_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_A_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_A_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LED_A_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LED_H aliases
#define LED_H_TRIS                 TRISAbits.TRISA2
#define LED_H_LAT                  LATAbits.LATA2
#define LED_H_PORT                 PORTAbits.RA2
#define LED_H_WPU                  WPUAbits.WPUA2
#define LED_H_OD                   ODCONAbits.ODCA2
#define LED_H_ANS                  ANSELAbits.ANSELA2
#define LED_H_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_H_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_H_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_H_GetValue()           PORTAbits.RA2
#define LED_H_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_H_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_H_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_H_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_H_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_H_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_H_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED_H_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED_M aliases
#define LED_M_TRIS                 TRISAbits.TRISA4
#define LED_M_LAT                  LATAbits.LATA4
#define LED_M_PORT                 PORTAbits.RA4
#define LED_M_WPU                  WPUAbits.WPUA4
#define LED_M_OD                   ODCONAbits.ODCA4
#define LED_M_ANS                  ANSELAbits.ANSELA4
#define LED_M_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_M_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_M_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_M_GetValue()           PORTAbits.RA4
#define LED_M_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_M_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_M_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_M_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_M_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_M_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_M_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED_M_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED_P aliases
#define LED_P_TRIS                 TRISAbits.TRISA5
#define LED_P_LAT                  LATAbits.LATA5
#define LED_P_PORT                 PORTAbits.RA5
#define LED_P_WPU                  WPUAbits.WPUA5
#define LED_P_OD                   ODCONAbits.ODCA5
#define LED_P_ANS                  ANSELAbits.ANSELA5
#define LED_P_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_P_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_P_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_P_GetValue()           PORTAbits.RA5
#define LED_P_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_P_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_P_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_P_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_P_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_P_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_P_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_P_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set xtraGPIO aliases
#define xtraGPIO_TRIS                 TRISAbits.TRISA6
#define xtraGPIO_LAT                  LATAbits.LATA6
#define xtraGPIO_PORT                 PORTAbits.RA6
#define xtraGPIO_WPU                  WPUAbits.WPUA6
#define xtraGPIO_OD                   ODCONAbits.ODCA6
#define xtraGPIO_ANS                  ANSELAbits.ANSELA6
#define xtraGPIO_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define xtraGPIO_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define xtraGPIO_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define xtraGPIO_GetValue()           PORTAbits.RA6
#define xtraGPIO_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define xtraGPIO_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define xtraGPIO_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define xtraGPIO_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define xtraGPIO_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define xtraGPIO_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define xtraGPIO_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define xtraGPIO_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set BTN_D aliases
#define BTN_D_TRIS                 TRISAbits.TRISA7
#define BTN_D_LAT                  LATAbits.LATA7
#define BTN_D_PORT                 PORTAbits.RA7
#define BTN_D_WPU                  WPUAbits.WPUA7
#define BTN_D_OD                   ODCONAbits.ODCA7
#define BTN_D_ANS                  ANSELAbits.ANSELA7
#define BTN_D_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BTN_D_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BTN_D_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BTN_D_GetValue()           PORTAbits.RA7
#define BTN_D_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BTN_D_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BTN_D_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BTN_D_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BTN_D_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define BTN_D_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define BTN_D_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define BTN_D_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set Input2B aliases
#define Input2B_TRIS                 TRISBbits.TRISB0
#define Input2B_LAT                  LATBbits.LATB0
#define Input2B_PORT                 PORTBbits.RB0
#define Input2B_WPU                  WPUBbits.WPUB0
#define Input2B_OD                   ODCONBbits.ODCB0
#define Input2B_ANS                  ANSELBbits.ANSELB0
#define Input2B_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define Input2B_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define Input2B_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define Input2B_GetValue()           PORTBbits.RB0
#define Input2B_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define Input2B_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define Input2B_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define Input2B_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define Input2B_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define Input2B_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define Input2B_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define Input2B_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set Input1B aliases
#define Input1B_TRIS                 TRISBbits.TRISB1
#define Input1B_LAT                  LATBbits.LATB1
#define Input1B_PORT                 PORTBbits.RB1
#define Input1B_WPU                  WPUBbits.WPUB1
#define Input1B_OD                   ODCONBbits.ODCB1
#define Input1B_ANS                  ANSELBbits.ANSELB1
#define Input1B_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Input1B_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Input1B_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Input1B_GetValue()           PORTBbits.RB1
#define Input1B_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Input1B_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Input1B_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define Input1B_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define Input1B_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define Input1B_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define Input1B_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define Input1B_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set EnableB aliases
#define EnableB_TRIS                 TRISBbits.TRISB2
#define EnableB_LAT                  LATBbits.LATB2
#define EnableB_PORT                 PORTBbits.RB2
#define EnableB_WPU                  WPUBbits.WPUB2
#define EnableB_OD                   ODCONBbits.ODCB2
#define EnableB_ANS                  ANSELBbits.ANSELB2
#define EnableB_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define EnableB_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define EnableB_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define EnableB_GetValue()           PORTBbits.RB2
#define EnableB_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define EnableB_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define EnableB_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define EnableB_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define EnableB_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define EnableB_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define EnableB_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define EnableB_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set Input2A aliases
#define Input2A_TRIS                 TRISBbits.TRISB3
#define Input2A_LAT                  LATBbits.LATB3
#define Input2A_PORT                 PORTBbits.RB3
#define Input2A_WPU                  WPUBbits.WPUB3
#define Input2A_OD                   ODCONBbits.ODCB3
#define Input2A_ANS                  ANSELBbits.ANSELB3
#define Input2A_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define Input2A_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define Input2A_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define Input2A_GetValue()           PORTBbits.RB3
#define Input2A_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define Input2A_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define Input2A_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define Input2A_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define Input2A_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define Input2A_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define Input2A_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define Input2A_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set Input1A aliases
#define Input1A_TRIS                 TRISBbits.TRISB4
#define Input1A_LAT                  LATBbits.LATB4
#define Input1A_PORT                 PORTBbits.RB4
#define Input1A_WPU                  WPUBbits.WPUB4
#define Input1A_OD                   ODCONBbits.ODCB4
#define Input1A_ANS                  ANSELBbits.ANSELB4
#define Input1A_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define Input1A_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define Input1A_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define Input1A_GetValue()           PORTBbits.RB4
#define Input1A_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define Input1A_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define Input1A_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define Input1A_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define Input1A_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define Input1A_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define Input1A_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define Input1A_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set EnableA aliases
#define EnableA_TRIS                 TRISBbits.TRISB5
#define EnableA_LAT                  LATBbits.LATB5
#define EnableA_PORT                 PORTBbits.RB5
#define EnableA_WPU                  WPUBbits.WPUB5
#define EnableA_OD                   ODCONBbits.ODCB5
#define EnableA_ANS                  ANSELBbits.ANSELB5
#define EnableA_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define EnableA_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define EnableA_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define EnableA_GetValue()           PORTBbits.RB5
#define EnableA_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define EnableA_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define EnableA_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define EnableA_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define EnableA_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define EnableA_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define EnableA_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define EnableA_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set xtraGPIO_1 aliases
#define xtraGPIO_1_TRIS                 TRISCbits.TRISC0
#define xtraGPIO_1_LAT                  LATCbits.LATC0
#define xtraGPIO_1_PORT                 PORTCbits.RC0
#define xtraGPIO_1_WPU                  WPUCbits.WPUC0
#define xtraGPIO_1_OD                   ODCONCbits.ODCC0
#define xtraGPIO_1_ANS                  ANSELCbits.ANSELC0
#define xtraGPIO_1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define xtraGPIO_1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define xtraGPIO_1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define xtraGPIO_1_GetValue()           PORTCbits.RC0
#define xtraGPIO_1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define xtraGPIO_1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define xtraGPIO_1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define xtraGPIO_1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define xtraGPIO_1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define xtraGPIO_1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define xtraGPIO_1_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define xtraGPIO_1_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set xtraGPIO_2 aliases
#define xtraGPIO_2_TRIS                 TRISCbits.TRISC1
#define xtraGPIO_2_LAT                  LATCbits.LATC1
#define xtraGPIO_2_PORT                 PORTCbits.RC1
#define xtraGPIO_2_WPU                  WPUCbits.WPUC1
#define xtraGPIO_2_OD                   ODCONCbits.ODCC1
#define xtraGPIO_2_ANS                  ANSELCbits.ANSELC1
#define xtraGPIO_2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define xtraGPIO_2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define xtraGPIO_2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define xtraGPIO_2_GetValue()           PORTCbits.RC1
#define xtraGPIO_2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define xtraGPIO_2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define xtraGPIO_2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define xtraGPIO_2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define xtraGPIO_2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define xtraGPIO_2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define xtraGPIO_2_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define xtraGPIO_2_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set BTN_E aliases
#define BTN_E_TRIS                 TRISCbits.TRISC4
#define BTN_E_LAT                  LATCbits.LATC4
#define BTN_E_PORT                 PORTCbits.RC4
#define BTN_E_WPU                  WPUCbits.WPUC4
#define BTN_E_OD                   ODCONCbits.ODCC4
#define BTN_E_ANS                  ANSELCbits.ANSELC4
#define BTN_E_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define BTN_E_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define BTN_E_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BTN_E_GetValue()           PORTCbits.RC4
#define BTN_E_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define BTN_E_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define BTN_E_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define BTN_E_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define BTN_E_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define BTN_E_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define BTN_E_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define BTN_E_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/