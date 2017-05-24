; os7.s

	.module os7

	; global from this code
	.globl  _os7
	; os7 (addr,af,bc,de,hl)
	
	.area _CODE
	
_os7:
	pop     bc                      ; return address
	pop     de                      ; OS-7 address
	exx
	pop     af                      ; registers
	pop     bc
	pop     de
	pop     hl
	push    hl                      ; unjunk stack
	push    de
	push    bc
	push    af
	exx
	push    de
	push    bc
	push    de                      ; push OS-7 address
	exx
	ret                             ; jump to it
