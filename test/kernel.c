#include "screen.h"
//#include <unistd.h>
//#include "syscall.h"
#include "init.c"
// the holy heart of ministate
/*
void msgtow(void) {
	clears(); // Clear screen 
	setcolor(0x0F); // Change color to light gray
	putstr("Copyright(c) 2025 DiabloBlanco\n");
	putstr("MiniState v2-TEST\n");
	putstr("MiniState is a multi-purpose kernel written by DiabloBlanco.\n");
	putstr("Feel free to customize the kernel as you want! We only appreciate it!\n");
	putstr("BUILDNOTE::This is test build. Kernel panic may appear, dont be scared.\n"); 
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
	putstr("That's all.\n"); }*/

/*
void kpanictest(); {
	setcolor("0x07");
	putstr("Since that is a boring kernel that does not collect input, u have no choice but kernel panic!\n");
	putstr("It will happen in 10 seconds!\n");
	sleep(10);
	kpanic("If u see that, kpanic works"); }*/

	
void kmain() {
	setcolor(0x0A); // Kolor for kernel logs
	putstr("MiniState v2\n");
	putstr("Kernel is starting default init.\n");
	initmain(); }
	//kpanic("Test", "Test", 1); }
