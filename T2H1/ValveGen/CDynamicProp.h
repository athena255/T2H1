//***********************************************
// File: CDynamicProp.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CDynamicProp
	{
	public:
		uint64_t	DT_DynamicProp; // 0x0
		unsigned char _0x8[0x39c];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x320];
		int    	m_lifeState; // 0x6c8
		unsigned char _0x6cc[0x261];
		int    	m_physDummyMotionEnabled; // 0x92d
		unsigned char _0x931[0x908];
		int    	m_bUseHitboxesForRenderBox; // 0x1239
	};
#pragma pack(pop)
