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

#include "ddrawpalette_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK ddrawpalette_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAWPALETTE_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAWPALETTE_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAWPALETTE_HOOK_Release },
/*3*/	{ "GetCaps",				0x0C, NULL, (PDWORD)DDRAWPALETTE_HOOK_GetCaps },
/*4*/	{ "GetEntries",				0x10, NULL, (PDWORD)DDRAWPALETTE_HOOK_GetEntries },
/*5*/	{ "Initialize",				0x14, NULL, (PDWORD)DDRAWPALETTE_HOOK_Initialize },
/*6*/	{ "SetEntries",				0x18, NULL, (PDWORD)DDRAWPALETTE_HOOK_SetEntries },
};
#else
SVTBL_HOOK ddrawpalette_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAWPALETTE_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAWPALETTE_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAWPALETTE_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "GetCaps",				0x0C, NULL, (PDWORD)DDRAWPALETTE_HOOK_GetCaps },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "GetEntries",				0x10, NULL, (PDWORD)DDRAWPALETTE_HOOK_GetEntries },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x14, NULL, (PDWORD)DDRAWPALETTE_HOOK_Initialize },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "SetEntries",				0x18, NULL, (PDWORD)DDRAWPALETTE_HOOK_SetEntries },
};
#endif
const unsigned int count_ddrawpalette_hooks = 7;
bool ishooked_ddrawpalette_hooks = false;

HRESULT __stdcall DDRAWPALETTE_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	DDRAWPALETTE_QueryInterface_Type ofn = (DDRAWPALETTE_QueryInterface_Type)ddrawpalette_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectDrawPalette::%s(this=%#010lx, riid={ %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, ppvObj%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall DDRAWPALETTE_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	DDRAWPALETTE_AddRef_Type ofn = (DDRAWPALETTE_AddRef_Type)ddrawpalette_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDrawPalette::%s(this=%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut);

	return ret;
}

ULONG __stdcall DDRAWPALETTE_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	DDRAWPALETTE_Release_Type ofn = (DDRAWPALETTE_Release_Type)ddrawpalette_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDrawPalette::%s(this=%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DDRAWPALETTE_HOOK_GetCaps(LPVOID *ppvOut, LPDWORD lpdwCaps) {
	const unsigned int hpos = 3;

	DDRAWPALETTE_GetCaps_Type ofn = (DDRAWPALETTE_GetCaps_Type)ddrawpalette_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdwCaps);
	LogDXError(ret);

	char dwCaps_buffer[LOGBUFFER_MAX];
	if(lpdwCaps != NULL) FlagsToString(FLAGS_DDPCAPS, CFLAGS_DDPCAPS, *lpdwCaps, (char *)&dwCaps_buffer, LOGBUFFER_MAX);
	Log("IDirectDrawPalette::%s(this=%#010lx, lpdwCaps=%#010lx *[%#010lx]%s%s%s)\n", ddrawpalette_hooks[hpos].name, ppvOut, lpdwCaps, (lpdwCaps != NULL ? *lpdwCaps : NULL), (lpdwCaps != NULL ? " (" : ""), dwCaps_buffer, (lpdwCaps != NULL ? ")" : ""));

	return ret;
}

HRESULT __stdcall DDRAWPALETTE_HOOK_GetEntries(LPVOID *ppvOut, DWORD dwFlags, DWORD dwBase, DWORD dwNumEntries, LPPALETTEENTRY lpEntries) {
	const unsigned int hpos = 4;

	DDRAWPALETTE_GetEntries_Type ofn = (DDRAWPALETTE_GetEntries_Type)ddrawpalette_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, dwBase, dwNumEntries, lpEntries);
	LogDXError(ret);

	Log("IDirectDrawPalette::%s(this=%#010lx, dwFlags=%#010lx, dwBase=%#010lx, dwNumEntries=%#010lx (%d), lpEntries=%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut, dwFlags, dwBase, dwNumEntries, dwNumEntries, lpEntries);

	return ret;
}

HRESULT __stdcall DDRAWPALETTE_HOOK_Initialize(LPVOID *ppvOut, LPDIRECTDRAW lpDD, DWORD dwFlags, LPPALETTEENTRY lpDDColorTable) {
	const unsigned int hpos = 5;

	DDRAWPALETTE_Initialize_Type ofn = (DDRAWPALETTE_Initialize_Type)ddrawpalette_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDD, dwFlags, lpDDColorTable);
	LogDXError(ret);

	Log("IDirectDrawPalette::%s(this=%#010lx, lpDD=%#010lx, dwFlags=%#010lx, lpDDColorTable=%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut, lpDD, dwFlags, lpDDColorTable);

	return ret;
}

HRESULT __stdcall DDRAWPALETTE_HOOK_SetEntries(LPVOID *ppvOut, DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries) {
	const unsigned int hpos = 6;

	DDRAWPALETTE_SetEntries_Type ofn = (DDRAWPALETTE_SetEntries_Type)ddrawpalette_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, dwStartingEntry, dwCount, lpEntries);
	LogDXError(ret);

	Log("IDirectDrawPalette::%s(this=%#010lx, dwFlags=%#010lx, dwStartingEntry=%#010lx, dwCount=%#010lx (%d), lpEntries=%#010lx)\n", ddrawpalette_hooks[hpos].name, ppvOut, dwFlags, dwStartingEntry, dwCount, dwCount, lpEntries);

	return ret;
}