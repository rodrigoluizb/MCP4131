/* 
 * File:   example.c
 * Author: rodrigobarbosa
 *
 * Created on April 29, 2016, 1:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "MCP4131.h"
#include <xc.h>

#pragma config FOSC = INTIO67   // Oscillator Selection bits 
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit 
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit 

// CONFIG2L
#pragma config PWRT = ON          // Power-up Timer Enable bit 
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits 
#pragma config BORV = 30        // Brown Out Reset Voltage bits 

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit 
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits 

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit
#pragma config PBADEN = ON     // PORTB A/D Enable bit
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit
#pragma config HFOFST = OFF     // HFINTOSC Fast Start-up
#pragma config MCLRE = OFF       // MCLR Pin Enable bit

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit 
#pragma config XINST = OFF      // Extended Instruction Set Enable bit

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0
#pragma config CP1 = OFF        // Code Protection Block 1 
#pragma config CP2 = OFF        // Code Protection Block 2 
#pragma config CP3 = OFF        // Code Protection Block 3 

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit 
#pragma config CPD = OFF        // Data EEPROM Code Protection bit 

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 
#pragma config WRT1 = OFF       // Write Protection Block 1 
#pragma config WRT2 = OFF       // Write Protection Block 2 
#pragma config WRT3 = OFF       // Write Protection Block 3 

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit 
#pragma config WRTB = OFF       // Boot Block Write Protection bit 
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit 

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 
#pragma config EBTR2 = OFF      // Table Read Protection Block 2  
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit 
#define _XTAL_FREQ  8000000

/*
 * 
 */
int main() {
    char i=0;
    SPI_init();
    OSCCON = 0b11101100;
    writeVal(i);
    while(1){
        while(i<128){
            increment();
            i++;
        }
        i=0;
        while(i<128){
            decrement();
            i++;
        }
        i=0;
    }
    return 0;
}

