//***********************************************
// File: CScriptTraceVolume.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CScriptTraceVolume
	{
	public:
		uint64_t	DT_ScriptTraceVolume; // 0x0
		unsigned char _0x8[0xb30];
		int    	m_contents; // 0xb38
		int    	m_shapeType; // 0xb3c
		float  	m_sphereRadius; // 0xb40
		vector3	m_boxMins; // 0xb44
		vector3	m_boxMaxs; // 0xb50
		int    	m_drawDebug; // 0xb5c
	};
#pragma pack(pop)
