/* 
 * File:   mydelays.h
 * Author: Raphael
 *
 * Created on 6 de Março de 2016, 20:42
 */

#ifndef MYDELAYS_H
#define	MYDELAYS_H

#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
#define __delaywdt_us(x) _delaywdt((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delaywdt_ms(x) _delaywdt((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

#endif	/* MYDELAYS_H */
