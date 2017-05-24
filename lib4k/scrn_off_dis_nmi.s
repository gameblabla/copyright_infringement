; scrn_off_dis_nmi.s

	.module screen

	.globl  _screen_off_disable_nmi
	; screen_off_disable_nmi (void)
	
	.globl  writevdpreg1

	.area _CODE
    
_screen_off_disable_nmi:
			ld		a,(0x73c4)
			and	#0x9f
			jp		writevdpreg1
