#include "stdafx.h"

VOID Main()
{
    MH_Initialize();

    SettingsHelper::LoadDefaultConfig();

    if (!Util::Initialize()) {
        return;
    }

    if (!offsets::Initialize()) {
        return;
    }
    if (!hooks::Initialize()) {
        return;
    }

    if (!rend::Initialize()) {
        return;
    }
}



BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
       // Util::CreateConsole();
       Main();
    }

    return TRUE;
}