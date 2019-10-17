/* 
 * File:   i2c_scan.c
 * Author: Raphael
 *
 * Created on October 17, 2019, 3:37 PM
 */

#include <stdint.h>

#include "hardware.h"
#include "i2c_scan.h"
#include "my_delays.h"

uint8_t I2C_TestADR(uint8_t addr)
{
    uint8_t val, m, error;
    
    ssda_hi;
    sscl_hi;
    __delay_ms(1);
    
        ssda_lo;
    I2C_Wait();
    sscl_lo;
    I2C_Wait();
    I2C_Wait();
    val = addr << 1;
    m = 0x80;

    while(m)
    {
        if(val & m)
        {
            ssda_hi;
        }
        else
        {
            ssda_lo;
        }
        I2C_Wait_Clk();
        sscl_hi;
        I2C_Wait_Clk();
        m >>= 1;
        sscl_lo;
    }

    m = SUCCESS;
    I2C_Wait_Clk();
    ssda_hi;
    I2C_Wait_Clk();
    sscl_hi;
    I2C_Wait_Clk();

    if(ssda_tst)
    {
        m = FAIL;
    }

    sscl_lo;
    I2C_Wait();

    if(m == SUCCESS)
    {
        error = 0;
    }
    else
    {
        error = 3;
    }

    ssda_lo;
    I2C_Wait();
    sscl_hi;
    I2C_Wait();
    ssda_hi;
    I2C_Wait();

    return error;
}

void I2C_Wait_Clk(void)
{
    NOP();
}

void I2C_Wait(void)
{
    for(volatile uint8_t t = i2c_wait_val; t > 0; t--);
}
