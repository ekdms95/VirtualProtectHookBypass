# VirtualProtectHookBypass

Bypass WinAPI Hook via Directly syscall

How can Directly Syscall ?
-> copy function using assembly

Just directly syscalling ZwProtectVirtualMemory instead of calling the export to syscall in ntdll.dll.

call directly via using assembly.

it can't not be hooked by anything except the kernel mode functions.

This example is for x86.

[ Ntdll.dll ] ZwProtectVirtualMemory
![image](https://user-images.githubusercontent.com/13113619/119382779-788a2800-bcfd-11eb-84a9-832bf0563d51.png)

[ Kernel.dll ] VirtualProtect
![image](https://user-images.githubusercontent.com/13113619/119382654-4bd61080-bcfd-11eb-8e4f-b0577b203271.png)

