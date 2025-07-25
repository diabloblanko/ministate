// Panic.h
// Added in MiniState v1.1
#pragma once
#define KPANIC(msg) kpanic(msg, __FILE__, __LINE__)
void kpanic(const char* message, const char* file, int line);
