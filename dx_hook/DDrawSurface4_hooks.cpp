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

#include "ddrawsurface4_hooks.h"
#include "d3dtexture2_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK ddrawsurface4_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAWSURFACE4_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Release },
/*3*/	{ "AddAttachedSurface",		0x0C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddAttachedSurface },
/*4*/	{ "AddOverlayDirtyRect",	0x10, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddOverlayDirtyRect },
/*5*/	{ "Blt",					0x14, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Blt },
/*6*/	{ "BltBatch",				0x18, NULL, (PDWORD)DDRAWSURFACE4_HOOK_BltBatch },
/*7*/	{ "BltFast",				0x1C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_BltFast },
/*8*/	{ "DeleteAttachedSurface",	0x20, NULL, (PDWORD)DDRAWSURFACE4_HOOK_DeleteAttachedSurface },
/*9*/	{ "EnumAttachedSurfaces",	0x24, NULL, (PDWORD)DDRAWSURFACE4_HOOK_EnumAttachedSurfaces },
/*10*/	{ "EnumOverlayZOrders",		0x28, NULL, (PDWORD)DDRAWSURFACE4_HOOK_EnumOverlayZOrders },
/*11*/	{ "Flip",					0x2C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Flip },
/*12*/	{ "GetAttachedSurface",		0x30, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetAttachedSurface },
/*13*/	{ "GetBltStatus",			0x34, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetBltStatus },
/*14*/	{ "GetCaps",				0x38, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetCaps },
/*15*/	{ "GetClipper",				0x3C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetClipper },
/*16*/	{ "GetColorKey",			0x40, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetColorKey },
/*17*/	{ "GetDC",					0x44, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetDC },
/*18*/	{ "GetFlipStatus",			0x48, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetFlipStatus },
/*19*/	{ "GetOverlayPosition",		0x4C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetOverlayPosition },
/*20*/	{ "GetPalette",				0x50, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPalette },
/*21*/	{ "GetPixelFormat",			0x54, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPixelFormat },
/*22*/	{ "GetSurfaceDesc",			0x58, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetSurfaceDesc },
/*23*/	{ "Initialize",				0x5C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Initialize },
/*24*/	{ NULL, 0, NULL, NULL },	//{ "IsLost",					0x60, NULL, (PDWORD)DDRAWSURFACE4_HOOK_IsLost },
/*25*/	{ "Lock",					0x64, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Lock },
/*26*/	{ "ReleaseDC",				0x68, NULL, (PDWORD)DDRAWSURFACE4_HOOK_ReleaseDC },
/*27*/	{ "Restore",				0x6C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Restore },
/*28*/	{ "SetClipper",				0x70, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetClipper },
/*29*/	{ "SetColorKey",			0x74, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetColorKey },
/*30*/	{ "SetOverlayPosition",		0x78, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetOverlayPosition },
/*31*/	{ "SetPalette",				0x7C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetPalette },
/*32*/	{ "Unlock",					0x80, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Unlock },
/*33*/	{ "UpdateOverlay",			0x84, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlay },
/*34*/	{ "UpdateOverlayDisplay",	0x88, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlayDisplay },
/*35*/	{ "UpdateOverlayZOrder",	0x8C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlayZOrder },
/*36*/	{ "GetDDInterface",			0x90, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetDDInterface },
/*37*/	{ "PageLock",				0x94, NULL, (PDWORD)DDRAWSURFACE4_HOOK_PageLock },
/*38*/	{ "PageUnlock",				0x98, NULL, (PDWORD)DDRAWSURFACE4_HOOK_PageUnlock },
/*39*/	{ "SetSurfaceDesc",			0x9C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetSurfaceDesc },
/*40*/	{ "SetPrivateData",			0xA0, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetPrivateData },
/*41*/	{ "GetPrivateData",			0xA4, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPrivateData },
/*42*/	{ "FreePrivateData",		0xA8, NULL, (PDWORD)DDRAWSURFACE4_HOOK_FreePrivateData },
/*43*/	{ "GetUniquenessValue",		0xAC, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetUniquenessValue },
/*44*/	{ "ChangeUniquenessValue",	0xB0, NULL, (PDWORD)DDRAWSURFACE4_HOOK_ChangeUniquenessValue }
};
#else
SVTBL_HOOK ddrawsurface4_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DDRAWSURFACE4_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "AddAttachedSurface",		0x0C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddAttachedSurface },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "AddOverlayDirtyRect",	0x10, NULL, (PDWORD)DDRAWSURFACE4_HOOK_AddOverlayDirtyRect },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "Blt",					0x14, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Blt },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "BltBatch",				0x18, NULL, (PDWORD)DDRAWSURFACE4_HOOK_BltBatch },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "BltFast",				0x1C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_BltFast },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "DeleteAttachedSurface",	0x20, NULL, (PDWORD)DDRAWSURFACE4_HOOK_DeleteAttachedSurface },
/*9*/	{ NULL, 0, NULL, NULL },	//{ "EnumAttachedSurfaces",	0x24, NULL, (PDWORD)DDRAWSURFACE4_HOOK_EnumAttachedSurfaces },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "EnumOverlayZOrders",		0x28, NULL, (PDWORD)DDRAWSURFACE4_HOOK_EnumOverlayZOrders },
/*11*/	{ "Flip",					0x2C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Flip },
/*12*/	{ NULL, 0, NULL, NULL },	//{ "GetAttachedSurface",		0x30, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetAttachedSurface },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "GetBltStatus",			0x34, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetBltStatus },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "GetCaps",				0x38, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetCaps },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "GetClipper",				0x3C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetClipper },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "GetColorKey",			0x40, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetColorKey },
/*17*/	{ NULL, 0, NULL, NULL },	//{ "GetDC",					0x44, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetDC },
/*18*/	{ NULL, 0, NULL, NULL },	//{ "GetFlipStatus",			0x48, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetFlipStatus },
/*19*/	{ NULL, 0, NULL, NULL },	//{ "GetOverlayPosition",		0x4C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetOverlayPosition },
/*20*/	{ NULL, 0, NULL, NULL },	//{ "GetPalette",				0x50, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPalette },
/*21*/	{ NULL, 0, NULL, NULL },	//{ "GetPixelFormat",			0x54, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPixelFormat },
/*22*/	{ NULL, 0, NULL, NULL },	//{ "GetSurfaceDesc",			0x58, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetSurfaceDesc },
/*23*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x5C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Initialize },
/*24*/	{ NULL, 0, NULL, NULL },	//{ "IsLost",					0x60, NULL, (PDWORD)DDRAWSURFACE4_HOOK_IsLost },
/*25*/	{ "Lock",					0x64, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Lock },
/*26*/	{ NULL, 0, NULL, NULL },	//{ "ReleaseDC",				0x68, NULL, (PDWORD)DDRAWSURFACE4_HOOK_ReleaseDC },
/*27*/	{ NULL, 0, NULL, NULL },	//{ "Restore",				0x6C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Restore },
/*28*/	{ NULL, 0, NULL, NULL },	//{ "SetClipper",				0x70, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetClipper },
/*29*/	{ NULL, 0, NULL, NULL },	//{ "SetColorKey",			0x74, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetColorKey },
/*30*/	{ NULL, 0, NULL, NULL },	//{ "SetOverlayPosition",		0x78, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetOverlayPosition },
/*31*/	{ NULL, 0, NULL, NULL },	//{ "SetPalette",				0x7C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetPalette },
/*32*/	{ "Unlock",					0x80, NULL, (PDWORD)DDRAWSURFACE4_HOOK_Unlock },
/*33*/	{ NULL, 0, NULL, NULL },	//{ "UpdateOverlay",			0x84, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlay },
/*34*/	{ NULL, 0, NULL, NULL },	//{ "UpdateOverlayDisplay",	0x88, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlayDisplay },
/*35*/	{ NULL, 0, NULL, NULL },	//{ "UpdateOverlayZOrder",	0x8C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_UpdateOverlayZOrder },
/*36*/	{ NULL, 0, NULL, NULL },	//{ "GetDDInterface",			0x90, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetDDInterface },
/*37*/	{ NULL, 0, NULL, NULL },	//{ "PageLock",				0x94, NULL, (PDWORD)DDRAWSURFACE4_HOOK_PageLock },
/*38*/	{ NULL, 0, NULL, NULL },	//{ "PageUnlock",				0x98, NULL, (PDWORD)DDRAWSURFACE4_HOOK_PageUnlock },
/*39*/	{ NULL, 0, NULL, NULL },	//{ "SetSurfaceDesc",			0x9C, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetSurfaceDesc },
/*40*/	{ NULL, 0, NULL, NULL },	//{ "SetPrivateData",			0xA0, NULL, (PDWORD)DDRAWSURFACE4_HOOK_SetPrivateData },
/*41*/	{ NULL, 0, NULL, NULL },	//{ "GetPrivateData",			0xA4, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetPrivateData },
/*42*/	{ NULL, 0, NULL, NULL },	//{ "FreePrivateData",		0xA8, NULL, (PDWORD)DDRAWSURFACE4_HOOK_FreePrivateData },
/*43*/	{ NULL, 0, NULL, NULL },	//{ "GetUniquenessValue",		0xAC, NULL, (PDWORD)DDRAWSURFACE4_HOOK_GetUniquenessValue },
/*44*/	{ NULL, 0, NULL, NULL },	//{ "ChangeUniquenessValue",	0xB0, NULL, (PDWORD)DDRAWSURFACE4_HOOK_ChangeUniquenessValue }
};
#endif
const unsigned int count_ddrawsurface4_hooks = 45;
bool ishooked_ddrawsurface4_hooks = false;

