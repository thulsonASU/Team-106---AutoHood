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

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA1
#define LED1_LAT                  LATAbits.LATA1
#define LED1_PORT                 PORTAbits.RA1
#define LED1_WPU                  WPUAbits.WPUA1
#define LED1_OD                   ODCONAbits.ODCA1
#define LED1_ANS                  ANSELAbits.ANSELA1
#define LED1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED1_GetValue()           PORTAbits.RA1
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA2
#define LED2_LAT                  LATAbits.LATA2
#define LED2_PORT                 PORTAbits.RA2
#define LED2_WPU                  WPUAbits.WPUA2
#define LED2_OD                   ODCONAbits.ODCA2
#define LED2_ANS                  ANSELAbits.ANSELA2
#define LED2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED2_GetValue()           PORTAbits.RA2
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA3
#define LED3_LAT                  LATAbits.LATA3
#define LED3_PORT                 PORTAbits.RA3
#define LED3_WPU                  WPUAbits.WPUA3
#define LED3_OD                   ODCONAbits.ODCA3
#define LED3_ANS                  ANSELAbits.ANSELA3
#define LED3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED3_GetValue()           PORTAbits.RA3
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISAbits.TRISA4
#define LED4_LAT                  LATAbits.LATA4
#define LED4_PORT                 PORTAbits.RA4
#define LED4_WPU                  WPUAbits.WPUA4
#define LED4_OD                   ODCONAbits.ODCA4
#define LED4_ANS                  ANSELAbits.ANSELA4
#define LED4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED4_GetValue()           PORTAbits.RA4
#define LED4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS                 TRISAbits.TRISA5
#define LED5_LAT                  LATAbits.LATA5
#define LED5_PORT                 PORTAbits.RA5
#define LED5_WPU                  WPUAbits.WPUA5
#define LED5_OD                   ODCONAbits.ODCA5
#define LED5_ANS                  ANSELAbits.ANSELA5
#define LED5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED5_GetValue()           PORTAbits.RA5
#define LED5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set enableA aliases
#define enableA_TRIS                 TRISBbits.TRISB0
#define enableA_LAT                  LATBbits.LATB0
#define enableA_PORT                 PORTBbits.RB0
#define enableA_WPU                  WPUBbits.WPUB0
#define enableA_OD                   ODCONBbits.ODCB0
#define enableA_ANS                  ANSELBbits.ANSELB0
#define enableA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define enableA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define enableA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define enableA_GetValue()           PORTBbits.RB0
#define enableA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define enableA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define enableA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define enableA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define enableA_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define enableA_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define enableA_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define enableA_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set enableB aliases
#define enableB_TRIS                 TRISBbits.TRISB1
#define enableB_LAT                  LATBbits.LATB1
#define enableB_PORT                 PORTBbits.RB1
#define enableB_WPU                  WPUBbits.WPUB1
#define enableB_OD                   ODCONBbits.ODCB1
#define enableB_ANS                  ANSELBbits.ANSELB1
#define enableB_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define enableB_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define enableB_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define enableB_GetValue()           PORTBbits.RB1
#define enableB_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define enableB_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define enableB_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define enableB_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define enableB_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define enableB_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define enableB_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define enableB_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set input1A aliases
#define input1A_TRIS                 TRISBbits.TRISB2
#define input1A_LAT                  LATBbits.LATB2
#define input1A_PORT                 PORTBbits.RB2
#define input1A_WPU                  WPUBbits.WPUB2
#define input1A_OD                   ODCONBbits.ODCB2
#define input1A_ANS                  ANSELBbits.ANSELB2
#define input1A_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define input1A_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define input1A_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define input1A_GetValue()           PORTBbits.RB2
#define input1A_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define input1A_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define input1A_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define input1A_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define input1A_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define input1A_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define input1A_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define input1A_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set input2A aliases
#define input2A_TRIS                 TRISBbits.TRISB3
#define input2A_LAT                  LATBbits.LATB3
#define input2A_PORT                 PORTBbits.RB3
#define input2A_WPU                  WPUBbits.WPUB3
#define input2A_OD                   ODCONBbits.ODCB3
#define input2A_ANS                  ANSELBbits.ANSELB3
#define input2A_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define input2A_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define input2A_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define input2A_GetValue()           PORTBbits.RB3
#define input2A_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define input2A_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define input2A_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define input2A_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define input2A_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define input2A_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define input2A_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define input2A_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set input1B aliases
#define input1B_TRIS                 TRISBbits.TRISB4
#define input1B_LAT                  LATBbits.LATB4
#define input1B_PORT                 PORTBbits.RB4
#define input1B_WPU                  WPUBbits.WPUB4
#define input1B_OD                   ODCONBbits.ODCB4
#define input1B_ANS                  ANSELBbits.ANSELB4
#define input1B_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define input1B_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define input1B_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define input1B_GetValue()           PORTBbits.RB4
#define input1B_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define input1B_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define input1B_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define input1B_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define input1B_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define input1B_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define input1B_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define input1B_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set input2B aliases
#define input2B_TRIS                 TRISBbits.TRISB5
#define input2B_LAT                  LATBbits.LATB5
#define input2B_PORT                 PORTBbits.RB5
#define input2B_WPU                  WPUBbits.WPUB5
#define input2B_OD                   ODCONBbits.ODCB5
#define input2B_ANS                  ANSELBbits.ANSELB5
#define input2B_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define input2B_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define input2B_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define input2B_GetValue()           PORTBbits.RB5
#define input2B_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define input2B_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define input2B_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define input2B_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define input2B_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define input2B_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define input2B_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define input2B_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

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