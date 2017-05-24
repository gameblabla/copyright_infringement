; vdpwrite.s

	.module vdp
	
    .globl  vdpwrite
	
	.area _CODE
	
vdpwrite:
    ld      c,#0xbf ;; (1d43h) = 0bfh
    out     (c),e
    set     6,d
    out     (c),d
	ret