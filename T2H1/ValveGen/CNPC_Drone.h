//***********************************************
// File: CNPC_Drone.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CNPC_Drone
	{
	public:
		uint64_t	DT_NPC_Drone; // 0x0
		unsigned char _0x8[0x1808];
		int    	m_bAttackTarget; // 0x1810
		int    	m_scanTarget; // 0x1814
		float  	m_beamSpread; // 0x1818
	};
#pragma pack(pop)
