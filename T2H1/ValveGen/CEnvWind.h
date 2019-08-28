//***********************************************
// File: CEnvWind.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CEnvWind
	{
	public:
		uint64_t	DT_EnvWind; // 0x0
		unsigned char _0x8[0xb30];
		uint64_t	m_EnvWindShared; // 0xb38
	};
#pragma pack(pop)
