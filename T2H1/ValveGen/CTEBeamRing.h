//***********************************************
// File: CTEBeamRing.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBeamRing
	{
	public:
		uint64_t	DT_TEBeamRing; // 0x0
		unsigned char _0x8[0x60];
		int    	m_nStartEntity; // 0x68
		int    	m_nEndEntity; // 0x6c
	};
#pragma pack(pop)
