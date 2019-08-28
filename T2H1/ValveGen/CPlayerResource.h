//***********************************************
// File: CPlayerResource.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPlayerResource
	{
	public:
		unsigned char _0x0[0xdc4];
		uint64_t	m_boolStats; // 0xdc4
		unsigned char _0xdcc[0x7c];
		uint64_t	m_killStats; // 0xe48
		unsigned char _0xe50[0x310];
		uint64_t	m_scoreStats; // 0x1160
		unsigned char _0x1168[0x28c];
		uint64_t	m_iPing; // 0x13f4
		unsigned char _0x13fc[0x7c];
		uint64_t	m_iTeam; // 0x1478
		unsigned char _0x1480[0x7c];
		uint64_t	m_iPRHealth; // 0x14fc
		unsigned char _0x1504[0x7c];
		uint64_t	m_bConnected; // 0x1580
		unsigned char _0x1588[0x7c];
		uint64_t	m_bAlive; // 0x1604
	};
#pragma pack(pop)
