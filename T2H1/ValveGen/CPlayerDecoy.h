//***********************************************
// File: CPlayerDecoy.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPlayerDecoy
	{
	public:
		uint64_t	DT_PlayerDecoy; // 0x0
		unsigned char _0x8[0x174];
		float  	m_cloakEndTime; // 0x17c
		float  	m_cloakFadeInEndTime; // 0x180
		float  	m_cloakFadeOutStartTime; // 0x184
		float  	m_cloakFadeInDuration; // 0x188
		float  	m_cloakFlickerAmount; // 0x18c
		float  	m_cloakFlickerEndTime; // 0x190
		unsigned char _0x194[0x1fc];
		int    	m_iHealth; // 0x390
		unsigned char _0x394[0x114];
		int    	m_iMaxHealth; // 0x4a8
		unsigned char _0x4ac[0x3fc];
		int    	m_nameVisibilityFlags; // 0x8a8
		unsigned char _0x8ac[0x6dc];
		int    	m_camoIndex; // 0xf88
		unsigned char _0xf8c[0x2a4];
		int    	m_currentState; // 0x1230
		int    	m_decoyFlags; // 0x1234
		unsigned char _0x1238[0x4];
		float  	m_lastPulseTime; // 0x123c
	};
#pragma pack(pop)
