//***********************************************
// File: CFirstPersonProxy.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CFirstPersonProxy
	{
	public:
		uint64_t	DT_FirstPersonProxy; // 0x0
		unsigned char _0x8[0xf80];
		int    	m_camoIndex; // 0xf88
		unsigned char _0xf8c[0x2a4];
		int    	m_viewModelOwner; // 0x1230
	};
#pragma pack(pop)
