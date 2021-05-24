void* NtdllAddress = GetProcAddress(GetModuleHandleA(xorstr_("ntdll.dll")), xorstr_("RtlInterlockedCompareExchange64"));
void* KernelAddress = GetProcAddress(GetModuleHandleA(xorstr_("kernel.dll")), xorstr_("GetSystemLeapSecondInformation"));

DWORD ntdll170 = (DWORD)NtdllAddress + 0x170;
DWORD KernelEC85 = (DWORD)KernelAddress + 0xEC85;

void __declspec(naked) CopyZwVirtualProtect() // ZwVirtualProtectMemory 함수 복사.
{
	__asm
	{
		mov eax, 0x50
		mov edx, ntdll170 // ntdll.RtlInterlockedCompareExchange64 + 170
		call edx
		ret 0x14
	}
}

BOOL __declspec(naked) __cdecl CopyVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) // VirtualProtect 함수 복사.
{
	__asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		push ecx
		push ecx
		mov eax, [ebp + 0xC]
		push esi
		push[ebp + 0x14]
		mov[ebp - 4], eax
		push[ebp + 0x10]
		mov eax, [ebp + 8]
		mov[ebp - 8], eax
		lea eax, [ebp - 4]
		push eax
		lea eax, [ebp - 8]
		push eax
		push - 1
		call CopyZwVirtualProtect // asm으로 복사했던 ZwVirtualProtectMemory 함수 호출.
		mov esi, eax
		test esi, esi
		js KK //KERNELBASE.GetSystemLeapSecondInformation + EC85 
		xor eax, eax
		inc eax
		pop esi
		leave
		ret 0x10

		KK:
		jmp KernelEC85
	}
}

void WhatTheFuckRiotEAC()
{
  // CopyVirtualProtect((PVOID*)og_fun, 1, (PAGE_EXECUTE_READ | PAGE_GUARD), &oldProtection);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        WhatTheFuckRiot();
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) {}

    return TRUE;
}
