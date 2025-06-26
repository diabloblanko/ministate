; entry.asm
bits 32             ; Режим защищённый (32-bit)
section .multiboot
    align 4
    dd 0x1BADB002   ; Магическое число Multiboot
    dd 0x00         ; Флаги
    dd -(0x1BADB002 + 0x00) ; Контрольная сумма

section .text
global _start
extern kmain   ; Главная функция на C

_start:
    ; Настройка стека
    mov esp, 0x90000
    
    ; Проверка магического числа Multiboot
    cmp eax, 0x2BADB002
    jne .no_multiboot
    
    ; Вызов главной функции ядра
    call kmain
    
    ; Зависание, если kernel_main вернётся
    cli
    hlt
    jmp $

.no_multiboot:
    ; Вывод ошибки (красный текст)
    mov dword [0xB8000], 0x4F524F45 ; 'ERR'
    mov dword [0xB8004], 0x4F3A4F52 ; 'R:'
    mov dword [0xB8008], 0x4F204F20 ; '  '
    mov byte  [0xB800A], 0x4F       ; Красный фон
    mov byte  [0xB800B], 'M'        ; Код ошибки
    hlt
		
