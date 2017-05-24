; music.s

    .module music

    ; global from this code

    .globl  _next_music
    .globl  _play_music
    .globl  _stop_music
    .globl  _update_music

    .area _DATA
    
pointer:
    .ds 2
counter:
    .ds 2
    
    .area _CODE

nomusic_track:
    .dw 0

_next_music:
    pop bc
    pop de
    push de
    push bc
next_music:
    ld hl,#pointer
    ld (hl),e
    inc hl
    ld (hl),d
    ret
_play_music:
    pop bc
    pop de
    push de
    push bc
    call next_music
    jp trigger_sounds
_update_music:
    ld hl,#counter+1
    ld a,(hl)
    dec hl
    or a
    jr nz,update_counter
    ld a,(hl)
    or a
    jp z,trigger_sounds
update_counter:
    ld a,(hl)
    sub #1
    ld (hl),a
    inc hl
    ld a,(hl)
    sbc a,#0
    ld (hl),a
    ret
trigger_sounds:
    ld hl,#pointer
    ld e,(hl)
    inc hl
    ld d,(hl)
    ex de,hl
    ld e,(hl)
    inc hl
    ld d,(hl)
    xor a
    ;; CASE == 0000 -> it's END OF DATA marker
    sub d
    jr nz, $1
    sub e
    ret z
$1:
    ;; CASE >= 8000 -> it's a new pointer
    bit 7,d
    jr z, $2
    ld hl,#pointer
    ld (hl),e
    inc hl
    ld (hl),d
    jr trigger_sounds
$2:
    ;; counter = (uint) data[pointer];
    dec de
    ld hl,#counter
    ld (hl),e
    inc hl
    ld (hl),d
    ld hl,#pointer
    ld e,(hl)
    inc hl
    ld d,(hl)

    call stop_music
    
    ex de,hl
    ;; hl = address;
    inc hl
    inc hl
    ld a,(hl)
    rlca
    rlca
    and #3
    inc a
    ld b,a
    ;; b is element of {1,2,3,4}
$4:
    ld a,(hl)
    inc hl
    and #0x3f
    ;; MISSING : start sound #a
    
    push bc
    push de
    push hl
    
    push af
    sub #1
    ld c,a
    ld b,#0
    ld hl,(#0x7020)
    rlc c
    rlc c
    add hl,bc
    ld e,(hl)
    inc hl
    ld d,(hl)
    push de
    inc hl
    ld e,(hl)
    inc hl
    ld d,(hl)
    pop hl ;; de = @ Sound Area, hl = @ sound data
    ld a,(hl)
    inc hl
    ld c,a
    and #0xc0
    ld b,a
    pop af
    and #0x3f
    or b
    ld (de),a
    inc de
    inc de
    inc de ;; de = @ Sound Area + 3
    
    ld a,c
    bit 5,a
    jr z, $5
    inc de
    inc de
    and #0x1f
    ld (de),a
    jr $6    

$5:
    cp #0x02 ; case noise with volumen sweep
    jr nz, $7
    dec hl
$7:
    ldi
    ldi
    ldi
    bit 0,a
    jr z,$8
    ldi
    ldi
$10:
    bit 1,a
    jr z,$9
    ldi
    ldi
    dec de
    dec de
$9:
    dec de
    dec de
    dec de
    dec de
$6:
    dec de
    dec de
    ex de,hl
    ld (hl),d
    dec hl
    ld (hl),e
    ex de, hl

    pop hl
    pop de
    pop bc
    
    djnz $4
    ex de,hl
    ;; update pointer
    ld hl,#pointer
    ld (hl),e
    inc hl
    ld (hl),d

    jp 0x0295 ;; NOT AN APPROVED COLECO BIOS ENTRY, BUT DONE ANYWAY

$8:
    inc de
    inc de
    jr $10
    
_stop_music:
    ld hl,#pointer
    ld de,#nomusic_track
    ld (hl),e
    inc hl
    ld (hl),d
    ; inc hl
    ; xor a
    ; ld (hl),a
    ; inc hl
    ; ld (hl),a    
    call stop_music
    jp 0x0295 ;; NOT AN APPROVED COLECO BIOS ENTRY, BUT DONE ANYWAY

stop_music:
    ;; Inactive All 4 Sound Areas
    ld b,#4
    xor a
    ld hl,#0x702b ; Address for the 1st Sound Area
$3:
    ld (hl),#0xff
    inc hl
    inc hl
    inc hl
    inc hl
    ld (hl),#0xf0
    inc hl
    ld (hl),a
    inc hl
    inc hl
    ld (hl),a
    inc hl
    ld (hl),a
    inc hl
    inc hl
    djnz $3
    ret

    
; _+_ WHAT IS THIS ? _+_
;
; Hello,
; This routine can be called at the end of the NMI routine, in project code.
; ... it's only if the programmer want to use this functionality.
; It's a routine to deal with playing background music in the following format.
;
; MUSIC TABLE
; ----------
; DURATION, [NBR-1 sounds to start | sound_no in 6 bits ], sound_no2*, sound_no2*, sound_no2*
; * these sound_no are not essential, it depends on the value of NBR.
; IF DURATION = 0000, END MARKER
; IF DURATION > 7FFF, SET MUSIC TABLE POINTER TO THIS NEW LOCATION TO CONTINUE
;
; To use this routine, the program should not use the first 4 SOUNDAREAs to play sound effects, because they are reserved for the music.
; Why? Because the first 4 AREAs are low priotity and because of that the sound effect in AREAs 5+ will play while continuing playing logically the music in the background.
