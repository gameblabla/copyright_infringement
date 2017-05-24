/*
The MIT License (MIT)
Copyright (c) 2017 Gameblabla

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*/

#include "player.h"
#include "coleco.h"
#include "getput1.h"
#include "banks.h"
#include "main.h"
#include "text.h"


static void init_vdp()
{
	disable_nmi();
	screen_off();
	screen_mode_2_text();
	fill_vram (0,0,0x4000);
	load_ascii();
	duplicate_pattern();
	fill_vram(0x2000,0xf0,6144);
	vdp_out (7,0xf1);
	cls();	
	enable_nmi();
	screen_on();
}

static void Clear_field()
{
	unsigned char i;
	for(i=0;i<32;i++)
	{
		print_at (i, 17, " ");
		print_at (i, 18, " ");
		print_at (i, 19, " ");
		print_at (i, 20, " ");
		print_at (i, 21, " ");
	}
}

static void Clear_field_slow()
{
	unsigned char i;
	for(i=0;i<32;i++)
	{
		print_at (i, 17, " ");
		print_at (i, 18, " ");
		print_at (i, 19, " ");
		print_at (i, 20, " ");
		print_at (i, 21, " ");
		delay(0);
	}
}

static void Print_text(const unsigned char *string, byte size, byte y)
{
	unsigned char x = 0;
	unsigned char i = 0;
	
	for(i=0;i<size;i++)
	{
		if (string[i] == 124) 
		{
			y++;
			x = 0;
		}
		else
		{
			put_char (x, y, string[i]);
			x++;
		}
		delay(1);
	}
}

void bakura_face(unsigned char pc)
{
	unsigned char i;
	SWITCH_IN_BANK10;
	switch(pc)
	{
		case 0:
			for(i=0;i<2;i++)
			{
				sprites[i].colour = 0;
				sprites[i].x = 0;
				sprites[i].y = 0;
				sprites[i].pattern = 0;
			}
			sprites[2].colour = 15;
			sprites[2].x = 141;
			sprites[2].y = 48;
			sprites[2].pattern = 2;
			sprites[3].colour = 15;
			sprites[3].x = 141;
			sprites[3].y = 56;
			sprites[3].pattern = 3;
			sprites[4].colour = 15;
			sprites[4].x = 112;
			sprites[4].y = 50;
			sprites[4].pattern = 4;
			show_picture(bakura2_img);
		break;
		case 1:
			sprites[0].colour = 15;
			sprites[0].x = 124;
			sprites[0].y = 58;
			sprites[0].pattern = 0;
			sprites[1].colour = 9;
			sprites[1].x = 126;
			sprites[1].y = 60;
			sprites[1].pattern = 1;
			sprites[2].colour = 15;
			sprites[2].x = 141;
			sprites[2].y = 48;
			sprites[2].pattern = 2;
			sprites[3].colour = 15;
			sprites[3].x = 141;
			sprites[3].y = 56;
			sprites[3].pattern = 3;
			sprites[4].colour = 15;
			sprites[4].x = 112;
			sprites[4].y = 50;
			sprites[4].pattern = 4;
			
			show_picture(bakura3_img);
		break;
	}
	
	Clear_field();
}

static void Print(const unsigned char* string, byte size, byte face, byte y)
{
	screen_off();
	disable_nmi();
	if (face != 255) bakura_face(face);
	enable_nmi();
	screen_on();
	SWITCH_IN_BANK12;
	Print_text(string, size, y);
	pause();
	Clear_field_slow();
}


void story()
{
	unsigned char i;
	SWITCH_IN_BANK12;
	for(i=0;i<5;i++)
	{
		Print(text_introduction_firstline[i], sizeof(text_introduction_firstline[0]), face_introduction_firstline[i], 17);
	}
	switch_gamemode(4);
}

void details_beforemj1()
{
	SWITCH_IN_BANK12;
	Print(text_minigame_1, sizeof(text_minigame_1), 255, 3);
	score = 0;
	switch_gamemode(1);
}

