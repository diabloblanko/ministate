// Panic.h
// Copyright(c) 2025 DiabloBlanco
// MiniState project, V3R
// Added in MiniState v1.1
#pragma once
#define KPANIC(msg) kpanic(msg, __FILE__, __LINE__)
void kpanic(const char* message, const char* file, int line);
