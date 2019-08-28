//***********************************************
// File: CTEBeamPoints.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBeamPoints
	{
	public:
		uint64_t	DT_TEBeamPoints; // 0x0
		unsigned char _0x8[0x60];
		vector3	m_vecStartPoint; // 0x68
		vector3	m_vecEndPoint; // 0x74
	};
#pragma pack(pop)
