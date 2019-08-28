//***********************************************
// File: CFuncBrushLightweight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CFuncBrushLightweight
	{
	public:
		unsigned char _0x0[0x1c];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0x10];
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
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0xa4];
		int    	m_CollisionGroup; // 0x838
		unsigned char _0x83c[0xf1];
		int    	m_physDummyMotionEnabled; // 0x92d
	};
#pragma pack(pop)
