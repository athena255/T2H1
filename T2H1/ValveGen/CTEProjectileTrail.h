//***********************************************
// File: CTEProjectileTrail.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEProjectileTrail
	{
	public:
		uint64_t	DT_TEProjectileTrail; // 0x0
		unsigned char _0x8[0x20];
		int    	m_owner; // 0x28
		vector3	m_startPos; // 0x2c
		vector3	m_endPos; // 0x38
		int    	m_weaponClassIndex; // 0x44
		int    	m_modBitfield; // 0x48
		int    	m_overrideMods; // 0x4c
		int    	m_projectileTrailIndex; // 0x50
	};
#pragma pack(pop)
