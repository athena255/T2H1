//***********************************************
// File: CVortexSphere.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CVortexSphere
	{
	public:
		uint64_t	DT_VortexSphere; // 0x0
		unsigned char _0x8[0x388];
		int    	m_iHealth; // 0x390
		unsigned char _0x394[0x3b0];
		int    	m_spawnflags; // 0x744
		unsigned char _0x748[0x3f0];
		int    	m_enabled; // 0xb38
		float  	m_radius; // 0xb3c
		float  	m_height; // 0xb40
		float  	m_bulletFov; // 0xb44
		int    	m_bulletAbsorbedCount; // 0xb48
		int    	m_projectileAbsorbedCount; // 0xb4c
		int    	m_ownerWeapon; // 0xb50
		int    	m_vortexEffect; // 0xb54
		vector3	m_vortexGunAngles; // 0xb58
		unsigned char _0xb64[0x4];
		char*  	m_gunAttachment; // 0xb68
	};
#pragma pack(pop)
