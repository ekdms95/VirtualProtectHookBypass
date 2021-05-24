# VirtualProtectHookBypass

Bypass WinAPI Hook Using copy function

유저모드 안티치트나 API 후킹을 통하여 해당함수를 못쓰게 막아놓은경우

어셈블리어를 이용하여 해당 함수를 복사하게되면 손쉽게 우회가 가능하다.

[ Ntdll.dll ] ZwProtectVirtualMemory
![image](https://user-images.githubusercontent.com/13113619/119382779-788a2800-bcfd-11eb-84a9-832bf0563d51.png)

[ Kernel.dll ] VirtualProtect
![image](https://user-images.githubusercontent.com/13113619/119382654-4bd61080-bcfd-11eb-8e4f-b0577b203271.png)

