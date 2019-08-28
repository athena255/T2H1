//***********************************************
// File: CScriptMover.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CScriptMover
	{
	public:
		uint64_t	DT_ScriptMover; // 0x0
		unsigned char _0x8[0x18];
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0xe4];
		vector3	m_vecAngVelocity; // 0x108
		unsigned char _0x114[0x2ac];
		vector3	m_vecVelocity; // 0x3c0
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x3b4];
		int    	m_parentAttachmentHitbox; // 0x78c
	};
#pragma pack(pop)
