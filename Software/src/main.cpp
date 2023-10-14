/**
 * @file    main.cpp
 * @author  Jesutofunmi Kupoluyi (jimsufficiency@gmail.com)
 * @brief   This is a version of automatic irrigation device
 *          firmware written in C++
 * @version 0.1
 * @date    2023-09-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Including required header file */
#include "main.h"



/* main function */
int main ()
{
    DDRD |= _BV(PD5); /* Set PB5 as output */

    while (1)
    {
        PORTD |= (1 << PD5);    /* Toggle PB5 high */
        _delay_ms(250);        /* Wait 1 second */
        PORTD &= ~(1 << PD5);    /* Toggle PB5 low */
        _delay_ms(250);        /* Wait 1 second */
    }

    return 0;
}