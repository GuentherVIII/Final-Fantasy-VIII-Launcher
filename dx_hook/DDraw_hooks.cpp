/*
Final Fantasy VIII Launcher
Copyright 2007, 2008 Tobias Sebring


This file is part of Final Fantasy VII Launcher.

Final Fantasy VII Launcher is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3.

Final Fantasy VII Launcher is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Final Fantasy VII Launcher.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "DDRAW_hooks.h"
#include "DDRAW4_hooks.h"
#include "ddrawpalette_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK ddraw_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAW_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAW_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAW_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "Compact",				0x0C, NULL, (PDWORD)DDRAW_HOOK_Compact },
/*4*/	{ "CreateClipper",			0x10, NULL, (PDWORD)DDRAW_HOOK_CreateClipper },
/*5*/	{ "CreatePalette",			0x14, NULL, (PDWORD)DDRAW_HOOK_CreatePalette },
/*6*/	{ "CreateSurface",			0x18, NULL, (PDWORD)DDRAW_HOOK_CreateSurface },
/*7*/	{ "DuplicateSurface",		0x1C, NULL, (PDWORD)DDRAW_HOOK_DuplicateSurface },
/*8*/	{ "EnumDisplayModes",		0x20, NULL, (PDWORD)DDRAW_HOOK_EnumDisplayModes },
/*9*/	{ "EnumSurfaces",			0x24, NULL, (PDWORD)DDRAW_HOOK_EnumSurfaces },
/*10*/	{ "FlipToGDISurface",		0x28, NULL, (PDWORD)DDRAW_HOOK_FlipToGDISurface },
/*11*/	{ "GetCaps",				0x2C, NULL, (PDWORD)DDRAW_HOOK_GetCaps },
/*12*/	{ "GetDisplayMode",			0x30, NULL, (PDWORD)DDRAW_HOOK_GetDisplayMode },
/*13*/	{ "GetFourCCCodes",			0x34, NULL, (PDWORD)DDRAW_HOOK_GetFourCCCodes },
/*14*/	{ "GetGDISurface",			0x38, NULL, (PDWORD)DDRAW_HOOK_GetGDISurface },
/*15*/	{ "GetMonitorFrequency",	0x3C, NULL, (PDWORD)DDRAW_HOOK_GetMonitorFrequency },
/*16*/	{ "GetScanLine",			0x40, NULL, (PDWORD)DDRAW_HOOK_GetScanLine },
/*17*/	{ "GetVerticalBlankStatus",	0x44, NULL, (PDWORD)DDRAW_HOOK_GetVerticalBlankStatus },
/*18*/	{ "Initialize",				0x48, NULL, (PDWORD)DDRAW_HOOK_Initialize },
/*19*/	{ "RestoreDisplayMode",		0x4C, NULL, (PDWORD)DDRAW_HOOK_RestoreDisplayMode },
/*20*/	{ "SetCooperativeLevel",	0x50, NULL, (PDWORD)DDRAW_HOOK_SetCooperativeLevel },
/*21*/	{ "SetDisplayMode",			0x54, NULL, (PDWORD)DDRAW_HOOK_SetDisplayMode },
/*22*/	{ "WaitForVerticalBlank",	0x58, NULL, (PDWORD)DDRAW_HOOK_WaitForVerticalBlank }
};
#else
SVTBL_HOOK ddraw_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAW_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAW_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAW_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "Compact",				0x0C, NULL, (PDWORD)DDRAW_HOOK_Compact },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "CreateClipper",			0x10, NULL, (PDWORD)DDRAW_HOOK_CreateClipper },
/*5*/	{ "CreatePalette",			0x14, NULL, (PDWORD)DDRAW_HOOK_CreatePalette },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "CreateSurface",			0x18, NULL, (PDWORD)DDRAW_HOOK_CreateSurface },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "DuplicateSurface",		0x1C, NULL, (PDWORD)DDRAW_HOOK_DuplicateSurface },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "EnumDisplayModes",		0x20, NULL, (PDWORD)DDRAW_HOOK_EnumDisplayModes },
/*9*/	{ NULL, 0, NULL, NULL },	//{ "EnumSurfaces",			0x24, NULL, (PDWORD)DDRAW_HOOK_EnumSurfaces },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "FlipToGDISurface",		0x28, NULL, (PDWORD)DDRAW_HOOK_FlipToGDISurface },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "GetCaps",				0x2C, NULL, (PDWORD)DDRAW_HOOK_GetCaps },
/*12*/	{ NULL, 0, NULL, NULL },	//{ "GetDisplayMode",			0x30, NULL, (PDWORD)DDRAW_HOOK_GetDisplayMode },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "GetFourCCCodes",			0x34, NULL, (PDWORD)DDRAW_HOOK_GetFourCCCodes },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "GetGDISurface",			0x38, NULL, (PDWORD)DDRAW_HOOK_GetGDISurface },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "GetMonitorFrequency",	0x3C, NULL, (PDWORD)DDRAW_HOOK_GetMonitorFrequency },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "GetScanLine",			0x40, NULL, (PDWORD)DDRAW_HOOK_GetScanLine },
/*17*/	{ NULL, 0, NULL, NULL },	//{ "GetVerticalBlankStatus",	0x44, NULL, (PDWORD)DDRAW_HOOK_GetVerticalBlankStatus },
/*18*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x48, NULL, (PDWORD)DDRAW_HOOK_Initialize },
/*19*/	{ NULL, 0, NULL, NULL },	//{ "RestoreDisplayMode",		0x4C, NULL, (PDWORD)DDRAW_HOOK_RestoreDisplayMode },
/*20*/	{ NULL, 0, NULL, NULL },	//{ "SetCooperativeLevel",	0x50, NULL, (PDWORD)DDRAW_HOOK_SetCooperativeLevel },
/*21*/	{ NULL, 0, NULL, NULL },	//{ "SetDisplayMode",			0x54, NULL, (PDWORD)DDRAW_HOOK_SetDisplayMode },
/*22*/	{ NULL, 0, NULL, NULL },	//{ "WaitForVerticalBlank",	0x58, NULL, (PDWORD)DDRAW_HOOK_WaitForVerticalBlank }
};
#endif
const unsigned int count_ddraw_hooks = 23;
bool ishooked_ddraw_hooks = false;

