// Copyright(c) 2025 DiabloBlanco
// MiniState project, V3
#include "screen.h"
//#include "kernel.h" // maybe in further versions
void kmain() {
	clears();
	setcolor(0x0A); // Kolor for kernel logs
	putstr("Copyright(c) 2025 DiabloBlanco\n");
	putstr("MiniState kernel V3\n");
	setcolor(0x07);
	putstr("If you see this message, piece of crap named MiniState works :D \n");
	putstr("If you kinda enjoy this piece of crap, learn more about MS_OS("); 
	setcolor(0x0E);
	putstr("github.com/diabloblanko/ms_os\n");
	setcolor(0x07); }
