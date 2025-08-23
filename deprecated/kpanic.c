#include "panic.h"
#include "screen.h"
#include <stdint.h>
#include <stdlib.h>
void kpanic(const char* why, const char* where, int line) {
  	uint8_t prev_color = get_text_color();
	setcolor("0x4F");
	clears();
	putstr("MiniState kernel panik!\n");
	putstr("-----------------------\n");
	putstr("Msg        ::"); putstr(message); putstr("\n");
	putstr("Because of ::"); putstr(file); putstr(" In line");
	char nbuf[12];
	char *p = nbuf + sizeof(nbuf) - 1;
	*p = '\0';
	int n = line;
	do {
		*--p = '0' + (n % 10);
		n /= 10;
	} while(n);
	putstr(p);
	putstr("\nSystem will be halted.");
	asm volatile("cli");
	asm volatile("hlt");