HRESULT __stdcall DDRAW_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	DDRAW_QueryInterface_Type ofn = (DDRAW_QueryInterface_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectDraw::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", ddraw_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);
	if(ret == S_OK && riid == IID_IDirectDraw4 && ishooked_ddraw4_hooks == false) {
		HookVTBLCalls(ppvObj, ddraw4_hooks, count_ddraw4_hooks, "IDirectDraw4");
		ishooked_ddraw4_hooks = true;
	}

	return ret;
}

ULONG __stdcall DDRAW_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	DDRAW_AddRef_Type ofn = (DDRAW_AddRef_Type)ddraw_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

//HOOKING RELEASE CAUSES FF8 TO CRASH TRYING TO DEREFERENCE A NULL POINTER AT SHUTDOWN (REASON: UNKNOWN...)
ULONG __stdcall DDRAW_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	DDRAW_Release_Type ofn = (DDRAW_Release_Type)ddraw_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDraw::%s(%#010lx)\n", ddraw_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_Compact(LPVOID *ppvOut) {
	const unsigned int hpos = 3;

	//not implemented in ddraw4
	return (HRESULT)0;
}

HRESULT __stdcall DDRAW_HOOK_CreateClipper(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter) {
	const unsigned int hpos = 4;

	DDRAW_CreateClipper_Type ofn = (DDRAW_CreateClipper_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lplpDDClipper, pUnkOuter);
	LogDXError(ret);

	Log("IDirectDraw::%s(this=%#010lx, dwFlags=%#010lx, lplpDDClipper=%#010lx *[%#010lx], pUnkOuter=%#010lx)\n", ddraw_hooks[hpos].name, ppvOut, dwFlags, lplpDDClipper, (lplpDDClipper != NULL ? *lplpDDClipper : NULL), pUnkOuter);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_CreatePalette(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter) {
	const unsigned int hpos = 5;

	DDRAW_CreatePalette_Type ofn = (DDRAW_CreatePalette_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDColorArray, lplpDDPalette, pUnkOuter);
	LogDXError(ret);

	char dwFlags_buffer[LOGBUFFER_MAX];
	FlagsToString(FLAGS_DDPCAPS, CFLAGS_DDPCAPS, dwFlags, (char *)&dwFlags_buffer, LOGBUFFER_MAX);
	Log("IDirectDraw::%s(this=%#010lx, dwFlags=%#010lx (%s), lpDDColorArray=%#010lx, lplpDDPalette=%#010lx *[%#010lx], pUnkOuter=%#010lx)\n", ddraw_hooks[hpos].name, ppvOut, dwFlags, dwFlags_buffer, lpDDColorArray, lplpDDPalette, (lplpDDPalette != NULL ? *lplpDDPalette : NULL), pUnkOuter);
	if(ishooked_ddrawpalette_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpDDPalette, ddrawpalette_hooks, count_ddrawpalette_hooks, "IDirectDrawPalette");
		ishooked_ddrawpalette_hooks = true;
	}
	return ret;
}

