//***********************************************
// File: CEntityDissolve.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CEntityDissolve
	{
	public:
		uint64_t	DT_EntityDissolve; // 0x0
		unsigned char _0x8[0xb38];
		float  	m_flStartTime; // 0xb40
		float  	m_flFadeOutStart; // 0xb44
		float  	m_flFadeOutLength; // 0xb48
		float  	m_flFadeOutModelStart; // 0xb4c
		float  	m_flFadeOutModelLength; // 0xb50
		float  	m_flFadeInStart; // 0xb54
		float  	m_flFadeInLength; // 0xb58
		int    	m_nDissolveType; // 0xb5c
		unsigned char _0xb60[0x4];
		int    	fadeColorR; // 0xb64
		int    	fadeColorG; // 0xb68
		int    	fadeColorB; // 0xb6c
		int    	m_isLethal; // 0xb70
		vector3	m_vDissolverOrigin; // 0xb74
		int    	m_nMagnitude; // 0xb80
	};
#pragma pack(pop)
