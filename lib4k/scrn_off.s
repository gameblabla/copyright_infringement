; scrn_off.s

	.module screen

	.globl  _screen_off
	; screen_off (void)
	
	.globl  writevdpreg1

	.area _CODE
    
_screen_off:    	ld	a,(0x73c4)
					and	#0xbf
					jp		writevdpreg1
