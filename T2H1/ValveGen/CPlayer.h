//***********************************************
// File: CPlayer.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CPlayer
	{
	public:
		uint64_t	DT_Player; // 0x0
		vector3	m_vecAbsOrigin; // 0x4
		int    	isLocalOriginLocal; // 0x10
		unsigned char _0x14[0x78];
		int    	m_fFlags; // 0x8c
		unsigned char _0x90[0x2fc];
		int    	m_hGroundEntity; // 0x38c
		int    	m_iHealth; // 0x390
		float  	m_flMaxspeed; // 0x394
		unsigned char _0x398[0x110];
		int    	m_iMaxHealth; // 0x4a8
		unsigned char _0x4ac[0x21c];
		int    	m_lifeState; // 0x6c8
		unsigned char _0x6cc[0x8bc];
		int    	m_camoIndex; // 0xf88
		int    	m_decalIndex; // 0xf8c
		unsigned char _0xf90[0x5a8];
		uint64_t	m_inventory; // 0x1538
		unsigned char _0x1540[0x5c];
		int    	m_selectedOffhand; // 0x159c
		int    	m_selectedOffhandPendingHybridAction; // 0x15a0
		unsigned char _0x15a4[0x2c];
		int    	m_titanSoul; // 0x15d0
		unsigned char _0x15d4[0xc4];
		int    	m_bZooming; // 0x1698
		int    	m_zoomToggleOn; // 0x1699
		float  	m_zoomBaseFrac; // 0x169c
		float  	m_zoomBaseTime; // 0x16a0
		float  	m_zoomFullStartTime; // 0x16a4
		unsigned char _0x16a8[0x3c];
		int    	m_lastUCmdSimulationTicks; // 0x16e4
		float  	m_lastUCmdSimulationRemainderTime; // 0x16e8
		unsigned char _0x16ec[0x3c4];
		uint64_t	m_currentFramePlayer; // 0x1ab0
		unsigned char _0x1ab8[0x3a0];
		uint64_t	pl; // 0x1e58
		unsigned char _0x1e60[0x58];
		uint64_t	m_rodeo; // 0x1eb8
		unsigned char _0x1ec0[0xec];
		int    	m_hasBadReputation; // 0x1fac
		int    	m_happyHourActive; // 0x1fad
		char*  	m_communityName; // 0x1faf
		unsigned char _0x1fb7[0x38];
		char*  	m_communityClanTag; // 0x1fef
		unsigned char _0x1ff7[0x8];
		char*  	m_factionName; // 0x1fff
		unsigned char _0x2007[0x8];
		char*  	m_hardwareIcon; // 0x200f
		unsigned char _0x2017[0x9];
		vector4	m_platformUserId; // 0x2020
		int    	m_classModsActive; // 0x2030
		unsigned char _0x2034[0x78];
		int    	m_posClassModsActive_0; // 0x20ac
		unsigned char _0x20b0[0x3c];
		int    	m_passives_ 0 ; // 0x20ec
		unsigned char _0x20f0[0x100];
		uint64_t	m_statusEffectsTimedPlayerNV; // 0x21f0
		unsigned char _0x21f8[0xe8];
		uint64_t	m_statusEffectsEndlessPlayerNV; // 0x22e0
		unsigned char _0x22e8[0xa4];
		uint64_t	m_gestureSequences; // 0x238c
		unsigned char _0x2394[0x8];
		uint64_t	m_gestureStartTimes; // 0x239c
		unsigned char _0x23a4[0x8];
		uint64_t	m_gestureBlendInDuration; // 0x23ac
		unsigned char _0x23b4[0x8];
		uint64_t	m_gestureBlendOutDuration; // 0x23bc
		unsigned char _0x23c4[0x8];
		uint64_t	m_gestureFadeOutStartTime; // 0x23cc
		unsigned char _0x23d4[0x8];
		uint64_t	m_gestureFadeOutDuration; // 0x23dc
		unsigned char _0x23e4[0x8];
		int    	m_gestureAutoKillBitfield; // 0x23ec
		unsigned char _0x23f0[0x40];
		int    	m_autoSprintForced; // 0x2430
		int    	m_fIsSprinting; // 0x2434
		unsigned char _0x2438[0x4];
		float  	m_sprintStartedTime; // 0x243c
		float  	m_sprintStartedFrac; // 0x2440
		float  	m_sprintEndedTime; // 0x2444
		float  	m_sprintEndedFrac; // 0x2448
		float  	m_stickySprintStartTime; // 0x244c
		float  	m_damageImpulseNoDecelEndTime; // 0x2450
		int    	m_titanSoulBeingRodeoed; // 0x2454
		unsigned char _0x2458[0x4];
		int    	m_duckState; // 0x245c
		vector3	m_StandHullMin; // 0x2460
		vector3	m_StandHullMax; // 0x246c
		vector3	m_DuckHullMin; // 0x2478
		vector3	m_DuckHullMax; // 0x2484
		int    	m_entitySyncingWithMe; // 0x2490
		vector3	m_upDir; // 0x2494
		unsigned char _0x24a0[0x64];
		int    	m_traversalState; // 0x2504
		int    	m_traversalType; // 0x2508
		unsigned char _0x250c[0x28];
		vector3	m_traversalForwardDir; // 0x2534
		vector3	m_traversalRefPos; // 0x2540
		unsigned char _0x254c[0x20];
		float  	m_traversalYawDelta; // 0x256c
		int    	m_traversalYawPoseParameter; // 0x2570
		unsigned char _0x2574[0x14];
		int    	m_wallHanging; // 0x2588
		unsigned char _0x258c[0x4];
		uint64_t	m_grapple; // 0x2590
		unsigned char _0x2598[0x60];
		int    	m_grappleActive; // 0x25f8
		unsigned char _0x25fc[0x38];
		int    	m_remoteTurret; // 0x2634
		int    	m_hViewModel; // 0x2638
		unsigned char _0x263c[0x4];
		uint64_t	m_viewOffsetEntity; // 0x2640
		unsigned char _0x2648[0x38];
		uint64_t	m_animViewEntity; // 0x2680
		unsigned char _0x2688[0xdc];
		int    	m_activeZipline; // 0x2764
		unsigned char _0x2768[0x8];
		int    	m_ziplineReverse; // 0x2770
		int    	m_ziplineValid3pWeaponLayerAnim; // 0x2771
		int    	m_ziplineState; // 0x2774
		unsigned char _0x2778[0xee];
		int    	m_isPerformingBoostAction; // 0x2866
		unsigned char _0x286a[0x5e];
		uint64_t	m_melee; // 0x28c8
		unsigned char _0x28d0[0x20];
		int    	m_useCredit; // 0x28f0
		int    	m_playerFlags; // 0x28f4
		int    	m_hasMic; // 0x28f8
		int    	m_inPartyChat; // 0x28f9
		float  	m_playerMoveSpeedScale; // 0x28fc
		unsigned char _0x2900[0x160];
		int    	m_bShouldDrawPlayerWhileUsingViewEntity; // 0x2a60
		unsigned char _0x2a64[0x50];
		int    	m_iSpawnParity; // 0x2ab4
		unsigned char _0x2ab8[0x4];
		int    	m_iObserverMode; // 0x2abc
		int    	m_hObserverTarget; // 0x2ac0
		int    	m_activeBurnCardIndex; // 0x2ac4
		unsigned char _0x2ac8[0x84];
		float  	m_flDeathTime; // 0x2b4c
		unsigned char _0x2b50[0x30];
		float  	m_lastDodgeTime; // 0x2b80
		unsigned char _0x2b84[0x70];
		int    	m_grappleHook; // 0x2bf4
		int    	m_petTitan; // 0x2bf8
		unsigned char _0x2bfc[0x24];
		int    	m_xp; // 0x2c20
		unsigned char _0x2c24[0x4];
		int    	m_generation; // 0x2c28
		int    	m_rank; // 0x2c2c
		int    	m_serverForceIncreasePlayerListGenerationParity; // 0x2c30
		int    	m_isPlayingRanked; // 0x2c34
		float  	m_skill_mu; // 0x2c38
		float  	m_nextTitanRespawnAvailable; // 0x2c3c
		unsigned char _0x2c40[0x340];
		int    	m_ubEFNoInterpParity; // 0x2f80
		int    	m_hColorCorrectionCtrl; // 0x2f84
		int    	m_PlayerFog_m_hCtrl; // 0x2f88
		unsigned char _0x2f8c[0x154];
		char*  	m_title; // 0x30e0
		unsigned char _0x30e8[0xa0];
		uint64_t	m_smartAmmoHighestLocksOnMeFractionValues; // 0x3188
		unsigned char _0x3190[0x8];
		uint64_t	m_smartAmmoHighestLocksOnMeEntities; // 0x3198
		unsigned char _0x31a0[0x8];
		float  	m_smartAmmoPreviousHighestLockOnMeFractionValue; // 0x31a8
		unsigned char _0x31ac[0x9dc];
		uint64_t	m_Shared; // 0x3b88
		unsigned char _0x3b90[0x34];
		int    	m_pilotClassIndex; // 0x3bc4
		unsigned char _0x3bc8[0x188];
		int    	m_playerScriptNetDataGlobal; // 0x3d50
	};
#pragma pack(pop)
