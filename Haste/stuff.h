#pragma once
#include "haste.h"

LPCWSTR GetRandomizedPath(VOID);
VOID WINAPI EndGdiPayload(HANDLE hGdiPayload, HANDLE hHeapGdiPayload);

DWORD WINAPI CursorMoveThread(LPVOID lpCursorThread);
DWORD WINAPI MoveWindowThread(LPVOID lpWindowThread);