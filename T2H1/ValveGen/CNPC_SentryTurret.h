//***********************************************
// File: CNPC_SentryTurret.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CNPC_SentryTurret
	{
	public:
		uint64_t	DT_NPC_SentryTurret; // 0x0
		unsigned char _0x8[0x1808];
		int    	m_turretState; // 0x1810
		int    	m_killCount; // 0x1814
		int    	m_titanKillCount; // 0x1818
		int    	m_eyeAttach; // 0x181c
		int    	m_controlPanel; // 0x1820
	};
#pragma pack(pop)
