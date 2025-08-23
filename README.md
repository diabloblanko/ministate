# MiniState V2R (Rebuilt), the fourth release of the Kernel!
BSD2-Licensed 32-bit monolithic(?) kernel.

Feel free to contribute and suggesting me ideas using the "issues" page!
We are looking for people that can provide binaries for *BSD/Solaris/ETC.
![ministate-v2r]
## Dependencies
* gcc(release is built with gcc 15.2.1 20250813)
* nasm(release is built with 2.16.03 compiled on May 13 2025)
## Building
Just
```
chmod +x build.sh && ./build.sh
```
Thats all.
You can use the -run flag to build&run
## my words about it (not required to read)
Im still unsure would it be monolithic or micro. Theres almost no guides for that.
I plan to write most of it using C. Dlang will be used for MSH(Minimal Shell), and maybe login
I will create tools like init or MSH to make it easier for other developers to make an MS-based OS.
Still unsure, would the name "MiniState" stay, dont have any ideas lol
If you have any suggestions about name, pls open an issue!
Maybe, i should create Ministate-based OS to provide basic tools for the kernel. Maintaining both kernel and a whole OS would be hard.
## Version history(not required to read)
V1 -> V1.1 -> V2 -> V2R
IDK why there is no release of V1.1 on GitHUb page, but it counts because of the note in panic.h: "Added in MiniState v1.1".
## Tools that is planned to be ported/created
* sysinfo, uname but simple and small.
* Execution file format. Maybe classic UNIX ELF, idk
* TCC, tiny C compiler
* (maybe)DMD, D compiler. Would be a total headache to port.
* EXT2, filesystem is a must-have.
* MSH(Minimal shell). It would be easier to create a small shell with basic functions than porting a fatty BASH.
## Differences between V2 and V2R:
* Fixed source tree
* Kernel panic is temporarily removed.(deprecated/)
* Init prototype in init/ directory. Needs modifications before serious using. 
* Minor changes in kernel
* Added copyright notices to every file.
* Updated build.sh