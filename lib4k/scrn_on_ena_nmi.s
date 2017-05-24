; scrn_on_dis_nmi.s

	.module screen

	.globl  _screen_on_enable_nmi
	; screen_on_enable_nmi (void)
	
	.globl  writevdpreg1

	.area _CODE
    
_screen_on_enable_nmi:
			ld		a,(0x73c4)
			and	#0x60
			jp		writevdpreg1
			jp      0x1fdc
