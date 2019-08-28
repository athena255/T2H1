//***********************************************
// File: CWorld.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CWorld
	{
	public:
		uint64_t	DT_World; // 0x0
		unsigned char _0x8[0xb30];
		vector3	m_WorldMins; // 0xb38
		vector3	m_WorldMaxs; // 0xb44
		int    	m_bStartDark; // 0xb50
		unsigned char _0xb54[0x10];
		int    	m_statusEffectsGenerationNV; // 0xb64
		unsigned char _0xb68[0x4];
		int    	m_worldFlags; // 0xb6c
		int    	m_timeshiftArmDeviceSkin; // 0xb70
		int    	m_spTitanLoadoutUnlocks; // 0xb74
	};
#pragma pack(pop)
