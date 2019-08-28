//***********************************************
// File: CInfoPlacementHelper.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CInfoPlacementHelper
	{
	public:
		unsigned char _0x0[0x4];
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0xc];
		int    	moveparent; // 0x1c
		unsigned char _0x20[0x3ac];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x3ac];
		int    	m_parentAttachmentType; // 0x784
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
	};
#pragma pack(pop)
