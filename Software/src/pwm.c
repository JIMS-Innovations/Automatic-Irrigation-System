ISR(TIMER1_COMPA_vect)
{
  // PORTD ^= (1 << PD7);    /* Toggle PB5 high */
}




int main()
{
	sei();

  	TCNT1 = 0;			/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
  	DDRD |= _BV(PD7) | _BV(PD5); /* Set PB5 as output */

	while(1)
	{
		OCR1A = 139;		/* Set servo shaft at -90° position */
		// _delay_ms(1500);
    // for(uint8_t i = 129; i < 259; i++)
    // {
    //   OCR1A = i;
    //   _delay_ms(500);
    // }
			/* Set servo shaft at 0° position 175, 129 -> 1.000ms / 1.020ms, 259 -> 2.000ms / 2.020ms  */
		// _delay_ms(1500);
		// OCR1A = 259;	/* Set servo at +90° position */
		// _delay_ms(1500);
	}
    

  }
