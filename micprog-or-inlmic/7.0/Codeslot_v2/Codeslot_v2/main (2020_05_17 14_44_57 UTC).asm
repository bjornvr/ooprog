/*
 * Codeslot.asm
 *
 *  Created: 11-10-2019 13:36:17
 *   Author: Jordi
 */ 

.equ	leds		=PORTB			; Lampen op poort B
.equ	dirleds		=DDRB
.equ	switches	=PINA			; Drukknoppen op poort A
.equ	dirswitches	=DDRA
.equ	allout		=0b1111_1111	; Leds
.equ	allin		=0b0000_0000	; Drukknoppen

.def	fouten		=r16
.def	knoppen		=r17
.def	delay1		=r22
.def	delay2		=r23


;.org	0x020
main:
		ldi		r20,allin			; Configureer poort 
		out		dirswitches,r20		; voor drukknoppen

		ldi		r21,allout			; Configureer poort
		out		dirleds,r21			; voor lampen
		;ldi r16,0000_0111
		
start:
	ldi r18,allout
	out leds,r18



;---------------------------------------------------------------------------------
knop1:									
	readswitches1:
		in		r23,switches		; Lees drukknop
		ldi		r27,0xFF
		cp		r23,r27			; Een knop
		brge	readswitches1		; Niet ingedrukt?
		
		ldi delay1, 0x00			;10ms
		ldi delay2, 0x24
		wait10ms1_1:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms1_1;

			ldi knoppen, switches	;inladen

	readswitches1_2:
		in		r17,switches		;geen knop?
		andi	r17,0xff
		brne	readswitches1_2
		
		ldi delay1, 0x00
		ldi delay2, 0x24
		wait10ms1_2:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms1_2;

			cpi knoppen, 0x01				;<-------------------------
				breq knop2
			rjmp fout ;nietnodig j =wel nodig
;---------------------------------------------------------------------------------
fout:			;r26 plus 1 aan het eind kijk je of die gelijk is aan nul
				; gelijk aan 0 is goed
				; niet gelijk an 0 dan doe je onderstaande dus r 16 +1 gelijk aan 3? ja fout lamp
	lsr r16	
	cpi r16,0
	brne main
	rjmp alarm
;---------------------------------------------------------------------------------
knop2:
readswitches2:
		in		r23,switches		; Lees drukknop
		andi	r23,0x00			; Een knop
		brne	readswitches2		; Niet ingedrukt?
		
		ldi delay1, 0x00			;10ms
		ldi delay2, 0x24
		wait10ms2_1:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms2_1;

			ldi knoppen, switches	;inladen

	readswitches2_2:
		in		r23,switches		;geen knop?
		andi	r23,0xff
		brne	readswitches2_2
		
		ldi delay1, 0x00
		ldi delay2, 0x24
		wait10ms2_2:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms2_2;

	cpi knoppen, 0x01				;<-------------------------
		breq knop3
	rjmp fout
;---------------------------------------------------------------------------------
knop3:
readswitches3:
		in		r23,switches		; Lees drukknop
		andi	r23,0x00			; Een knop
		brne	readswitches3		; Niet ingedrukt?
		
		ldi delay1, 0x00			;10ms
		ldi delay2, 0x24
		wait10ms3_1:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms3_1;

			ldi knoppen, switches	;inladen

	readswitches3_2:
		in		r23,switches		;geen knop?
		andi	r23,0xff
		brne	readswitches3_2
		
		ldi delay1, 0x00
		ldi delay2, 0x24
		wait10ms3_2:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms3_2;

	cpi knoppen, 0x01				;<-------------------------
		breq knop4
	rjmp fout
;---------------------------------------------------------------------------------
knop4:
readswitches4:
		in		r23,switches		; Lees drukknop
		andi	r23,0x00			; Een knop
		brne	readswitches4		; Niet ingedrukt?
		
		ldi delay1, 0x00			;10ms
		ldi delay2, 0x24
		wait10ms4_1:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms4_1;

			ldi knoppen, switches	;inladen

	readswitches4_2:
		in		r23,switches		;geen knop?
		andi	r23,0xff
		brne	readswitches4_2
		
		ldi delay1, 0x00
		ldi delay2, 0x24
		wait10ms4_2:			
			subi	delay1,1
			sbci	delay2,0		
		brne wait10ms4_2;

	cpi knoppen, 0x01			;<-------------------------
		breq correct
	rjmp fout
;---------------------------------------------------------------------------------
correct:
	rjmp main

alarm:
	ldi	r21,allin
	out	leds,r21
	rjmp alarm