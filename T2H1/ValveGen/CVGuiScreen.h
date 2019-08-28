//***********************************************
// File: CVGuiScreen.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CVGuiScreen
	{
	public:
		uint64_t	DT_VGuiScreen; // 0x0
		unsigned char _0x8[0xb30];
		float  	m_flWidth; // 0xb38
		float  	m_flHeight; // 0xb3c
		unsigned char _0xb40[0x8];
		int    	m_nPanelName; // 0xb48
		unsigned char _0xb4c[0x18];
		int    	m_nAttachmentIndex; // 0xb64
		int    	m_nOverlayMaterial; // 0xb68
		int    	m_fScreenFlags; // 0xb6c
		unsigned char _0xb70[0x68];
		int    	m_hPlayerOwner; // 0xbd8
	};
#pragma pack(pop)
