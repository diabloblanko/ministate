#ifndef SCREEN_H
#define SCREEN_H
void clears();
void putstr(const char* str);
void putchr(char c);
void update_cursor();
void setcolor(uint8_t color);
uint8_t get_text_color;
#endif
