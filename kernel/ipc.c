#include "ipc.h"
#include "task.h"
#include "kpanic.h"

#define IPC_QUEUE_SIZE 256

static struct ipc_message ipc_queue[IPC_QUEUE_SIZE];
static uint32_t ipc_head = 0;
static uint32_t ipc_tail = 0;
static uint32_t ipc_count = 0;

void ipc_init() {
    ipc_head = ipc_tail = ipc_count = 0;
    printk("IPC subsystem initialized\n");
}

int ipc_send(uint32_t dest_pid, const struct ipc_message* msg) {
    if(ipc_count >= IPC_QUEUE_SIZE) {
        return -1; 
    }
    
    if(!task_exists(dest_pid)) {
        return -2; 
    }
    
    ipc_queue[ipc_tail] = *msg;
    ipc_queue[ipc_tail].source_pid = current_task->pid;
    ipc_queue[ipc_tail].dest_pid = dest_pid;
    
    ipc_tail = (ipc_tail + 1) % IPC_QUEUE_SIZE;
    ipc_count++;
    
    task_wake(dest_pid);
    
    return 0;
}

int ipc_receive(uint32_t pid, struct ipc_message* msg, uint32_t timeout) {
    for(uint32_t i = 0; i < ipc_count; i++) {
        uint32_t idx = (ipc_head + i) % IPC_QUEUE_SIZE;
        
        if(ipc_queue[idx].dest_pid == pid) {
            *msg = ipc_queue[idx];
            
            for(uint32_t j = idx; j != ipc_tail; j = (j + 1) % IPC_QUEUE_SIZE) {
                ipc_queue[j] = ipc_queue[(j + 1) % IPC_QUEUE_SIZE];
            }
            
            ipc_tail = (ipc_tail - 1 + IPC_QUEUE_SIZE) % IPC_QUEUE_SIZE;
            ipc_count--;
            
            return 0;
        }
    }
    
    
    if(timeout > 0) {
        current_task->state = TASK_WAITING;
        current_task->wake_time = get_ticks() + timeout;
    }
    
    return -1; 
}
