//***********************************************
// File: CWeaponX.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CWeaponX
	{
	public:
		uint64_t	DT_WeaponX; // 0x0
		unsigned char _0x8[0x348];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0xc34];
		int    	m_camoIndex; // 0xf88
		unsigned char _0xf8c[0x184];
		int    	m_bClientSideAnimation; // 0x1110
		unsigned char _0x1114[0x1a4];
		int    	m_weapState; // 0x12b8
		int    	m_allowedToUse; // 0x12bc
		int    	m_discarded; // 0x12bd
		int    	m_forcedADS; // 0x12c0
		int    	m_forceRelease; // 0x12c4
		int    	m_customActivity; // 0x12c8
		int    	m_customActivitySequence; // 0x12cc
		int    	m_customActivityOwner; // 0x12d0
		float  	m_customActivityEndTime; // 0x12d4
		uint64_t	m_playerData; // 0x12d8
		unsigned char _0x12e0[0xa0];
		int    	m_smartAmmoEnable; // 0x1380
		unsigned char _0x1384[0x4];
		uint64_t	m_smartAmmo; // 0x1388
		unsigned char _0x1390[0x1e8];
		int    	m_needsReloadCheck; // 0x1578
		int    	m_needsCooldown; // 0x1579
		int    	m_needsEmptyCycleCheck; // 0x157a
		int    	m_skinOverride; // 0x157c
		int    	m_skinOverrideIsValid; // 0x1580
		float  	m_chargeStartTime; // 0x1584
		unsigned char _0x1588[0x24];
		float  	m_sustainedDischargeEndTime; // 0x15ac
		int    	m_modBitfieldFromPlayer; // 0x15b0
		int    	m_modBitfieldInternal; // 0x15b4
		int    	m_modBitfieldCurrent; // 0x15b8
		int    	m_curSharedEnergyCost; // 0x15bc
		int    	m_scriptActivated; // 0x15c0
		int    	m_isLoadoutPickup; // 0x15c1
		int    	m_utilityEnt; // 0x15c4
		int    	m_weaponNameIndex; // 0x15c8
	};
#pragma pack(pop)
