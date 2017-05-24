; gpcolor.s

		.module load_color

				.globl  writevdp

				.globl  _load_color
				; load_color (table)

	.AREA   _CODE

_load_color:
				pop     bc
				pop     hl
				push    hl
				push    bc
				
				ld      de,(0x73FA) ; de = offset = COLTAB
				call	writevdp
				
				ld		bc,#0x20be ;; b = 32, c = (1D47h) = 0beh
$1:
				ld		d,(hl)
				ld      a,#0x40
$2:
				out	(c),d 	; SEND DATA TO VIDEO
				dec	a
				or		a
				jr		nz,$2
				inc	hl
				djnz	$1				
				ret

				;;jp	0x1FDC	; get vdp status

