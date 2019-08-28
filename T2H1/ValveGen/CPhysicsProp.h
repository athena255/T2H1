//***********************************************
// File: CPhysicsProp.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPhysicsProp
	{
	public:
		uint64_t	DT_PhysicsProp; // 0x0
		unsigned char _0x8[0x73c];
		int    	m_spawnflags; // 0x744
		unsigned char _0x748[0xaf8];
		int    	m_bAwake; // 0x1240
		unsigned char _0x1244[0x18];
		int    	m_iPhysicsMode; // 0x125c
		float  	m_fMass; // 0x1260
		vector3	m_collisionMins; // 0x1264
		vector3	m_collisionMaxs; // 0x1270
	};
#pragma pack(pop)
