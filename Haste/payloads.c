#include "haste.h"

VOID WINAPI AudioSequence1(VOID) {
	HWAVEOUT hWaveout = 0;
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, 38000, 38000, 1, 8, 0 };

	waveOutOpen(&hWaveout, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
	CONST DWORD dwSoundLength = 38000 * 20;
	CHAR* cBuffer = (CHAR*)HeapAlloc(GetProcessHeap(), 0, dwSoundLength);

	for (DWORD t = 0; t < dwSoundLength; t++) {
		cBuffer[t] = ((t & t >> 8) * (t >> 3 ^ 7)) + ((t >> 8 ^ t >> 7) & 187);
	}

	WAVEHDR waveHeader = { 0 };
	waveHeader.lpData = cBuffer;
	waveHeader.dwBufferLength = dwSoundLength;

	waveOutPrepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutWrite(hWaveout, &waveHeader, sizeof(WAVEHDR));

	while (!(waveHeader.dwFlags & WHDR_DONE)) {
		Sleep(10);
	}

	waveOutUnprepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutClose(hWaveout);

	HeapFree(GetProcessHeap(), 0, cBuffer);
	Sleep(10);
}

VOID WINAPI AudioSequence2(VOID) {
	HWAVEOUT hWaveout = 0;
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, 38000, 38000, 1, 8, 0 };

	waveOutOpen(&hWaveout, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
	CONST DWORD dwSoundLength = 38000 * 20;
	CHAR* cBuffer = (CHAR*)HeapAlloc(GetProcessHeap(), 0, dwSoundLength);

	for (DWORD t = 0; t < dwSoundLength; t++) {
		cBuffer[t] = (t * ((t >> 9 | t >> 7) & (t >> 11))) + ((t >> 5 ^ t >> 3) & 127) + ((t >> 13) * (t & 63));
	}

	WAVEHDR waveHeader = { 0 };
	waveHeader.lpData = cBuffer;
	waveHeader.dwBufferLength = dwSoundLength;

	waveOutPrepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutWrite(hWaveout, &waveHeader, sizeof(WAVEHDR));

	while (!(waveHeader.dwFlags & WHDR_DONE)) {
		Sleep(10);
	}

	waveOutUnprepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutClose(hWaveout);

	HeapFree(GetProcessHeap(), 0, cBuffer);
	Sleep(10);
}

VOID WINAPI AudioSequence3(VOID) {
	HWAVEOUT hWaveout = 0;
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, 38000, 38000, 1, 8, 0 };

	waveOutOpen(&hWaveout, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
	CONST DWORD dwSoundLength = 38000 * 30;
	CHAR* cBuffer = (CHAR*)HeapAlloc(GetProcessHeap(), 0, dwSoundLength);

	for (DWORD t = 0; t < dwSoundLength; t++) {
		cBuffer[t] = (t >> 6 ^ t >> 8) * (t >> 5 | t >> 7);
	}

	WAVEHDR waveHeader = { 0 };
	waveHeader.lpData = cBuffer;
	waveHeader.dwBufferLength = dwSoundLength;

	waveOutPrepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutWrite(hWaveout, &waveHeader, sizeof(WAVEHDR));

	while (!(waveHeader.dwFlags & WHDR_DONE)) {
		Sleep(10);
	}

	waveOutUnprepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutClose(hWaveout);

	HeapFree(GetProcessHeap(), 0, cBuffer);
	Sleep(10);
}

VOID WINAPI AudioSequence4(VOID) {
	HWAVEOUT hWaveout = 0;
	WAVEFORMATEX waveFormat = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };

	waveOutOpen(&hWaveout, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL);
	CONST DWORD dwSoundLength = 32000 * 20;
	CHAR* cBuffer = (CHAR*)HeapAlloc(GetProcessHeap(), 0, dwSoundLength);

	for (DWORD t = 0; t < dwSoundLength; t++) {
		cBuffer[t] = (t & (t >> 5) * (t >> 9)) & 255;
	}

	WAVEHDR waveHeader = { 0 };
	waveHeader.lpData = cBuffer;
	waveHeader.dwBufferLength = dwSoundLength;

	waveOutPrepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutWrite(hWaveout, &waveHeader, sizeof(WAVEHDR));

	while (!(waveHeader.dwFlags & WHDR_DONE)) {
		Sleep(10);
	}

	waveOutUnprepareHeader(hWaveout, &waveHeader, sizeof(WAVEHDR));
	waveOutClose(hWaveout);

	HeapFree(GetProcessHeap(), 0, cBuffer);
	Sleep(10);
}

