//***********************************************
// File: CScriptMoverLightweight.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CScriptMoverLightweight
	{
	public:
		unsigned char _0x0[0x1c];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0xc];
		int    	m_fEffects; // 0x30
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0xb8];
		vector3	m_vecAngVelocity; // 0x108
		unsigned char _0x114[0x23c];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x6c];
		vector3	m_vecVelocity; // 0x3c0
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x3b0];
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x4];
		float  	m_fadeDist; // 0x798
		unsigned char _0x79c[0x87d];
		int    	m_bCanUseFastPathFromServer; // 0x1019
	};
#pragma pack(pop)
