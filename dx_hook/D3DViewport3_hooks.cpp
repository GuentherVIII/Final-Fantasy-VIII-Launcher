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

#include "d3dviewport3_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK d3dviewport3_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)D3DVIEWPORT3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DVIEWPORT3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Release },
/*3*/	{ "Initialize",				0x0C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Initialize },
/*4*/	{ "GetViewport",			0x10, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport },
/*5*/	{ "GetViewport",			0x14, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport },
/*6*/	{ "TransformVertices",		0x18, NULL, (PDWORD)D3DVIEWPORT3_HOOK_TransformVertices },
/*7*/	{ "LightElements",			0x1C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_LightElements },
/*8*/	{ "SetBackground",			0x20, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackground },
/*9*/	{ "GetBackground",			0x24, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackground },
/*10*/	{ "SetBackgroundDepth",		0x28, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackgroundDepth },
/*11*/	{ "GetBackgroundDepth",		0x2C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackgroundDepth },
/*12*/	{ "Clear",					0x30, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Clear },
/*13*/	{ "AddLight",				0x34, NULL, (PDWORD)D3DVIEWPORT3_HOOK_AddLight },
/*14*/	{ "DeleteLight",			0x38, NULL, (PDWORD)D3DVIEWPORT3_HOOK_DeleteLight },
/*15*/	{ "NextLight",				0x3C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_NextLight },
/*16*/	{ "GetViewport2",			0x40, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport2 },
/*17*/	{ "SetViewport2",			0x44, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetViewport2 },
/*18*/	{ "SetBackgroundDepth2",	0x48, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackgroundDepth2 },
/*19*/	{ "GetBackgroundDepth2",	0x4C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackgroundDepth2 },
/*20*/	{ "Clear2",					0x50, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Clear2 }
};
#else
SVTBL_HOOK d3dviewport3_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)D3DVIEWPORT3_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)D3DVIEWPORT3_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x0C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Initialize },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "GetViewport",			0x10, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "GetViewport",			0x14, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "TransformVertices",		0x18, NULL, (PDWORD)D3DVIEWPORT3_HOOK_TransformVertices },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "LightElements",			0x1C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_LightElements },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "SetBackground",			0x20, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackground },
/*9*/	{ NULL, 0, NULL, NULL },	//{ "GetBackground",			0x24, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackground },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "SetBackgroundDepth",		0x28, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackgroundDepth },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "GetBackgroundDepth",		0x2C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackgroundDepth },
/*12*/	{ "Clear",					0x30, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Clear },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "AddLight",				0x34, NULL, (PDWORD)D3DVIEWPORT3_HOOK_AddLight },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "DeleteLight",			0x38, NULL, (PDWORD)D3DVIEWPORT3_HOOK_DeleteLight },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "NextLight",				0x3C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_NextLight },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "GetViewport2",			0x40, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetViewport2 },
/*17*/	{ "SetViewport2",			0x44, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetViewport2 },
/*18*/	{ NULL, 0, NULL, NULL },	//{ "SetBackgroundDepth2",	0x48, NULL, (PDWORD)D3DVIEWPORT3_HOOK_SetBackgroundDepth2 },
/*19*/	{ NULL, 0, NULL, NULL },	//{ "GetBackgroundDepth2",	0x4C, NULL, (PDWORD)D3DVIEWPORT3_HOOK_GetBackgroundDepth2 },
/*20*/	{ NULL, 0, NULL, NULL },	//{ "Clear2",					0x50, NULL, (PDWORD)D3DVIEWPORT3_HOOK_Clear2 }
};
#endif
const unsigned int count_d3dviewport3_hooks = 21;
bool ishooked_d3dviewport3_hooks = false;

