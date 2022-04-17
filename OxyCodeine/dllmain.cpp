#include "Globals/includes.h"





/*

Maybe one day I will be important to everyone like they are to me, that would be nice!
because I'm getting so lonely and I feel invisible. I'm trying so hard to stay positive. Please care.

~ Dawg

*/


__int64 m_state = {  };
auto loadfile = (__int64 (*)(__int64 instance, char* a2, __int64 a3))((uintptr_t)LI_MODULE("citizen-scripting-lua.dll").cached<HMODULE>() + 114528); //0x1BF60

DWORD WINAPI HelpMe() {
    while (!m_state) {
		Sleep(10); // for not killing cpu
		auto sc_lua = LI_MODULE("citizen-scripting-lua.dll").cached<HMODULE>();
        auto runtime = Mem::Read<uintptr_t>((uintptr_t)sc_lua + 0xE9218); // + 0x50 to hit lua reg heap
		m_state = Mem::Read<uintptr_t>(runtime + 0x10);

		
    }
    if (m_state > 1) {
        try
        {
            loadfile((__int64)m_state, _strdup("c://nigger.lua"), 0x0);
        }
        catch (const std::exception&)
        {
            Sleep(10);
        }
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HelpMe, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

