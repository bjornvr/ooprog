;
; wk4_codeslot.asm
;
; Created: 27-9-2019 11:45:57
; Author : bdoof
;
.include "m32adef.inc"

;registers
.def	delay1	=r20
.def	delay2	=r21
.def	fout	=r22
; Replace with your application code
start:
	ldi		r16,0x00 
	out		DDRA,r16		; configure Port A as 8 inputs
	ldi		r16,0xFF		
	out		DDRB,r16		; configure Port B as 8 outputs



    rjmp start

wait10:	ldi		delay1,5F
		ldi		delay2,01

loop10:	subi	delay1,1
		sbci	delay2,0
		brne	loop10
		ret