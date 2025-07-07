#include "screen.h"
void motd() {
	setcolor(0x0F); // Change color to light gray
	putstr("Copyright(c) 2025 DiabloBlanco\n");
	putstr("MiniState v2\n");
	putstr("MiniState is a multi-purpose kernel written by DiabloBlanco.\n");
	putstr("Feel free to customize the kernel as you want! We only appreciate it!\n");
	putstr("\n\n  -2025, DiabloBlanco\n\n"); }
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
	putstr("INITLOG::Init just started\n");
	putstr("I created it to make developers life easier.\n"); 
	// putstr("Currently, its just a programm printing this text to screen.\n"); 
	motd();
	colortest(); }
