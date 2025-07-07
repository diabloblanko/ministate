#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#define MAX_TASKS 32

enum task_state {
    TASK_FREE,      
    TASK_READY,     
    TASK_RUNNING,   
    TASK_WAITING,   
    TASK_SLEEPING   
};

enum task_type {
    TASK_KERNEL,    
    TASK_USER       
};

enum task_priority {
    PRIORITY_HIGH = 0,
    PRIORITY_NORMAL,
    PRIORITY_LOW
};

struct task_context {
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t eip;
    uint32_t eflags;
};

struct task {
    uint32_t pid;           
    enum task_state state;  
    enum task_type type;    
    enum task_priority priority; 
    void (*entry)();        
    uint32_t esp;           
    uint32_t stack_base;    
    uint32_t stack_size; };
void task_init();

uint32_t mktask(void (*entry)(), enum task_type type);

void task_wake(uint32_t pid);

int task_exists(uint32_t pid);

void task_switch();

#endif
