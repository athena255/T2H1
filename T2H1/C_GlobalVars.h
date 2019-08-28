#pragma once


class C_GlobalVars
{
public:
	float realtime; //0x0000
	int framecount; //0x0004
	float absoluteframetime; //0x0008
	float curtime; //0x000C
	float frametime; //0x0010
	int tickcount; //0x0014
	float Unk1; //0x0018
	float interval_per_tick; //0x001C
	float interpolation_amount; //0x0020
	int simTicksThisFrame; //0x0024
	int network_protocol; //0x0028
};

//class C_GlobalVars //9344AC
//{
//public:
//	double realtime; // 0x000
//	int framecount; // 0x008
//	float absoluteframetime; //0x00C
//	float u0; //0x010
//	float u1;
//	float u2;
//	float u3;
//	float interpolation_amount;
//	float u4;
//	float u5;
//	float u6;
//	float simTicksThisFrame;
//	int u7;
//	int u8;
//	int tickcount;
//
//};
C_GlobalVars * g_pGlobals = nullptr;