void results()
{
	init_vdp();

	SWITCH_IN_BANK12;
	Print_text(results_minigame_1[0], sizeof(results_minigame_1[0]), 2);
	Print_text(str(score), 5, 3);
	if (score == 666)
	{
		Print(results_minigame_1[2], sizeof(results_minigame_1[2]), 255, 5);
		pause();
		init_vdp();
		Print(gameover_mj1_alternate2, sizeof(gameover_mj1_alternate2), 255, 1);
		pause();
	}
	else if (score < 300)
	{
		Print(results_minigame_1[1], sizeof(results_minigame_1[1]), 255, 5);
		pause();
		init_vdp();
		Print(gameover_mj1, sizeof(gameover_mj1), 255, 1);
		pause();
	}
	else if (score < 950)
	{
		Print(results_minigame_1[2], sizeof(results_minigame_1[2]), 255, 5);
		pause();
		init_vdp();
		Print(gameover_mj1_alternate, sizeof(gameover_mj1_alternate), 255, 1);
		pause();
	}
	else
	{
		Print(results_minigame_1[3], sizeof(results_minigame_1[3]), 255, 5);
		pause();
	}
	
	switch_gamemode(0);	
}



void titlescreen_func()
{
	if (time_splash > 250)
	{
		if (joypad_1&FIRE1)
		{
			switch_gamemode(3);
			time_splash = 0;
		}
	}
	else
	{
		time_splash++;
	}
}

void switch_gamemode(byte mode)
{
	unsigned char i;
	unsigned char tempy_y = 128;
	game_mode = mode;
	flag = 0;
	status = 0;
	time = 0;
	disable_nmi();
	screen_off();
	delay(1);
	
	switch(mode)
	{
		/* Titlescreen */
		case 0:
			screen_mode_2_bitmap();
			SWITCH_IN_BANK9;
			load_spatternrle(sprite_titlescreen_pattern);
			duplicate_pattern();
			show_picture(titlescreen_img);
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 15;
			sprites[4].colour = 15;
			sprites[0].x = 16+88;
			sprites[0].y = tempy_y;
			sprites[1].x = 32+88;
			sprites[1].y = tempy_y;
			sprites[2].x = 48+88;
			sprites[2].y = tempy_y;
			
			sprites[3].x = 20+88;
			sprites[3].y = tempy_y+16;
			
			sprites[4].x = 36+88;
			sprites[4].y = tempy_y+16;
			
			
			sprites[0].pattern = 0;
			sprites[1].pattern = 4;
			sprites[2].pattern = 8;
			sprites[3].pattern = 12;
			sprites[4].pattern = 16;
			flag_spr = 1;
			updatesprites(0,8);
		break;
		
		/* In-game (gameplay) */
		case 1:
			frame_picture = 4;
			screen_mode_2_bitmap();
			load_spatternrle(SPRITE_PATTERNRLE);
			duplicate_pattern();
			picture(0);
			sprite_text(status_level1[status], 96, 175);
			updatesprites(0,8);
			flag_spr = 1;
			place_score();
			play_sound(1);
		break;

		/* Introduction */
		case 3:
			screen_mode_2_bitmap();
			sprites_8x8();
			SWITCH_IN_BANK9;
			load_spatternrle(bakura_img_pattern);
			duplicate_pattern();
			flag_spr = 1;
			updatesprites(0,8);
			Clear_field();
		break;

		case 2:
		case 4:
			flag_spr = 0;
			update_sprites(0,0);
			init_vdp();
		break;
	}
	
	delay(1);
	screen_on();
	enable_nmi();
}

// code starts
void main(void)
{
	set_snd_table(snd_table);
	switch_gamemode(0);
	
	// now we can main loop
	while(1)
	{
		switch(game_mode)
		{
			case 0:
				titlescreen_func();
			break;
			case 1:
				ingame_fucking();
			break;
			case 2:
				results();
			break;
			case 3:
				story();
			break;
			case 4:
				details_beforemj1();
			break;
		}
	}

}

void nmi()
{
	time++;
	
	if (flag == 1)
	{
		picture(frame_picture);
		flag = 0;
	}
	
	if (flag_spr == 1)
	{
		updatesprites(0,8);
	}

}
