//***********************************************
// File: CMovieDisplay.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CMovieDisplay
	{
	public:
		uint64_t	DT_MovieDisplay; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_bEnabled; // 0xb38
		int    	m_bLooping; // 0xb39
		char*  	m_szMovieFilename; // 0xb3a
		unsigned char _0xb42[0x78];
		char*  	m_szGroupName; // 0xbba
		unsigned char _0xbc2[0x78];
		int    	m_bStretchToFill; // 0xc3a
		int    	m_bForcedSlave; // 0xc3b
		int    	m_bUseCustomUVs; // 0xc3c
		float  	m_flUMin; // 0xc40
		float  	m_flUMax; // 0xc44
		float  	m_flVMin; // 0xc48
		float  	m_flVMax; // 0xc4c
	};
#pragma pack(pop)
