//***********************************************
// File: CScriptProp.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CScriptProp
	{
	public:
		uint64_t	DT_ScriptProp; // 0x0
		unsigned char _0x8[0x348];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x3c];
		int    	m_iHealth; // 0x390
		unsigned char _0x394[0x114];
		int    	m_iMaxHealth; // 0x4a8
		unsigned char _0x4ac[0x3dc];
		uint64_t	m_minimapData; // 0x888
		unsigned char _0x890[0x18];
		int    	m_nameVisibilityFlags; // 0x8a8
		unsigned char _0x8ac[0x9d4];
		char*  	m_title; // 0x1280
		unsigned char _0x1288[0x18];
		char*  	m_footstepType; // 0x12a0
		unsigned char _0x12a8[0x38];
		int    	m_renderColorFriendlyIsValid; // 0x12e0
		int    	m_renderColorFriendly; // 0x12e1
		unsigned char _0x12e5[0x3];
		int    	m_armorType; // 0x12e8
		int    	m_scriptPropFlags; // 0x12ec
		int    	m_scriptPropSmartAmmoLockType; // 0x12f0
	};
#pragma pack(pop)
