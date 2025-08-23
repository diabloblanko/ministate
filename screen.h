#include <stdint.h>
// Copyright(c) 2025 DiabloBlanco
// MiniState project, V3R
#ifndef SCREEN_H
#define SCREEN_H
void clears();
void putstr(const char* str);
void putchar(char c);
void update_cursor();
void setcolor(uint8_t color);
#endif
