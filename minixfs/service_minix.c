#include "minix.h"
#include <stdint.h>



struct ipc_message {
    uint32_t source_pid;
    uint32_t dest_pid;
    uint32_t type;
    uint8_t data[128];
};


void ipc_register(uint32_t service_id);
int ipc_receive(struct ipc_message* msg) { return 0; }
void ipc_send(uint32_t dest_pid, const struct ipc_message* msg);

int main() {
    
    minix_init(0);
    
    
    ipc_register(0x20);
    
    while(1) {
        struct ipc_message msg;
        if(ipc_receive(&msg) == 0) {
            
            switch(msg.type) {
                case MSG_FS_OPEN: {
                    const char* path = (const char*)msg.data;
                    int result = minix_open(path);
                    
                    
                    struct ipc_response {
                        int result;
                        int inode;
                    } response = {0, result};
                    
                    struct ipc_message reply;
                    reply.dest_pid = msg.source_pid;
                    reply.type = MSG_FS_OPEN;
                    memcpy(reply.data, &response, sizeof(response));
                    ipc_send(reply.dest_pid, &reply);
                    break;
                }
                case MSG_FS_READ: {
                 
                    break;
                }
            }
        }
    }
    return 0;
}
