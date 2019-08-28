//***********************************************
// File: CDynamicPropLightweight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CDynamicPropLightweight
	{
	public:
		unsigned char _0x0[0x1c];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0xc];
		int    	m_fEffects; // 0x30
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0x348];
		int    	m_visibilityFlags; // 0x398
		int    	m_scriptVisible; // 0x39c
		unsigned char _0x3a0[0x2c];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x20];
		uint64_t	m_Collision; // 0x3f8
		unsigned char _0x400[0x388];
		int    	m_parentAttachmentIndex; // 0x788
		unsigned char _0x78c[0x4];
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x4];
		float  	m_fadeDist; // 0x798
		unsigned char _0x79c[0x9c];
		int    	m_CollisionGroup; // 0x838
		unsigned char _0x83c[0xf1];
		int    	m_physDummyMotionEnabled; // 0x92d
		unsigned char _0x931[0x64f];
		int    	m_nSkin; // 0xf80
	};
#pragma pack(pop)
