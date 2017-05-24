; crt0.s for Colecovision cart


	;; Ordering of segments for the linker - copied from sdcc crt0.s
	.area _HOME
	.area _CODE
		.ascii "LinkTag:Fixed\0"	; also to ensure there is data BEFORE the banking LinkTags
		.area _main					;   to work around a bug that drops the first AREA: tag in the ihx
	.area _GSINIT
	.area _GSFINAL
        
	;; banking (must be located before the RAM sections)
	.area _bank1
		.ascii "LinkTag:Bank1\0"
		.area _bk1

	.area _bank2
		.ascii "LinkTag:Bank2\0"
		.area _bk2

	.area _bank3
		.ascii "LinkTag:Bank3\0"
		.area _bk3
		
	.area _bank4
		.ascii "LinkTag:Bank4\0"
		.area _bk4
		
	.area _bank5
		.ascii "LinkTag:Bank5\0"
		.area _bk5

	.area _bank6
		.ascii "LinkTag:Bank6\0"
		.area _bk6
		
	.area _bank7
		.ascii "LinkTag:Bank7\0"
		.area _bk7
		
	.area _bank8
		.ascii "LinkTag:Bank8\0"
		.area _bk8

	.area _bank9
		.ascii "LinkTag:Bank9\0"
		.area _bk9

	.area _bank10
		.ascii "LinkTag:Bank10\0"
		.area _bk10
		
	.area _bank11
		.ascii "LinkTag:Bank11\0"
		.area _bk11
		
	.area _bank12
		.ascii "LinkTag:Bank12\0"
		.area _bk12
		
	.area _bank13
		.ascii "LinkTag:Bank13\0"
		.area _bk13
		
	.area _bank14
		.ascii "LinkTag:Bank14\0"
		.area _bk14
		
	.area _bank15
		.ascii "LinkTag:Bank15\0"
		.area _bk15

	.area _bank16
		.ascii "LinkTag:Bank16\0"
		.area _bk16

	;; end of list - needed for makemegacart. Must go before RAM areas.
	; This isn't used by anything else and should not contain data
	.area _ENDOFMAP
    
    .module crt0   

    ;; external sound table setting routine
	.globl set_snd_table

	;; global from this code
	.globl  _buffer32
	.globl _no_nmi
	.globl _vdp_status
	.globl _nmi_flag
	.globl _joypad_1
	.globl _keypad_1
	.globl _joypad_2
	.globl _keypad_2
	.globl snd_areas
	
	;; global from C code
	.globl _main
	.globl _nmi
        
	.area _DATA
	.area _BSS
	.area _HEAP

	;; TABLE OF VARIABLES (IN RAM)
	.area	_DATA
_buffer32::
	.ds	32 ; buffer space 32    [7000-701F]
snd_addr::
	.ds	11 ; sound addresses    [7020-702A]
snd_areas::
	.ds	61 ; 5 sound slots + NULL (00h) [702B-...]
_no_nmi::
	.ds    1
_vdp_status::
	.ds    1
_nmi_flag::
	.ds    1
_joypad_1::
	.ds    1
_keypad_1::
	.ds    1
_joypad_2::
	.ds    1
_keypad_2::
	.ds    1	

	;; CARTRIDGE HEADER (IN ROM)
	.area _HEADER(ABS)
	.org 0x8000
	
	.db	0x55, 0xaa		; no default colecovision title screen => 55 AA
	.dw	0			; no copy of sprite table, etc.
	.dw	0			; all unused
	.dw	_buffer32		; work buffer
	.dw	0			; ??
	.dw	start_program	; start address for game coding
	.db	0xc9,0,0		; no RST 08 support
	.db	0xc9,0,0		; no RST 10 support
	.db	0xc9,0,0		; no RST 18 support
	.db	0xc9,0,0		; no RST 20 support
	.db	0xc9,0,0		; no RST 28 support
	.db	0xc9,0,0		; no RST 30 support
	.db	0xc9,0,0		; no RST 38 support  (spinner)
	jp	_nmi_asm

	;; CODE STARTS HERE WITH NMI
        .area _CODE
_nmi_asm:
	push	af
        ld	a,#1
        ld      (_nmi_flag),a           ; set NMI flag
	;;;
        call    0x1fdc                   ; get VDP status
        ld      (_vdp_status),a
	;;;
        ld      a,(_no_nmi)             ; check if nmi() should be
        or      a                       ;  called
        jp      nz,nmi_exit
        inc     a
        ld      (_no_nmi),a
        push    bc
        push    de
        push    hl
        push    ix
        push    iy
        ex      af,af'
        push    af
        exx
        push    bc
        push    de
        push    hl
        call    0x1f76                   ; update controllers
        ld      a,(0x73ee)
        and	#0x4f
        ld      (_joypad_1),a
        ld      a,(0x73ef)
        and	#0x4f
        ld      (_joypad_2),a
        ld      a,(0x73f0)
        and	#0x4f
        ld      (_keypad_1),a
        ld      a,(0x73f1)
        and	#0x4f
        ld      (_keypad_2),a
        call    decode_controllers
        call    _nmi                    ; call C function
        call    0x1f61                   ; play sounds
        call    0x1ff4                   ; update snd_addr with snd_areas
        pop     hl
        pop     de
        pop     bc
        exx
        pop     af
        ex      af,af'
        pop     iy
        pop     ix
        pop     hl
        pop     de
        pop     bc
        xor     a
        ld      (_no_nmi),a
nmi_exit:
        pop     af
        ret

keypad_table::
	.db    0xff,8,4,5,0xff,7,11,2,0xff,10,0,9,3,1,6,0xff

; joypads will be decoded as follows:
; bit
; 0     left
; 1     down
; 2     right
; 3     up
; 4     --------
; 5     --------
; 6     button 2
; 7     button 1
; keypads will hold key pressed (0-11), or 0xff
decode_controllers:
	ld      ix, #_joypad_1
	call    decode_controller
	inc     ix
	inc     ix
decode_controller:
	ld      a,0(ix)
	ld      b,a
	and     #0x40
	rlca
	ld      c,a
	ld      a,b
	and     #0x0f
	or      c
	ld      b,a
	ld      a,1(ix)
	ld      c,a
	and     #0x40
	or      b
	ld      0(ix),a
	ld      a,c
	cpl
	and    #0x0f
	ld      e,a
	ld      d,#0
	ld      hl,#keypad_table
	add     hl,de
	ld      a,(hl)
	ld      1(ix),a
	ret


start_program:
	im       1                      ; interrupt mode -> rst 38h
	di

	xor     a                       ; clear carry
	ld      bc,#0x3b8		; ram size left
	ld      hl,#0x7000		; starting from 7000
	ld      de,#0x7001
	ld      (hl),a
	ldir                            ; zero-fill bss

	ld	bc,#0xFFFE			; switch in code bank
   	ld	a,(bc)				; note that this does NOT set the local pBank variable, user code still must do that!

	call gsinit					; Initialize global variables.

	ld	h,#0 ; set dummy sound table
	call set_snd_table

	ld      hl,#0x0033                ; initialise random generator
	ld      (0x73c8),hl
                                    ; set screen mode 2 text
	call    0x1f85                   ; set default VDP regs 16K
	ld      de,#0x4000                ; clear VRAM
	xor     a
	ld      l,a
	ld      h,a
	call    0x1f82
	
	; call main rountine
	jp      _main
	
	.area _GSINIT
gsinit::
	.area _GSFINAL
	ret
	;
