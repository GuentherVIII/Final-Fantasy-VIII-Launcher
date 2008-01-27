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

#include "d3d2_hooks.h"
#include "d3ddevice2_hooks.h"
#include "d3dviewport2_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3d2_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3D2_HOOK_QueryInterface },
/*1*/	{ "AddRef",					0x04, NULL, (PDWORD)D3D2_HOOK_AddRef },
/*2*/	{ "Release",				0x08, NULL, (PDWORD)D3D2_HOOK_Release },
/*3*/	{ "EnumDevices",			0x0C, NULL, (PDWORD)D3D2_HOOK_EnumDevices },
/*4*/	{ "CreateLight",			0x10, NULL, (PDWORD)D3D2_HOOK_CreateLight },
/*5*/	{ "CreateMaterial",			0x14, NULL, (PDWORD)D3D2_HOOK_CreateMaterial },
/*6*/	{ "CreateViewport",			0x18, NULL, (PDWORD)D3D2_HOOK_CreateViewport },
/*7*/	{ "FindDevice",				0x1C, NULL, (PDWORD)D3D2_HOOK_FindDevice },
/*8*/	{ "CreateDevice",			0x20, NULL, (PDWORD)D3D2_HOOK_CreateDevice },
};
#else
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)D3D2_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3D2_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3D2_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "EnumDevices",			0x0C, NULL, (PDWORD)D3D2_HOOK_EnumDevices },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "CreateLight",			0x10, NULL, (PDWORD)D3D2_HOOK_CreateLight },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "CreateMaterial",			0x14, NULL, (PDWORD)D3D2_HOOK_CreateMaterial },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "CreateViewport",			0x18, NULL, (PDWORD)D3D2_HOOK_CreateViewport },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "FindDevice",				0x1C, NULL, (PDWORD)D3D2_HOOK_FindDevice },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "CreateDevice",			0x20, NULL, (PDWORD)D3D2_HOOK_CreateDevice },
};
#endif
const unsigned int count_d3d2_hooks = 9;
bool ishooked_d3d2_hooks = false;

HRESULT __stdcall D3D2_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3D2_QueryInterface_Type ofn = (D3D2_QueryInterface_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3D2::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", d3d2_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall D3D2_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3D2_AddRef_Type ofn = (D3D2_AddRef_Type)d3d2_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D2::%s()\n", d3d2_hooks[hpos].name);

	return ret;
}

ULONG __stdcall D3D2_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3D2_Release_Type ofn = (D3D2_Release_Type)d3d2_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D2::%s(%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D2_HOOK_EnumDevices(LPVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg) {
	const unsigned int hpos = 3;

	D3D2_EnumDevices_Type ofn = (D3D2_EnumDevices_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpEnumDevicesCallback, lpUserArg);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D2_HOOK_CreateLight(LPVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, IUnknown *pUnkOuter) {
	const unsigned int hpos = 4;

	D3D2_CreateLight_Type ofn = (D3D2_CreateLight_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DLight, pUnkOuter);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D2_HOOK_CreateMaterial(LPVOID *ppvOut, LPDIRECT3DMATERIAL2 *lplpDirect3DMaterial, IUnknown *pUnkOuter) {
	const unsigned int hpos = 5;

	D3D2_CreateMaterial_Type ofn = (D3D2_CreateMaterial_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DMaterial, pUnkOuter);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D2_HOOK_CreateViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT2 *lplpD3DViewport, IUnknown *pUnkOuter) {
	const unsigned int hpos = 6;

	D3D2_CreateViewport_Type ofn = (D3D2_CreateViewport_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpD3DViewport, pUnkOuter);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);
	if(ret == S_OK && ishooked_d3dviewport2_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpD3DViewport, d3dviewport2_hooks, count_d3dviewport2_hooks, "IDirect3DViewport2");
		ishooked_d3dviewport2_hooks = true;
	}

	return ret;
}

HRESULT __stdcall D3D2_HOOK_FindDevice(LPVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR) {
	const unsigned int hpos = 7;

	D3D2_FindDevice_Type ofn = (D3D2_FindDevice_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DFDS, lpD3DFDR);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D2_HOOK_CreateDevice(LPVOID *ppvOut, REFCLSID refclsid, LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DDEVICE2 *lplpD3DDevice) {
	const unsigned int hpos = 8;

	D3D2_CreateDevice_Type ofn = (D3D2_CreateDevice_Type)d3d2_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, refclsid, lpDDS, lplpD3DDevice);

	Log("IDirect3D2::%s(this=%#010lx)\n", d3d2_hooks[hpos].name, ppvOut);
	if(ret == S_OK && refclsid == IID_IDirect3DHALDevice && ishooked_d3ddevice2_hooks == false) {
		g_d3ddevice = (LPVOID)*lplpD3DDevice;
		
		HookVTBLCalls((LPVOID *)lplpD3DDevice, d3ddevice2_hooks, count_d3ddevice2_hooks, "IDirect3DDevice2");
		ishooked_d3ddevice2_hooks = true;
	}

	return ret;
}