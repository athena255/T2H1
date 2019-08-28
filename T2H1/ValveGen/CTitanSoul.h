//***********************************************
// File: CTitanSoul.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTitanSoul
	{
	public:
		uint64_t	statuseffectsdata_soul; // 0x0
		unsigned char _0x8[0xfc];
		int    	m_bossPlayer; // 0x104
		unsigned char _0x108[0x48];
		int    	m_shieldHealth; // 0x150
		int    	m_shieldHealthMax; // 0x154
		unsigned char _0x158[0x1f8];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x7e4];
		int    	m_titan; // 0xb38
		unsigned char _0xb3c[0x4];
		int    	m_titanSoulScriptNetData; // 0xb40
		unsigned char _0xb44[0x194];
		float  	m_lastRodeoHitTime; // 0xcd8
		unsigned char _0xcdc[0x4];
		float  	m_nextCoreChargeAvailable; // 0xce0
		unsigned char _0xce4[0x4];
		float  	m_coreChargeExpireTime; // 0xce8
		unsigned char _0xcec[0x4];
		float  	m_coreChargeStartTime; // 0xcf0
		float  	m_coreUseDuration; // 0xcf4
		float  	m_damageComboLatestUpdateTime; // 0xcf8
		int    	m_damageComboStartHealth; // 0xcfc
		unsigned char _0xd00[0x198];
		int    	m_stance; // 0xe98
		int    	m_doomed; // 0xe9c
		int    	m_playerSettingsNum; // 0xea0
		int    	m_invalidHealthBarEnt; // 0xea4
		int    	m_bEjecting; // 0xea5
		int    	m_isValidRodeoTarget; // 0xea6
	};
#pragma pack(pop)
