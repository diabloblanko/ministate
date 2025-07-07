#include <stdint.h>
#ifndef SCREEN_H
#define SCREEN_H
void clears();
void putstr(const char* str);
void putchr(char c);
void update_cursor();
void setcolor(uint8_t color);
extern unsigned char get_text_color;
#endif
