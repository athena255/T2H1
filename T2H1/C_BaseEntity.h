#pragma once
#include "Offsets.h"
#include "hook.h"
#include "C_Vec.h"
#include "ValveGen/CBaseEntity.h"

class C_BaseEntity : CBaseEntity
{
public:
	inline int m_iHealth()
	{
		return *(int*)((uintptr_t)this + offsets::m_iHealth);
	}

	inline int m_iMaxHealth()
	{
		return *(int*)((uintptr_t)this + offsets::m_iMaxHealth);
	}

	inline int m_shieldHealth()
	{
		return *(int*)((uintptr_t)this + offsets::m_sheildHealth);
	}

	inline int m_shieldHealthMax()
	{
		return *(int*)((uintptr_t)this + offsets::m_shieldHealthMax);
	}

	
	inline int m_iLifeState()
	{
		return *(int*)((uintptr_t)this + offsets::m_lifeState);
	}

	inline int m_iindex()
	{
		return *(int*)((uintptr_t)this + 0x8); // not sure
	}

	inline int m_iTeamNum()
	{
		return *(int*)((uintptr_t)this + offsets::m_iTeamNum);
	}

	inline const char* m_sname()
	{
		return GetName((uintptr_t)this);
	}

	inline c_vec m_vecOrigin()
	{
		return *(c_vec*)((uintptr_t)this + offsets::m_vecOrigin); // not sure
	}

	inline char* m_shandle()
	{
		return *(char**)((uintptr_t)this + offsets::m_iSignifierName);
	}

};

class C_BaseCombatWeapon : C_BaseEntity
{

};

class C_BasePlayer : C_BaseEntity
{

};