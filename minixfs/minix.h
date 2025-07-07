#ifndef MINIX_H
#define MINIX_H

#include <stdint.h>

#define MINIX_MAGIC 0x137F
#define MINIX_NAME_LEN 30
#define MINIX_ROOT_INO 1


struct minix_superblock {
    uint16_t ninodes;          
		uint16_t nzones;           
    uint16_t imap_blocks;      
    uint16_t zmap_blocks;      
    uint16_t firstdatazone;    
    uint16_t log_zone_size;    
    uint32_t max_size;         
    uint16_t magic;            
    uint16_t state;            
    uint16_t zones;            
};


struct minix_inode {
    uint16_t mode;    
    uint16_t uid;     
    uint32_t size;    
    uint32_t time;    
    uint8_t  gid;     
    uint8_t  nlinks;  
    uint16_t zones[9]; 
};

struct minix_dir_entry {
    uint16_t inode;
    char name[MINIX_NAME_LEN];
};


int minix_init(uint8_t drive_num);


int minix_open(const char* path);
int minix_read(int inode, void* buffer, size_t size, off_t offset);
int minix_readdir(int dir_inode, struct minix_dir_entry* entries, size_t count);

#endif
