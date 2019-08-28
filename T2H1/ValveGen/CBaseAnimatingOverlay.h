//***********************************************
// File: CBaseAnimatingOverlay.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseAnimatingOverlay
	{
	public:
		uint64_t	DT_BaseAnimatingOverlay; // 0x0
		uint64_t	m_animOverlayIsActive; // 0x8
		uint64_t	m_animOverlayStartTime; // 0x10
		unsigned char _0x18[0x18];
		uint64_t	m_animOverlayStartCycle; // 0x30
		unsigned char _0x38[0x18];
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
	};
#pragma pack(pop)
