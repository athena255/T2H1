//***********************************************
// File: CBaseTrigger.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseTrigger
	{
	public:
		uint64_t	DT_BaseTrigger; // 0x0
		unsigned char _0x8[0x73c];
		int    	m_spawnflags; // 0x744
		unsigned char _0x748[0x420];
		int    	m_bClientSidePredicted; // 0xb68
	};
#pragma pack(pop)
