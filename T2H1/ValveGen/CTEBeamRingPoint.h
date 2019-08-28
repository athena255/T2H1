//***********************************************
// File: CTEBeamRingPoint.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBeamRingPoint
	{
	public:
		uint64_t	DT_TEBeamRingPoint; // 0x0
		unsigned char _0x8[0x60];
		vector3	m_vecCenter; // 0x68
		float  	m_flStartRadius; // 0x74
		float  	m_flEndRadius; // 0x78
	};
#pragma pack(pop)
