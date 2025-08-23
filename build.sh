#!/bin/bash

CLEANOFILES="YES"

echo "Building MiniState V2R"
gcc -m32 -c screen.c  -o ofiles/screen.o -ffreestanding -nostdlib
gcc -m32 -c kernel.c  -o ofiles/kernel.o -ffreestanding -nostdlib
# gcc -m32 kpanic.c  -o kpanic.o    -ffreestanding -nostdlib
nasm -f elf32 entry.asm -o ofiles/entry.o
# nasm -f elf32 kernel.asm -o asmkernel.o
nasm -f elf32 ports.asm -o ofiles/ports.o
ld -m elf_i386 -T link.ld -o ministate-v2r ofiles/entry.o ofiles/ports.o ofiles/kernel.o ofiles/screen.o
echo "Building finished"
if [ "$1" == "-run" ]; then
    qemu-system-i386 -kernel ministate-v2r
fi
if [ "$CLEANOFILES" == "YES" ]; then
    rm ofiles/*
fi
echo "Tip: You can use the -run flag to run in QEMU after building"
