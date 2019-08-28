//***********************************************
// File: CPointCamera.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPointCamera
	{
	public:
		uint64_t	DT_PointCamera; // 0x0
		unsigned char _0x8[0xb90];
		float  	m_FOV; // 0xb98
		unsigned char _0xb9c[0x24];
		int    	m_bFogEnable; // 0xbc0
		int    	m_bActive; // 0xbc1
	};
#pragma pack(pop)
