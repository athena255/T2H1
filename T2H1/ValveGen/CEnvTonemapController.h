//***********************************************
// File: CEnvTonemapController.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CEnvTonemapController
	{
	public:
		uint64_t	DT_EnvTonemapController; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_bUseCustomAutoExposureMin; // 0xb38
		int    	m_bUseCustomAutoExposureMax; // 0xb39
		int    	m_bUseCustomAutoExposureRate; // 0xb3a
		int    	m_bUseCustomBloomScale; // 0xb3b
		float  	m_flCustomAutoExposureMin; // 0xb3c
		float  	m_flCustomAutoExposureMax; // 0xb40
		float  	m_flCustomAutoExposureRate; // 0xb44
		float  	m_flCustomBloomScale; // 0xb48
	};
#pragma pack(pop)
