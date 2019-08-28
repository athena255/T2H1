//***********************************************
// File: CBaseToggle.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseToggle
	{
	public:
		uint64_t	DT_BaseToggle; // 0x0
		unsigned char _0x8[0xb44];
		vector3	m_vecFinalDest; // 0xb4c
		int    	m_movementType; // 0xb58
		float  	m_flMoveTargetTime; // 0xb5c
	};
#pragma pack(pop)
