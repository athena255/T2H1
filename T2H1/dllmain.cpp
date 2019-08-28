// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "utils.h"
//#include "CInterface.h"
#include "IClientMode.h"
#include "IClientEntityList.h"
#include "IVEngineClient.h"
#include "IBaseClientDLL.h"
#include "IConVar.h"
#include "C_Input.h"
#include "ConVar.h"
#include "ICvar.h"

#define PROCESSNAME L"client.dll"
#define SERVERDLL L"server.dll"
#define ENGINEDLL L"engine.dll"
#define POLL_RATE 100

#define PENGINEPLAYER 0x1308C248
#define ENGINE_HEALTH_OFF 0x4D4

#define CLIENTENTITYLIST 0xB0F030

// server.dll + 6A1F30 location
#define AMMO_PATCH_START 0x6A1F30
#define OLD_AMMO "\x89\xB7\xDC\x0E\x00\x00"
#define AMMO_SIG "\x89\x00\x00\x00\x00\x00\x48\x8B\x5C\x24\x30\x48\x8B\x74\x24\x40\x48\x83\xC4\x20\x5F\xC3\xCC\xCC"
#define AMMO_MASK "x?????xxxxxxxxxxxxxxxxxx"

#define TAKE_DAMAGE_OFFSET 0x43373A // server.dll + 0x43373A

#define CINPUTVT 0xB1D380

#define B_LEVELINIT 0xC3D87C
#define P_IMPACT_EFFECT_TABLE_NAMES 0xC3DB08
#define P_STRING_TABLE_EFFECT_DISPATCH 0xC3DAD0
#define P_STRING_TABLE_VGUI_SCREEN 0xC3DAC8
#define P_STRING_TABLE_MATERIALS 0xC3DB18
#define P_STRING_TABLE_INFO_PANEL 0xC3DAD8
#define P_MOVIES 0xC3DB20
#define P_WEAPONNAMES 0xC3DAE8
#define P_SCRIPTNAMES 0xC3DAF0
#define P_CLASSLIST 0xC3DB30
#define P_CLIENTMODE 0xFB3780
#define P_GLOBALS 0xB06AD0

void SetConVar(ICvar* g_cvar, const char* name, int value)
{
	ConVar* c = g_cvar->FindVar(name);
	if (g_cvar)
	{
		c->SetValue(value);
		std::cout << name << ": " << c->m_Value.m_pszString << std::endl;
	}
	else
	{
		std::cout << "Could not find: " << name << std::endl;
	}
}

template<typename T> T* GetInterface(HMODULE hModule, const char* interfaceName)
{
	CreateInterfaceFn CreateInterface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(hModule, "CreateInterface"));
	uintptr_t pInterface = CreateInterface(interfaceName, NULL);
	

	return reinterpret_cast<T*>(pInterface);
}

