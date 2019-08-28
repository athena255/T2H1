//***********************************************
// File: CTurret.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTurret
	{
	public:
		uint64_t	DT_Turret; // 0x0
		unsigned char _0x8[0x388];
		int    	m_iHealth; // 0x390
		unsigned char _0x394[0x114];
		int    	m_iMaxHealth; // 0x4a8
		unsigned char _0x4ac[0x108c];
		uint64_t	m_inventory; // 0x1538
		unsigned char _0x1540[0x160];
		int    	m_settingsIndex; // 0x16a0
		unsigned char _0x16a4[0x14];
		int    	m_driver; // 0x16b8
		unsigned char _0x16bc[0xc];
		float  	m_forceAimPitch; // 0x16c8
		float  	m_forceAimYaw; // 0x16cc
		float  	m_driverTimeStart; // 0x16d0
		char*  	m_title; // 0x16d4
	};
#pragma pack(pop)
