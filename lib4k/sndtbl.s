; sound.s

    .module play_sound

    ; global from this code

    .globl  _set_snd_table, set_snd_table ;, _snd_dummy
    ; set_snd_table (void *snd_table);

    .area _CODE
    
_set_snd_table:
    pop de
    pop hl
    push hl
    push de
set_snd_table:
	ld	b,#6
    ld a,h
    or a
    jr nz, call_snd_table
    ld hl,#snd_table_dummy
call_snd_table:
    jp 0x1fee

snd_table_dummy:
    .dw _snd_dummy, #0x702b ; SOUNDAREA1
_snd_dummy:
    .db #0xff
    