//***********************************************
// File: CInfoTargetMinimap.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CInfoTargetMinimap
	{
	public:
		uint64_t	DT_InfoTargetMinimap; // 0x0
		unsigned char _0x8[0x880];
		uint64_t	m_minimapData; // 0x888
	};
#pragma pack(pop)
