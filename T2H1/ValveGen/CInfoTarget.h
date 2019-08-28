//***********************************************
// File: CInfoTarget.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CInfoTarget
	{
	public:
		uint64_t	EntityLinks; // 0x0
		unsigned char _0x8[0x14];
		int    	moveparent; // 0x1c
		unsigned char _0x20[0x14];
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		unsigned char _0x4c[0x358];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x24];
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0xcc];
		char*  	m_iSignifierName; // 0x4b0
		unsigned char _0x4b8[0x1];
		char*  	m_iName; // 0x4b9
		unsigned char _0x4c1[0xff];
		int    	m_scriptNameIndex; // 0x5c0
		int    	m_instanceNameIndex; // 0x5c4
		unsigned char _0x5c8[0x1bc];
		int    	m_parentAttachmentType; // 0x784
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x19b];
		int    	m_areEntityLinksNetworked; // 0x92f
	};
#pragma pack(pop)
