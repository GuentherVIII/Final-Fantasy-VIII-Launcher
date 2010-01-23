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

#include "d3dtexture2_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3dtexture2_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3DTEXTURE2_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DTEXTURE2_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DTEXTURE2_HOOK_Release },
/*3*/	{ "GetHandle",				0x0C, NULL, (PDWORD)D3DTEXTURE2_HOOK_GetHandle },
/*4*/	{ "PaletteChanged",				0x10, NULL, (PDWORD)D3DTEXTURE2_HOOK_PaletteChanged },
/*5*/	{ "Load",				0x14, NULL, (PDWORD)D3DTEXTURE2_HOOK_Load }
};
#else
SVTBL_HOOK d3dtexture2_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)D3DTEXTURE2_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DTEXTURE2_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DTEXTURE2_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "GetHandle",				0x0C, NULL, (PDWORD)D3DTEXTURE2_HOOK_GetHandle },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "PaletteChanged",				0x10, NULL, (PDWORD)D3DTEXTURE2_HOOK_PaletteChanged },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "Load",				0x14, NULL, (PDWORD)D3DTEXTURE2_HOOK_Load }
};
#endif
const unsigned int count_d3dtexture2_hooks = 6;
bool ishooked_d3dtexture2_hooks = false;

HRESULT __stdcall D3DTEXTURE2_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3DTEXTURE2_QueryInterface_Type ofn = (D3DTEXTURE2_QueryInterface_Type)d3dtexture2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3DTexture2::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx *[%#010lx])\n", d3dtexture2_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj, *ppvObj);

	return ret;
}

ULONG __stdcall D3DTEXTURE2_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3DTEXTURE2_AddRef_Type ofn = (D3DTEXTURE2_AddRef_Type)d3dtexture2_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DTexture2::%s()\n", d3dtexture2_hooks[hpos].name);

	return ret;
}

ULONG __stdcall D3DTEXTURE2_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3DTEXTURE2_Release_Type ofn = (D3DTEXTURE2_Release_Type)d3dtexture2_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DTexture2::%s(%#010lx)\n", d3dtexture2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DTEXTURE2_HOOK_GetHandle(LPVOID *ppvOut, LPDIRECT3DDEVICE2 lpDirect3DDevice2, LPD3DTEXTUREHANDLE lpHandle) {
	const unsigned int hpos = 3;

	D3DTEXTURE2_GetHandle_Type ofn = (D3DTEXTURE2_GetHandle_Type)d3dtexture2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DDevice2, lpHandle);
	LogDXError(ret);

	Log("IDirect3DTexture2::%s()\n", d3dtexture2_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DTEXTURE2_HOOK_PaletteChanged(LPVOID *ppvOut, DWORD dwStart, DWORD dwCount) {
	const unsigned int hpos = 4;

	D3DTEXTURE2_PaletteChanged_Type ofn = (D3DTEXTURE2_PaletteChanged_Type)d3dtexture2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwStart, dwCount);
	LogDXError(ret);

	Log("IDirect3DTexture2::%s()\n", d3dtexture2_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3DTEXTURE2_HOOK_Load(LPVOID *ppvOut, LPDIRECT3DTEXTURE2 lpD3DTexture2) {
	const unsigned int hpos = 5;

	D3DTEXTURE2_Load_Type ofn = (D3DTEXTURE2_Load_Type)d3dtexture2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DTexture2);
	LogDXError(ret);

	Log("IDirect3DTexture2::%s(%#010lx, %#010lx)\n", d3dtexture2_hooks[hpos].name, ppvOut, lpD3DTexture2);

	return ret;
}