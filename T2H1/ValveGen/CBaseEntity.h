//***********************************************
// File: CBaseEntity.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseEntity
	{
	public:
		int    	movetype; // 0x0
		unsigned char _0x4[0x18];
		int    	moveparent; // 0x1c
		unsigned char _0x20[0x10];
		int    	m_fEffects; // 0x30
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		int    	m_clrRender; // 0x48
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0xb4];
		int    	m_bossPlayer; // 0x104
		unsigned char _0x108[0x48];
		int    	m_shieldHealth; // 0x150
		int    	m_shieldHealthMax; // 0x154
		unsigned char _0x158[0x40];
		int    	m_highlightIsNetworked; // 0x198
		unsigned char _0x19c[0x1b4];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x44];
		int    	m_visibilityFlags; // 0x398
		int    	m_scriptVisible; // 0x39c
		unsigned char _0x3a0[0x4];
		int    	m_iTeamNum; // 0x3a4
		int    	m_passThroughFlags; // 0x3a8
		int    	m_passThroughThickness; // 0x3ac
		float  	m_passThroughDirection; // 0x3b0
		unsigned char _0x3b4[0x18];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		int    	m_bRenderWithViewModels; // 0x3e4
		int    	m_nRenderFX; // 0x3e5
		unsigned char _0x3e9[0x8];
		int    	m_nRenderMode; // 0x3f1
		unsigned char _0x3f5[0x3];
		uint64_t	m_Collision; // 0x3f8
		unsigned char _0x400[0xb0];
		char*  	m_iSignifierName; // 0x4b0
		unsigned char _0x4b8[0x1];
		char*  	m_iName; // 0x4b9
		unsigned char _0x4c1[0xff];
		int    	m_scriptNameIndex; // 0x5c0
		int    	m_instanceNameIndex; // 0x5c4
		unsigned char _0x5c8[0x80];
		char*  	m_holdUsePrompt; // 0x648
		char*  	m_pressUsePrompt; // 0x650
		unsigned char _0x658[0x8c];
		int    	m_forceVisibleInPhaseShift; // 0x6e4
		int    	m_baseTakeDamage; // 0x6e5
		int    	m_invulnerableToDamageCount; // 0x6e8
		unsigned char _0x6ec[0x78];
		float  	m_attachmentLerpStartTime; // 0x764
		float  	m_attachmentLerpEndTime; // 0x768
		vector3	m_attachmentLerpStartOrigin; // 0x76c
		vector3	m_attachmentLerpStartAngles; // 0x778
		unsigned char _0x784[0x4];
		int    	m_parentAttachmentIndex; // 0x788
		unsigned char _0x78c[0x4];
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x4];
		float  	m_fadeDist; // 0x798
		unsigned char _0x79c[0x9c];
		int    	m_CollisionGroup; // 0x838
		int    	m_contents; // 0x83c
		unsigned char _0x840[0x18];
		int    	m_dissolveEffectEntityHandle; // 0x858
		unsigned char _0x85c[0x8];
		int    	m_usableType; // 0x864
		int    	m_usablePriority; // 0x868
		float  	m_usableRadius; // 0x86c
		float  	m_usableFOV; // 0x870
		float  	m_usePromptSize; // 0x874
		unsigned char _0x878[0x8];
		int    	m_spottedByTeams; // 0x880
		unsigned char _0x884[0xa8];
		int    	m_debugBrokenInterpolation; // 0x92c
		int    	m_areEntityLinksNetworked; // 0x92f
	};
#pragma pack(pop)
