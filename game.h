
extern const byte fontgo_NAMERLE[];
extern const byte fontgo_PATTERNRLE[];

extern unsigned short time;
extern unsigned char flag_spr;
extern unsigned short score ;
extern unsigned char flag ;
extern unsigned char status;
extern unsigned char frame_picture ;
extern unsigned char game_mode;
extern const unsigned char frame1_color[];
extern const unsigned char frame2_color[];
extern const unsigned char frame3_color[];
extern const unsigned char frame4_color[];
extern const unsigned char frame5_color[];
extern const unsigned char frame6_color[];
extern const unsigned char frame7_color[];
extern const unsigned char frame8_color[];
extern const unsigned char frame1_pattern[];
extern const unsigned char frame2_pattern[];
extern const unsigned char frame3_pattern[];
extern const unsigned char frame4_pattern[];
extern const unsigned char frame5_pattern[];
extern const unsigned char frame6_pattern[];
extern const unsigned char frame7_pattern[];
extern const unsigned char frame8_pattern[];

extern const unsigned char status_level1[9];

const unsigned char font_number[11] =
{ 52, 56, 60, 64, 68, 72, 76, 80, 84, 88 };

const unsigned char* const frame_porn_color[]=
{
	frame1_color,frame2_color,frame3_color,frame4_color,frame5_color,
	frame6_color,frame7_color,frame8_color
};

const unsigned char* const frame_porn_pattern[]=
{
	frame1_pattern,frame2_pattern,frame3_pattern,frame4_pattern,frame5_pattern,
	frame6_pattern,frame7_pattern,frame8_pattern
};

extern void switch_gamemode(byte mode);
