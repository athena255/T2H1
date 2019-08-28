//***********************************************
// File: CTEBeamSpline.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBeamSpline
	{
	public:
		bool   	m_vecPoints[1]; // 0x0
		unsigned char _0x0[0x28];
		vector3	m_vecPoints_0; // 0x28
		unsigned char _0x34[0xb4];
		int    	m_nPoints; // 0xe8
	};
#pragma pack(pop)
