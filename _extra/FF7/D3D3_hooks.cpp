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

#include "d3d3_hooks.h"
#include "d3ddevice3_hooks.h"
#include "d3dviewport3_hooks.h"
#include "d3dmaterial3_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3d3_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3D3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3D3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3D3_HOOK_Release },
/*3*/	{ "EnumDevices",			0x0C, NULL, (PDWORD)D3D3_HOOK_EnumDevices },
/*4*/	{ "CreateLight",			0x10, NULL, (PDWORD)D3D3_HOOK_CreateLight },
/*5*/	{ "CreateMaterial",			0x14, NULL, (PDWORD)D3D3_HOOK_CreateMaterial },
/*6*/	{ "CreateViewport",			0x18, NULL, (PDWORD)D3D3_HOOK_CreateViewport },
/*7*/	{ "FindDevice",				0x1C, NULL, (PDWORD)D3D3_HOOK_FindDevice },
/*8*/	{ "CreateDevice",			0x20, NULL, (PDWORD)D3D3_HOOK_CreateDevice},
/*9*/	{ "CreateVertexBuffer",		0x24, NULL, (PDWORD)D3D3_HOOK_CreateVertexBuffer },
/*10*/	{ "EnumZBufferFormats",		0x28, NULL, (PDWORD)D3D3_HOOK_EnumZBufferFormats },
/*11*/	{ "EvictManagedTextures",	0x2C, NULL, (PDWORD)D3D3_HOOK_EvictManagedTextures }
};
#else
SVTBL_HOOK d3d3_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)D3D3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3D3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3D3_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "EnumDevices",			0x0C, NULL, (PDWORD)D3D3_HOOK_EnumDevices },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "CreateLight",			0x10, NULL, (PDWORD)D3D3_HOOK_CreateLight },
/*5*/	{ "CreateMaterial",			0x14, NULL, (PDWORD)D3D3_HOOK_CreateMaterial },
/*6*/	{ "CreateViewport",			0x18, NULL, (PDWORD)D3D3_HOOK_CreateViewport },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "FindDevice",				0x1C, NULL, (PDWORD)D3D3_HOOK_FindDevice },
/*8*/	{ "CreateDevice",			0x20, NULL, (PDWORD)D3D3_HOOK_CreateDevice},
/*9*/	{ NULL, 0, NULL, NULL },	//{ "CreateVertexBuffer",		0x24, NULL, (PDWORD)D3D3_HOOK_CreateVertexBuffer },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "EnumZBufferFormats",		0x28, NULL, (PDWORD)D3D3_HOOK_EnumZBufferFormats },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "EvictManagedTextures",	0x2C, NULL, (PDWORD)D3D3_HOOK_EvictManagedTextures }
};
#endif
const unsigned int count_d3d3_hooks = 12;
bool ishooked_d3d3_hooks = false;

