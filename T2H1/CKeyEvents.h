// Keyboard Hook Class ( Singleton ) 
// Keys[i] for i = 0 to 255, is Virtual Key Code [i]
// For a given key event, the callback will only be called once

#pragma once
#include "stdafx.h"
#include <stdint.h>
class CKeyEvents
{

private: 
	HHOOK hKeyboard; // Keyboard hook object

	uint64_t Keys[4]; // bitset representing keyboard (256 possible keys)

	void SetBitNZero(uint64_t &Keys, uint8_t n) const { Keys &= ~(1 << n); }

	void SetBitNOne(uint64_t &Keys, uint8_t n) const { Keys |= 1 << n; }

	uint64_t GetBit(uint64_t &Keys, uint8_t n) const { return Keys & 1 << n;  }

	void SetKeyState(uint8_t Key, uint8_t State)
	{
		uint8_t SectionID = Key / 64;
		uint8_t n = Key - SectionID * 64;
		!State ? SetBitNZero( Keys[SectionID], n ) : SetBitNOne( Keys[SectionID], n ) ;
	}

	static LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam) // lParam should contain a pointer to the PKBDLLHOOKSTRUCT
	{
		if (nCode < HC_ACTION) { return CallNextHookEx(nullptr, nCode, wParam, lParam); }

		PKBDLLHOOKSTRUCT Events = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);

		if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
		{
			GetInstance()->SetKeyState(Events->vkCode, 1);
		}

		if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		{
			GetInstance()->SetKeyState(Events->vkCode, 0);
		}

		return CallNextHookEx(nullptr, nCode, wParam, lParam);
	}

	CKeyEvents(){
		hKeyboard = nullptr; 
		memset(Keys, 0, sizeof(Keys));
	}
	~CKeyEvents() {}

public:
	static CKeyEvents* GetInstance()
	{
		static CKeyEvents Instance;
		return &Instance;
	}

	bool GetKeyState(uint8_t Key)
	{
		uint8_t SectionID = Key / 64;
		uint8_t n = Key - SectionID * 64;
		return GetBit(Keys[SectionID], n);
	}

	bool Hook()
	{
		hKeyboard = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, nullptr, NULL);
		
		return hKeyboard != nullptr;
	}

	bool UnHook()
	{
		memset(Keys, 0, sizeof(Keys));
		return UnhookWindowsHookEx(hKeyboard);
	}

};
