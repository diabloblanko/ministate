# MiniState V2R (Rebuilt), the fourth release of the Kernel!
BSD2-Licensed 32-bit monolithic(?) kernel.
#### Keep GPL outta it!
Feel free to contribute and suggesting me ideas using the "issues" page!
We are looking for people that can provide binaries for *BSD/Solaris(Illumos)/ETC
![ministate-v2r](https://i.ibb.co/hRt2c29q/2025-08-23-16-10.png)
## Dependencies
* gcc(release is built with gcc 15.2.1 20250813)
* nasm(release is built with 2.16.03)
## Building
```
chmod +x build.sh && ./build.sh
```
I recommend using QEMU for running in VM.
You can use the -run flag to build and run in QEMU

## my words about it (not required to read)
Im still unsure would it be monolithic or micro. Theres almost no guides for that.
I tried a lot of times to make d-written msh work on ministate-dev but no sucsess.
Still unsure, would the name "MiniState" stay, dont have any ideas lol
If you have any suggestions about name, pls open an issue!
Maybe, i should create Ministate-based OS to provide basic tools for the kernel. Maintaining both kernel and a whole OS would be hard.
Convert to 64-bit?
## Version history
V1 -> V1.1 -> V2 -> V2R
IDK why there is no release of V1.1 on GitHub page, but it counts because of the note in panic.h: "Added in MiniState v1.1".
## Tools that is planned to be ported/created
* sysinfo(uname)
* Execution file format. Maybe classic UNIX ELF, idk
* C compiler(TCC,?)(GCC is GPL-ed and CLang is too hard to port)
* (maybe)DMD, D compiler. Would be a total headache to port.
* Filesystem(EXT2,?)
* Build system(self-written, ?)
### Planned to be added in V3
* MSH(Minimal shell). It would be easier to create a small shell with basic functions than porting a fatty BASH.
* ANSI-Escape codes
* SRBFetch(github.com/diabloblanko/srbfetch)
## Differences between V2 and V2R:
* Fixed source tree
* Kernel panic is temporarily removed.(deprecated/)
* Init prototype in init/ directory. Needs modifications before serious using. 
* Minor changes in kernel
* Added copyright notices to every file.
* Updated build.sh
