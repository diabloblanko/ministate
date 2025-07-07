  1 #!/bin/bash
  2 gcc -m32 -c screen.c  -o screen.o -ffreestanding -nostdlib
  3 gcc -m32 -c kernel.c  -o kernel.o -ffreestanding -nostdlib
  4 #gcc -m32 kpanic.c  -o kpanic.o    -ffreestanding -nostdlib
  5 nasm -f elf32 entry.asm -o entry.o
  6 #nasm -f elf32 kernel.asm -o asmkernel.o
  7 nasm -f elf32 ports.asm -o ports.o
  8 ld -m elf_i386 -T link.ld -o ministate-2-test entry.o ports.o kernel.o screen.o
  9 echo "Building finished"
