
#include "utils.h"

void WriteToMemory(BYTE* dst, BYTE* src, size_t size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldProtect, NULL);
}

void Nop(BYTE* dst, size_t size)
{
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldProtect, NULL);
}

DWORD GetProcId(const wchar_t* procName)
{
	DWORD procID = NULL;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32	procEntry;
		procEntry.dwSize = sizeof(procEntry);

		do
		{
			if (!_wcsicmp(procEntry.szExeFile, procName))
			{
				procID = procEntry.th32ProcessID;
				break;
			}
		} while (Process32Next(hSnap, &procEntry));
	}
	CloseHandle(hSnap);
	return procID;
}


uintptr_t FindPattern(HMODULE hModule, BYTE* pattern, BYTE* mask, size_t patternLength, size_t offsetFromBegin)
{
	MODULEINFO modInfo = { 0 };
	GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO));

	uintptr_t base = reinterpret_cast<uintptr_t>(modInfo.lpBaseOfDll);
	size_t size = modInfo.SizeOfImage;

	for (uintptr_t i = 0; i < size - patternLength; ++i)
	{
		bool found = true;
		for (size_t j = 0; j < patternLength; ++j)
		{
			found &= mask[j] == '?' || pattern[j] == *(BYTE*)(base + i + j);
		}

		if (found)
		{
			return base + i + offsetFromBegin;
		}
	}
	return NULL;
}
