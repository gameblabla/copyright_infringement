/*
The MIT License (MIT)
Copyright (c) 2017 Gameblabla

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*/

#include "coleco.h"

const byte sprite_titlescreen_pattern[] = {
  0x03, 0xF8, 0x88, 0x88, 0xF0, 0x83, 0x80, 0x87, 0x00, 0x03, 0xF0, 0x90, 0x90, 0xE0, 0x83,
  0x90, 0x88, 0x00, 0x06, 0xF0, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF0, 0x87, 0x00, 0x07, 0x38, 0xC0,
  0x80, 0x78, 0x04, 0x04, 0x0C, 0xF0, 0x87, 0x00, 0x07, 0x38, 0xC0, 0x80, 0x78, 0x04, 0x04, 0x0C,
  0xF0, 0x97, 0x00, 0x03, 0xF8, 0x80, 0x80, 0xF8, 0x83, 0x80, 0x87, 0x00, 0x02, 0x10, 0x00, 0x00,
  0x84, 0x10, 0x87, 0x00, 0x04, 0xF8, 0x88, 0x98, 0xE0, 0xB0, 0x82, 0x88, 0x88, 0x00, 0x06, 0xF0,
  0x80, 0x80, 0xF0, 0x80, 0x80, 0xF0, 0x87, 0x00, 0x84, 0x38, 0x02, 0x10, 0x00, 0x38, 0xFE, 0x00,
  0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00,
  0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xE5, 0x00, 0xFF};

