

#include "required.h"
#include "client.h"
#include "classbuilder.h"
#include <iostream>

DWORD WINAPI Begin(LPVOID param)
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	valvegen::Client* client = valvegen::Client::Instance();

	std::cout << "Client Instance initialized..." << std::endl;
	client->WaitForClientToBecomeReady();

	if (!client->InitClientInterface()) {
		std::cout << GetLastError() << std::endl;
		std::cout << "Client failed" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	HINSTANCE module_instance = param ? reinterpret_cast<HINSTANCE>(param) : nullptr;
	std::cout << "Creating classes" << std::endl;
	valvegen::ClassBuilder::Instance()->CreateClasses(module_instance);
	std::cout << "Classes created" << std::endl;
	system("PAUSE");

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(module_instance, 0);
	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
	)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)&Begin, hinstDLL, 0, nullptr);
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		valvegen::ClassBuilder::Instance()->Cleanup();
	}
	return TRUE;
}