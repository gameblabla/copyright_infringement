; scrn_on.s

	.module screen

	.globl  _screen_on
	; screen_on (void)
	
	.globl  writevdpreg1
	
	.area _CODE
    
_screen_on:			ld	a,(0x73c4)
					or	#0x40
					jp		writevdpreg1
