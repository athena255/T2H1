//***********************************************
// File: CTEPhysicsProp.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEPhysicsProp
	{
	public:
		uint64_t	DT_TEPhysicsProp; // 0x0
		unsigned char _0x8[0x20];
		vector3	m_vecOrigin; // 0x28
		float  	m_angRotation_0; // 0x34
		float  	m_angRotation_1; // 0x38
		float  	m_angRotation_2; // 0x3c
		vector3	m_vecVelocity; // 0x40
		int    	m_nModelIndex; // 0x4c
		int    	m_nSkin; // 0x50
		int    	m_nFlags; // 0x54
		int    	m_nEffects; // 0x58
	};
#pragma pack(pop)
