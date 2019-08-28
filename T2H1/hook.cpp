#pragma once
#include "stdafx.h"
#include "utils.h"

// places a jmp to the the target function
bool Hook(void* dst, void* src, size_t len) // dst is the target function, src is our function
{
	if (len < 5)
		return false;
	Nop(static_cast<BYTE*>(dst), len);

	DWORD oldProtect;
	VirtualProtect(dst, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	uintptr_t relAddr = ((uintptr_t)src - (uintptr_t)dst) - 5;

	*(BYTE*)(dst) = 0xE9;

	*(uintptr_t*)((uintptr_t)dst + 1) = relAddr; // jmp to relative address

	VirtualProtect(dst, len, oldProtect, NULL);

	return true;
}

