#pragma once
class C_UserCmd
{
	int command_number;
	int tick_count;
	float command_time;
	float worldViewAngles[3];
	float localViewAngles[3];
	float attackangles[3];
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	char impulse;
};