DWORD WINAPI GdiPayload1(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;

	PRGBQUAD prgb = { 0 };
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (VOID**)&prgb, NULL, 0);
	SelectObject(hdcCopy, hBitmap);

	while (TRUE) {
		hdc = GetDC(NULL);
		BitBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);
		for (INT i = 0; i < screenWidth * screenHeight; i++) {
			INT x = i % screenWidth, y = i / screenWidth;
			prgb[i].nRGB += (x + y >> x * 23);
		}
		BitBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, SRCCOPY);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
	}
	return 0x00;
}

DWORD WINAPI GdiPayload2(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;

	RGBQUAD* rgb = NULL;
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (VOID**)&rgb, NULL, 0);
	SelectObject(hdcCopy, hBitmap);

	while (TRUE) {
		hdc = GetDC(NULL);
		BitBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);
		for (INT i = 0; i < screenWidth * screenHeight; i++) {
			INT x = i % screenWidth, y = i / screenWidth;
			INT nIndex = y * screenWidth + x;

			INT shaderFX = sqrt(x & y);

			rgb[nIndex].rgbRed += (shaderFX);
			rgb[nIndex].rgbGreen += (shaderFX + 32);
			rgb[nIndex].rgbBlue += (shaderFX + 64);
		}
		BitBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, SRCCOPY);
		StretchBlt(hdc, rand() % 3, rand() % 3, screenWidth, screenHeight, hdcCopy, rand() % 3, rand() % 3, screenWidth, screenHeight, SRCCOPY);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
	}
	return 0x00;
}

DWORD WINAPI GdiPayload3(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;

	RGBQUAD* rgb = NULL;
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (VOID**)&rgb, NULL, 0);
	SelectObject(hdcCopy, hBitmap);

	while (TRUE) {
		hdc = GetDC(NULL);
		BitBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);
		for (INT i = 0; i < screenWidth * screenHeight; i++) {
			INT x = i % screenWidth, y = i / screenWidth;
			INT nIndex = y * screenWidth + x;

			INT shaderFX = sqrt(x ^ y);

			rgb[nIndex].rgbRed = (shaderFX);
			rgb[nIndex].rgbGreen += (shaderFX ^ 32);
			rgb[nIndex].rgbBlue = (shaderFX + 64);
		}
		BitBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, SRCCOPY);
		StretchBlt(hdc, rand() % 3, rand() % 3, screenWidth, screenHeight, hdcCopy, rand() % 3, rand() % 3, screenWidth, screenHeight, SRCCOPY);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
	}
	return 0x00;
}

DWORD WINAPI PostGdiPayload3(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	INT sx = 0, poseX = 5;
	INT sy = 0, poseY = 6;

	while (TRUE) {
		hdc = GetDC(NULL);

		DrawIcon(hdc, sx, sy, LoadIcon(NULL, IDI_APPLICATION));
		sx += poseX;
		sy += poseY;

		if (sx <= 0 || sx >= screenWidth) {
			poseX = -poseX;
		}

		if (sy <= 0 || sy >= screenHeight) {
			poseY = -poseY;
		}

		ReleaseDC(NULL, hdc);
		Sleep(1);
	}
}

DWORD WINAPI GdiPayload4(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;

	RGBQUAD* rgb = NULL;
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (VOID**)&rgb, NULL, 0);
	SelectObject(hdcCopy, hBitmap);

	while (TRUE) {
		hdc = GetDC(NULL);
		BitBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);
		for (INT i = 0; i < screenWidth * screenHeight; i++) {
			INT x = i % screenWidth, y = i / screenWidth;
			INT nIndex = y * screenWidth + x;

			INT shaderFX = sqrt(x ^ y);

			rgb[nIndex].rgbRed ^= (shaderFX);
			rgb[nIndex].rgbGreen += (shaderFX);
			rgb[nIndex].rgbBlue *= (shaderFX);
		}
		BitBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, SRCCOPY);
		StretchBlt(hdc, rand() % 3, rand() % 3, screenWidth, screenHeight, hdcCopy, rand() % 3, rand() % 3, screenWidth, screenHeight, SRCCOPY);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
	}
	return 0x00;
}

DWORD WINAPI FinalGdiPayload(LPVOID lpVoidParam) {
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	CONST INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	CONST INT screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;

	PRGBQUAD prgb = { 0 };
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (VOID**)&prgb, NULL, 0);
	SelectObject(hdcCopy, hBitmap);

	while (TRUE) {
		hdc = GetDC(NULL);
		BitBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);
		for (INT i = 0; i < screenWidth * screenHeight; i++) {
			INT x = i % screenWidth, y = i / screenWidth;
			prgb[i].nRGB = (rand() % 0x100) * 0x010101;
		}
		BitBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, SRCCOPY);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
	}
	return 0x00;
}