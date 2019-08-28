//***********************************************
// File: CBoneFollower.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBoneFollower
	{
	public:
		unsigned char _0x0[0x34];
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0x37c];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x14];
		uint64_t	m_Collision; // 0x3f8
		unsigned char _0x400[0x438];
		int    	m_CollisionGroup; // 0x838
		unsigned char _0x83c[0x2fc];
		int    	m_modelIndex; // 0xb38
		int    	m_boneIndex; // 0xb3c
	};
#pragma pack(pop)
