/* 
 * File:   main.c
 * Author: Raphael
 *
 * Created on 24 de Dezembro de 2016, 02:06
 */

// This program is based on: https://playground.arduino.cc/Main/I2cScanner/
// Ported by: Raphael Pereira
// https://github.com/fannaticc/i2c_scanner

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "my_delays.h"
#include "config.h"
#include "serial.h"
#include "main.h"
#include "i2c_scan.h"
#include "hardware.h"
#include "my_delays.h"

void main()
{
    uint8_t error;
    uint8_t address;
    uint8_t chartoserial[40];
    uint16_t nDevices;
    
    System_init();
    
    putrsserial("\nI2C Scanner\n");

    putrsserial("Scanning...\n");
    nDevices = 0;
    
    putrsserial("                            7bits  8bits\n");
    
    for(address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        error = I2C_TestADR(address);
        
        if(error == 0)
        {
            putrsserial("I2C device found at address  0x");
            if(address < 16)
            {
                putrsserial("0");
            }
            sprintf(chartoserial, "%02X   0x%02X", address, (address << 1));
            putrsserial(chartoserial);
            putrsserial("  !\n");
            nDevices++;
        } 
        else if(error == 2)
             {
                putrsserial("Unknow error at address 0x");
                if(address < 16)
                {
                    putrsserial("0");
                }
                sprintf(chartoserial, "%02X", address);
                putrsserial(chartoserial);
             }
    }
    
    if (nDevices == 0)
        putrsserial("No I2C devices found\n");
    else
        putrsserial("Test done!\n");
    
    Long_delay_ms(5000); //wait 5 seconds for next scan
}

void System_init()
{
    OSCCON = 0b01110000; // 8MHZ INTOSC
    OSCTUNEbits.PLLEN = 1;
    
    ADCON1 = 0b00001111; // Disable all analog channels
    CMCON = 0b00000111;
    
    PORTA= 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    
    TXSTA = 0b00100110;
    RCSTA = 0b10010000;
    BAUDCON = 0b00001010;
    //SPBRG = 16; // 115200 @ 8MHz.
    SPBRG = 68; // 115200 @ 32MHz.
    SPBRGH = 0;
    
    __delay_ms(10);
}

void Long_delay_ms(unsigned int count)
{
    unsigned int i;
    
    for(i = 0; i < count; i ++)
    {
        __delay_ms(1);
    }
}