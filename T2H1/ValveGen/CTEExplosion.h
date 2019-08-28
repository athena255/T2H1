//***********************************************
// File: CTEExplosion.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEExplosion
	{
	public:
		uint64_t	DT_TEExplosion; // 0x0
		unsigned char _0x8[0x30];
		float  	m_fScale; // 0x38
		int    	m_nFrameRate; // 0x3c
		int    	m_nFlags; // 0x40
		vector3	m_vecNormal; // 0x44
		int    	m_chMaterialType; // 0x50
		int    	m_nRadius; // 0x54
		int    	m_nInnerRadius; // 0x58
		int    	m_nMagnitude; // 0x5c
		int    	m_impactEffectTableIndex; // 0x60
		int    	m_surfaceProp; // 0x64
		int    	m_owner; // 0x68
		int    	m_victim; // 0x6c
	};
#pragma pack(pop)
