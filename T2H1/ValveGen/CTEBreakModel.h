//***********************************************
// File: CTEBreakModel.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEBreakModel
	{
	public:
		uint64_t	DT_TEBreakModel; // 0x0
		unsigned char _0x8[0x20];
		vector3	m_vecOrigin; // 0x28
		float  	m_angRotation_0; // 0x34
		float  	m_angRotation_1; // 0x38
		float  	m_angRotation_2; // 0x3c
		vector3	m_vecSize; // 0x40
		vector3	m_vecVelocity; // 0x4c
		int    	m_nRandomization; // 0x58
		int    	m_nModelIndex; // 0x5c
		int    	m_nCount; // 0x60
		float  	m_fTime; // 0x64
		int    	m_nFlags; // 0x68
	};
#pragma pack(pop)