HRESULT __stdcall DDRAW_HOOK_CreateSurface(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR *lplpDDSurface, IUnknown FAR *pUnkOuter) {
	const unsigned int hpos = 6;

	DDRAW_CreateSurface_Type ofn = (DDRAW_CreateSurface_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_DuplicateSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface) {
	const unsigned int hpos = 7;

	DDRAW_DuplicateSurface_Type ofn = (DDRAW_DuplicateSurface_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurface, lplpDupDDSurface);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_EnumDisplayModes(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback) {
	const unsigned int hpos = 8;

	DDRAW_EnumDisplayModes_Type ofn = (DDRAW_EnumDisplayModes_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_EnumSurfaces(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) {
	const unsigned int hpos = 9;

	DDRAW_EnumSurfaces_Type ofn = (DDRAW_EnumSurfaces_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_FlipToGDISurface(LPVOID *ppvOut) {
	const unsigned int hpos = 10;

	DDRAW_FlipToGDISurface_Type ofn = (DDRAW_FlipToGDISurface_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetCaps(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps) {
	const unsigned int hpos = 11;

	DDRAW_GetCaps_Type ofn = (DDRAW_GetCaps_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDDriverCaps, lpDDHELCaps);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetDisplayMode(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc2) {
	const unsigned int hpos = 12;

	DDRAW_GetDisplayMode_Type ofn = (DDRAW_GetDisplayMode_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceDesc2);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetFourCCCodes(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes) {
	const unsigned int hpos = 13;

	DDRAW_GetFourCCCodes_Type ofn = (DDRAW_GetFourCCCodes_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpNumCodes, lpCodes);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetGDISurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE FAR *lplpGDIDDSurface) {
	const unsigned int hpos = 14;

	DDRAW_GetGDISurface_Type ofn = (DDRAW_GetGDISurface_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpGDIDDSurface);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetMonitorFrequency(LPVOID *ppvOut, LPDWORD lpdwFrequency) {
	const unsigned int hpos = 15;

	DDRAW_GetMonitorFrequency_Type ofn = (DDRAW_GetMonitorFrequency_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwFrequency);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetScanLine(LPVOID *ppvOut, LPDWORD lpdwScanLine) {
	const unsigned int hpos = 16;

	DDRAW_GetScanLine_Type ofn = (DDRAW_GetScanLine_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwScanLine);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_GetVerticalBlankStatus(LPVOID *ppvOut, LPBOOL lpbIsInVB) {
	const unsigned int hpos = 17;

	DDRAW_GetVerticalBlankStatus_Type ofn = (DDRAW_GetVerticalBlankStatus_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpbIsInVB);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_Initialize(LPVOID *ppvOut, GUID FAR *lpGUID) {
	const unsigned int hpos = 18;

	DDRAW_Initialize_Type ofn = (DDRAW_Initialize_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpGUID);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_RestoreDisplayMode(LPVOID *ppvOut) {
	const unsigned int hpos = 19;

	DDRAW_RestoreDisplayMode_Type ofn = (DDRAW_RestoreDisplayMode_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDraw::%s(this=%#010lx)\n", ddraw_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags) {
	const unsigned int hpos = 20;

	DDRAW_SetCooperativeLevel_Type ofn = (DDRAW_SetCooperativeLevel_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hWnd, dwFlags);
	LogDXError(ret);

	Log("IDirectDraw::%s(this=%#010lx, hWnd=%#010lx, dwFlags=%#010lx)\n", ddraw_hooks[hpos].name, ppvOut, hWnd, dwFlags);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_SetDisplayMode(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP) {
	const unsigned int hpos = 21;

	DDRAW_SetDisplayMode_Type ofn = (DDRAW_SetDisplayMode_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwWidth, dwHeight, dwBPP);
	LogDXError(ret);

	Log("IDirectDraw::%s(this=%#010lx, dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), dwBPP=%#010lx (%d))\n", ddraw_hooks[hpos].name, ppvOut, dwWidth, dwWidth, dwHeight, dwHeight, dwBPP, dwBPP);

	return ret;
}

HRESULT __stdcall DDRAW_HOOK_WaitForVerticalBlank(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent) {
	const unsigned int hpos = 22;

	DDRAW_WaitForVerticalBlank_Type ofn = (DDRAW_WaitForVerticalBlank_Type)ddraw_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, hEvent);
	LogDXError(ret);

	Log("IDirectDraw::%s()\n", ddraw_hooks[hpos].name);

	return ret;
}