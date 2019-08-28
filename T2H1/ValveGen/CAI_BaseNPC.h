//***********************************************
// File: CAI_BaseNPC.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CAI_BaseNPC
	{
	public:
		uint64_t	DT_AI_BaseNPC; // 0x0
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0x37c];
		int    	m_hGroundEntity; // 0x38c
		int    	m_iHealth; // 0x390
		unsigned char _0x394[0x38];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0xd0];
		int    	m_iMaxHealth; // 0x4a8
		unsigned char _0x4ac[0x21c];
		int    	m_lifeState; // 0x6c8
		unsigned char _0x6cc[0xe6c];
		uint64_t	m_inventory; // 0x1538
		unsigned char _0x1540[0x158];
		int    	m_fireteamSlotIndex; // 0x1698
		unsigned char _0x169c[0x11e];
		int    	m_aiSprinting; // 0x17ba
		unsigned char _0x17be[0x1e];
		int    	m_aiNetworkFlags; // 0x17dc
		int    	m_isHologram; // 0x17e0
		char*  	m_title; // 0x17e1
		unsigned char _0x17e9[0x1b];
		int    	m_aiSettingsIndex; // 0x1804
		int    	m_subclass; // 0x1808
	};
#pragma pack(pop)
