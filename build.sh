#!/bin/bash

CLEANOFILES="YES"
CC="clang"
echo "Building MiniState V3."
mkdir ofiles
echo "Compiling C code($CC).."
$CC -m32 -c screen.c  -o ofiles/screen.o -ffreestanding -nostdlib
$CC -m32 -c kernel.c  -o ofiles/kernel.o -ffreestanding -nostdlib
# gcc -m32 kpanic.c  -o kpanic.o    -ffreestanding -nostdlib
echo "Compiling ASM code($AC, $ACARG).."
nasm -f elf32 entry.asm -o ofiles/entry.o
# nasm -f elf32 kernel.asm -o asmkernel.o
nasm -f elf32 ports.asm -o ofiles/ports.o
echo "Linking($LD, $LDARG) all the files into $OUT.."
ld -m elf_i386 -T link.ld -o ministate-v3 ofiles/entry.o ofiles/ports.o ofiles/kernel.o ofiles/screen.o
echo "Building finished."
if [ "$1" == "-run" ]; then
    qemu-system-i386 -kernel ministate-v3
fi
if [ "$CLEANOFILES" == "YES" ]; then
    rm ofiles/*
fi
echo "Tip:: You can use the -run flag to run in qemu right after building."
