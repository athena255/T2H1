//***********************************************
// File: CPostProcessController.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPostProcessController
	{
	public:
		uint64_t	DT_PostProcessController; // 0x0
		unsigned char _0x8[0xb30];
		uint64_t	m_flPostProcessParameters; // 0xb38
		unsigned char _0xb40[0x10];
		int    	m_bMaster; // 0xb50
	};
#pragma pack(pop)
