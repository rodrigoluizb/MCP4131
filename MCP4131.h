/* 
 * File:   MCP4131.h
 * Author: rodrigobarbosa
 *
 * Created on April 29, 2016, 1:13 PM
 */

#ifndef MCP4131_H
#define	MCP4131_H

void SPI_Init();
unsigned char SPI_transfer(unsigned char data);
void writeVal(char val);
void increment();
void decrement();
void writeTcon(char val);
#endif	/* MCP4131_H */

