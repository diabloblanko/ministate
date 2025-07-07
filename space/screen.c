// screen.c
#include "screen.h"
#include <stdint.h> 

#define VGA_BUFFER 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

int cursor_x = 0;
int cursor_y = 0;

uint8_t vga_color = 0x07;  

void clears() {
    volatile uint16_t* vga = (volatile uint16_t*)VGA_BUFFER;
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            const int index = y * VGA_WIDTH + x;
            vga[index] = (uint16_t)' ' | (uint16_t)vga_color << 8;
        }
    }
    cursor_x = 0;
    cursor_y = 0;
    update_cursor();
}

void putchar(char c) {
    volatile uint16_t* vga = (volatile uint16_t*)VGA_BUFFER;
    
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        const int index = cursor_y * VGA_WIDTH + cursor_x;
        vga[index] = (uint16_t)c | (uint16_t)vga_color << 8;
        cursor_x++;
    }

    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    
    if (cursor_y >= VGA_HEIGHT) {
        for (int y = 1; y < VGA_HEIGHT; y++) {
            for (int x = 0; x < VGA_WIDTH; x++) {
                const int src_index = y * VGA_WIDTH + x;
                const int dst_index = (y - 1) * VGA_WIDTH + x;
                vga[dst_index] = vga[src_index];
            }
        }
        
        for (int x = 0; x < VGA_WIDTH; x++) {
            const int index = (VGA_HEIGHT - 1) * VGA_WIDTH + x;
            vga[index] = (uint16_t)' ' | (uint16_t)vga_color << 8;
        }
        
        cursor_y = VGA_HEIGHT - 1;
    }
    
    update_cursor();
}

void putstr(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
}


extern void outb(uint16_t port, uint8_t value);

void update_cursor() {
    const uint16_t position = cursor_y * VGA_WIDTH + cursor_x;
    
    outb(0x3D4, 0x0F);  
    outb(0x3D5, (uint8_t)(position & 0xFF));
    
    outb(0x3D4, 0x0E);  
    outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));
}
