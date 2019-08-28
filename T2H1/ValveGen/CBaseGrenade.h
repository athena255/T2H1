//***********************************************
// File: CBaseGrenade.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CBaseGrenade
	{
	public:
		uint64_t	DT_BaseGrenade; // 0x0
		unsigned char _0x8[0x14];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0x6c1];
		int    	m_baseTakeDamage; // 0x6e5
		int    	m_invulnerableToDamageCount; // 0x6e8
		unsigned char _0x6ec[0x9c];
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x198d];
		int    	m_doesExplode; // 0x2121
		float  	m_DmgRadius; // 0x2124
		unsigned char _0x2128[0x1c];
		int    	m_collideWithOwner; // 0x2144
	};
#pragma pack(pop)
