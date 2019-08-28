#pragma once
#include "C_UserCmd.h"
class C_Input
{
public:

	inline C_UserCmd* GetUserCmd(int sequence_number);
	inline C_UserCmd* GetUserCmd(int nSlot, int sequence_number);
	
};

C_UserCmd* C_Input::GetUserCmd(int nSlot, int sequence_number)
{
	return vFunc<C_UserCmd*(__fastcall*)(void*, int, int)>(this, cinput::idx_GetUserCmd)(this, nSlot, sequence_number);
}

C_UserCmd* C_Input::GetUserCmd(int sequence_number)
{
	return vFunc<C_UserCmd*(__fastcall*)(void*, int)>(this, cinput::idx_GetUserCmd)(this, sequence_number);
}
