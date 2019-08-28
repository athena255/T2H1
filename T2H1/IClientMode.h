#pragma once
// 35 methods in IClientMode vftable

class IClientMode {
public:
	// LevelInit is number 20
	virtual void InitViewport() = 0;	// 0x8
	virtual void Init() = 0;			// 0x10
	virtual void VGui_Shutdown() = 0;	// 0x18
	virtual void Shutdown() = 0;        // 0x20
	virtual void Enable() = 0;			//0x28

	virtual void Disable() = 0;  // 0x38

	virtual void ProcessInput(bool); // 0x60

	// possibly ClientStructs at //0x100
	
};