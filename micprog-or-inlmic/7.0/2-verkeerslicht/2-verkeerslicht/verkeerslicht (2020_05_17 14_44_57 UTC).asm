;
;	verkeerslicht.asm  -  Simpel verkeerslichtsysteem
;
;	Author:		J. op den Brouw
;	Date:		09-oct-2006
;	Revised:	28-jul-2010
;	Revised:	05-sep-2014 (J.Z.M. Broeders)
;	Version:	1.0.2
;	Status:		Unfinished, with errors
;	Target:		AVR simulator
;	Frequency:	4 MHz
;
;	Dit is een voorbeeld van zeer simpel verkeerslichtsysteem.
;	Na start van het systeem wordt het licht voor de auto's
;	op groen gezet, die voor de voetgangers op rood.
;	Na een druk op een knop wordt het licht voor de auto's op
;	rood gezet, die voor de voetgangers is nog rood. Na 5
;	seconden wordt het voetgangers dan op groen gezet. Dit
;	licht blijft 10 seconden op groen, daarna gaan beide
;	lichten op rood.
;
;
;	Voor een beschrijving van de wachtlussen, zie handleiding 
;   AVR-Assembler Programmeren INLMIC-pr week 1
;
;	De verkeerslichten:

;	+--+--+--+--+--+--+--+--+		AR = auto's - rood
;	|AR|AG|  |  |  |  |VR|VG|		AG = auto's - groen
;	+--+--+--+--+--+--+--+--+		VR = voetgangers - rood
;	                         		VG = voetgangers - groen

;.include "m32def.inc"


; Deze registers worden gebruikt voor de timing van
; de wachtlussen, maximaal 6442 s = 107 min.
.def	delay1		=r20			; 32 bits counter LSB
.def	delay2		=r21
.def	delay3		=r22
.def	delay4		=r23			; 32 bits counter MSB

; Equates voor makkelijk gebruik
.equ	leds		=PORTB			; Lampen op poort B
.equ	dirleds		=DDRB
.equ	switches	=PINA			; Drukknoppen op poort C
.equ	dirswitches	=DDRA
.equ	allout		=0b1111_1111
.equ	allin		=0b0000_0000

; Verkeerslichten die aan moeten.
; 1 = uit, 0 = aan
.equ	veh_r_ped_r	=0b0111_1101
.equ	veh_r_ped_g	=0b0111_1110
.equ	veh_g_ped_r	=0b1011_1101

; Start code
.org	0x000
main:
		ldi		r15,allin			; Configureer poort 
		out		dirswitches,r15		; voor drukknoppen

		outi	dirleds,allout		; Configureer poort
									; voor lampen

start:	ld		r16,veh_g_ped_r		; Auto's groen en
		out		leds,r16			; voetgangers rood

readswitches:
		in		r16,switches		; Lees drukknop
		andi	r16,0x01			; Alleen de eerste
		brne	readswitches		; Niet ingedrukt?

		ldi		r16,veh_r_ped_r		; Auto's rood en
		in		r16,leds			; voetgangers rood
		
		ldi		delay1,0xd5			; Wacht 5 seconden
		ldi		delay2,0xdc
		ldi		delay3,0x32
		ldi		delay4,0x00

wait5:	subi	delay1,1
		sbci	delay2,0
		sbci	delay3,0
		sbci	delay4,0
		brne	wait5

		ldi		r16,veh_r_ped_g		; Auto's rood en
		out		leds,r16			; voetgangers groen

		ldi		delay1,0xff			; Wacht 10 seconden
		ldi		delay2,0x00			; TODO: werkt nog niet
		ldi		delay3,0x00
		ldi		delay4,0x00

wait10:	subi	delay1,1
		sbci	delay2,0
		sbci	delay3,0
		sbci	delay4,0
		brne	wait10

		ldi		r16,veh_r_ped_r		; Auto's rood,
		out		leds,r16			; voetganger rood

		ldi		delay1,0xd5			; Wacht 5 seconden
		ldi		delay2,0xdc
		ldi		delay3,0x32
		ldi		delay4,0x00

wait5:	subi	delay1,1
		sbci	delay2,0
		sbci	delay3,0
		sbci	delay4,0
		brne	wait5

endcode:
		rjmp	readswitches				; Opnieuw!


