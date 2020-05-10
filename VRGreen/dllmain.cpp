#define HTTP_IMPLEMENTATION

#include "Hack.hpp"

#pragma execution_character_set( "utf-8" ) 




#define LOADER

#ifdef LOADER


extern "C"
__declspec(dllexport)
void __vrgreen_init()
{
	Hack &hack = Hack::getInstance();

	hack.init();
	hack.mainLoop();
	hack.destroy();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	return TRUE;
}


#else

DWORD WINAPI newThread(LPVOID lpParameter)
{
	Hack& hack = Hack::getInstance();

	hack.init();
	hack.mainLoop();
	hack.destroy();

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:


		CreateThread(NULL, 0, newThread, 0, 0, 0);
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

#endif // LOADER