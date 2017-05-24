; nmi.s

	.module nmi

	; global from this code
	.globl  _disable_nmi
	; disable_nmi (void)

	.globl  writevdpreg1

	.area _CODE

_disable_nmi:
	ld      a,(#0x73c4)
	and     #0xdf
	jp writevdpreg1
	