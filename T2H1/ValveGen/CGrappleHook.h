//***********************************************
// File: CGrappleHook.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CGrappleHook
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
		unsigned char _0x39c[0x30];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x3a8];
		int    	m_parentAttachmentHitbox; // 0x78c
	};
#pragma pack(pop)
