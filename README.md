# MiniState V3, the fifth release of the Kernel!
BSD2-Licensed 32-bit monolithic(?) kernel.
MiniState is designed as a kernel that can be used to create a cool OS with less efforts.
Also, MiniState follows KISS.
Feel free to contribute and suggesting me ideas using the "issues" page(github.com/diabloblanko/ministate/issues)!
![ministate-v3](https://i.ibb.co/gb2Zfxk9/basestate.png)
## Dependencies
* clang(release is built with gcc 15.2.1 20250813)
* nasm(release is built with 2.16.03)
## Building
```
chmod +x build.sh && ./build.sh
```
You can use the -run flag to build and run in QEMU
## Where is MSH and things you promised to add?
After some thinking i decided to create MS_OS to demonstrate MSH, sysinfo and other things. 
By 13.11.2025, MS_OS is still on work. Everything works fine, except the bootloader.
(currently)Empty MS_OS repo is on github.com/diabloblanko/ms_os
## Version history
V1 -> V1.1 -> V2 -> V2R -> V3
## Differences between V2R and V3:
* Default cc to compile is now clang
* Some minor changes and fixes
