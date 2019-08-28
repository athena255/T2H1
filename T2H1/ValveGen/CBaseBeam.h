//***********************************************
// File: CBaseBeam.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseBeam
	{
	public:
		unsigned char _0x0[0x28];
		int    	m_nModelIndex; // 0x28
		int    	m_nHaloIndex; // 0x2c
		int    	m_nStartFrame; // 0x30
		int    	m_nFrameRate; // 0x34
		float  	m_fLife; // 0x38
		float  	m_fWidth; // 0x3c
		float  	m_fEndWidth; // 0x40
		int    	m_nFadeLength; // 0x44
		float  	m_fAmplitude; // 0x48
		int    	r; // 0x4c
		int    	g; // 0x50
		int    	b; // 0x54
		int    	a; // 0x58
		int    	m_nSpeed; // 0x5c
		int    	m_nFlags; // 0x60
	};
#pragma pack(pop)
