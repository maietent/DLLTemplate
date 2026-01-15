#pragma once

#include <Windows.h>
#include "MinHook.h"

class Hook {
public:
    Hook(const char* moduleName, uintptr_t offset, LPVOID detour, LPVOID* original);
    ~Hook();

    auto Enable() -> bool;
    auto Disable() -> bool;

private:
    LPVOID m_target;
    LPVOID m_detour;
    LPVOID* m_original;
};