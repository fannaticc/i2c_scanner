/* 
 * File:   serial.h
 * Author: Raphael
 *
 * Created on 12 de Abril de 2016, 14:22
 */

#include "serial.h"
#include "config.h"

void putrsserial(const char const *data)
{
  do
  {  // Transmit a byte
    while(!TXSTAbits.TRMT);
    writeserial(*data);
  } while( *data++ );
}

void putsserial(char *data)
{
  do
  {  // Transmit a byte
    while(!TXSTAbits.TRMT);
    writeserial(*data);
  } while( *data++ );
}

void writeserial(char data)
{
  TXREG = data;      // Write the data byte to the USART
}

char readserial(void)		//this function can be removed by macro #define ReadUSART RCREG
{
  return(RCREG); // Return the received data
}

/*char readserial(void) //this function can be removed by macro #define ReadUSART RCREG
{
    char data; // Holds received data

    USART1_Status.val &= 0xf2; // Clear previous status flags

    if(RCSTA1bits.RX9) // If 9-bit mode
    {
        USART1_Status.RX_NINE = 0; // Clear the recieve bit 9 for USART1
        if (RCSTA1bits.RX9D) // according to the RX9D bit
            USART1_Status.RX_NINE = 1;
    }

    if (RCSTA1bits.FERR) // If a framing error occured
        USART1_Status.FRAME_ERROR = 1; // Set the status bit

    if (RCSTA1bits.OERR) // If an overrun error occured
        USART1_Status.OVERRUN_ERROR = 1; // Set the status bit

    data = RCREG1; // Read data

    return (data); // Return the received data

}*/

char Busy1USART(void)
{
  if(!TXSTAbits.TRMT) // Is the transmit shift register empty
    return 1;          // No, return FALSE
    return 0;            // Return TRUE
}