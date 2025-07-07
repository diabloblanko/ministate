#include "task.h"
#include "memory.h"
#include "kpanic.h"
#include "screen.h"
#define MAX_TASKS 32
#define KERNEL_STACK_SIZE 0x4000  // 16KB
#define USER_STACK_SIZE   0x8000  // 32KB

struct task tasks[MAX_TASKS];
uint32_t current_pid = 0;
uint32_t next_pid = 1;  


void task_init() {
    memset(tasks, 0, sizeof(tasks));
    
   
    tasks[0].pid = 0;
    tasks[0].state = TASK_RUNNING;
    tasks[0].priority = 0;
    
    putstr("Task subsystem initialized\n");
}

uint32_t mktask(void (*entry)(), enum task_type type) {
    
    uint32_t pid = -1;
    for(uint32_t i = 1; i < MAX_TASKS; i++) {
        if(tasks[i].state == TASK_FREE) {
            pid = i;
            break;
        }
    }
    
    if(pid == -1) {
        kpanic("No free task slots");
        return 0;
    }
    
    uint32_t stack_size = (type == TASK_KERNEL) ? 
        KERNEL_STACK_SIZE : USER_STACK_SIZE;
    
    void* stack = kmalloc(stack_size);
    if(!stack) {
        kpanic("Task stack allocation failed");
        return 0;
    }
    
    tasks[pid].pid = next_pid++;
    tasks[pid].state = TASK_READY;
    tasks[pid].type = type;
    tasks[pid].entry = entry;
    tasks[pid].stack_base = (uint32_t)stack;
    tasks[pid].stack_size = stack_size;
    tasks[pid].esp = (uint32_t)stack + stack_size - sizeof(struct task_context);
    
    struct task_context* ctx = (struct task_context*)tasks[pid].esp;
    memset(ctx, 0, sizeof(struct task_context));
    ctx->eip = (uint32_t)entry;
    ctx->eflags = 0x202;  
    
    return tasks[pid].pid;
}

void task_wake(uint32_t pid) { // &pid, wake up!
    for(uint32_t i = 0; i < MAX_TASKS; i++) {
        if(tasks[i].pid == pid) {
            tasks[i].state = TASK_READY;
            return;
        }
    }
}


int task_exists(uint32_t pid) {
    for(uint32_t i = 0; i < MAX_TASKS; i++) {
        if(tasks[i].pid == pid && tasks[i].state != TASK_FREE) {
            return 1;
        }
    }
    return 0;
}

void task_switch() {
    
    asm volatile("mov %%esp, %0" : "=r"(tasks[current_pid].esp));
    
    
    uint32_t next = (current_pid + 1) % MAX_TASKS;
    while(tasks[next].state != TASK_READY) {
        next = (next + 1) % MAX_TASKS;
        
        
        if(next == current_pid) {
            next = 0;
            break;
        }
    }
    
    current_pid = next;
    
    
    asm volatile("mov %0, %%esp" :: "r"(tasks[current_pid].esp));
}
