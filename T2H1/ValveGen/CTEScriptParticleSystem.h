//***********************************************
// File: CTEScriptParticleSystem.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEScriptParticleSystem
	{
	public:
		uint64_t	DT_TEScriptParticleSystem; // 0x0
		unsigned char _0x8[0x20];
		int    	m_effectIndex; // 0x28
		vector3	m_origin; // 0x2c
		vector3	m_angles; // 0x38
		vector3	m_controlPoint1; // 0x44
	};
#pragma pack(pop)
