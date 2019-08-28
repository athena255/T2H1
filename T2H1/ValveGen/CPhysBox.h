//***********************************************
// File: CPhysBox.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPhysBox
	{
	public:
		uint64_t	DT_PhysBox; // 0x0
		unsigned char _0x8[0xb30];
		float  	m_mass; // 0xb38
	};
#pragma pack(pop)
