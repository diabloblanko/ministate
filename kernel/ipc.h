#ifndef IPC_H
#define IPC_H

#include <stdint.h>
#include <stddef.h>

#define MAX_MSG_SIZE 64

enum ipc_msg_type {
    MSG_TYPE_NONE = 0,
    MSG_FS_OPEN,
    MSG_FS_READ,
    MSG_FS_WRITE,
    MSG_ATA_READ,
    MSG_ATA_WRITE,
    MSG_TIMER,
    MSG_USER_DEFINED = 100  
};

struct ipc_message {
    uint32_t source_pid;   
    uint32_t dest_pid;     
    uint32_t type;         
    uint32_t size;         
    uint8_t data[MAX_MSG_SIZE]; 
};

void ipc_init();

int ipc_send(uint32_t dest_pid, const struct ipc_message* msg);

int ipc_receive(uint32_t pid, struct ipc_message* msg, uint32_t timeout);

#endif
