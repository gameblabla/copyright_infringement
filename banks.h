/*
The MIT License (MIT)
Copyright (c) 2017 Gameblabla

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*/

#define SWITCH_IN_BANK1	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfffe);
#define SWITCH_IN_BANK2	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfffd);
#define SWITCH_IN_BANK3	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfffc);
#define SWITCH_IN_BANK4	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfffb);
#define SWITCH_IN_BANK5	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfffa);
#define SWITCH_IN_BANK6	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff9);
#define SWITCH_IN_BANK7	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff8);
#define SWITCH_IN_BANK8	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff7);
#define SWITCH_IN_BANK9	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff6);
#define SWITCH_IN_BANK10	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff5);
#define SWITCH_IN_BANK11	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff4);
#define SWITCH_IN_BANK12	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff3);
#define SWITCH_IN_BANK13	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff2);
#define SWITCH_IN_BANK14	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff1);
#define SWITCH_IN_BANK15	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xfff0);
#define SWITCH_IN_BANK16	(*(volatile unsigned char*)0)=(*(volatile unsigned char*)0xffef);