HRESULT __stdcall D3D3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3D3_QueryInterface_Type ofn = (D3D3_QueryInterface_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3D3::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", d3d3_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall D3D3_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3D3_AddRef_Type ofn = (D3D3_AddRef_Type)d3d3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

ULONG __stdcall D3D3_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3D3_Release_Type ofn = (D3D3_Release_Type)d3d3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3D3::%s(%#010lx)\n", d3d3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_EnumDevices(PVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg) {
	const unsigned int hpos = 3;

	D3D3_EnumDevices_Type ofn = (D3D3_EnumDevices_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpEnumDevicesCallback, lpUserArg);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_CreateLight(PVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 4;

	D3D3_CreateLight_Type ofn = (D3D3_CreateLight_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DLight, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_CreateMaterial(PVOID *ppvOut, LPDIRECT3DMATERIAL3 *lplpDirect3DMaterial, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 5;

	D3D3_CreateMaterial_Type ofn = (D3D3_CreateMaterial_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDirect3DMaterial, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);
	/*if(ret == S_OK && ishooked_d3dmaterial3_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpDirect3DMaterial, d3dmaterial3_hooks, count_d3dmaterial3_hooks, "IDirect3DMaterial3");
		ishooked_d3dmaterial3_hooks = true;
	}*/

	return ret;
}

HRESULT __stdcall D3D3_HOOK_CreateViewport(PVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpD3DViewport, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 6;

	D3D3_CreateViewport_Type ofn = (D3D3_CreateViewport_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpD3DViewport, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);
	/*if(ret == S_OK && ishooked_d3dviewport3_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpD3DViewport, d3dviewport3_hooks, count_d3dviewport3_hooks, "IDirect3DViewport3");
		ishooked_d3dviewport3_hooks = true;
	}*/

	return ret;
}

HRESULT __stdcall D3D3_HOOK_FindDevice(PVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR) {
	const unsigned int hpos = 7;

	D3D3_FindDevice_Type ofn = (D3D3_FindDevice_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpD3DFDS, lpD3DFDR);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_CreateDevice(PVOID *ppvOut, REFCLSID refclsid, LPDIRECTDRAWSURFACE4 lpDDS, LPDIRECT3DDEVICE3 *lplpD3DDevice, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 8;

	Log("[pre] IDirect3D3::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx, %#010lx, %#010lx)\n", d3d3_hooks[hpos].name, ppvOut, refclsid.Data1, refclsid.Data2, refclsid.Data3, refclsid.Data4[0], refclsid.Data4[1], refclsid.Data4[2], refclsid.Data4[3], refclsid.Data4[4], refclsid.Data4[5], refclsid.Data4[6], refclsid.Data4[7], lpDDS, lplpD3DDevice, pUnkOuter);

	D3D3_CreateDevice_Type ofn = (D3D3_CreateDevice_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, refclsid, lpDDS, lplpD3DDevice, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D3::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx, %#010lx, %#010lx)\n", d3d3_hooks[hpos].name, ppvOut, refclsid.Data1, refclsid.Data2, refclsid.Data3, refclsid.Data4[0], refclsid.Data4[1], refclsid.Data4[2], refclsid.Data4[3], refclsid.Data4[4], refclsid.Data4[5], refclsid.Data4[6], refclsid.Data4[7], lpDDS, lplpD3DDevice, pUnkOuter);
	/*if(ret == S_OK && refclsid == IID_IDirect3DHALDevice && ishooked_d3ddevice3_hooks == false) {
		g_d3ddevice = (LPVOID)*lplpD3DDevice;
		
		HookVTBLCalls((LPVOID *)lplpD3DDevice, d3ddevice3_hooks, count_d3ddevice3_hooks, "IDirect3DDevice3");
		ishooked_d3ddevice3_hooks = true;
	}*/

	return ret;
}

HRESULT __stdcall D3D3_HOOK_CreateVertexBuffer(PVOID *ppvOut, LPD3DVERTEXBUFFERDESC lpVBDesc, LPDIRECT3DVERTEXBUFFER *lpD3DVertexBuffer, DWORD dwFlags, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 9;

	D3D3_CreateVertexBuffer_Type ofn = (D3D3_CreateVertexBuffer_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpVBDesc, lpD3DVertexBuffer, dwFlags, pUnkOuter);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_EnumZBufferFormats(PVOID *ppvOut, REFCLSID riidDevice, LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback, LPVOID lpContext) {
	const unsigned int hpos = 10;

	D3D3_EnumZBufferFormats_Type ofn = (D3D3_EnumZBufferFormats_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riidDevice, lpEnumCallback, lpContext);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall D3D3_HOOK_EvictManagedTextures(PVOID *ppvOut) {
	const unsigned int hpos = 11;

	D3D3_EvictManagedTextures_Type ofn = (D3D3_EvictManagedTextures_Type)d3d3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirect3D3::%s()\n", d3d3_hooks[hpos].name);

	return ret;
}