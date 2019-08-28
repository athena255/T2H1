//***********************************************
// File: CFogController.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CFogController
	{
	public:
		unsigned char _0x0[0xb38];
		float  	m_fog_botAlt; // 0xb38
		float  	m_fog_topAlt; // 0xb3c
		float  	m_fog_halfDistBot; // 0xb40
		float  	m_fog_halfDistTop; // 0xb44
		float  	m_fog_distColorStr; // 0xb48
		float  	m_fog_dirColorStr; // 0xb4c
		float  	m_fog_distOffset; // 0xb50
		float  	m_fog_densityScale; // 0xb54
		float  	m_fog_halfAngleDeg; // 0xb58
		float  	m_fog_HDRColorScale; // 0xb5c
		int    	m_fog_distColor; // 0xb60
		int    	m_fog_dirColor; // 0xb64
		vector3	m_fog_direction; // 0xb68
		float  	m_fog_minFadeTime; // 0xb74
		int    	m_fog_forceOntoSky; // 0xb78
		int    	m_fog_enable; // 0xb79
		int    	m_fog_id; // 0xb7c
	};
#pragma pack(pop)
