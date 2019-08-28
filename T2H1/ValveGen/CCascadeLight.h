//***********************************************
// File: CCascadeLight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CCascadeLight
	{
	public:
		uint64_t	DT_CascadeLight; // 0x0
		unsigned char _0x8[0xb30];
		vector3	m_shadowDirection; // 0xb38
		unsigned char _0xb44[0xc];
		vector3	m_envLightShadowDirection; // 0xb50
		unsigned char _0xb5c[0x8];
		int    	m_bEnabled; // 0xb64
		int    	m_bEnableShadows; // 0xb65
		int    	m_LightColor; // 0xb67
		char*  	m_cloudMaskName; // 0xb6b
		unsigned char _0xb73[0xfd];
		vector3	m_cloudOffset; // 0xc70
		float  	m_cloudScale; // 0xc7c
	};
#pragma pack(pop)
