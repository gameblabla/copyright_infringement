; gp2color.s

	.module change_color
	
	.globl  change_color
	;void change_color(unsigned char c, void *color, unsigned char l);

	.area _CODE
	
_change_color:
                pop     bc
                pop     de
                pop     hl
                push    hl
                push    de
                push    bc
		
		ld	c,h
		ld	h,l
		ld	l,d
		
                push    hl

                ld	b,c	; B = C (count)

                ld	h,#4	; DE = 8*E + COLTAB (offset)
                ld	l,e
                add	hl,hl
                add	hl,hl
                add	hl,hl

                ld	a,l
                out	(0xBF),a
                ld	a,h
                or	#0x40
                out	(0xBF),a	; SET VIDEO ADDR

                pop     hl	; HL = ptr

                ld	c,#0xBE
$1:
		ld	d,(hl)
                ld      a,#8
$2:
		out	(c),d 	; SEND DATA TO VIDEO
                dec	a
                or	a
                jr	nz,$2
                inc	hl
                dec	b
                djnz	$1

                call	0x1FDC	; get vdp status

                ret