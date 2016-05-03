/****************************************
Filename: MCP4131.c
Module: MCP4131, digital Potentiometer
Company: Microchip 
This code was developed in a PIC18F45K20
Author: Rodrigo Barbosa
The commands tested only send data to 
the chip. Read the datasheet to see how that
can be done.
 ***************************************/

#include "MCP4131.h"
#include <xc.h>
#include "p18f45k20.h"
#define triscs TRISC1
#define cs PORTCbits.RC1
#define _XTAL_FREQ  8000000


/***********************************************
 Function: SPI_init()
 Return value: void
 Parameters: Void
 Description: This function initializes the SPI
 module, by setting the registers that control 
 this peripheral.
 ***********************************************/
void SPI_init()
{
    triscs = 0;
    cs = 1;
    SSPEN = 0;
    TRISC3 = 0;     //SCK
    TRISC4 = 1;      //SDI
    TRISC5 = 0;     //SDO
    CKE = 1;
    SSPCON1 = 0x01;  //CKP = 0, SCK = 1MHz
    SMP = 1;
    SSPEN = 1;
}

/***********************************************
 Function: SPI_transfer()
 Return value: unsigned char
 Parameters: unsigned char data
 Description: This function sends an unsigned
 char through the SPI interface and returns the 
 value received.
 ***********************************************/
unsigned char SPI_transfer(unsigned char data)
{
    cs=0;
    SSPBUF = data;       // Put command into SPI buffer
    while (!BF);         // Wait for the transfer to finish
    return SSPBUF;       // Save the read value
    cs=1;
}

/***********************************************
 Function: writeVal()
 Return value: void
 Parameters: char
 Description: This function sends a value that
 will change the wiper's value.
 ***********************************************/
void writeVal(char val){
    SPI_transfer(0);
    SPI_transfer(val);
    __delay_ms(10);
}

/***********************************************
 Function: increment()
 Return value: void
 Parameters: void
 Description: This function increments the 
 wiper's value.
 ***********************************************/
void increment(){
    SPI_transfer(4);
    __delay_ms(10);
}
/***********************************************
 Function: decrement()
 Return value: void
 Parameters: void
 Description: This function decrements the 
 wiper's value.
 ***********************************************/
void decrement(){
    SPI_transfer(8);
    __delay_ms(10);
}
/***********************************************
 Function: writeTcon()
 Return value: void
 Parameters: char
 Description: This function decrements changes
 the status of the Tcon register.
 ***********************************************/
void writeTcon(char val){
    SPI_transfer(0x40);
    SPI_transfer(val);
    __delay_ms(10);
}
