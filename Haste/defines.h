#pragma once
#include "haste.h"

typedef union _RGBQUAD {
	COLORREF nRGB;
	struct {
		BYTE Red;
		BYTE Green;
		BYTE Blue;
		BYTE bUnused;
	};
} *PRGBQUAD;