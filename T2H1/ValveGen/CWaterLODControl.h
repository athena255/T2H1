//***********************************************
// File: CWaterLODControl.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CWaterLODControl
	{
	public:
		uint64_t	DT_WaterLODControl; // 0x0
		unsigned char _0x8[0xb30];
		float  	m_flCheapWaterStartDistance; // 0xb38
		float  	m_flCheapWaterEndDistance; // 0xb3c
	};
#pragma pack(pop)
