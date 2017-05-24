; nmi2.s

	.module nmi

	; global from this code
	.globl  _enable_nmi
	; enable_nmi (void)

	.globl  writevdpreg1

	.area _CODE

_enable_nmi:
	ld      a,(#0x73c4)
	or      #0x20
	call    writevdpreg1
	jp      0x1fdc
	