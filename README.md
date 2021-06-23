# VirtualProtectHookBypass

### Bypass IAT Hook via Directly syscall

### How can Directly Syscall ?
  * Copy Function via using assembly

* Just directly syscalling ZwProtectVirtualMemory instead of calling the export to syscall in ntdll.dll.

* it can't not be hooked by anything except the Hooking man in kernelland

* This example is for x86.

### if you want to use on x64

 1. Check masm Compile option.
 2. make a .asm file on project
 3. code on .asm file
 4. Profit

### [ Ntdll.dll ] ZwProtectVirtualMemory

![image](https://user-images.githubusercontent.com/13113619/119382779-788a2800-bcfd-11eb-84a9-832bf0563d51.png)

### [ Kernel.dll ] VirtualProtect

![image](https://user-images.githubusercontent.com/13113619/119382654-4bd61080-bcfd-11eb-8e4f-b0577b203271.png)

# Credit
me (Ekdms95)
and
I will give some credit for sexyyume
