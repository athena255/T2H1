#pragma once
#ifndef HOOK_H
#define HOOK_H
#include "C_UserCmd.h"
#include "VMatrix.h"
bool Hook(void* dst, void* src, size_t len);

using CreateHookFn = int(__stdcall*)(LPVOID pTarget, LPVOID pDetour, LPVOID *ppOriginal);
CreateHookFn CreateHook;

using EnableHookFn = int(__stdcall*)(LPVOID pTarget, BOOL enable);
EnableHookFn EnableHook;

using CreateMoveFn = bool(__fastcall*)(void* cinput, int sequence_number, float input_sample_frametime, bool active);
CreateMoveFn CreateMove;

using CreateInterfaceFn = uintptr_t(__fastcall *)(const char*, uintptr_t);
CreateInterfaceFn CreateInterface;
//using GetAsyncKeyStateFn = uintptr_t(__stdcall*)(int vKey);
//GetAsyncKeyStateFn GetAsyncKeyState;
//using WorldToScreenFn = bool(__fastcall*)(C_Vec& origin, C_Vec& screen);

using GetWorldToScreenMatrixFn = matrix3x4_t * (__fastcall *)(void*, char);
GetWorldToScreenMatrixFn GetWorldToScreenMatrix;

using GetNameFn = char*(__fastcall*)(uintptr_t);
GetNameFn GetName;

using GetUserCmdFn = C_UserCmd * (__fastcall*)(void*, int, int);
GetUserCmdFn GetUserCmd;

//template <typename T> 
//__forceinline static T vFunc(void* pTable, int index)
//{
//	uintptr_t* VTableFuncBase = *(uintptr_t**)pTable;
//	uintptr_t dwAddress = VTableFuncBase[index];
//	return reinterpret_cast<T>(dwAddress);
//}

inline void**& getvtable(void* inst, size_t offset = 0)
{
	return *reinterpret_cast<void***>((size_t)inst + offset);
}
inline const void** getvtable(const void* inst, size_t offset = 0)
{
	return *reinterpret_cast<const void***>((size_t)inst + offset);
}
template< typename Fn >
inline Fn vFunc(const void* inst, size_t index, size_t offset = 0)
{
	return reinterpret_cast<Fn>(getvtable(inst, offset)[index]);
}

#endif