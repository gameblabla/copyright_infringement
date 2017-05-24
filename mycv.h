#ifndef MYCV_H
#define MYCV_H 1

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint16_t cv_vmemp; // 14-Bit Video memory address type
extern void cv_set_write_vram_address(cv_vmemp address);
extern void cv_memtovmemcpy_fast(const void *src, size_t n);
extern void cv_memtovmemcpy_slow(const void *src, size_t n);

const cv_vmemp color_address = 0x2000;
const cv_vmemp pattern_addres = 0x0000;
volatile uint8_t cv_vint_indicator;

#endif
