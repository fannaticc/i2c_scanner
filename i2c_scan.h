/* 
 * File:   i2c_scan.h
 * Author: Raphael
 *
 * Created on October 17, 2019, 3:37 PM
 */

#ifndef I2C_SCAN_H
#define	I2C_SCAN_H

#include <stdint.h>

#include "config.h"
#include "main.h"

#define ssda_bit PORTCbits.RC4
#define sscl_bit PORTCbits.RC3

#define ssda_bit_tris TRISCbits.RC4
#define sscl_bit_tris TRISCbits.RC3

#define ssda_hi			{ssda_bit_tris = 1;}
#define ssda_lo			{ssda_bit_tris = 0;}
#define sscl_hi			{sscl_bit_tris = 1;}
#define sscl_lo			{sscl_bit_tris = 0;}
#define ssda_tst		(ssda_bit) ? 1 : 0
#define sscl_tst		(sscl_bit) ? 0 : 1

#define i2c_wait_val	2

#define SUCCESS			0
#define FAIL			!SUCCESS
#define READ			1
#define WRITE			0
#define ACK				1
#define NACK			0

uint8_t I2C_TestADR(uint8_t addr);
void I2C_Wait_Clk(void);
void I2C_Wait(void);

#endif	/* I2C_SCAN_H */

