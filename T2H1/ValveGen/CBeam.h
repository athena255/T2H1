//***********************************************
// File: CBeam.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBeam
	{
	public:
		uint64_t	beampredictable_id; // 0x0
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0xc];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0x24];
		int    	m_clrRender; // 0x48
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0x348];
		int    	m_visibilityFlags; // 0x398
		unsigned char _0x39c[0x8];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x38];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x1];
		int    	m_nRenderFX; // 0x3e5
		unsigned char _0x3e9[0x8];
		int    	m_nRenderMode; // 0x3f1
		unsigned char _0x3f5[0x393];
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x3a4];
		float  	m_flFrameRate; // 0xb38
		float  	m_flHDRColorScale; // 0xb3c
		int    	m_clrRenderFriendly; // 0xb40
		unsigned char _0xb44[0x8];
		int    	m_nNumBeamEnts; // 0xb4c
		unsigned char _0xb50[0x4];
		int    	m_nHaloIndex; // 0xb54
		int    	m_nBeamType; // 0xb58
		int    	m_nBeamFlags; // 0xb5c
		uint64_t	m_hAttachEntity; // 0xb60
		unsigned char _0xb68[0x20];
		uint64_t	m_nAttachIndex; // 0xb88
		unsigned char _0xb90[0x20];
		float  	m_fWidth; // 0xbb0
		float  	m_fEndWidth; // 0xbb4
		float  	m_fFadeLength; // 0xbb8
		float  	m_fHaloScale; // 0xbbc
		float  	m_fAmplitude; // 0xbc0
		float  	m_fStartFrame; // 0xbc4
		float  	m_fSpeed; // 0xbc8
		float  	m_flFrame; // 0xbcc
		int    	m_nClipStyle; // 0xbd0
		vector3	m_vecEndPos; // 0xbd4
	};
#pragma pack(pop)
