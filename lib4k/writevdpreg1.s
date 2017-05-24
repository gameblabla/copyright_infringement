; writevdpreg1.s

	.module vdp

	.globl  writevdpreg1

	.area _CODE

writevdpreg1:
	ld      c,a
	ld      b,#1
	jp      0x1fd9
