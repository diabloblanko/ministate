# MiniState-1
MiniState is a 32-bit multi-purpose microkernel.
NOTE::MiniState is still very "raw".
## Dependencies
* GNU LD
* GCC
* NASM 
* QEMU(To test it)
## Building
I made building simple: Just run this command to build it.
```bash
chmod +x build.sh # if dont have execution permissions
./build.sh
```
This will create a ministate-1 file.
## Running
Running is also very simple
```bash
qemu-system-i386 -kernel ministate-1
```
## Why microkernel instead of traditional monolithic/modular?
Microkernel is stable and safe. If one driver breaks, whole system will down.
I will try to represent architecture of Microkernel with ascii art

          ___
  ______ |d  |  ___
 |      ||___| | d |
 |Kernel|      |___|
 |______|

d stands for "driver"
Every driver is in his own space, divided from each others.

## What will be in next release?
Planned release date: 27th june, 2025
(✔ means done)
- [] MinixFS support
- [x] Kernel panic
- [] Tiny C Compiler port
- [] Shell port
- [x] Color output support
When everything will be done, new release will appear.
## Gallery
### MiniState 1:
![ee](https://i.ibb.co/X1TV8dC/minist.png)
