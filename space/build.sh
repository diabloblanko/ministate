#!/bin/bash
# Compile ASM files
nasm -f elf32 entry.asm -o entry.o
nasm -f elf32 ports.asm -o ports.o

# Compile C files
gcc -m32 -c kernel.c -o ministate-kernel.o -ffreestanding -nostdlib
gcc -m32 -c screen.c -o screen.o -ffreestanding -nostdlib

# Linking tiime:P
ld -m elf_i386 -T link.ld -o ministate-1 entry.o ports.o ministate-kernel.o screen.o
