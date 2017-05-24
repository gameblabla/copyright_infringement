/*
The MIT License (MIT)
Copyright (c) 2017 Gameblabla

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*/

#include "coleco.h"
#include "getput1.h"
#include "mycv.h"
#include "banks.h"
#include "game.h"


void sprite_text(unsigned char id, unsigned char x, unsigned char y)
{
	switch(id)
	{
		/* Keep it up !!*/
		case 0:
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 0;
			sprites[0].pattern = 0;
			sprites[1].pattern = 4;
			sprites[2].pattern = 8;
			sprites[3].pattern = 96;
			sprites[0].x = x;
			sprites[0].y = y;
			sprites[1].x = x+16;
			sprites[1].y = y;
			sprites[2].x = x+40;
			sprites[2].y = y;
			sprites[3].x = 255;
			sprites[3].y = 204;
		break;
		/* You win !!! */
		case 1:
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 15;
			sprites[0].pattern = 12;
			sprites[1].pattern = 16;
			sprites[2].pattern = 20;
			sprites[3].pattern = 24;
			sprites[0].x = x;
			sprites[0].y = y;
			sprites[1].x = x+16;
			sprites[1].y = y;
			sprites[2].x = x+32;
			sprites[2].y = y;
			sprites[3].x = x+48;
			sprites[3].y = y;
		break;
		/* STOP !*/ 
		case 2:
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 0;
			sprites[0].pattern = 28;
			sprites[1].pattern = 32;
			sprites[2].pattern = 36;
			sprites[3].pattern = 0;
			sprites[0].x = x+8;
			sprites[0].y = y;
			sprites[1].x = x+24;
			sprites[1].y = y;
			sprites[2].x = x+40;
			sprites[2].y = y;
			sprites[3].x = x+56;
			sprites[3].y = y;
		break;
		/* FUCK ! */
		case 3:
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 0;
			sprites[0].pattern = 40;
			sprites[1].pattern = 44;
			sprites[2].pattern = 36;
			sprites[3].pattern = 96;
			sprites[0].x = x+8;
			sprites[0].y = y;
			sprites[1].x = x+24;
			sprites[1].y = y;
			sprites[2].x = x+40;
			sprites[2].y = y;
			sprites[3].x = x+56;
			sprites[3].y = y;
		break;
		/* FINISH ! */
		case 4:
			sprites[0].colour = 15;
			sprites[1].colour = 15;
			sprites[2].colour = 15;
			sprites[3].colour = 15;
			sprites[0].pattern = 92;
			sprites[1].pattern = 96;
			sprites[2].pattern = 100;
			sprites[3].pattern = 104;
			sprites[0].x = x+8;
			sprites[0].y = y;
			sprites[1].x = x+24;
			sprites[1].y = y;
			sprites[2].x = x+40;
			sprites[2].y = y;
			sprites[3].x = x+56;
			sprites[3].y = y;
		break;
	}
}

void picture(unsigned char pc)
{
	switch(frame_picture)
	{
		case 0:
			SWITCH_IN_BANK1;
		break;
		case 1:
			SWITCH_IN_BANK2;
		break;
		case 2:
			SWITCH_IN_BANK3;
		break;
		case 3:
			SWITCH_IN_BANK4;
		break;
		case 4:
			SWITCH_IN_BANK5;
		break;
		case 5:
			SWITCH_IN_BANK6;
		break;
		case 6:
			SWITCH_IN_BANK7;
		break;
		case 7:
			SWITCH_IN_BANK8;
		break;
	}
	
	cv_set_write_vram_address(pattern_addres);
	cv_memtovmemcpy_slow(frame_porn_pattern[pc], 6144);
	cv_set_write_vram_address(color_address);
	cv_memtovmemcpy_slow(frame_porn_color[pc], 6144);
}

static void add_score(unsigned short sc)
{
	sprites[4].pattern = font_number[(sc/1000)%10];
	sprites[5].pattern = font_number[(sc/100)%10];
	sprites[6].pattern = font_number[(sc/10)%10];
	sprites[7].pattern = font_number[sc%10];
}

static void decrease_score()
{
	if (score > 2) score-=3;
}

void place_score()
{
	sprites[4].colour = 15;
	sprites[5].colour = 15;
	sprites[6].colour = 15;
	sprites[7].colour = 15;
	sprites[4].x = 4;
	sprites[4].y = 4;
	sprites[5].x = 4+16;
	sprites[5].y = 4;
	sprites[6].x = 4+32;
	sprites[6].y = 4;
	sprites[7].x = 4+48;
	sprites[7].y = 4;
}


void ingame_fucking()
{
	if (time > 128)
	{
		time = 0;
		status++;
		if (status >= sizeof(status_level1)) game_mode = 2;
		sprite_text(status_level1[status], 96, 175);
	}
		
	if (status_level1[status] != 4)
	{
		add_score(score);
		switch(status_level1[status])
		{
			case 0:
			case 3:
				if (frame_picture != 4 && frame_picture != 0) score++;
			break;
			case 2:
				if (frame_picture != 4) decrease_score();
			break;
		}
			
		if (frame_picture == 4)
		{
			if (joypad_1&FIRE1 && frame_picture == 4 && flag == 0)
			{
				frame_picture = 5;
				flag = 1;
			}
		}
		else if (frame_picture != 4)
		{
			if (flag == 0)
			{
				if (frame_picture == 0 && !(joypad_1&FIRE1))
				{
					frame_picture++;
					if (frame_picture > 7) frame_picture = 0;
					flag = 1;
				}
				else if (frame_picture != 0)
				{
					frame_picture++;
					if (frame_picture > 7) frame_picture = 0;
					flag = 1;
				}
			}
		}	
	}
	// If Status level is 4, aka if game reached END
	else
	{
		if (time > 123)
		{
			switch_gamemode(2);
		}
	} 

}
