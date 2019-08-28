//***********************************************
// File: CBaseCombatCharacter.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseCombatCharacter
	{
	public:
		uint64_t	DT_BaseCombatCharacter; // 0x0
		int    	m_weaponGettingSwitchedOut; // 0x8
		int    	m_showNewWeapon3p; // 0xc
		uint64_t	m_rodeoRiders; // 0x10
		unsigned char _0x18[0xc];
		float  	m_vecViewOffset_0; // 0x24
		float  	m_vecViewOffset_1; // 0x28
		float  	m_vecViewOffset_2; // 0x2c
		unsigned char _0x30[0x14c];
		float  	m_cloakEndTime; // 0x17c
		float  	m_cloakFadeInEndTime; // 0x180
		float  	m_cloakFadeOutStartTime; // 0x184
		float  	m_cloakFadeInDuration; // 0x188
		float  	m_cloakFlickerAmount; // 0x18c
		float  	m_cloakFlickerEndTime; // 0x190
		unsigned char _0x194[0x1bc];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x60];
		vector3	m_deathVelocity; // 0x3b4
		unsigned char _0x3c0[0x4c8];
		uint64_t	m_minimapData; // 0x888
		unsigned char _0x890[0x18];
		int    	m_nameVisibilityFlags; // 0x8a8
		unsigned char _0x8ac[0xc68];
		float  	m_lastFiredTime; // 0x1514
		float  	m_raiseFromMeleeEndTime; // 0x1518
		int    	m_sharedEnergyCount; // 0x151c
		int    	m_sharedEnergyTotal; // 0x1520
		float  	m_lastSharedEnergyRegenTime; // 0x1524
		float  	m_sharedEnergyRegenRate; // 0x1528
		float  	m_sharedEnergyRegenDelay; // 0x152c
		float  	m_lastSharedEnergyTakeTime; // 0x1530
		unsigned char _0x1534[0x3c];
		int    	m_selectedWeapon; // 0x1570
		int    	m_latestPrimaryWeapon; // 0x1574
		int    	m_latestNonOffhandWeapon; // 0x1578
		int    	m_lastCycleSlot; // 0x157c
		int    	m_weaponPermission; // 0x1580
		unsigned char _0x1584[0x21];
		int    	m_weaponDisabled; // 0x15a5
		int    	m_hudInfo_visibilityTestAlwaysPasses; // 0x15a6
		unsigned char _0x15aa[0xa];
		int    	m_contextAction; // 0x15b4
		unsigned char _0x15b8[0x1c];
		vector3	m_meleeExecutionUnstuckPosition; // 0x15d4
		unsigned char _0x15e0[0x4];
		float  	m_phaseShiftTimeStart; // 0x15e4
		float  	m_phaseShiftTimeEnd; // 0x15e8
		unsigned char _0x15ec[0x48];
		char*  	m_targetInfoIconName; // 0x1634
	};
#pragma pack(pop)
