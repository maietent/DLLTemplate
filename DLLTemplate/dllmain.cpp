#include "entry.hpp"

BOOL WINAPI DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved) 
{
    switch (fdwReason) 
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        auto hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Entry, hModule, 0, nullptr);
        if (hThread != nullptr)
        {
            CloseHandle(hThread);
        }
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}