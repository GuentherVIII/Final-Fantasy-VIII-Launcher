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

#include "d3dmaterial3_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3dmaterial3_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3DMATERIAL3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DMATERIAL3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DMATERIAL3_HOOK_Release },
/*3*/	{ "SetMaterial",			0x0C, NULL, (PDWORD)D3DMATERIAL3_HOOK_SetMaterial },
/*4*/	{ "GetMaterial",			0x10, NULL, (PDWORD)D3DMATERIAL3_HOOK_GetMaterial },
/*5*/	{ "GetHandle",				0x14, NULL, (PDWORD)D3DMATERIAL3_HOOK_GetHandle },
};
#else
SVTBL_HOOK d3dmaterial3_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)D3DMATERIAL3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DMATERIAL3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DMATERIAL3_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "SetMaterial",			0x0C, NULL, (PDWORD)D3DMATERIAL3_HOOK_SetMaterial },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "GetMaterial",			0x10, NULL, (PDWORD)D3DMATERIAL3_HOOK_GetMaterial },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "GetHandle",				0x14, NULL, (PDWORD)D3DMATERIAL3_HOOK_GetHandle },
};
#endif
const unsigned int count_d3dmaterial3_hooks = 6;
bool ishooked_d3dmaterial3_hooks = false;

HRESULT __stdcall D3DMATERIAL3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3DMATERIAL3_QueryInterface_Type ofn = (D3DMATERIAL3_QueryInterface_Type)d3dmaterial3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3DMaterial3::%s(this=%#010lx, riid={ %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, ppvObj=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall D3DMATERIAL3_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3DMATERIAL3_AddRef_Type ofn = (D3DMATERIAL3_AddRef_Type)d3dmaterial3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DMaterial3::%s(this=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut);

	return ret;
}

