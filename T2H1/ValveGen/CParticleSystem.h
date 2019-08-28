//***********************************************
// File: CParticleSystem.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CParticleSystem
	{
	public:
		unsigned char _0x0[0x4];
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0xc];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0xc];
		int    	m_fEffects; // 0x30
		unsigned char _0x34[0x364];
		int    	m_visibilityFlags; // 0x398
		unsigned char _0x39c[0x8];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x24];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x3a4];
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x3a4];
		int    	m_iEffectIndex; // 0xb38
		int    	m_nStopType; // 0xb3c
		unsigned char _0xb40[0x1];
		int    	m_bActive; // 0xb41
		int    	m_bForceRenderAlways; // 0xb43
		float  	m_flStartTime; // 0xb44
		unsigned char _0xb48[0x5];
		int    	m_bInSkybox; // 0xb4d
		int    	m_killForReplay; // 0xb4e
		int    	m_killIfOverLimit; // 0xb4f
		unsigned char _0xb53[0x1];
		uint64_t	m_vServerControlPoints; // 0xb54
		unsigned char _0xb5c[0x34];
		uint64_t	m_hControlPointEnts; // 0xb90
		unsigned char _0xb98[0xc];
		uint64_t	m_controlPointAttachTypes; // 0xba4
		unsigned char _0xbac[0x10];
		int    	m_controlPoint1AttachmentIndex; // 0xbbc
		unsigned char _0xbc0[0xc];
		int    	m_parentAttachType; // 0xbcc
	};
#pragma pack(pop)
