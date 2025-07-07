#include "minix.h"
#include "../fs/ata.h"
#include "kpanic.h"
#include "include/string.h"

static uint8_t current_drive = 0;
static struct minix_superblock sb;
static uint8_t* imap = 0;
static uint8_t* zmap = 0;


static void read_block(uint16_t block_num, void* buffer) {
    
    uint32_t lba = (block_num * 2) + 2; 
    ata_read_sectors(lba, 2, buffer);
}

int minix_init(uint8_t drive_num) {
    current_drive = drive_num;
    
    
    ata_read_sectors(1, 2, &sb);
    
    if(sb.magic != MINIX_MAGIC) {
        return -1; 
    }
    
    
    imap = (uint8_t*)kmalloc(sb.imap_blocks * 1024);
    zmap = (uint8_t*)kmalloc(sb.zmap_blocks * 1024);
    
    
    read_block(1, imap); 
    read_block(1 + sb.imap_blocks, zmap); 
    
    return 0;
}

int minix_open(const char* path) {
    if(strcmp(path, "/") == 0) {
        return MINIX_ROOT_INO;
    }
    
    
    struct minix_dir_entry entries[16];
    int count = minix_readdir(MINIX_ROOT_INO, entries, 16);
    
    for(int i = 0; i < count; i++) {
        if(strcmp(entries[i].name, path + 1) == 0) { 
            return entries[i].inode;
        }
    }
    
    return -1; 
}

int minix_read(int inode, void* buffer, size_t size, off_t offset) {
    
    struct minix_inode ino;
    uint32_t inode_block = 2 + sb.imap_blocks + sb.zmap_blocks; // Начало inode
    uint32_t inode_offset = (inode - 1) * sizeof(struct minix_inode);
    uint32_t block_num = inode_block + (inode_offset / 1024);
    uint32_t block_offset = inode_offset % 1024;
    
    uint8_t block[1024];
    read_block(block_num, block);
    memcpy(&ino, block + block_offset, sizeof(ino));
    
    
    if(offset < ino.size) {
        size_t to_read = (size < (ino.size - offset)) ? size : (ino.size - offset);
        read_block(ino.zones[0], buffer);
        return to_read;
    }
    
    return 0;
}

int minix_readdir(int dir_inode, struct minix_dir_entry* entries, size_t count) {
    if(dir_inode != MINIX_ROOT_INO) return 0; 
    
    struct minix_inode ino;
    
    
    uint8_t dir_block[1024];
    read_block(ino.zones[0], dir_block);
    
    struct minix_dir_entry* de = (struct minix_dir_entry*)dir_block;
    int i = 0;
    // Hidden comment! :0 
    while(de->inode != 0 && i < count) {
        entries[i] = *de;
        de++;
        i++;
    }
    
    return i;
}
