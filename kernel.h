// kernel.h
// Headers for kernel.

/* Macros marked with ! are disabled by default.
* !COLOR_TEST_ENABLE
* !USE_CINIT_AS_DEFINIT
* USE_DOIT_INIT_AS_DEFINIT
* !MOTD_ENABLED
* DLOGIN_ENABLED
*
*/




// Please, be carefull with what are you changing.

//          Init Color test
//#define COLOR_TEST_ENABLE // Enable init COLOR

//            Default init(C-Written CInit vs D-Written doit_Init)
#define USE_CINIT_AS_DEFINIT
// #define USE_DOIT_INIT_AS_DEFINIT

//             Services (doIt & CInit)
//#define MOTD_ENABLED
//#define DLOGIN_ENABLED // If commented, will automatically login into root account.
