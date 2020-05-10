#include <Windows.h>


DWORD WINAPI LoaderThread(LPVOID lpParameter)
{
	while (true)
	{
		if (::GetAsyncKeyState(VK_INSERT) & 1)
		{
			using HackFunc_t = void(*)();

			auto Lib = ::LoadLibraryA("VRGreen.dll");
			HackFunc_t Hack = (HackFunc_t)GetProcAddress(Lib, "__vrgreen_init");

			Hack();

			::FreeLibrary(Lib);
		}

		Sleep(16);
		// std::this_thread::sleep_for(std::chrono::milliseconds(16)); 
	}

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
		::CreateThread(0, 0, LoaderThread, 0, 0, 0);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

