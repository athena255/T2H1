//***********************************************
// File: CBreakableSurface.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBreakableSurface
	{
	public:
		uint64_t	DT_BreakableSurface; // 0x0
		unsigned char _0x8[0xb38];
		int    	m_nNumWide; // 0xb40
		int    	m_nNumHigh; // 0xb44
		float  	m_flPanelWidth; // 0xb48
		float  	m_flPanelHeight; // 0xb4c
		vector3	m_vNormal; // 0xb50
		vector3	m_vUp; // 0xb5c
		unsigned char _0xb68[0xc];
		vector3	m_vCorner; // 0xb74
		int    	m_bIsBroken; // 0xb80
		int    	m_nSurfaceType; // 0xb84
		unsigned char _0xb88[0x38];
		uint64_t	m_RawPanelBitVec; // 0xbc0
	};
#pragma pack(pop)
