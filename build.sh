#!/bin/bash
echo "Building MiniState v2"
gcc -m32 -c screen.c  -o screen.o -ffreestanding -nostdlib
gcc -m32 -c kernel.c  -o kernel.o -ffreestanding -nostdlib
# gcc -m32 kpanic.c  -o kpanic.o    -ffreestanding -nostdlib
nasm -f elf32 entry.asm -o entry.o
nasm -f elf32 kernel.asm -o asmkernel.o
nasm -f elf32 ports.asm -o ports.o
ld -m elf_i386 -T link.ld -o ministate-2-test entry.o ports.o kernel.o screen.o
echo "Building finished"
