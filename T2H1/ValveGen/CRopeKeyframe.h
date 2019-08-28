//***********************************************
// File: CRopeKeyframe.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CRopeKeyframe
	{
	public:
		unsigned char _0x0[0x4];
		vector3	m_localOrigin; // 0x4
		unsigned char _0x10[0xc];
		int    	moveparent; // 0x1c
		int    	m_parentAttachmentType; // 0x20
		unsigned char _0x24[0x374];
		int    	m_visibilityFlags; // 0x398
		unsigned char _0x39c[0x44];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x3a4];
		int    	m_parentAttachmentIndex; // 0x788
		int    	m_parentAttachmentHitbox; // 0x78c
		int    	m_parentAttachmentModel; // 0x790
		unsigned char _0x794[0x3a4];
		float  	m_ziplineAutoDetachDistance; // 0xb38
		int    	m_ziplineSagEnable; // 0xb3c
		float  	m_ziplineSagHeight; // 0xb40
		unsigned char _0xb44[0x124];
		float  	m_ziplineMoveSpeedScale; // 0xc68
		float  	m_wiggleFadeStartTime; // 0xc6c
		float  	m_wiggleEndTime; // 0xc70
		float  	m_wiggleMaxLen; // 0xc74
		float  	m_wiggleMagnitude; // 0xc78
		float  	m_wiggleSpeed; // 0xc7c
		unsigned char _0xc80[0x34];
		float  	m_flScrollSpeed; // 0xcb4
		int    	m_RopeFlags; // 0xcb8
		int    	m_iRopeMaterialModelIndex; // 0xcbc
		unsigned char _0xcc0[0x548];
		int    	m_nSegments; // 0x1208
		int    	m_hStartPoint; // 0x120c
		int    	m_hEndPoint; // 0x1210
		int    	m_hPrevPoint; // 0x1214
		int    	m_iStartAttachment; // 0x1218
		int    	m_iEndAttachment; // 0x121a
		int    	m_Subdiv; // 0x121c
		int    	m_RopeLength; // 0x1220
		int    	m_Slack; // 0x1224
		float  	m_TextureScale; // 0x1228
		int    	m_fLockedPoints; // 0x122c
		int    	m_nChangeCount; // 0x1230
		float  	m_Width; // 0x1234
		unsigned char _0x1238[0x88];
		int    	m_bConstrainBetweenEndpoints; // 0x12c0
	};
#pragma pack(pop)
