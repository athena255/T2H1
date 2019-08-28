//***********************************************
// File: CBaseCombatWeapon.h
//***********************************************

#pragma once
#include "../stdafx.h"

#pragma pack(push,1)
	class CBaseCombatWeapon
	{
	public:
		uint64_t	DT_BaseCombatWeapon; // 0x0
		unsigned char _0x8[0x122c];
		int    	m_weaponOwner; // 0x1234
		unsigned char _0x1238[0x8];
		int    	m_iWorldModelIndex; // 0x1240
		int    	m_holsterModelIndex; // 0x1244
		int    	m_droppedModelIndex; // 0x1248
		int    	m_ActiveState; // 0x124c
		unsigned char _0x1250[0x1c];
		int    	m_weaponActivity; // 0x126c
		unsigned char _0x1270[0x4];
		int    	m_nIdealSequence; // 0x1274
		int    	m_IdealActivity; // 0x1278
	};
#pragma pack(pop)
