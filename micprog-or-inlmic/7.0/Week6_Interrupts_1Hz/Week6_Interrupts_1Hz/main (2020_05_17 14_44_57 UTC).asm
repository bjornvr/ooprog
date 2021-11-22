reset:
    inc r16
    rjmp start;
; Week6_Interrupts_1Hz.asm
;
; Created: 11-10-2019 11:16:30
; Author : bdoof
;









int1:
	rjmp overflow;


; Replace with your application code
start:
    inc r16
    rjmp start;

overflow:
	;doe shit

	ret