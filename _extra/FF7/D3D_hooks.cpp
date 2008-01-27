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

#include "d3d_hooks.h"
#include "d3d2_hooks.h";

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3d_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3D_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3D_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3D_HOOK_Release },
/*3*/	{ "Initialize",				0x0C, NULL, (PDWORD)D3D_HOOK_Initialize },
/*4*/	{ "EnumDevices",			0x10, NULL, (PDWORD)D3D_HOOK_EnumDevices },
/*5*/	{ "CreateLight",			0x14, NULL, (PDWORD)D3D_HOOK_CreateLight },
/*6*/	{ "CreateMaterial",			0x18, NULL, (PDWORD)D3D_HOOK_CreateMaterial },
/*7*/	{ "CreateViewport",			0x1C, NULL, (PDWORD)D3D_HOOK_CreateViewport },
/*8*/	{ "FindDevice",				0x20, NULL, (PDWORD)D3D_HOOK_FindDevice }
};
#else
SVTBL_HOOK d3d_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3D_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3D_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3D_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x0C, NULL, (PDWORD)D3D_HOOK_Initialize },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "EnumDevices",			0x10, NULL, (PDWORD)D3D_HOOK_EnumDevices },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "CreateLight",			0x14, NULL, (PDWORD)D3D_HOOK_CreateLight },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "CreateMaterial",			0x18, NULL, (PDWORD)D3D_HOOK_CreateMaterial },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "CreateViewport",			0x1C, NULL, (PDWORD)D3D_HOOK_CreateViewport },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "FindDevice",				0x20, NULL, (PDWORD)D3D_HOOK_FindDevice }
};
#endif
const unsigned int count_d3d_hooks = 9;
bool ishooked_d3d_hooks = false;

HRESULT __stdcall D3D_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3D_QueryInterface_Type ofn = (D3D_QueryInterface_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3D::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", d3d_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);
	if(ret == S_OK) {
		if(riid == IID_IDirect3D2 && ishooked_d3d2_hooks == false) {
			HookVTBLCalls(ppvObj, d3d2_hooks, count_d3d2_hooks, "IDirect3D2");
			ishooked_d3d2_hooks = true;
		}
	}

	return ret;
}

ULONG __stdcall D3D_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3D_AddRef_Type ofn = (D3D_AddRef_Type)d3d_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

ULONG __stdcall D3D_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3D_Release_Type ofn = (D3D_Release_Type)d3d_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D::%s(%#010lx)\n", d3d_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D_HOOK_Initialize(LPVOID *ppvOut, REFCLSID refclsid) {
	const unsigned int hpos = 3;

	D3D_Initialize_Type ofn = (D3D_Initialize_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, refclsid);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D_HOOK_EnumDevices(LPVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg) {
	const unsigned int hpos = 4;

	D3D_EnumDevices_Type ofn = (D3D_EnumDevices_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpEnumDevicesCallback, lpUserArg);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D_HOOK_CreateLight(LPVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, IUnknown *pUnkOuter) {
	const unsigned int hpos = 5;

	D3D_CreateLight_Type ofn = (D3D_CreateLight_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DLight, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D_HOOK_CreateMaterial(LPVOID *ppvOut, LPDIRECT3DMATERIAL *lplpDirect3DMaterial, IUnknown *pUnkOuter) {
	const unsigned int hpos = 6;

	D3D_CreateMaterial_Type ofn = (D3D_CreateMaterial_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DMaterial, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D_HOOK_CreateViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT *lplpD3DViewport,IUnknown *pUnkOuter) {
	const unsigned int hpos = 7;

	D3D_CreateViewport_Type ofn = (D3D_CreateViewport_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpD3DViewport, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D_HOOK_FindDevice(LPVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR) {
	const unsigned int hpos = 8;

	D3D_FindDevice_Type ofn = (D3D_FindDevice_Type)d3d_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DFDS, lpD3DFDR);
	LogDXError(ret);

	Log("IDirect3D::%s()\n", d3d_hooks[hpos].name);

	return ret;
}