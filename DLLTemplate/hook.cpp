#include "Hook.hpp"

Hook::Hook(const char* moduleName, uintptr_t offset, LPVOID detour, LPVOID* original)
    : m_detour(detour), m_original(original), m_target(nullptr) {

    auto base = reinterpret_cast<uintptr_t>(GetModuleHandleA(moduleName));
    if (!base) return;

    m_target = reinterpret_cast<LPVOID>(base + offset);

    MH_CreateHook(m_target, m_detour, m_original);
}

Hook::~Hook() {
    Disable();
    MH_RemoveHook(m_target);
}

auto Hook::Enable() -> bool {
    auto status = MH_EnableHook(m_target);
    return status == MH_OK;
}

auto Hook::Disable() -> bool {
    auto status = MH_DisableHook(m_target);
    return status == MH_OK;
}