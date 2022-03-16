

.include "m328Pdef.inc"

Start:
	ldi r17, 0b11100011 ; identifying input pins 10,11,12
	out DDRB,r17		; declaring pins as input
	ldi r17, 0b11111111 ;
	out PORTB,r17		; activating internal pullup for pins 10,11,12
	in r17,PINB
	
	ldi r20,0b00000010
	rcall loopr
	
	ldi r21,0b00000001
	and r21,r17 ;r
	lsr r17
	ldi r22,0b00000001
	and r22,r17 ;q
	lsr r17
	ldi r23,0b00000001
	and r23,r17 ;p
	
	ldi r24,0b00000001
	ldi r25,0b00000001

	eor r24,r22     ;q'
	eor r25,r21	    ;r'
	
	or r22,r25		;q+r'
	or r24,r21		;q'+r
	and r22,r24		;(q+r').(q'+r) = X

	ldi r20,0b00000010
	rcall loopl

	ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
	out DDRD,r16		;declaring pins as output
	out PORTD,r22		;writing output to pins 2,3,4,5
	

	rjmp Start

loopr:	lsr r17
	dec r20
	brne loopr
	ret

loopl:	lsl r22
	dec r20
	brne loopl
	ret
