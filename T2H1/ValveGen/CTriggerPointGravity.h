//***********************************************
// File: CTriggerPointGravity.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTriggerPointGravity
	{
	public:
		uint64_t	DT_TriggerPointGravity; // 0x0
		unsigned char _0x8[0xb68];
		float  	m_pullOuterRadius; // 0xb70
		float  	m_pullInnerRadius; // 0xb74
		float  	m_reduceSpeedOuterRadius; // 0xb78
		float  	m_reduceSpeedInnerRadius; // 0xb7c
		float  	m_pullAccel; // 0xb80
		float  	m_pullSpeed; // 0xb84
	};
#pragma pack(pop)