const byte titlescreen_img[] = 
{
 0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,
 0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xFE,0x1F,0xD9,0x1F,0xFE,0x18,
 0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,
 0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,
 0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,
 0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,0xFE,0x18,
 0xD4,0x18,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xD0,0xFF,0x02,0xE0,0x80,
 0x0F,0x84,0xFF,0x02,0x7F,0x3C,0xB8,0x84,0xFF,0x02,0x07,0x01,0x70,0x84,0xFF,0x81,
 0xF0,0x00,0xF1,0x84,0xFF,0x02,0x07,0x03,0xE1,0x84,0xFF,0x02,0x0F,0x87,0xC7,0x84,
 0xFF,0x02,0x86,0x0E,0x1E,0x84,0xFF,0x02,0x01,0x00,0x38,0x84,0xFF,0x81,0xF8,0x00,
 0x78,0x84,0xFF,0x02,0xFE,0xF8,0xF0,0x84,0xFF,0x02,0x03,0x01,0xF9,0x84,0xFF,0x82,
 0xC7,0x84,0xFF,0x82,0xE3,0x84,0xFF,0x81,0x80,0x00,0xFC,0x84,0xFF,0x81,0x07,0x00,
 0x7F,0xFC,0xFF,0x83,0xFF,0x84,0xFE,0x81,0xFF,0x00,0x1F,0x84,0x3F,0x02,0x1F,0x0F,
 0xF8,0x84,0xF1,0x02,0xF8,0xB8,0xF8,0x84,0xFC,0x07,0xF8,0x70,0xF1,0x71,0x71,0x70,
 0x70,0x71,0x83,0xF1,0x02,0xE1,0x03,0x07,0x82,0xFF,0x03,0xC2,0xE2,0xF0,0xF0,0x83,
 0xF8,0x03,0x1E,0x3E,0x7E,0x7E,0x83,0xFE,0x81,0x3C,0x05,0x38,0x00,0x00,0x38,0x38,
 0x3C,0x82,0x78,0x82,0xF8,0x81,0x78,0x00,0xF1,0x84,0xE3,0x01,0xF1,0xF0,0x82,0xFF,
 0x81,0xC1,0x82,0xF1,0x81,0xC7,0x81,0xC0,0x83,0xC7,0x81,0xE3,0x81,0x03,0x83,0xE3,
 0x87,0xFC,0x87,0x7F,0xFE,0xFF,0x88,0xFF,0x01,0x80,0xE0,0x85,0xFF,0x01,0x3C,0x7F,
 0x85,0xFF,0x01,0x01,0x07,0x85,0xFF,0x81,0xF1,0x8D,0xFF,0x81,0xF8,0x85,0xFF,0x81,
 0xFE,0x85,0xFF,0x01,0x3C,0x3E,0x85,0xFF,0x81,0x38,0x85,0xFF,0x01,0xF8,0xFE,0x85,
 0xFF,0x01,0x01,0x03,0x85,0xFF,0x81,0xC7,0x85,0xFF,0x81,0xE3,0x85,0xFF,0x81,0xFC,
 0x85,0xFF,0x81,0x7F,0xE7,0xFF,0x85,0xE3,0x81,0xFF,0x07,0xC3,0xC1,0xC1,0xC0,0xC0,
 0xC4,0xFF,0xFF,0x84,0xE3,0x04,0x63,0xFF,0xFF,0xC0,0xC0,0x82,0xC7,0x04,0xC0,0xFF,
 0xFF,0x1E,0x1E,0x82,0xFE,0x0C,0x1E,0xFF,0xFF,0x01,0x00,0x38,0x3C,0x3C,0x38,0xFF,
 0xFF,0xF8,0xF8,0x83,0x78,0x81,0xFF,0x84,0xF0,0x15,0xF1,0xFF,0xFF,0xF8,0x78,0x78,
 0x38,0x38,0x18,0xFF,0xFF,0xFE,0xF8,0xF0,0xF1,0xE3,0xE3,0xFF,0xFF,0x03,0x01,0xF9,
 0x84,0xFF,0x81,0xC0,0x82,0xC7,0x04,0xC0,0xFF,0xFF,0x1E,0x1E,0x82,0xFE,0x0B,0x1E,
 0xFF,0xFF,0x1F,0x0F,0x0F,0x06,0x06,0x26,0xFF,0xFF,0x87,0x83,0x07,0x04,0x47,0xFF,
 0xFF,0x80,0x80,0x82,0x8F,0x04,0x80,0xFF,0xFF,0x3C,0x3C,0x82,0xFC,0x0C,0x3C,0xFF,
 0xFF,0x3E,0x1E,0x1E,0x0E,0x0E,0x46,0xFF,0xFF,0x38,0x38,0x83,0x3F,0x81,0xFF,0x81,
 0x00,0x83,0xC7,0x81,0xFF,0x81,0x7F,0x85,0xFF,0x85,0xE3,0x81,0xFF,0x85,0xF1,0x81,
 0xFF,0x85,0xF8,0xBF,0xFF,0x86,0xE3,0x02,0xFF,0xC4,0xC6,0x84,0xC7,0x09,0xFF,0x23,
 0x23,0x03,0x03,0x83,0x83,0xC3,0xFF,0xC0,0x85,0xC7,0x01,0xFF,0x1E,0x85,0xFE,0x08,
 0xFF,0x00,0x00,0x38,0x38,0x3C,0x3C,0x3E,0xFF,0x82,0xF8,0x81,0x78,0x81,0x38,0x00,
 0xFF,0x86,0xF1,0x08,0xFF,0x08,0x88,0xC0,0xC0,0xE0,0xE0,0xF0,0xFF,0x82,0xE3,0x06,
 0xF1,0xF0,0xF8,0xFE,0xFF,0xC1,0xC1,0x82,0xF1,0x03,0x01,0x03,0xFF,0xC0,0x83,0xC7,
 0x81,0xC0,0x01,0xFF,0x1E,0x83,0xFE,0x81,0x1E,0x09,0xFF,0x20,0x30,0x30,0x39,0x39,
 0x3F,0x3F,0xFF,0x47,0x85,0xC7,0x01,0xFF,0x80,0x83,0x8F,0x81,0x80,0x01,0xFF,0x3C,
 0x83,0xFC,0x81,0x3C,0x08,0xFF,0x42,0x62,0x70,0x70,0x78,0x78,0x7C,0xFF,0x86,0x3F,
 0x00,0xFF,0x86,0xC7,0x88,0xFF,0x81,0xE3,0x81,0xFF,0x82,0xE3,0x04,0xFF,0xF1,0xF1,
 0xFF,0xFF,0x82,0xF1,0x04,0xFF,0xF8,0xF8,0xFF,0xFF,0x82,0xF8,0xEC,0xFF,0x00,0xF8,
 0x82,0xFE,0x83,0xFF,0x03,0x37,0xF7,0xF7,0xF0,0x83,0xFF,0x03,0x61,0x6F,0x6F,0x63,
 0x83,0xFF,0x03,0xE1,0xED,0xED,0xE3,0x83,0xFF,0x03,0x86,0xBC,0xBD,0x8D,0x83,0xFF,
 0x03,0x18,0xFB,0xFB,0x98,0x83,0xFF,0x03,0x61,0x6F,0x6F,0xE3,0x83,0xFF,0x03,0x8E,
 0x7D,0x3C,0x0C,0x83,0xFF,0x03,0x34,0xF6,0xF6,0x36,0x83,0xFF,0x03,0xC8,0xCB,0xDB,
 0x58,0x83,0xFF,0x03,0x78,0xFB,0xFB,0xF8,0x83,0xFF,0x03,0x6E,0x6C,0x6D,0xED,0x83,
 0xFF,0x03,0x1B,0xFB,0xFB,0x98,0x83,0xFF,0x03,0xB0,0xBD,0xBD,0x3D,0x83,0xFF,0x00,
 0x7F,0xFE,0xFF,0x8B,0xFF,0x82,0xFE,0x84,0xFF,0x82,0xF7,0x84,0xFF,0x81,0x6F,0x00,
 0x61,0x84,0xFF,0x02,0xE9,0xED,0xEC,0x84,0xFF,0x02,0xBD,0xBC,0x86,0x84,0xFF,0x02,
 0xDA,0xDB,0x1B,0x84,0xFF,0x81,0x6F,0x00,0x21,0x84,0xFF,0x02,0xCF,0xEF,0x0C,0x84,
 0xFF,0x02,0x36,0xB7,0x37,0x84,0xFF,0x02,0x1B,0x3B,0x38,0x84,0xFF,0x02,0xFA,0xFB,
 0x7B,0x84,0xFF,0x02,0x6D,0x6C,0x2E,0x84,0xFF,0x81,0xDB,0x00,0x1B,0x84,0xFF,0x82,
 0xBD,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,
 0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,
 0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,
 0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xEA,0xFF,0xFF};
 