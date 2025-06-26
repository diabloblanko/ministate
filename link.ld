ENTRY(_start)

SECTIONS
{
    . = 0x100000;
    
    .text BLOCK(4K) : ALIGN(4K) {
        *(.multiboot)
        *(.text)
        *(.rodata*)
    }
    
    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
    }
    
    .bss BLOCK(4K) : ALIGN(4K) {
        *(COMMON)
        *(.bss)
    }
    
    /DISCARD/ : {
        *(.comment)
        *(.eh_frame)
    }
}
