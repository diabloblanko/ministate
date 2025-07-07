// 00:40 MSK/ 27.06.25
#include "screen.h"
void kmain(void) {
	clears(); // Clear screen
	putstr("MiniState V1 greets you!\n");
	putstr("MiniState is a 32-bit multi-purpose kernel written by DiabloBlanco\n");
	putstr("Currently, it has these features:: A printf-like functions(putstr and putchar) and clear.\n");
	putstr("In future, i want to port BASH and tcc.\n");
	putstr(" -2025, DiabloBlanco.\n"); }


/*Legacy code! Was used in very-very first version of MiniState.
void kmain(void) {
		const char *str= "Welcome to MiniK, the kernel of MiniState";
		char *vidptr = (char*)0xb8000;
		unsigned int i = 0;
		unsigned int j = 0;
		while(j < 80 * 25 * 2) {
			vidptr[j] = ' ';
			vidptr[j+1] = 0x07;
			j = j + 2; }
		 j = 0;

		 while(str[j] != '\0') {
			 vidptr[i] = str[j];
			 vidptr[i+1] = 0x07;
			 ++j;
			 i = i + 2; }
		  return; }
*/
