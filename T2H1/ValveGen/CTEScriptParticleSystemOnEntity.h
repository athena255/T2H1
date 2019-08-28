//***********************************************
// File: CTEScriptParticleSystemOnEntity.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CTEScriptParticleSystemOnEntity
	{
	public:
		uint64_t	DT_TEScriptParticleSystemOnEntity; // 0x0
		unsigned char _0x8[0x20];
		int    	m_effectIndex; // 0x28
		int    	m_ent; // 0x2c
		int    	m_attachType; // 0x30
		int    	m_attachmentIndex; // 0x34
		int    	m_attachType2; // 0x38
		int    	m_attachmentIndex2; // 0x3c
	};
#pragma pack(pop)
