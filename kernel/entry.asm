; entry.asm
bits 32             
section .multiboot
    align 4
    dd 0x1BADB002   
    dd 0x00         
    dd -(0x1BADB002 + 0x00) 

section .text
global _start
extern kmain   

_start:
    
    mov esp, 0x90000
    
    
    cmp eax, 0x2BADB002
    jne .no_multiboot
    
    
    call kmain
    
    
    cli
    hlt
    jmp $

.no_multiboot:
    
    mov dword [0xB8000], 0x4F524F45 ; 'ERR'
    mov dword [0xB8004], 0x4F3A4F52 ; 'R:'
    mov dword [0xB8008], 0x4F204F20 ; '  '
    mov byte  [0xB800A], 0x4F       
    mov byte  [0xB800B], 'M'        
    hlt
		
