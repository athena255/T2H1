//***********************************************
// File: CStatueProp.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CStatueProp
	{
	public:
		uint64_t	DT_StatueProp; // 0x0
		unsigned char _0x8[0x1278];
		int    	m_hInitBaseAnimating; // 0x1280
		int    	m_bShatter; // 0x1284
		int    	m_nShatterFlags; // 0x1288
		vector3	m_vShatterPosition; // 0x128c
		vector3	m_vShatterForce; // 0x1298
	};
#pragma pack(pop)
