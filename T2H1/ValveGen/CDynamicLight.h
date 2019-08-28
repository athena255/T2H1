//***********************************************
// File: CDynamicLight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CDynamicLight
	{
	public:
		uint64_t	DT_DynamicLight; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_Flags; // 0xb38
		int    	m_LightStyle; // 0xb39
		float  	m_Radius; // 0xb3c
		int    	m_Exponent; // 0xb40
		float  	m_InnerAngle; // 0xb44
		float  	m_OuterAngle; // 0xb48
		float  	m_SpotRadius; // 0xb4c
	};
#pragma pack(pop)
