//***********************************************
// File: CStatusEffectPlugin.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CStatusEffectPlugin
	{
	public:
		unsigned char _0x0[0x3e0];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x754];
		uint64_t	m_statusEffectsTimedPluginNV; // 0xb38
		unsigned char _0xb40[0x10];
		uint64_t	m_statusEffectsEndlessPluginNV; // 0xb50
	};
#pragma pack(pop)