ULONG __stdcall D3DMATERIAL3_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3DMATERIAL3_Release_Type ofn = (D3DMATERIAL3_Release_Type)d3dmaterial3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DMaterial3::%s(this=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DMATERIAL3_HOOK_SetMaterial(LPVOID *ppvOut, LPD3DMATERIAL lpMat) {
	const unsigned int hpos = 3;

	D3DMATERIAL3_SetMaterial_Type ofn = (D3DMATERIAL3_SetMaterial_Type)d3dmaterial3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpMat);
	LogDXError(ret);

	Log("IDirect3DMaterial3::%s(this=%#010lx, lpMat=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut, lpMat);
	Log("->lpMat { dwSize=%#010lx, "
		"diffuse={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvDiffuse={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"ambient={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvAmbient={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"specular={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvSpecular={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"emissive={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvEmissive={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f },\n"
		"  power=%f, dvPower=%f, hTexture=%#010lx, dwRampSize=%#010lx (%d)"
		" }\n", lpMat->dwSize, 
		lpMat->diffuse.r, lpMat->diffuse.g, lpMat->diffuse.b, lpMat->diffuse.a, lpMat->diffuse.dvR, lpMat->diffuse.dvG, lpMat->diffuse.dvB, lpMat->diffuse.dvA,
		lpMat->dcvDiffuse.r, lpMat->dcvDiffuse.g, lpMat->dcvDiffuse.b, lpMat->dcvDiffuse.a, lpMat->dcvDiffuse.dvR, lpMat->dcvDiffuse.dvG, lpMat->dcvDiffuse.dvB, lpMat->dcvDiffuse.dvA,
		lpMat->ambient.r, lpMat->ambient.g, lpMat->ambient.b, lpMat->ambient.a, lpMat->ambient.dvR, lpMat->ambient.dvG, lpMat->ambient.dvB, lpMat->ambient.dvA,
		lpMat->dcvAmbient.r, lpMat->dcvAmbient.g, lpMat->dcvAmbient.b, lpMat->dcvAmbient.a, lpMat->dcvAmbient.dvR, lpMat->dcvAmbient.dvG, lpMat->dcvAmbient.dvB, lpMat->dcvAmbient.dvA,
		lpMat->specular.r, lpMat->specular.g, lpMat->specular.b, lpMat->specular.a, lpMat->specular.dvR, lpMat->specular.dvG, lpMat->specular.dvB, lpMat->specular.dvA,
		lpMat->dcvSpecular.r, lpMat->dcvSpecular.g, lpMat->dcvSpecular.b, lpMat->dcvSpecular.a, lpMat->dcvSpecular.dvR, lpMat->dcvSpecular.dvG, lpMat->dcvSpecular.dvB, lpMat->dcvSpecular.dvA,
		lpMat->emissive.r, lpMat->emissive.g, lpMat->emissive.b, lpMat->emissive.a, lpMat->emissive.dvR, lpMat->emissive.dvG, lpMat->emissive.dvB, lpMat->emissive.dvA,
		lpMat->dcvEmissive.r, lpMat->dcvEmissive.g, lpMat->dcvEmissive.b, lpMat->dcvEmissive.a, lpMat->dcvEmissive.dvR, lpMat->dcvEmissive.dvG, lpMat->dcvEmissive.dvB, lpMat->dcvEmissive.dvA,
		lpMat->power, lpMat->dvPower, lpMat->hTexture, lpMat->dwRampSize, lpMat->dwRampSize
	);

	return ret;
}

HRESULT __stdcall D3DMATERIAL3_HOOK_GetMaterial(LPVOID *ppvOut, LPD3DMATERIAL lpMat) {
	const unsigned int hpos = 4;

	D3DMATERIAL3_GetMaterial_Type ofn = (D3DMATERIAL3_GetMaterial_Type)d3dmaterial3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpMat);
	LogDXError(ret);

	Log("IDirect3DMaterial3::%s(this=%#010lx, lpMat=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut, lpMat);
	Log("->lpMat { dwSize=%#010lx, "
		"diffuse={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvDiffuse={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"ambient={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvAmbient={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"specular={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvSpecular={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"emissive={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f }, "
		"dcvEmissive={ r=%f, g=%f, b=%f, a=%f, dvR=%f, dvG=%f, dvB=%f, dvA=%f },\n"
		"  power=%f, dvPower=%f, hTexture=%#010lx, dwRampSize=%#010lx (%d)"
		" }\n", lpMat->dwSize, 
		lpMat->diffuse.r, lpMat->diffuse.g, lpMat->diffuse.b, lpMat->diffuse.a, lpMat->diffuse.dvR, lpMat->diffuse.dvG, lpMat->diffuse.dvB, lpMat->diffuse.dvA,
		lpMat->dcvDiffuse.r, lpMat->dcvDiffuse.g, lpMat->dcvDiffuse.b, lpMat->dcvDiffuse.a, lpMat->dcvDiffuse.dvR, lpMat->dcvDiffuse.dvG, lpMat->dcvDiffuse.dvB, lpMat->dcvDiffuse.dvA,
		lpMat->ambient.r, lpMat->ambient.g, lpMat->ambient.b, lpMat->ambient.a, lpMat->ambient.dvR, lpMat->ambient.dvG, lpMat->ambient.dvB, lpMat->ambient.dvA,
		lpMat->dcvAmbient.r, lpMat->dcvAmbient.g, lpMat->dcvAmbient.b, lpMat->dcvAmbient.a, lpMat->dcvAmbient.dvR, lpMat->dcvAmbient.dvG, lpMat->dcvAmbient.dvB, lpMat->dcvAmbient.dvA,
		lpMat->specular.r, lpMat->specular.g, lpMat->specular.b, lpMat->specular.a, lpMat->specular.dvR, lpMat->specular.dvG, lpMat->specular.dvB, lpMat->specular.dvA,
		lpMat->dcvSpecular.r, lpMat->dcvSpecular.g, lpMat->dcvSpecular.b, lpMat->dcvSpecular.a, lpMat->dcvSpecular.dvR, lpMat->dcvSpecular.dvG, lpMat->dcvSpecular.dvB, lpMat->dcvSpecular.dvA,
		lpMat->emissive.r, lpMat->emissive.g, lpMat->emissive.b, lpMat->emissive.a, lpMat->emissive.dvR, lpMat->emissive.dvG, lpMat->emissive.dvB, lpMat->emissive.dvA,
		lpMat->dcvEmissive.r, lpMat->dcvEmissive.g, lpMat->dcvEmissive.b, lpMat->dcvEmissive.a, lpMat->dcvEmissive.dvR, lpMat->dcvEmissive.dvG, lpMat->dcvEmissive.dvB, lpMat->dcvEmissive.dvA,
		lpMat->power, lpMat->dvPower, lpMat->hTexture, lpMat->dwRampSize, lpMat->dwRampSize
	);

	return ret;
}

HRESULT __stdcall D3DMATERIAL3_HOOK_GetHandle(LPVOID *ppvOut, LPDIRECT3DDEVICE3 lpDirect3DDevice, LPD3DMATERIALHANDLE lpHandle) {
	const unsigned int hpos = 5;

	D3DMATERIAL3_GetHandle_Type ofn = (D3DMATERIAL3_GetHandle_Type)d3dmaterial3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DDevice, lpHandle);
	LogDXError(ret);

	Log("IDirect3DMaterial3::%s(this=%#010lx, lpDirect3DDevice=%#010lx, lpHandle=%#010lx)\n", d3dmaterial3_hooks[hpos].name, ppvOut, lpDirect3DDevice, lpHandle);

	return ret;
}