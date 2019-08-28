//***********************************************
// File: CTEGibEvent.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEGibEvent
	{
	public:
		unsigned char _0x0[0x28];
		int    	m_hVictim; // 0x28
		vector3	m_attackDir; // 0x2c
	};
#pragma pack(pop)
