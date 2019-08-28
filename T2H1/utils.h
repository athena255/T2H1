#pragma once
#include "stdafx.h"
void WriteToMemory(BYTE* dst, BYTE* src, size_t size);
void Nop(BYTE* dst, size_t size);
DWORD GetProcId(const wchar_t* procName);
uintptr_t FindPattern(HMODULE hModule, BYTE* pattern, BYTE* mask, size_t patternLength, size_t offsetFromBegin);