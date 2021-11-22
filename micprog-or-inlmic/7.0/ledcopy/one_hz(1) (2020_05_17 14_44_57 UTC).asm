;	one_hz.asm  -  Simple 1 Hz pulse generator
;
;	Author:		<your name>
;	Date:		<date>
;	AVR type:	ATmega32
;	Target:		STK 500 (AVR development board)
;	Frequency:	3.6864 MHz

		ldi		r16,0xff
		out		DDRB,r16	; configure Port A as 8 inputs

		ldi		r17,0xff	; initialize LED state

start:	com		r17			; complement (invert) this state
		out		PORTB,r17	; show them on the LEDs

		ldi		r20,0x00
		ldi		r21,0xA0
		ldi		r22,0x05	; initialize 3 byte counter.

wait:	subi	r20,1
		sbci	r21,0
		sbci	r22,0		; wait 0.5 secs by decrementing the
		brne	wait		; 3 byte counter until zero

		rjmp	start		; and again












