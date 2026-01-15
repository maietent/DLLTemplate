#include "entry.hpp"
#include <MinHook.h>

void Cleanup(HMODULE hModule)
{
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    FreeLibraryAndExitThread(hModule, 0);
}

bool SetHooks()
{
    if (MH_Initialize() != MH_OK) return false;


}

// the main entrypoint
uintptr_t Entry(HMODULE hModule)
{
    if (!SetHooks())
        goto Exit;

    for (;;)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            break;
        }
		Sleep(100);
    }

Exit:
	Cleanup(hModule);
	return 0;
}