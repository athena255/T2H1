//***********************************************
// File: CNPC_Dropship.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CNPC_Dropship
	{
	public:
		uint64_t	DT_NPC_Dropship; // 0x0
		unsigned char _0x8[0x15c8];
		int    	m_titanSoul; // 0x15d0
		unsigned char _0x15d4[0x254];
		int    	m_bJetWakeFXEnabled; // 0x1828
	};
#pragma pack(pop)
