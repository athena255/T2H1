//***********************************************
// File: CFuncMoveLinear.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CFuncMoveLinear
	{
	public:
		uint64_t	DT_FuncMoveLinear; // 0x0
		unsigned char _0x8[0x84];
		int    	m_fFlags; // 0x8c
		unsigned char _0x90[0x330];
		vector3	m_vecVelocity; // 0x3c0
	};
#pragma pack(pop)
