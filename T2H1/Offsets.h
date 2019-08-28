#pragma once
#include "stdafx.h"
namespace offsets
{
	uintptr_t iindex = 0x8;

	uintptr_t m_iHealth = 0x390;
	uintptr_t m_iMaxHealth = 0x4A8;
	uintptr_t m_sheildHealth = 0x150;
	uintptr_t m_shieldHealthMax = 0x154;
	uintptr_t m_lifeState = 0x6C8;
	uintptr_t m_fFlags = 0x8C;
	uintptr_t m_iTeamNum = 0x3A4;
	uintptr_t m_iSignifierName = 0x4B0;
	uintptr_t m_vecOrigin = 0x90;

	uintptr_t m_hOwnerEntity = 0x3E0;
	uintptr_t m_localAngles = 0x3CC;

	uintptr_t m_nModelIndex = 0x4C;
	uintptr_t m_localOrigin = 0x40;

	uintptr_t m_scriptNameIndex = 0x5C0;
	uintptr_t m_instanceNameIndex = 0x5C4;

} 

namespace convar
{
	uintptr_t idx_FindVar = 16;
}

namespace engine
{
	uintptr_t m_vecOrigin = 0x490;

	uintptr_t idx_ServerCnd = 26;
	uintptr_t idx_ClientCmd = 27;
	uintptr_t idx_GetPlayerInfo = 28;
	uintptr_t idx_GetLocalPlayer = 41;
	uintptr_t idx_IsInGame = 200;
	uintptr_t idx_IsConnected = 201;
	uintptr_t idx_ClientCmd_Unrestricted = 272;
}

namespace cinput
{
	uintptr_t idx_CreateMove = 4;
	uintptr_t idx_KeyEvent = 16;
	uintptr_t idx_GetUserCmd = 9;
	uintptr_t idx_WriteUserCmdDeltaToBuffer = 6;
	uintptr_t idx_EncodeUserCmdToBuffer = 7;
	uintptr_t idx_DecodeUserCmdFromBuffer = 8;
}

namespace clientmode
{
	uintptr_t idx_KeyInput = 16;
	uintptr_t idx_CreateMove = 19; // 1 param added
	uintptr_t idx_LevelInit = 20;
}

namespace chlclient
{
	uintptr_t idx_CreateMove = 25;
	uintptr_t idx_GetAllClasses = 11;
	uintptr_t idx_HudUpdate = 14;
}

namespace clientrenderable
{
	uintptr_t idx_GetRenderOrigin = 1;
	uintptr_t idx_GetRenderAngles = 2;
	uintptr_t idx_GetPlayerModel = 8;
	uintptr_t idx_SetupBones = 13;
}

namespace prediction
{
	uintptr_t idx_Update = 4;
	uintptr_t idx_PostNetworkDataReceived = 7;
	uintptr_t idx_RunCommand = 25; // 1 param added 
	uintptr_t idx_SetIdealPitch = 27;
	uintptr_t idx_CheckError = 28;
	uintptr_t idx__Update = 29;
}

namespace enginetrace
{
	uintptr_t idx_ClipRayToEntity = 1;
	uintptr_t idx_ClipRayToCollideable = 2;
	uintptr_t idx_TraceRay = 4;
}

namespace viewrender
{
	uintptr_t idx_GetWorldToScreenMatrix = 14;
}