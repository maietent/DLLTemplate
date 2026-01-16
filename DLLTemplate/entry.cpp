#include "entry.hpp"
#include <MinHook.h>

auto Cleanup(HMODULE hModule) -> void
{
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    FreeLibraryAndExitThread(hModule, 0);
}

auto SetHooks() -> bool
{
    if (MH_Initialize() != MH_OK) return false;


}

// the main entrypoint
auto Entry(HMODULE hModule) -> uintptr_t
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