//***********************************************
// File: CColorCorrection.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CColorCorrection
	{
	public:
		uint64_t	DT_ColorCorrection; // 0x0
		unsigned char _0x8[0x3d8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x754];
		vector3	m_localOrigin; // 0xb38
		float  	m_MinFalloff; // 0xb44
		float  	m_MaxFalloff; // 0xb48
		float  	m_flFadeInDuration; // 0xb4c
		float  	m_flFadeOutDuration; // 0xb50
		float  	m_flMaxWeight; // 0xb54
		float  	m_flCurWeight; // 0xb58
		char*  	m_netLookupFilename; // 0xb5c
		unsigned char _0xb64[0xfc];
		int    	m_bEnabled; // 0xc60
		int    	m_bMaster; // 0xc61
		int    	m_bClientSide; // 0xc62
		int    	m_bExclusive; // 0xc63
	};
#pragma pack(pop)