DWORD WINAPI MyThread(HMODULE hModule)
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "Retriving handle to game..." << std::endl;

	// Module Base Address
	uintptr_t clientBaseAddr = NULL;

	while (!clientBaseAddr)
	{
		clientBaseAddr = reinterpret_cast<uintptr_t>(GetModuleHandle(PROCESSNAME));
	}
	std::cout << "Client Base Address: " << std::hex << clientBaseAddr << std::endl;

	// Server Base Address
	uintptr_t serverBaseAddr = NULL;

	while (!serverBaseAddr)
	{
		serverBaseAddr = reinterpret_cast<uintptr_t>(GetModuleHandle(SERVERDLL));
	}
	std::cout << "Server Base Address: " << std::hex << serverBaseAddr << std::endl;

	// Ammo Patch Address
	uintptr_t ammoPatchAddress = FindPattern(reinterpret_cast<HMODULE>(serverBaseAddr), (BYTE*)AMMO_SIG, (BYTE*)AMMO_MASK, strlen(AMMO_MASK), 0);
	std::cout << "Ammo Patch Address: " << std::hex << ammoPatchAddress << std::endl;
	std::cout << "Correct Ammo Patch Address: " << std::hex << (serverBaseAddr + AMMO_PATCH_START) << std::endl;

	// Engine Base Address
	uintptr_t engineBaseAddr = NULL;

	while (!engineBaseAddr)
	{
		engineBaseAddr = reinterpret_cast<uintptr_t>(GetModuleHandle(ENGINEDLL));
	}
	std::cout << "Engine Base Address: " << std::hex << engineBaseAddr << std::endl;

	// Player Ptr Address in Engine.dll
	uintptr_t pEnginePlayer = engineBaseAddr + PENGINEPLAYER;
	std::cout << "Engine Player Ptr: " << std::hex << pEnginePlayer << std::endl;

	IBaseClientDLL* g_CHLClient = GetInterface<IBaseClientDLL>(GetModuleHandle(PROCESSNAME), "VClient018");
	std::cout << "g_CHLClient: " << std::hex << g_CHLClient << std::endl;

	IClientEntityList* g_EntityList = GetInterface<IClientEntityList>(GetModuleHandle(PROCESSNAME), "VClientEntityList003");
	std::cout << "g_EntityList: " << std::hex << g_EntityList << std::endl;
	std::cout << "ClientEntityList: " << std::hex << clientBaseAddr + CLIENTENTITYLIST << std::endl;

	IVEngineClient* g_EngineClient = GetInterface<IVEngineClient>(GetModuleHandle(ENGINEDLL), "VEngineClient013");
	std::cout << "g_EngineClient: " << std::hex << g_EngineClient << std::endl;

	void* g_InputSystem = GetInterface<void*>(GetModuleHandleW(L"inputsystem.dll"), "InputSystemVersion001");
	std::cout << "g_InputSystem: " << std::hex << g_InputSystem << std::endl;

	ICvar* g_CVar = GetInterface<ICvar>(GetModuleHandleW(L"vstdlib.dll"), "VEngineCvar007");
	std::cout << "g_CVar: " << std::hex << g_CVar << std::endl;

	IClientMode* g_ClientMode = *reinterpret_cast<IClientMode**>(clientBaseAddr + P_CLIENTMODE);
	std::cout << "g_ClientMode: " << std::hex << g_ClientMode << std::endl;

	C_Input* g_Input = *reinterpret_cast<C_Input**>(clientBaseAddr + CINPUTVT);
	std::cout << "g_Input: " << std::hex << g_Input << std::endl;

	C_GlobalVars* g_GlobalVars = *reinterpret_cast<C_GlobalVars**>(clientBaseAddr + P_GLOBALS);
	std::cout << "g_GlobalVars: " << std::hex << g_GlobalVars << std::endl;

	//std::cout << "address of IsInGame: " << g_EngineClient->IsInGame << std::endl;
	int g_LocalPlayer = g_EngineClient->GetLocalPlayer();
	std::cout << "g_LocalPlayer: " << g_LocalPlayer << std::endl;

	//std::cout << "getLastTimeStamp: " << g_EngineClient->GetLastTimeStamp() << std::endl;

	SetConVar(g_CVar, "sv_cheats", 1);
	SetConVar(g_CVar, "cl_showpos", 1);
	SetConVar(g_CVar, "cl_pdump", 1);
	SetConVar(g_CVar, "cl_pclass", 1);

	g_CVar->FindVar("crosshair")->SetValue(true);
	


	//auto name = g_CVar->FindVar("name");
	//std::cout << "name" << name << std::endl;


	void* g_ClientState;  // this comes from engine, everything else comes from client



	bool bHealth = false, bAmmo = false;

	while (true)
	{
		//system("cls");
		//std::cout << "Titanfall2 Single Player Hack" << std::endl;
		//std::cout << "=============================" << std::endl;
		//std::cout << "[F3] Unlimited Ammo " << (bAmmo ? "Enabled" : "Disabled") << std::endl;
		//std::cout << "[F4] Unlimited Health " << (bHealth ? "Enabled" : "Disabled") << std::endl;
		//std::cout << "[End] Quit" << std::endl;

		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}

		if (GetAsyncKeyState(VK_F3) & 1)
		{
			bAmmo = !bAmmo;

			if (bAmmo) 
			{
				std::cout << "Unlimited Ammo Enabled" << std::endl;
				WriteToMemory(reinterpret_cast<BYTE*>(ammoPatchAddress), (BYTE*)"\x90\x90\x90\x90\x90\x90", 6);
			}
			else
			{
				std::cout << "Unlimited Ammo Disabled" << std::endl;
				WriteToMemory(reinterpret_cast<BYTE*>(ammoPatchAddress), (BYTE*)OLD_AMMO, 6);
			}
		}

		if (GetAsyncKeyState(VK_F4) & 1)
		{
			bHealth = !bHealth;
			if (bHealth) 
			{
				std::cout << "Invincibility Enabled" << std::endl;
				std::cout << "Current Player Health Address: " << (*(uintptr_t*)pEnginePlayer + ENGINE_HEALTH_OFF) << std::endl;
			}
			else
			{
				std::cout << "Invincibility Disabled" << std::endl;
			}
		}

		// continuous write
		if (bHealth)
		{
			*(uintptr_t*)(*(uintptr_t*)pEnginePlayer + ENGINE_HEALTH_OFF) = 500;
		}

		Sleep (POLL_RATE);
	}
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MyThread, hModule, 0, nullptr));
	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

