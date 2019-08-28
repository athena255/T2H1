//***********************************************
// File: CHardPointEntity.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CHardPointEntity
	{
	public:
		unsigned char _0x0[0x4];
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0x394];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x4e0];
		uint64_t	m_minimapData; // 0x888
		unsigned char _0x890[0x2ac];
		int    	m_state; // 0xb3c
		float  	m_estimatedCaptureTime; // 0xb40
		float  	m_progressRefPoint; // 0xb44
		int    	m_teamMilitiaAICount; // 0xb48
		int    	m_teamIMCAICount; // 0xb4c
		int    	m_teamMilitiaPlayerCount; // 0xb50
		int    	m_teamIMCPlayerCount; // 0xb54
		int    	m_teamMilitiaPlayerTitanCount; // 0xb58
		int    	m_teamIMCPlayerTitanCount; // 0xb5c
		int    	m_hardpointID; // 0xb60
		unsigned char _0xb64[0x4];
		int    	m_terminal; // 0xb68
	};
#pragma pack(pop)
