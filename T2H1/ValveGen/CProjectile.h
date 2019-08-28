//***********************************************
// File: CProjectile.h
//***********************************************

#pragma once


#pragma pack(push,1)
	class CProjectile
	{
	public:
		unsigned char _0x0[0x34];
		int    	m_cellX; // 0x34
		int    	m_cellY; // 0x38
		int    	m_cellZ; // 0x3c
		vector3	m_localOrigin; // 0x40
		int    	m_nModelIndex; // 0x4c
		unsigned char _0x50[0x300];
		int    	m_networkedFlags; // 0x350
		unsigned char _0x354[0x50];
		int    	m_iTeamNum; // 0x3a4
		unsigned char _0x3a8[0x18];
		vector3	m_vecVelocity; // 0x3c0
		vector3	m_localAngles; // 0x3cc
		unsigned char _0x3d8[0x8];
		int    	m_hOwnerEntity; // 0x3e0
		unsigned char _0x3e4[0x310];
		int    	m_PredictableID; // 0x6f4
		unsigned char _0x6f8[0x140];
		int    	m_CollisionGroup; // 0x838
		unsigned char _0x83c[0x9f4];
		int    	m_weaponDataIsSet; // 0x1230
		int    	m_forceAdjustToGunBarrelDisabled; // 0x1231
		int    	m_weaponClassIndex; // 0x1234
		float  	m_destructionDistance; // 0x1238
		int    	m_passThroughDepthTotal; // 0x123c
		int    	m_modBitfield; // 0x1240
		int    	m_overrideMods; // 0x1244
		int    	m_projectileTrailIndex; // 0x1248
		int    	m_impactEffectTable; // 0x124c
		int    	m_reducedEffects; // 0x1250
		float  	m_projectileCreationTimeServer; // 0x1254
	};
#pragma pack(pop)
