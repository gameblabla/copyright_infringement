; rle2vram.s

	.module rle_to_vram

	.globl  vdpwrite

	; global from this code

    .globl  _rle2vram
    ; void *rle2vram (void *rledata,unsigned offset);
	
	.area _CODE

_rle2vram:
    pop     bc
    pop     hl
    pop     de
    push    de
    push    hl
    push    bc
	call		vdpwrite
    ld      c,#0xbe ;; (1d47h) = 0beh
$0:
    ld      a,(hl)
    inc     hl
    cp      #0xff
    ret     z
    bit     7,a
    jr      z,$2
    and     #0x7f
    inc     a
    ld      b,a
    ld      a,(hl)
    inc     hl
$1:
    out     (c),a
    nop
    nop
    djnz    $1
    jr      $0
$2:      
    inc     a
    ld      b,a
$3:            
    outi
    jr      z,$0
    jp      $3

