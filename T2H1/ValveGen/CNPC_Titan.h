//***********************************************
// File: CNPC_Titan.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CNPC_Titan
	{
	public:
		uint64_t	DT_NPC_Titan; // 0x0
		unsigned char _0x8[0xf80];
		int    	m_camoIndex; // 0xf88
		int    	m_decalIndex; // 0xf8c
		unsigned char _0xf90[0x5a8];
		uint64_t	m_inventory; // 0x1538
		unsigned char _0x1540[0x5c];
		int    	m_selectedOffhand; // 0x159c
		unsigned char _0x15a0[0x30];
		int    	m_titanSoul; // 0x15d0
		unsigned char _0x15d4[0x23c];
		int    	m_grappleHook; // 0x1810
		unsigned char _0x1814[0x4];
		uint64_t	m_grapple; // 0x1818
		unsigned char _0x1820[0x60];
		int    	m_grappleActive; // 0x1880
		int    	m_canStand; // 0x1881
	};
#pragma pack(pop)
