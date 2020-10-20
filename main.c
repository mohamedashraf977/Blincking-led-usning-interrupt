/*
 * File:   main.c
 * Author: Mohamed-PC
 *
 * Created on September 28, 2020, 8:01 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISC=0x00;
    PORTC=0x00;
    TRISB0=1;
    INTEDG=1;
    INTE=1;
    GIE=1;
    
    while(1)
    {
        PORTCbits.RC2=1;
        __delay_ms(200);
        PORTCbits.RC2=0;
        __delay_ms(200);
    }

    return;
}
    void __interrupt() ISR()
    {
        if(INTF)
        {
            RC1=~RC1;
            INTF=0;
        }
    }