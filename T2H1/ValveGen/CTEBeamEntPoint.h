//***********************************************
// File: CTEBeamEntPoint.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBeamEntPoint
	{
	public:
		uint64_t	DT_TEBeamEntPoint; // 0x0
		unsigned char _0x8[0x60];
		int    	m_nStartEntity; // 0x68
		int    	m_nEndEntity; // 0x6c
		vector3	m_vecStartPoint; // 0x70
		vector3	m_vecEndPoint; // 0x7c
	};
#pragma pack(pop)