HRESULT __stdcall DDRAWSURFACE4_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	DDRAWSURFACE4_QueryInterface_Type ofn = (DDRAWSURFACE4_QueryInterface_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx *[%#010lx])\n", ddrawsurface4_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj, *ppvObj);
	if(ret == S_OK && riid == IID_IDirect3DTexture2 && ishooked_d3dtexture2_hooks == false) {
		HookVTBLCalls((LPVOID *)ppvObj, d3dtexture2_hooks, count_d3dtexture2_hooks, "IDirect3DTexture2");
		ishooked_d3dtexture2_hooks = true;
	}
	if(ret == S_OK && riid == IID_IDirect3DTexture2) {
		textures[*ppvObj] = ppvOut;
		Log("textures[%#010lx] = %#010lx;\n", (DWORD)*ppvObj, (DWORD)ppvOut);
	}

	return ret;
}

ULONG __stdcall DDRAWSURFACE4_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	DDRAWSURFACE4_AddRef_Type ofn = (DDRAWSURFACE4_AddRef_Type)ddrawsurface4_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

ULONG __stdcall DDRAWSURFACE4_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	DDRAWSURFACE4_Release_Type ofn = (DDRAWSURFACE4_Release_Type)ddrawsurface4_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectDrawSurface4::%s(%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_AddAttachedSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface) {
	const unsigned int hpos = 3;

	DDRAWSURFACE4_AddAttachedSurface_Type ofn = (DDRAWSURFACE4_AddAttachedSurface_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSAttachedSurface);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSAttachedSurface=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSAttachedSurface);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_AddOverlayDirtyRect(LPVOID *ppvOut, LPRECT lpRect) {
	const unsigned int hpos = 4;

	DDRAWSURFACE4_AddOverlayDirtyRect_Type ofn = (DDRAWSURFACE4_AddOverlayDirtyRect_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpRect);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Blt(LPVOID *ppvOut, LPRECT lpDestRect, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx) {
	const unsigned int hpos = 5;

	DDRAWSURFACE4_Blt_Type ofn = (DDRAWSURFACE4_Blt_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDestRect=%#010lx { left=%d, right=%d, top=%d, bottom=%d }, lpDDSrcSurface=%#010lx, lpSrcRect=%#010lx { left=%d, right=%d, top=%d, bottom=%d }, dwFlags=%#010lx, lpDDBltFx=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDestRect, (lpDestRect != NULL ? lpDestRect->left : 0), (lpDestRect != NULL ? lpDestRect->right : 0), (lpDestRect != NULL ? lpDestRect->top : 0), (lpDestRect != NULL ? lpDestRect->bottom : 0), lpDDSrcSurface, lpSrcRect, (lpSrcRect != NULL ? lpSrcRect->left : 0), (lpSrcRect != NULL ? lpSrcRect->right : 0), (lpSrcRect != NULL ? lpSrcRect->top : 0), (lpSrcRect != NULL ? lpSrcRect->bottom : 0), dwFlags, lpDDBltFx);
	
	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_BltBatch(LPVOID *ppvOut, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags) {
	const unsigned int hpos = 6;

	DDRAWSURFACE4_BltBatch_Type ofn = (DDRAWSURFACE4_BltBatch_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDBltBatch, dwCount, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_BltFast(LPVOID *ppvOut, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans) {
	const unsigned int hpos = 7;

	DDRAWSURFACE4_BltFast_Type ofn = (DDRAWSURFACE4_BltFast_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_DeleteAttachedSurface(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface) {
	const unsigned int hpos = 8;

	DDRAWSURFACE4_DeleteAttachedSurface_Type ofn = (DDRAWSURFACE4_DeleteAttachedSurface_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSAttachedSurface);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_EnumAttachedSurfaces(LPVOID *ppvOut, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback) {
	const unsigned int hpos = 9;

	DDRAWSURFACE4_EnumAttachedSurfaces_Type ofn = (DDRAWSURFACE4_EnumAttachedSurfaces_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpContext, lpEnumSurfacesCallback);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpContext=%#010lx, lpEnumSurfacesCallback=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpContext, lpEnumSurfacesCallback);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_EnumOverlayZOrders(LPVOID *ppvOut, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback) {
	const unsigned int hpos = 10;

	DDRAWSURFACE4_EnumOverlayZOrders_Type ofn = (DDRAWSURFACE4_EnumOverlayZOrders_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpContext, lpfnCallback);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Flip(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurfaceTargetOverride, DWORD dwFlags) {
	const unsigned int hpos = 11;

#ifdef FF8_WINDOWED
	HRESULT ret = 0;
	if(((LPDIRECTDRAWSURFACE4)ppvOut) == g_frontbuffer) {
		RECT rect;
		POINT p1, p2;
		GetClientRect(g_hwnd, &rect);

		p1.x = rect.left;
		p1.y = rect.top;
		p2.x = rect.right;
		p2.y = rect.bottom;

		ClientToScreen(g_hwnd, &p1);
		ClientToScreen(g_hwnd, &p2);

		rect.left = p1.x;
		rect.top = p1.y;
		rect.right = p2.x;
		rect.bottom = p2.y;

		ret = ((LPDIRECTDRAWSURFACE4)ppvOut)->Blt(&rect, g_backbuffer, NULL, DDBLT_WAIT, NULL);

		Log("BLIT FLIP\n");
	} else {
		DDRAWSURFACE4_Flip_Type ofn = (DDRAWSURFACE4_Flip_Type)ddrawsurface4_hooks[hpos].oldFunc;
		ret = ofn(ppvOut, lpDDSurfaceTargetOverride, dwFlags);

		Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSurfaceTargetOverride=%#010lx, dwFlags=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSurfaceTargetOverride, dwFlags);
	}
#else
	DDRAWSURFACE4_Flip_Type ofn = (DDRAWSURFACE4_Flip_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceTargetOverride, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSurfaceTargetOverride=%#010lx, dwFlags=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSurfaceTargetOverride, dwFlags);
	if(g_d3ddevice != NULL && g_binkActive == FALSE) {
		LPDIRECT3DVIEWPORT3 lpVP = NULL;
		D3DVIEWPORT2 d3dvp_old, d3dvp_new;
		D3DRECT rect[4];
		memset(&rect, 0, sizeof(rect));
		memset(&d3dvp_old, 0, sizeof(d3dvp_old));
		d3dvp_old.dwSize = sizeof(d3dvp_old);

		((LPDIRECT3DDEVICE3)g_d3ddevice)->GetCurrentViewport(&lpVP);
		lpVP->GetViewport2(&d3dvp_old);

		memcpy(&d3dvp_new, &d3dvp_old, sizeof(d3dvp_new));
		d3dvp_new.dwSize = 0; //special case for internal call
		d3dvp_old.dwSize = 0;
		d3dvp_new.dwX = d3dvp_new.dwY = 0;
		d3dvp_new.dwWidth = displaymode_options[g_config.displaymode].resX;
		d3dvp_new.dwHeight = displaymode_options[g_config.displaymode].resY;

		lpVP->SetViewport2(&d3dvp_new);

		SetD3DRect(rect[0], 0, displaymode_options[g_config.displaymode].resX, 0, g_currentviewport.y);
		SetD3DRect(rect[1], 0, displaymode_options[g_config.displaymode].resX, g_currentviewport.y+g_game.height, displaymode_options[g_config.displaymode].resY);
		SetD3DRect(rect[2], 0, g_currentviewport.x, 0, displaymode_options[g_config.displaymode].resY);
		SetD3DRect(rect[3], g_currentviewport.x+g_game.width, displaymode_options[g_config.displaymode].resX, 0, displaymode_options[g_config.displaymode].resY);

		lpVP->Clear2(4, (LPD3DRECT)&rect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 0, 0);
		lpVP->SetViewport2(&d3dvp_old);
	}
#endif

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetAttachedSurface(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE4 FAR *lplpDDAttachedSurface) {
	const unsigned int hpos = 12;

#ifdef FF8_WINDOWED
	if(((LPDIRECTDRAWSURFACE4)ppvOut) == g_frontbuffer && (lpDDSCaps->dwCaps & DDSCAPS_BACKBUFFER) == DDSCAPS_BACKBUFFER) {
		*lplpDDAttachedSurface = g_backbuffer;
		return S_OK;
	}
#endif

	DDRAWSURFACE4_GetAttachedSurface_Type ofn = (DDRAWSURFACE4_GetAttachedSurface_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSCaps, lplpDDAttachedSurface);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSCaps=%#010lx { %#010lx, %#010lx, %#010lx, %#010lx }, lplpDDAttachedSurface=%#010lx *[%#010lx])\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSCaps, (lpDDSCaps != NULL ? lpDDSCaps->dwCaps : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps2 : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps3 : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps4 : NULL), lplpDDAttachedSurface, (lplpDDAttachedSurface != NULL ? *lplpDDAttachedSurface : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetBltStatus(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 13;

	DDRAWSURFACE4_GetBltStatus_Type ofn = (DDRAWSURFACE4_GetBltStatus_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetCaps(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps) {
	const unsigned int hpos = 14;

	DDRAWSURFACE4_GetCaps_Type ofn = (DDRAWSURFACE4_GetCaps_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSCaps);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSCaps=%#010lx { %#010lx, %#010lx, %#010lx, %#010lx })\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSCaps, (lpDDSCaps != NULL ? lpDDSCaps->dwCaps : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps2 : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps3 : NULL), (lpDDSCaps != NULL ? lpDDSCaps->dwCaps4 : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetClipper(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper) {
	const unsigned int hpos = 15;

	DDRAWSURFACE4_GetClipper_Type ofn = (DDRAWSURFACE4_GetClipper_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDDClipper);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lplpDDClipper=%#010lx *[%#010lx])\n", ddrawsurface4_hooks[hpos].name, ppvOut, lplpDDClipper, (lplpDDClipper != NULL ? *lplpDDClipper : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetColorKey(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) {
	const unsigned int hpos = 16;

	DDRAWSURFACE4_GetColorKey_Type ofn = (DDRAWSURFACE4_GetColorKey_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDColorKey);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, dwFlags=%#010lx, lpDDColorKey=%#010lx { %#010lx, %#010lx })\n", ddrawsurface4_hooks[hpos].name, ppvOut, dwFlags, lpDDColorKey, (lpDDColorKey != NULL ? lpDDColorKey->dwColorSpaceLowValue : NULL), (lpDDColorKey != NULL ? lpDDColorKey->dwColorSpaceLowValue : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetDC(LPVOID *ppvOut, HDC FAR *lphDC) {
	const unsigned int hpos = 17;

	DDRAWSURFACE4_GetDC_Type ofn = (DDRAWSURFACE4_GetDC_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lphDC);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lphDC=%#010lx *[%#010lx])\n", ddrawsurface4_hooks[hpos].name, ppvOut, lphDC, (lphDC != NULL ? *lphDC : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetFlipStatus(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 18;

	DDRAWSURFACE4_GetFlipStatus_Type ofn = (DDRAWSURFACE4_GetFlipStatus_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetOverlayPosition(LPVOID *ppvOut, LPLONG lplX, LPLONG lplY) {
	const unsigned int hpos = 19;

	DDRAWSURFACE4_GetOverlayPosition_Type ofn = (DDRAWSURFACE4_GetOverlayPosition_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplX, lplY);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPalette(LPVOID *ppvOut, LPDIRECTDRAWPALETTE FAR *lplpDDPalette) {
	const unsigned int hpos = 20;

	DDRAWSURFACE4_GetPalette_Type ofn = (DDRAWSURFACE4_GetPalette_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDDPalette);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lplpDDPalette=%#010lx *[%#010lx])\n", ddrawsurface4_hooks[hpos].name, ppvOut, lplpDDPalette, (lplpDDPalette != NULL ? *lplpDDPalette : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPixelFormat(LPVOID *ppvOut, LPDDPIXELFORMAT lpDDPixelFormat) {
	const unsigned int hpos = 21;

	DDRAWSURFACE4_GetPixelFormat_Type ofn = (DDRAWSURFACE4_GetPixelFormat_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDPixelFormat);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDPixelFormat=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDPixelFormat);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetSurfaceDesc(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc) {
	const unsigned int hpos = 22;

	DDRAWSURFACE4_GetSurfaceDesc_Type ofn = (DDRAWSURFACE4_GetSurfaceDesc_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurfaceDesc);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDSurfaceDesc=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDSurfaceDesc);
	if(lpDDSurfaceDesc != NULL) {
		char dwFlags_buffer[LOGBUFFER_MAX], ddscaps1_buffer[LOGBUFFER_MAX], ddpf_buffer[LOGBUFFER_MAX];
		FlagsToString(FLAGS_DDSD, CFLAGS_DDSD, lpDDSurfaceDesc->dwFlags, (char *)&dwFlags_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDSCAPS1, CFLAGS_DDSCAPS1, lpDDSurfaceDesc->ddsCaps.dwCaps, (char *)&ddscaps1_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDPF, CFLAGS_DDPF, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, (char *)&ddpf_buffer, LOGBUFFER_MAX);

		Log("->lpDDSurfaceDesc { dwSize=%#010lx, dwFlags=%#010lx (%s), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), lPitch=%#010lx , dwLinearSize=%#010lx, dwBackBufferCount=%#010lx, dwMipMapCount=%#010lx, dwRefreshRate=%#010lx, dwAlphaBitDepth=%#010lx, dwReserved=%#010lx,\n"
			"  lpSurface=%#010lx, ddckCKDestOverlay={ %#010lx, %#010lx }, ddckCKDestBlt={ %#010lx, %#010lx }, ddckCKSrcOverlay={ %#010lx, %#010lx }, ddckCKSrcBlt={ %#010lx, %#010lx },\n"
			"  ddpfPixelFormat={ dwSize=%#010lx, dwFlags=%#010lx (%s), dwFourCC=%#010lx, dwRGBBitCount=%#010lx, dwYUVBitCount=%#010lx, dwZBufferBitDepth=%#010lx, dwAlphaBitDepth=%#010lx, dwLuminanceBitCount=%#010lx, dwBumpBitCount=%#010lx, dwRBitMask=%#010lx,\n"
			"    dwYBitMask=%#010lx, dwStencilBitDepth=%#010lx, dwLuminanceBitMask=%#010lx, dwBumpDuBitMask=%#010lx, dwGBitMask=%#010lx, dwUBitMask=%#010lx, dwZBitMask=%#010lx, dwBumpDvBitMask=%#010lx, dwBBitMask=%#010lx, dwVBitMask=%#010lx, dwStencilBitMask=%#010lx,\n"
			"    dwBumpLuminanceBitMask=%#010lx, dwRGBAlphaBitMask=%#010lx, dwYUVAlphaBitMask=%#010lx, dwLuminanceAlphaBitMask=%#010lx, dwRGBZBitMask=%#010lx, dwYUVZBitMask=%#010lx },\n"
			"  ddsCaps={ %#010lx (%s), %#010lx, %#010lx, %#010lx }, dwTextureStage=%#010lx }\n",
			lpDDSurfaceDesc->dwSize, lpDDSurfaceDesc->dwFlags, dwFlags_buffer, lpDDSurfaceDesc->dwWidth, (unsigned int)lpDDSurfaceDesc->dwWidth, lpDDSurfaceDesc->dwHeight, (unsigned int)lpDDSurfaceDesc->dwHeight, lpDDSurfaceDesc->lPitch,
			lpDDSurfaceDesc->dwLinearSize, lpDDSurfaceDesc->dwBackBufferCount, lpDDSurfaceDesc->dwMipMapCount, lpDDSurfaceDesc->dwRefreshRate, lpDDSurfaceDesc->dwAlphaBitDepth, lpDDSurfaceDesc->dwReserved, lpDDSurfaceDesc->lpSurface,
			lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceHighValue,
			lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceHighValue,
			
			lpDDSurfaceDesc->ddpfPixelFormat.dwSize, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, ddpf_buffer, lpDDSurfaceDesc->ddpfPixelFormat.dwFourCC, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwZBufferBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwAlphaBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDuBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwGBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwUBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwZBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDvBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwVBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRGBAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBZBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVZBitMask,
			
			lpDDSurfaceDesc->ddsCaps.dwCaps, ddscaps1_buffer, lpDDSurfaceDesc->ddsCaps.dwCaps2, lpDDSurfaceDesc->ddsCaps.dwCaps3, lpDDSurfaceDesc->ddsCaps.dwCaps4, lpDDSurfaceDesc->dwTextureStage
		);
	}

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Initialize(LPVOID *ppvOut, LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc) {
	const unsigned int hpos = 23;

	DDRAWSURFACE4_Initialize_Type ofn = (DDRAWSURFACE4_Initialize_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDD, lpDDSurfaceDesc);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_IsLost(LPVOID *ppvOut) {
	const unsigned int hpos = 24;

	DDRAWSURFACE4_IsLost_Type ofn = (DDRAWSURFACE4_IsLost_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Lock(LPVOID *ppvOut, LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent) {
	const unsigned int hpos = 25;

	DDRAWSURFACE4_Lock_Type ofn = (DDRAWSURFACE4_Lock_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDestRect=%#010lx { left=%d, right=%d, top=%d, bottom=%d }, lpDDSurfaceDesc=%#010lx, dwFlags=%#010lx, hEvent=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDestRect, (lpDestRect != NULL ? lpDestRect->left : NULL), (lpDestRect != NULL ? lpDestRect->right : NULL), (lpDestRect != NULL ? lpDestRect->top : NULL), (lpDestRect != NULL ? lpDestRect->bottom : NULL), lpDDSurfaceDesc, dwFlags, hEvent);
	if(lpDDSurfaceDesc != NULL) {
		g_lastLockedSurface = ppvOut;
		g_lastLockedSurfaceData = lpDDSurfaceDesc->lpSurface;
		g_binkSurfaceNeedsStretch = false;
		char dwFlags_buffer[LOGBUFFER_MAX], ddscaps1_buffer[LOGBUFFER_MAX], ddpf_buffer[LOGBUFFER_MAX];
		FlagsToString(FLAGS_DDSD, CFLAGS_DDSD, lpDDSurfaceDesc->dwFlags, (char *)&dwFlags_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDSCAPS1, CFLAGS_DDSCAPS1, lpDDSurfaceDesc->ddsCaps.dwCaps, (char *)&ddscaps1_buffer, LOGBUFFER_MAX);
		FlagsToString(FLAGS_DDPF, CFLAGS_DDPF, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, (char *)&ddpf_buffer, LOGBUFFER_MAX);

		Log("->lpDDSurfaceDesc { dwSize=%#010lx, dwFlags=%#010lx (%s), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), lPitch=%#010lx , dwLinearSize=%#010lx, dwBackBufferCount=%#010lx, dwMipMapCount=%#010lx, dwRefreshRate=%#010lx, dwAlphaBitDepth=%#010lx, dwReserved=%#010lx,\n"
			"  lpSurface=%#010lx, ddckCKDestOverlay={ %#010lx, %#010lx }, ddckCKDestBlt={ %#010lx, %#010lx }, ddckCKSrcOverlay={ %#010lx, %#010lx }, ddckCKSrcBlt={ %#010lx, %#010lx },\n"
			"  ddpfPixelFormat={ dwSize=%#010lx, dwFlags=%#010lx (%s), dwFourCC=%#010lx, dwRGBBitCount=%#010lx, dwYUVBitCount=%#010lx, dwZBufferBitDepth=%#010lx, dwAlphaBitDepth=%#010lx, dwLuminanceBitCount=%#010lx, dwBumpBitCount=%#010lx, dwRBitMask=%#010lx,\n"
			"    dwYBitMask=%#010lx, dwStencilBitDepth=%#010lx, dwLuminanceBitMask=%#010lx, dwBumpDuBitMask=%#010lx, dwGBitMask=%#010lx, dwUBitMask=%#010lx, dwZBitMask=%#010lx, dwBumpDvBitMask=%#010lx, dwBBitMask=%#010lx, dwVBitMask=%#010lx, dwStencilBitMask=%#010lx,\n"
			"    dwBumpLuminanceBitMask=%#010lx, dwRGBAlphaBitMask=%#010lx, dwYUVAlphaBitMask=%#010lx, dwLuminanceAlphaBitMask=%#010lx, dwRGBZBitMask=%#010lx, dwYUVZBitMask=%#010lx },\n"
			"  ddsCaps={ %#010lx (%s), %#010lx, %#010lx, %#010lx }, dwTextureStage=%#010lx }\n",
			lpDDSurfaceDesc->dwSize, lpDDSurfaceDesc->dwFlags, dwFlags_buffer, lpDDSurfaceDesc->dwWidth, (unsigned int)lpDDSurfaceDesc->dwWidth, lpDDSurfaceDesc->dwHeight, (unsigned int)lpDDSurfaceDesc->dwHeight, lpDDSurfaceDesc->lPitch,
			lpDDSurfaceDesc->dwLinearSize, lpDDSurfaceDesc->dwBackBufferCount, lpDDSurfaceDesc->dwMipMapCount, lpDDSurfaceDesc->dwRefreshRate, lpDDSurfaceDesc->dwAlphaBitDepth, lpDDSurfaceDesc->dwReserved, lpDDSurfaceDesc->lpSurface,
			lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKDestBlt.dwColorSpaceHighValue,
			lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcOverlay.dwColorSpaceHighValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceLowValue, lpDDSurfaceDesc->ddckCKSrcBlt.dwColorSpaceHighValue,
			
			lpDDSurfaceDesc->ddpfPixelFormat.dwSize, lpDDSurfaceDesc->ddpfPixelFormat.dwFlags, ddpf_buffer, lpDDSurfaceDesc->ddpfPixelFormat.dwFourCC, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwZBufferBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwAlphaBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitCount, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpBitCount,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitDepth, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDuBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwGBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwUBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwZBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpDvBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwBBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwVBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwStencilBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwBumpLuminanceBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwRGBAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwYUVAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwLuminanceAlphaBitMask, lpDDSurfaceDesc->ddpfPixelFormat.dwRGBZBitMask,
			lpDDSurfaceDesc->ddpfPixelFormat.dwYUVZBitMask,
			
			lpDDSurfaceDesc->ddsCaps.dwCaps, ddscaps1_buffer, lpDDSurfaceDesc->ddsCaps.dwCaps2, lpDDSurfaceDesc->ddsCaps.dwCaps3, lpDDSurfaceDesc->ddsCaps.dwCaps4, lpDDSurfaceDesc->dwTextureStage
		);
	}

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_ReleaseDC(LPVOID *ppvOut, HDC hDC) {
	const unsigned int hpos = 26;

	DDRAWSURFACE4_ReleaseDC_Type ofn = (DDRAWSURFACE4_ReleaseDC_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hDC);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Restore(LPVOID *ppvOut) {
	const unsigned int hpos = 27;

	DDRAWSURFACE4_Restore_Type ofn = (DDRAWSURFACE4_Restore_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetClipper(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER lpDDClipper) {
	const unsigned int hpos = 28;

	DDRAWSURFACE4_SetClipper_Type ofn = (DDRAWSURFACE4_SetClipper_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDClipper);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDClipper=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDClipper);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetColorKey(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) {
	const unsigned int hpos = 29;

	DDRAWSURFACE4_SetColorKey_Type ofn = (DDRAWSURFACE4_SetColorKey_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDColorKey);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, dwFlags=%#010lx, lpDDColorKey=%#010lx { %#010lx, %#010lx })\n", ddrawsurface4_hooks[hpos].name, ppvOut, dwFlags, lpDDColorKey, (lpDDColorKey != NULL ? lpDDColorKey->dwColorSpaceLowValue : NULL), (lpDDColorKey != NULL ? lpDDColorKey->dwColorSpaceHighValue : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetOverlayPosition(LPVOID *ppvOut, LONG lX, LONG lY) {
	const unsigned int hpos = 30;

	DDRAWSURFACE4_SetOverlayPosition_Type ofn = (DDRAWSURFACE4_SetOverlayPosition_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lX, lY);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetPalette(LPVOID *ppvOut, LPDIRECTDRAWPALETTE lpDDPalette) {
	const unsigned int hpos = 31;

	DDRAWSURFACE4_SetPalette_Type ofn = (DDRAWSURFACE4_SetPalette_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDPalette);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpDDPalette=%#010lx)\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpDDPalette);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_Unlock(LPVOID *ppvOut, LPRECT lpRect) {
	const unsigned int hpos = 32;

	DDRAWSURFACE4_Unlock_Type ofn = (DDRAWSURFACE4_Unlock_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpRect);
	LogDXError(ret);

	if(g_binkActive == TRUE && g_config.displaymode != 0) {
		DDSURFACEDESC2 ddsd2;
		memset(&ddsd2, 0, sizeof(DDSURFACEDESC2));
		ddsd2.dwSize = sizeof(ddsd2);
		((IDirectDrawSurface4 *)ppvOut)->GetSurfaceDesc(&ddsd2);
		if(ddsd2.dwWidth == displaymode_options[g_config.displaymode].resX && ddsd2.dwHeight == displaymode_options[g_config.displaymode].resY
			&& g_lastLockedSurface == ppvOut && g_binkSurfaceNeedsStretch) {
			Log("Bink Active: Rescaling video surface...\n");
			RECT rcDest, rcSource;
			rcSource.top = g_currentviewport.old_y; rcSource.bottom = 480-g_currentviewport.old_y;
			rcSource.left = g_currentviewport.old_x; rcSource.right = 640-g_currentviewport.old_x;
			rcDest.top = g_currentviewport.y; rcDest.bottom = displaymode_options[g_config.displaymode].resY-g_currentviewport.y;
			rcDest.left = g_currentviewport.x; rcDest.right = displaymode_options[g_config.displaymode].resX-g_currentviewport.x;		

			if(g_binkCpySurface == NULL) {
				LPDIRECTDRAW4 lpDD = NULL;
				//LPDIRECTDRAWSURFACE4 lpDDS = NULL;
				DDSURFACEDESC2 ddsd;
				memset(&ddsd, 0, sizeof(DDSURFACEDESC2));
				ddsd.dwSize = sizeof(ddsd);
				ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
				ddsd.dwWidth = ddsd2.dwWidth;
				ddsd.dwHeight = ddsd2.dwHeight;
				ddsd.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_OFFSCREENPLAIN;

				((IDirectDrawSurface4 *)ppvOut)->GetDDInterface((LPVOID *)&lpDD);
				lpDD->CreateSurface(&ddsd, (LPDIRECTDRAWSURFACE4 *)&g_binkCpySurface, NULL);

				SAFE_RELEASE(lpDD);
			}

			((IDirectDrawSurface4 *)g_binkCpySurface)->Blt(&rcDest, (IDirectDrawSurface4 *)ppvOut, &rcSource, DDBLT_WAIT, NULL);

			if(g_d3ddevice != NULL) {
				LPDIRECT3DVIEWPORT3 lpVP = NULL;
				D3DVIEWPORT2 d3dvp_old, d3dvp_new;
				D3DRECT rect[4];
				memset(&rect, 0, sizeof(rect));
				memset(&d3dvp_old, 0, sizeof(d3dvp_old));
				d3dvp_old.dwSize = sizeof(d3dvp_old);

				((LPDIRECT3DDEVICE3)g_d3ddevice)->GetCurrentViewport(&lpVP);
				lpVP->GetViewport2(&d3dvp_old);

				memcpy(&d3dvp_new, &d3dvp_old, sizeof(d3dvp_new));
				d3dvp_new.dwX = d3dvp_new.dwY = 0;
				d3dvp_new.dwWidth = displaymode_options[g_config.displaymode].resX;
				d3dvp_new.dwHeight = displaymode_options[g_config.displaymode].resY;

				d3dvp_new.dwSize = 0; //special case for internal call
				d3dvp_old.dwSize = 0;
				
				lpVP->SetViewport2(&d3dvp_new);

				SetD3DRect(rect[0], 0, displaymode_options[g_config.displaymode].resX, 0, g_currentviewport.y);
				SetD3DRect(rect[1], 0, displaymode_options[g_config.displaymode].resX, g_currentviewport.y+g_game.height, displaymode_options[g_config.displaymode].resY);
				SetD3DRect(rect[2], 0, g_currentviewport.x, 0, displaymode_options[g_config.displaymode].resY);
				SetD3DRect(rect[3], g_currentviewport.x+g_game.width, displaymode_options[g_config.displaymode].resX, 0, displaymode_options[g_config.displaymode].resY);


				lpVP->Clear2(4, (LPD3DRECT)&rect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 0, 0);
				lpVP->SetViewport2(&d3dvp_old);
			}

			/*LPDIRECT3DVIEWPORT3 lpVP = NULL;
			D3DRECT rect;
			rect.x1 = rect.lX1 = rect.y1 = rect.lY1 = 0;
			rect.x2 = rect.lX2 = displaymode_options[g_config.displaymode].resX;
			rect.y2 = rect.lY2 = displaymode_options[g_config.displaymode].resY;

			((LPDIRECT3DDEVICE3)g_d3ddevice)->GetCurrentViewport(&lpVP);
			lpVP->Clear2(1, &rect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 0, 0);*/

			((IDirectDrawSurface4 *)ppvOut)->Blt(&rcDest, (IDirectDrawSurface4 *)g_binkCpySurface, &rcDest, DDBLT_WAIT, NULL);
		}
	}

	Log("IDirectDrawSurface4::%s(this=%#010lx, lpRect=%#010lx { left=%d, right=%d, top=%d, bottom=%d })\n", ddrawsurface4_hooks[hpos].name, ppvOut, lpRect, (lpRect != NULL ? lpRect->left : NULL), (lpRect != NULL ? lpRect->right : NULL), (lpRect != NULL ? lpRect->top : NULL), (lpRect != NULL ? lpRect->bottom : NULL));

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlay(LPVOID *ppvOut, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE4 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx) {
	const unsigned int hpos = 33;

	DDRAWSURFACE4_UpdateOverlay_Type ofn = (DDRAWSURFACE4_UpdateOverlay_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlayDisplay(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 34;

	DDRAWSURFACE4_UpdateOverlayDisplay_Type ofn = (DDRAWSURFACE4_UpdateOverlayDisplay_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlayZOrder(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSReference) {
	const unsigned int hpos = 35;

	DDRAWSURFACE4_UpdateOverlayZOrder_Type ofn = (DDRAWSURFACE4_UpdateOverlayZOrder_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags, lpDDSReference);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetDDInterface(LPVOID *ppvOut, LPVOID FAR *lplpDD) {
	const unsigned int hpos = 36;

	DDRAWSURFACE4_GetDDInterface_Type ofn = (DDRAWSURFACE4_GetDDInterface_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDD);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_PageLock(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 37;

	DDRAWSURFACE4_PageLock_Type ofn = (DDRAWSURFACE4_PageLock_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_PageUnlock(LPVOID *ppvOut, DWORD dwFlags) {
	const unsigned int hpos = 38;

	DDRAWSURFACE4_PageUnlock_Type ofn = (DDRAWSURFACE4_PageUnlock_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetSurfaceDesc(LPVOID *ppvOut, LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags) {
	const unsigned int hpos = 39;

	DDRAWSURFACE4_SetSurfaceDesc_Type ofn = (DDRAWSURFACE4_SetSurfaceDesc_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpddsd2, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_SetPrivateData(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpData, DWORD cbSize, DWORD dwFlags) {
	const unsigned int hpos = 40;

	DDRAWSURFACE4_SetPrivateData_Type ofn = (DDRAWSURFACE4_SetPrivateData_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, guidTag, lpData, cbSize, dwFlags);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPrivateData(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpBuffer, LPDWORD lpcbBufferSize) {
	const unsigned int hpos = 41;

	DDRAWSURFACE4_GetPrivateData_Type ofn = (DDRAWSURFACE4_GetPrivateData_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, guidTag, lpBuffer, lpcbBufferSize);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_FreePrivateData(LPVOID *ppvOut, REFGUID guidTag) {
	const unsigned int hpos = 42;

	DDRAWSURFACE4_FreePrivateData_Type ofn = (DDRAWSURFACE4_FreePrivateData_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, guidTag);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_GetUniquenessValue(LPVOID *ppvOut, LPDWORD lpValue) {
	const unsigned int hpos = 43;

	DDRAWSURFACE4_GetUniquenessValue_Type ofn = (DDRAWSURFACE4_GetUniquenessValue_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpValue);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}

HRESULT __stdcall DDRAWSURFACE4_HOOK_ChangeUniquenessValue(LPVOID *ppvOut) {
	const unsigned int hpos = 44;

	DDRAWSURFACE4_ChangeUniquenessValue_Type ofn = (DDRAWSURFACE4_ChangeUniquenessValue_Type)ddrawsurface4_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);
	LogDXError(ret);

	Log("IDirectDrawSurface4::%s()\n", ddrawsurface4_hooks[hpos].name);

	return ret;
}