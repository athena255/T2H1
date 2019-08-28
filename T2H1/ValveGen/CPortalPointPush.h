//***********************************************
// File: CPortalPointPush.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPortalPointPush
	{
	public:
		uint64_t	DT_PortalPointPush; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_bEnabled; // 0xb38
		float  	m_flMagnitude; // 0xb3c
		float  	m_flRadius; // 0xb40
		float  	m_flInnerRadius; // 0xb44
		float  	m_flConeOfInfluence; // 0xb48
	};
#pragma pack(pop)
