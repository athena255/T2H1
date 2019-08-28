//***********************************************
// File: CSprite.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CSprite
	{
	public:
		uint64_t	DT_Sprite; // 0x0
		unsigned char _0x8[0x39c];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x7a8];
		int    	m_hAttachedToEntity; // 0xb50
		int    	m_nAttachment; // 0xb54
		float  	m_flSpriteFramerate; // 0xb58
		float  	m_flFrame; // 0xb5c
		unsigned char _0xb60[0x4];
		int    	m_clrRenderFriendly; // 0xb64
		int    	m_nBrightness; // 0xb68
		float  	m_flBrightnessDuration; // 0xb6c
		float  	m_flSpriteScale; // 0xb70
		float  	m_flScaleDuration; // 0xb74
		int    	m_bWorldSpaceScale; // 0xb78
		float  	m_flGlowProxySize; // 0xb7c
		float  	m_flHDRColorScale; // 0xb80
	};
#pragma pack(pop)
