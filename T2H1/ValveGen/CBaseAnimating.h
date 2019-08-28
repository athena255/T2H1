//***********************************************
// File: CBaseAnimating.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseAnimating
	{
	public:
		uint64_t	DT_BaseAnimating; // 0x0
		unsigned char _0x8[0x8];
		float  	m_animPlaybackRate; // 0x10
		int    	m_animFrozen; // 0x14
		int    	m_animModelIndex; // 0x18
		int    	m_animSequence; // 0x1c
		int    	m_nNewSequenceParity; // 0x20
		uint64_t	m_flPoseParameter; // 0x24
		unsigned char _0x2c[0x58];
		int    	m_bClientSideRagdoll; // 0x84
		vector3	m_vecForce; // 0x88
		float  	m_flEstIkOffset; // 0x94
		unsigned char _0x98[0x654];
		int    	m_passDamageToParent; // 0x6ec
		unsigned char _0x6f0[0x470];
		int    	m_animNetworkFlags; // 0xb60
		int    	m_animActive; // 0xb64
		int    	m_animCollisionEnabled; // 0xb67
		unsigned char _0xb6b[0x1];
		uint64_t	m_animRelativeData; // 0xb6c
		unsigned char _0xb74[0xe8];
		int    	m_syncingWithEntity; // 0xc5c
		uint64_t	m_predictedAnimEventData; // 0xc60
		unsigned char _0xc68[0x64];
		int    	m_nRagdollImpactFXTableId; // 0xccc
		float  	m_flSkyScaleStartValue; // 0xcd0
		float  	m_flSkyScaleEndValue; // 0xcd4
		float  	m_flSkyScaleStartTime; // 0xcd8
		float  	m_flSkyScaleEndTime; // 0xcdc
		unsigned char _0xce0[0x18];
		uint64_t	m_SequenceTransitioner; // 0xcf8
		unsigned char _0xd00[0x280];
		int    	m_nSkin; // 0xf80
		int    	m_nBody; // 0xf84
		unsigned char _0xf88[0x30];
		int    	m_nForceBone; // 0xfb8
		unsigned char _0xfbc[0x5d];
		int    	m_bCanUseFastPathFromServer; // 0x1019
		unsigned char _0x101d[0x3];
		int    	m_bSequenceFinished; // 0x1020
		int    	m_useLockedAnimDeltaYaw; // 0x1021
		float  	m_lockedAnimDeltaYaw; // 0x1024
		unsigned char _0x1028[0x4];
		float  	m_flModelScale; // 0x102c
	};
#pragma pack(pop)
