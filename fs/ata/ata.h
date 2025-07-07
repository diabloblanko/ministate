#ifndef ATA_H
#define ATA_H

#include <stdint.h>

#define ATA_MASTER 0xE0
#define ATA_SECTOR_SIZE 512

void ata_init();


int ata_read_sectors(uint32_t lba, uint8_t count, void* buffer);


int ata_write_sectors(uint32_t lba, uint8_t count, const void* buffer);


void ata_get_info(uint16_t* cylinders, uint16_t* heads, uint16_t* sectors);

#endif
