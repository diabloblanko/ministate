# MiniState-1
MiniState is a 32-bit multi-purpose kernel.
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

