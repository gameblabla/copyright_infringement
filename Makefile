CC = sdcc
CFLAGS = -mz80 -c -I"./include" --std-sdcc99 --vc -DENABLEFX
OLDFLAGS = --opt-code-speed 
AS = sdasz80
AFLAGS = -plosgff
# might need to use .o for older SDCC, rel for newer
EXT=rel

.PHONY: all clean

objs = main.$(EXT) \
	frame1.$(EXT) frame2.$(EXT) frame3.$(EXT) frame4.$(EXT) frame5.$(EXT) frame6.$(EXT) frame7.$(EXT) frame8.$(EXT) \
	./libcv/cv_memtovmemcpy_slow.$(EXT) ./libcv/cv_memtovmemcpy_fast.$(EXT) ./libcv/cv_set_write_vram_address.$(EXT) sounds.$(EXT) bakura_beautifulface.$(EXT) \
	titlescreen.$(EXT) bakura.$(EXT) bakura2.$(EXT) game.$(EXT) text.$(EXT) fontgo.$(EXT)

all: build
		makemegacart -map crt0.s crt0.ihx game_buk.rom
	
# banks - all defined the same way, we just need to declare them
BANKS = "-Wl -b_bank1=0xc000" "-Wl -b_bank2=0xc000" "-Wl -b_bank3=0xc000" "-Wl -b_bank4=0xc000" "-Wl -b_bank5=0xc000" "-Wl -b_bank6=0xc000" "-Wl -b_bank7=0xc000" "-Wl -b_bank8=0xc000" \
 "-Wl -b_bank9=0xc000" "-Wl -b_bank10=0xc000" "-Wl -b_bank11=0xc000" "-Wl -b_bank12=0xc000"  "-Wl -b_bank13=0xc000" "-Wl -b_bank14=0xc000" "-Wl -b_bank15=0xc000" "-Wl -b_bank16=0xc000"
 
build: $(objs) crt0.$(EXT)
	$(CC) -mz80 --no-std-crt0 $(BANKS) --code-loc 0x8100 --data-loc 0x7000 -l./cvlib.lib -l./getput.lib ./crt0.$(EXT) $(objs)

clean:
	rm -f *.rel *.map *.lst *.lnk *.sym *.asm *~ *.o *.obj *.ihx *.sprite.* *.rom *.rel

# build the source files
main.rel: main.c
	$(CC) $(CFLAGS) -o main.rel main.c --codeseg main --constseg main
	
game.rel: game.c
	$(CC) $(CFLAGS) -o game.rel game.c --codeseg main --constseg main
	
fontgo.rel: fontgo.c
	$(CC) $(CFLAGS) -o fontgo.rel fontgo.c --codeseg bk11 --constseg bk11
	
text.rel: text.c
	$(CC) $(CFLAGS) -o text.rel text.c --codeseg bk12 --constseg bk12
	
frame1.rel: frame1.c
	$(CC) $(CFLAGS) -o frame1.rel frame1.c --codeseg bk1 --constseg bk1

frame2.rel: frame2.c
	$(CC) $(CFLAGS) -o frame2.rel frame2.c --codeseg bk2 --constseg bk2
	
frame3.rel: frame3.c
	$(CC) $(CFLAGS) -o frame3.rel frame3.c --codeseg bk3 --constseg bk3

frame4.rel: frame4.c
	$(CC) $(CFLAGS) -o frame4.rel frame4.c --codeseg bk4 --constseg bk4

frame5.rel: frame5.c
	$(CC) $(CFLAGS) -o frame5.rel frame5.c --codeseg bk5 --constseg bk5
	
frame6.rel: frame6.c
	$(CC) $(CFLAGS) -o frame6.rel frame6.c --codeseg bk6 --constseg bk6

frame7.rel: frame7.c
	$(CC) $(CFLAGS) -o frame7.rel frame7.c --codeseg bk7 --constseg bk7

frame8.rel: frame8.c
	$(CC) $(CFLAGS) -o frame8.rel frame8.c --codeseg bk8 --constseg bk8
	
bakura.rel: bakura.c
	$(CC) $(CFLAGS) -o bakura.rel bakura.c --codeseg bk9 --constseg bk9
	
bakura2.rel: bakura2.c
	$(CC) $(CFLAGS) -o bakura2.rel bakura2.c --codeseg bk10 --constseg bk10
	
bakura_beautifulface.rel: bakura_beautifulface.c
	$(CC) $(CFLAGS) -o bakura_beautifulface.rel bakura_beautifulface.c --codeseg bk10 --constseg bk10
	
titlescreen.rel: titlescreen.c
	$(CC) $(CFLAGS) -o titlescreen.rel titlescreen.c --codeseg bk9 --constseg bk9


# Recipe to compile all C files
%.rel: %.c
	$(CC) -c $< $(CFLAGS) -o $@

# Recipe to compile all assembly files
%.rel: %.s
	$(AS) -o $@ $<
