//***********************************************
// File: CBaseViewModel.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseViewModel
	{
	public:
		uint64_t	overlay_vars; // 0x0
		float  	m_animStartTime; // 0x8
		float  	m_animStartCycle; // 0xc
		float  	m_animPlaybackRate; // 0x10
		int    	m_animFrozen; // 0x14
		int    	m_animModelIndex; // 0x18
		int    	m_animSequence; // 0x1c
		int    	m_nNewSequenceParity; // 0x20
		unsigned char _0x24[0xc];
		int    	m_fEffects; // 0x30
		unsigned char _0x34[0x14];
		int    	m_clrRender; // 0x48
		int    	m_nModelIndex; // 0x4c
		uint64_t	m_animOverlayPlaybackRate; // 0x50
		unsigned char _0x58[0x18];
		uint64_t	m_animOverlayModelIndex; // 0x70
		unsigned char _0x78[0x18];
		uint64_t	m_animOverlaySequence; // 0x90
		unsigned char _0x98[0x18];
		uint64_t	m_animOverlayWeight; // 0xb0
		unsigned char _0xb8[0x18];
		uint64_t	m_animOverlayOrder; // 0xd0
		unsigned char _0xd8[0x18];
		uint64_t	m_animOverlayAnimTime; // 0xf0
		unsigned char _0xf8[0x18];
		uint64_t	m_animOverlayFadeInDuration; // 0x110
		unsigned char _0x118[0x18];
		uint64_t	m_animOverlayFadeOutDuration; // 0x130
		unsigned char _0x138[0x2b9];
		int    	m_nRenderMode; // 0x3f1
		unsigned char _0x3f5[0xb8b];
		int    	m_nSkin; // 0xf80
		int    	m_nBody; // 0xf84
		unsigned char _0xf88[0x8];
		int    	m_nResetEventsParity; // 0xf90
		unsigned char _0xf94[0x8c];
		int    	m_bSequenceFinished; // 0x1020
		unsigned char _0x1024[0x500];
		int    	m_viewModelOwner; // 0x1524
		unsigned char _0x1528[0x10];
		int    	m_projectileIsVisible; // 0x1538
		unsigned char _0x153c[0x1e0];
		int    	m_transitionSequence; // 0x171c
		int    	m_goalSequence; // 0x1720
		float  	m_goalPlaybackRate; // 0x1724
		int    	m_hWeapon; // 0x1728
		uint64_t	m_tracerAttachments; // 0x172c
		uint64_t	m_tracerAttachmentsScoped; // 0x1734
	};
#pragma pack(pop)