HRESULT __stdcall D3DVIEWPORT3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	D3DVIEWPORT3_QueryInterface_Type ofn = (D3DVIEWPORT3_QueryInterface_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, riid={ %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, ppvObj=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall D3DVIEWPORT3_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	D3DVIEWPORT3_AddRef_Type ofn = (D3DVIEWPORT3_AddRef_Type)d3dviewport3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DViewport3::%s(this=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut);

	return ret;
}

ULONG __stdcall D3DVIEWPORT3_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	D3DVIEWPORT3_Release_Type ofn = (D3DVIEWPORT3_Release_Type)d3dviewport3_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirect3DViewport3::%s(this=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_Initialize(LPVOID *ppvOut, LPDIRECT3D lpDirect3D) {
	const unsigned int hpos = 3;

	D3DVIEWPORT3_Initialize_Type ofn = (D3DVIEWPORT3_Initialize_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3D);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDirect3D=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDirect3D);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_GetViewport(LPVOID *ppvOut, LPD3DVIEWPORT lpData) {
	const unsigned int hpos = 4;

	D3DVIEWPORT3_GetViewport_Type ofn = (D3DVIEWPORT3_GetViewport_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpData);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpData=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpData);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_SetViewport(LPVOID *ppvOut, LPD3DVIEWPORT lpData) {
	const unsigned int hpos = 5;

	D3DVIEWPORT3_SetViewport_Type ofn = (D3DVIEWPORT3_SetViewport_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpData);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpData=%#010lx { dwSize=%#010lx, dwX=%#010lx (%d), dwY=%#010lx (%d), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), dvScaleX=%f, dvScaleY=%f, dvMaxX=%f, dvMaxY=%f, dvMaxZ=%f, dvMinZ=%f })\n", d3dviewport3_hooks[hpos].name, ppvOut, lpData, lpData->dwSize, lpData->dwX, lpData->dwX, lpData->dwY, lpData->dwY, lpData->dwWidth, lpData->dwWidth, lpData->dwHeight, lpData->dwHeight, lpData->dvScaleX, lpData->dvScaleY, lpData->dvMaxX, lpData->dvMaxY, lpData->dvMaxZ, lpData->dvMinZ);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_TransformVertices(LPVOID *ppvOut, DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen) {
	const unsigned int hpos = 6;

	D3DVIEWPORT3_TransformVertices_Type ofn = (D3DVIEWPORT3_TransformVertices_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwVertexCount, lpData, dwFlags, lpOffscreen);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, dwVertexCount=%#010lx (%d), lpData=%#010lx, dwFlags=%#010lx, lpOffscreen=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, dwVertexCount, dwVertexCount, lpData, dwFlags, lpOffscreen);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_LightElements(LPVOID *ppvOut, DWORD dwElementCount, LPD3DLIGHTDATA lpData) {
	const unsigned int hpos = 7;

	D3DVIEWPORT3_LightElements_Type ofn = (D3DVIEWPORT3_LightElements_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwElementCount, lpData);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, dwElementCount=%#010lx (%d), lpData=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, dwElementCount, dwElementCount, lpData);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackground(LPVOID *ppvOut, D3DMATERIALHANDLE hMat) {
	const unsigned int hpos = 8;

	D3DVIEWPORT3_SetBackground_Type ofn = (D3DVIEWPORT3_SetBackground_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hMat);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, hMat=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, hMat);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackground(LPVOID *ppvOut, LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid) {
	const unsigned int hpos = 9;

	D3DVIEWPORT3_GetBackground_Type ofn = (D3DVIEWPORT3_GetBackground_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lphMat, lpValid);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lphMat=%#010lx *[%#010lx], lpValid=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lphMat, (lphMat != NULL ? *lphMat : NULL), lpValid);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackgroundDepth(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface) {
	const unsigned int hpos = 10;

	D3DVIEWPORT3_SetBackgroundDepth_Type ofn = (D3DVIEWPORT3_SetBackgroundDepth_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDSurface);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDDSurface=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDDSurface);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackgroundDepth(LPVOID *ppvOut, LPDIRECTDRAWSURFACE *lplpDDSurface, LPBOOL lpValid) {
	const unsigned int hpos = 11;

	D3DVIEWPORT3_GetBackgroundDepth_Type ofn = (D3DVIEWPORT3_GetBackgroundDepth_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDDSurface, lpValid);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lplpDDSurface=%#010lx *[%#010lx], lpValid=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lplpDDSurface, (lplpDDSurface != NULL ? *lplpDDSurface : NULL), lpValid);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_Clear(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags) {
	const unsigned int hpos = 12;

	if(g_config.displaymode != 0) {
		if(dwCount == 1 && lpRects != NULL) {
			lpRects[0].x2 = displaymode_options[g_config.displaymode].resX;
			lpRects[0].y2 = displaymode_options[g_config.displaymode].resY;
			lpRects[0].lX2 = displaymode_options[g_config.displaymode].resX;
			lpRects[0].lY2 = displaymode_options[g_config.displaymode].resY;
		}
	}

	D3DVIEWPORT3_Clear_Type ofn = (D3DVIEWPORT3_Clear_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwCount, lpRects, dwFlags);
	LogDXError(ret);

	char dwFlags_buffer[LOGBUFFER_MAX], lpRects_buffer[LOGBUFFER_MAX];
	if(dwCount >= 1) {
		_snprintf_s(lpRects_buffer, LOGBUFFER_MAX, LOGBUFFER_MAX, " { x1=%d, x2=%d, y1=%d, y2=%d, lX1=%d, lX2=%d, lY1=%d, lY2=%d }", lpRects[0].x1, lpRects[0].x2, lpRects[0].y1, lpRects[0].y2, lpRects[0].lX1, lpRects[0].lX2, lpRects[0].lY1, lpRects[0].lY2);
	} else lpRects_buffer[0] = '\0';
	FlagsToString(FLAGS_D3DCLEAR, CFLAGS_D3DCLEAR, dwFlags, (char *)&dwFlags_buffer, LOGBUFFER_MAX);
	Log("IDirect3DViewport3::%s(this=%#010lx, dwCount=%#010lx (%d), lpRects=%#010lx%s, dwFlags=%#010lx (%s))\n", d3dviewport3_hooks[hpos].name, ppvOut, dwCount, dwCount, lpRects, lpRects_buffer, dwFlags, dwFlags_buffer);

	/*if(g_config.displaymode != 0) {
		D3DRECT r[2];
		r[0].x1 = r[0].lX1 = 0;
		r[0].x2 = r[0].lX2 = displaymode_options[g_config.displaymode].resX;
		r[0].y1 = r[0].lY1 = 0;
		r[0].y2 = r[0].lY2 = g_currentviewport.y;

		r[1].x1 = r[1].lX1 = 0;
		r[1].x2 = r[1].lX2 = displaymode_options[g_config.displaymode].resX;
		r[1].y1 = r[1].lY1 = displaymode_options[g_config.displaymode].resY-g_currentviewport.y;
		r[1].y2 = r[1].lY2 = displaymode_options[g_config.displaymode].resY;

		HRESULT ret;
		if((ret = ofn(ppvOut, 2, (LPD3DRECT)&r, D3DCLEAR_TARGET)) != S_OK) {
			std::map<HRESULT, char *> errcodes;
			errcodes[D3DERR_VIEWPORTHASNODEVICE] = "D3DERR_VIEWPORTHASNODEVICE";
			errcodes[D3DERR_ZBUFFER_NOTPRESENT] = "D3DERR_ZBUFFER_NOTPRESENT";
			errcodes[DDERR_INVALIDOBJECT] = "DDERR_INVALIDOBJECT";
			errcodes[DDERR_INVALIDPARAMS] = "DDERR_INVALIDPARAMS";
			if(errcodes.find(ret) != errcodes.end()) {
				Log("ERROR1: %s", errcodes[ret]);
			}
		}
	}*/

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_AddLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight) {
	const unsigned int hpos = 13;

	D3DVIEWPORT3_AddLight_Type ofn = (D3DVIEWPORT3_AddLight_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DLight);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDirect3DLight=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDirect3DLight);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_DeleteLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight) {
	const unsigned int hpos = 14;

	D3DVIEWPORT3_DeleteLight_Type ofn = (D3DVIEWPORT3_DeleteLight_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DLight);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDirect3DLight=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDirect3DLight);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_NextLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT *lplpDirect3DLight, DWORD dwFlags) {
	const unsigned int hpos = 15;

	D3DVIEWPORT3_NextLight_Type ofn = (D3DVIEWPORT3_NextLight_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDirect3DLight, lplpDirect3DLight, dwFlags);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDirect3DLight=%#010lx, lplpDirect3DLight=%#010lx *[%#010lx], dwFlags=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDirect3DLight, lplpDirect3DLight, (lplpDirect3DLight != NULL ? *lplpDirect3DLight : NULL), dwFlags);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_GetViewport2(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData) {
	const unsigned int hpos = 16;

	D3DVIEWPORT3_GetViewport2_Type ofn = (D3DVIEWPORT3_GetViewport2_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpData);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpData=%#010lx { dwSize=%#010lx, dwX=%#010lx (%d), dwY=%#010lx (%d), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), dvClipX=%f, dvClipY=%f, dvClipWidth=%f, dvClipHeight=%f, dvMinZ=%f, dvMaxZ=%f })\n", d3dviewport3_hooks[hpos].name, ppvOut, lpData, lpData->dwSize, lpData->dwX, lpData->dwX, lpData->dwY, lpData->dwY, lpData->dwWidth, lpData->dwWidth, lpData->dwHeight, lpData->dwHeight, lpData->dvClipX, lpData->dvClipY, lpData->dvClipWidth, lpData->dvClipHeight, lpData->dvMinZ, lpData->dvMaxZ);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_SetViewport2(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData) {
	const unsigned int hpos = 17;

	if(g_config.displaymode != 0 && lpData->dwSize != 0) {
		g_currentviewport.old_width = lpData->dwWidth;
		g_currentviewport.old_height = lpData->dwHeight;
		g_currentviewport.old_x = lpData->dwX;
		g_currentviewport.old_y = lpData->dwY;

		g_currentviewport.width = (DWORD)(lpData->dwWidth * g_game.modX);
		g_currentviewport.height = (DWORD)(lpData->dwHeight * g_game.modY);
		g_currentviewport.x = (int)(lpData->dwX * g_game.modX) + (((int)displaymode_options[g_config.displaymode].resX - (int)g_game.width) / 2);
		g_currentviewport.y = (int)(lpData->dwY * g_game.modY) + (((int)displaymode_options[g_config.displaymode].resY - (int)g_game.height) / 2);

		lpData->dwX = g_currentviewport.x;
		if(g_currentviewport.x < 0)
			lpData->dwX = 0;
		lpData->dwY = g_currentviewport.y;
		if(g_currentviewport.y < 0)
			lpData->dwY = 0;
		lpData->dwWidth = min(displaymode_options[g_config.displaymode].resX - lpData->dwX, g_currentviewport.width);
		lpData->dwHeight = min(displaymode_options[g_config.displaymode].resY - lpData->dwY, g_currentviewport.height);
	} else if(lpData->dwSize == 0) {
		lpData->dwSize = sizeof(D3DVIEWPORT2);
	}

	D3DVIEWPORT3_SetViewport2_Type ofn = (D3DVIEWPORT3_SetViewport2_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpData);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpData=%#010lx { dwSize=%#010lx, dwX=%#010lx (%d), dwY=%#010lx (%d), dwWidth=%#010lx (%d), dwHeight=%#010lx (%d), dvClipX=%f, dvClipY=%f, dvClipWidth=%f, dvClipHeight=%f, dvMinZ=%f, dvMaxZ=%f })\n", d3dviewport3_hooks[hpos].name, ppvOut, lpData, lpData->dwSize, lpData->dwX, lpData->dwX, lpData->dwY, lpData->dwY, lpData->dwWidth, lpData->dwWidth, lpData->dwHeight, lpData->dwHeight, lpData->dvClipX, lpData->dvClipY, lpData->dvClipWidth, lpData->dvClipHeight, lpData->dvMinZ, lpData->dvMaxZ);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackgroundDepth2(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDS) {
	const unsigned int hpos = 18;

	D3DVIEWPORT3_SetBackgroundDepth2_Type ofn = (D3DVIEWPORT3_SetBackgroundDepth2_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDDS);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lpDDS=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lpDDS);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackgroundDepth2(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpDDS, LPBOOL lpValid) {
	const unsigned int hpos = 19;

	D3DVIEWPORT3_GetBackgroundDepth2_Type ofn = (D3DVIEWPORT3_GetBackgroundDepth2_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lplpDDS, lpValid);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, lplpDDS=%#010lx *[%#010lx], lpValid=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, lplpDDS, (lplpDDS != NULL ? *lplpDDS : NULL), lpValid);

	return ret;
}

HRESULT __stdcall D3DVIEWPORT3_HOOK_Clear2(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags, D3DCOLOR dwColor, D3DVALUE dvZ, DWORD dwStencil) {
	const unsigned int hpos = 20;

	D3DVIEWPORT3_Clear2_Type ofn = (D3DVIEWPORT3_Clear2_Type)d3dviewport3_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil);
	LogDXError(ret);

	Log("IDirect3DViewport3::%s(this=%#010lx, dwCount=%#010lx (%d), lpRects=%#010lx, dwFlags=%#010lx, dwColor=%#010lx, dvZ=%f, dwStencil=%#010lx)\n", d3dviewport3_hooks[hpos].name, ppvOut, dwCount, dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil);

	return ret;
}