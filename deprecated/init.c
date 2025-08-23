#include "screen.h"
#include "kernel.h"
// Copyright(c) 2025 DiabloBlanco
// MiniState project, V3R
void motd() { // By default, MOTD is disabled. Uncomment MOTD_ENABLED to enable it.
	setcolor(0x0F); // Change color to light gray
	putstr(""); }

#ifdef COLORTEST_ENABLED
colortest();
#endif
#ifdef MOTD_ENABLED
char* motd_enabled = "YES";
#endif
void colortest() {
	setcolor(0x0A);
	putstr("Color test!\n");
	setcolor(0x02);
	putstr("Color test\n");
	setcolor(0x0C);
	putstr("Color test\n");
	setcolor(0x0B);
	putstr("Color test\n");
	setcolor(0x0E);
	putstr("How r' ya doin'?\n");
	setcolor(0x0F);
	putstr("That's all.\n"); }
int initmain() {
	setcolor(0x02); // green
	putstr("INITLOG::CInit just started\n");
	// putstr("Currently, its just a programm printing this text to screen.\n");
	if(motd_enabled = "YES") {
		putstr("INITLOG::Starting MOTD...");
		motd();
	}
	 }
