;	ledcopy.asm  -  Simply copies switches to LEDs
;
;	Author:		<your name>
;	Date:		<date>
;	AVR type:	ATmega32
;	Target:		STK 500 (E development board)

		ldi		r16,0x00 
		out		DDRA,r16		; configure Port A as 8 inputs
		ldi		r16,0xFF		
		out		DDRB,r16		; configure Port B as 8 outputs

loop:	in		r0,PINA 		; read Port A (switches)
		out		PORTB,r0		; output to Port B (leds)
		rjmp	loop			; and again
