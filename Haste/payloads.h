#pragma once
#include "haste.h"

VOID WINAPI AudioSequence1(VOID);
VOID WINAPI AudioSequence2(VOID);

VOID WINAPI AudioSequence3(VOID);
VOID WINAPI AudioSequence4(VOID);

DWORD WINAPI GdiPayload1(LPVOID lpVoidParam);
DWORD WINAPI GdiPayload2(LPVOID lpVoidParam);

DWORD WINAPI GdiPayload3(LPVOID lpVoidParam);
DWORD WINAPI PostGdiPayload3(LPVOID lpVoidParam);

DWORD WINAPI GdiPayload4(LPVOID lpVoidParam);
DWORD WINAPI FinalGdiPayload(LPVOID lpVoidParam);