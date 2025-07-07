#include "ata.h"
#include <stdint.h>

int main() {
    
    ata_init();
    
    
    ipc_register(0x10);
    
    while(1) {
        struct ipc_message msg;
        if(ipc_receive(&msg) == 0) {
            switch(msg.type) {
                case MSG_ATA_READ: {
                    struct ata_request {
                        uint32_t lba;
                        uint8_t count;
                    }* req = (struct ata_request*)msg.data;
                    
                    uint8_t buffer[512 * 16]; 
                    ata_read_sectors(req->lba, req->count, buffer);
                    
                    // Отправка данных обратно
                    struct ipc_message reply;
                    reply.dest_pid = msg.source_pid;
                    reply.type = MSG_ATA_READ;
                    memcpy(reply.data, buffer, req->count * 512);
                    ipc_send(reply.dest_pid, &reply);
                    break;
                }
            }
        }
    }
    return 0;
}
