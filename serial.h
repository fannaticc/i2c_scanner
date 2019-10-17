/* 
 * File:   serial.h
 * Author: Raphael
 *
 * Created on 12 de Abril de 2016, 14:22
 */

#ifndef SERIAL_H
#define	SERIAL_H

#define DataRdy1USART() (PIR1bits.RCIF)

void putrsserial(const char *data);
void putsserial(char *data);
void writeserial(char data);
char readserial(void);
char Busy1USART(void);

//#define putcUSART WriteUSART()
//#define WriteToTX2(x)   do{while(TXSTAbits.TRMT); WriteUSART(x);}while(0) /* This prevents from overwriting previous byte */

#endif	/* SERIAL_H */

