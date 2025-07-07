#include "ata.h"
#include "../kernel/ports.h"
#include "../kernel/kpanic.h"

static void ata_wait() {
    while (inb(0x1F7) & 0x80); 
    if (inb(0x1F7) & 0x01) kpanic("ATA error");
}

void ata_init() {
    outb(0x1F6, ATA_MASTER);
    outb(0x1F2, 0);
    outb(0x1F3, 0); outb(0x1F4, 0); outb(0x1F5, 0);
    outb(0x1F7, 0xEC); 
    
    ata_wait();
    
    
    if(inb(0x1F4) == 0 && inb(0x1F5) == 0) {
        // Диск присутствует
    } else {
        kpanic("No ATA disk detected");
    }
}

int ata_read_sectors(uint32_t lba, uint8_t count, void* buffer) {
    outb(0x1F6, ATA_MASTER | ((lba >> 24) & 0x0F));
    outb(0x1F2, count);
    outb(0x1F3, (uint8_t)lba);
    outb(0x1F4, (uint8_t)(lba >> 8));
    outb(0x1F5, (uint8_t)(lba >> 16));
    outb(0x1F7, 0x20); // Команда READ
    
    uint16_t* ptr = (uint16_t*)buffer;
    for (int s = 0; s < count; s++) {
        ata_wait();
        for (int i = 0; i < ATA_SECTOR_SIZE/2; i++) {
            ptr[i] = inw(0x1F0);
        }
        ptr += ATA_SECTOR_SIZE/2;
    }
    return 0;
}

int ata_write_sectors(uint32_t lba, uint8_t count, const void* buffer) {
    outb(0x1F6, ATA_MASTER | ((lba >> 24) & 0x0F));
    outb(0x1F2, count);
    outb(0x1F3, (uint8_t)lba);
    outb(0x1F4, (uint8_t)(lba >> 8));
    outb(0x1F5, (uint8_t)(lba >> 16));
    outb(0x1F7, 0x30); // Команда WRITE
    
    const uint16_t* ptr = (const uint16_t*)buffer;
    for (int s = 0; s < count; s++) {
        ata_wait();
        for (int i = 0; i < ATA_SECTOR_SIZE/2; i++) {
            outw(0x1F0, ptr[i]);
        }
        ptr += ATA_SECTOR_SIZE/2;
    }
    return 0;
}

void ata_get_info(uint16_t* cylinders, uint16_t* heads, uint16_t* sectors) {
    *cylinders = 1024;
    *heads = 16;
    *sectors = 63;
}
