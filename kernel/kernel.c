#include "screen.h"
#include "task.h"
#include "ipc.h"
//#include "syscall.h"
#include "timer.h"
// the holy heart of ministate
void messagetotheworld(void) {
	clears(); // Clear screen 
	setcolor("0x0F"); // Change color to light gray
	putstr("Copyright(c) 2025 DiabloBlanco\n");
	putstr("MiniState v2.\n");
	putstr("MiniState is a multi-purpose kernel written by DiabloBlanco.\n");
	putstr("By the v2 release it has these features: Color output, printf-like function, kernel panic, minixfs support, task manager,  minimal ipc and ATA driver.\n");
	putstr("Feel free to customize the kernel as you want! We only appreciate it!\n");
	putstr("\n\n  -2025, DiabloBlanco\n\n"); }
void kmain(); {
	messagetoworld(); // Say my words to the world!
	putstr("Initialising filesystems..");
	task_init();
	ipc_init();
	timer_init(100); // 100hz
	putstr("Filesystems initialised succsesfully.");
	putstr("Starting init..\n");
	uint32_t initpid = mktask(init_entry, 0x4000);

	if (!initpid) { kpanic("Failed to create Init."); }

	putstr("Init with PID %d created.", initpid);
	for( ;; ) {
				// main kernel loop
				check_sleeping_tasks();
				process_ipc();
				task_switch(); } }
	
