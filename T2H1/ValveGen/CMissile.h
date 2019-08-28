//***********************************************
// File: CMissile.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CMissile
	{
	public:
		uint64_t	DT_Missile; // 0x0
		unsigned char _0x8[0x2180];
		int    	m_hSpecificTarget; // 0x2188
		unsigned char _0x218c[0xc];
		vector3	m_targetPosition; // 0x2198
		int    	m_useTargetPosition; // 0x21a4
	};
#pragma pack(pop)
