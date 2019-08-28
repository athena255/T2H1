//***********************************************
// File: CBeamSpotlight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBeamSpotlight
	{
	public:
		uint64_t	DT_BeamSpotlight; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_nHaloIndex; // 0xb38
		int    	m_bSpotlightOn; // 0xb3c
		int    	m_bHasDynamicLight; // 0xb3d
		float  	m_flSpotlightMaxLength; // 0xb40
		float  	m_flSpotlightGoalWidth; // 0xb44
		float  	m_flHDRColorScale; // 0xb48
		unsigned char _0xb4c[0x4];
		int    	m_nRotationAxis; // 0xb50
		float  	m_flRotationSpeed; // 0xb54
	};
#pragma pack(pop)
