//***********************************************
// File: CTeam.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTeam
	{
	public:
		int    	player_array_element; // 0x0
		unsigned char _0x4[0xb34];
		int    	m_score; // 0xb38
		int    	m_score2; // 0xb3c
		int    	m_kills; // 0xb40
		int    	m_deaths; // 0xb44
		int    	m_iRoundsWon; // 0xb48
		int    	m_iTeamTeamNum; // 0xb4c
		unsigned char _0xb50[0x20];
		char*  	m_szTeamname; // 0xb70
		unsigned char _0xb78[0xf8];
		int    	m_reservedPlayerCount; // 0xc70
		int    	m_connectingPlayerCount; // 0xc74
		int    	m_loadingPlayerCount; // 0xc78
	};
#pragma pack(pop)
