//***********************************************
// File: CTEShatterSurface.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEShatterSurface
	{
	public:
		uint64_t	DT_TEShatterSurface; // 0x0
		unsigned char _0x8[0x20];
		vector3	m_vecOrigin; // 0x28
		vector3	m_vecAngles; // 0x34
		vector3	m_vecForce; // 0x40
		vector3	m_vecForcePos; // 0x4c
		float  	m_flWidth; // 0x58
		float  	m_flHeight; // 0x5c
		float  	m_flShardSize; // 0x60
		unsigned char _0x64[0xc];
		int    	m_nSurfaceType; // 0x70
	};
#pragma pack(pop)
