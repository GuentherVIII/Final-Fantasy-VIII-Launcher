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

#ifndef _D3DVIEWPORT3_HOOKS
#define _D3DVIEWPORT3_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3dviewport3_hooks[];
extern const unsigned int count_d3dviewport3_hooks;
extern bool ishooked_d3dviewport3_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3DVIEWPORT3_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3DVIEWPORT3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3DVIEWPORT3_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DVIEWPORT3_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3DVIEWPORT3_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DVIEWPORT3_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DVIEWPORT3_Initialize_Type)(LPVOID *ppvOut, LPDIRECT3D lpDirect3D);
HRESULT __stdcall D3DVIEWPORT3_HOOK_Initialize(LPVOID *ppvOut, LPDIRECT3D lpDirect3D);

typedef HRESULT (__stdcall *D3DVIEWPORT3_GetViewport_Type)(LPVOID *ppvOut, LPD3DVIEWPORT lpData);
HRESULT __stdcall D3DVIEWPORT3_HOOK_GetViewport(LPVOID *ppvOut, LPD3DVIEWPORT lpData);

typedef HRESULT (__stdcall *D3DVIEWPORT3_SetViewport_Type)(LPVOID *ppvOut, LPD3DVIEWPORT lpData);
HRESULT __stdcall D3DVIEWPORT3_HOOK_SetViewport(LPVOID *ppvOut, LPD3DVIEWPORT lpData);

typedef HRESULT (__stdcall *D3DVIEWPORT3_TransformVertices_Type)(LPVOID *ppvOut, DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen);
HRESULT __stdcall D3DVIEWPORT3_HOOK_TransformVertices(LPVOID *ppvOut, DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen);

typedef HRESULT (__stdcall *D3DVIEWPORT3_LightElements_Type)(LPVOID *ppvOut, DWORD dwElementCount, LPD3DLIGHTDATA lpData);
HRESULT __stdcall D3DVIEWPORT3_HOOK_LightElements(LPVOID *ppvOut, DWORD dwElementCount, LPD3DLIGHTDATA lpData);

typedef HRESULT (__stdcall *D3DVIEWPORT3_SetBackground_Type)(LPVOID *ppvOut, D3DMATERIALHANDLE hMat);
HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackground(LPVOID *ppvOut, D3DMATERIALHANDLE hMat);

typedef HRESULT (__stdcall *D3DVIEWPORT3_GetBackground_Type)(LPVOID *ppvOut, LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid);
HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackground(LPVOID *ppvOut, LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid);

typedef HRESULT (__stdcall *D3DVIEWPORT3_SetBackgroundDepth_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface);
HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackgroundDepth(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface);

typedef HRESULT (__stdcall *D3DVIEWPORT3_GetBackgroundDepth_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE *lplpDDSurface, LPBOOL lpValid);
HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackgroundDepth(LPVOID *ppvOut, LPDIRECTDRAWSURFACE *lplpDDSurface, LPBOOL lpValid);

typedef HRESULT (__stdcall *D3DVIEWPORT3_Clear_Type)(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags);
HRESULT __stdcall D3DVIEWPORT3_HOOK_Clear(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DVIEWPORT3_AddLight_Type)(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight);
HRESULT __stdcall D3DVIEWPORT3_HOOK_AddLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight);

typedef HRESULT (__stdcall *D3DVIEWPORT3_DeleteLight_Type)(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight);
HRESULT __stdcall D3DVIEWPORT3_HOOK_DeleteLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight);

typedef HRESULT (__stdcall *D3DVIEWPORT3_NextLight_Type)(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT *lplpDirect3DLight, DWORD dwFlags);
HRESULT __stdcall D3DVIEWPORT3_HOOK_NextLight(LPVOID *ppvOut, LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT *lplpDirect3DLight, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DVIEWPORT3_GetViewport2_Type)(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData);
HRESULT __stdcall D3DVIEWPORT3_HOOK_GetViewport2(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData);

typedef HRESULT (__stdcall *D3DVIEWPORT3_SetViewport2_Type)(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData);
HRESULT __stdcall D3DVIEWPORT3_HOOK_SetViewport2(LPVOID *ppvOut, LPD3DVIEWPORT2 lpData);

typedef HRESULT (__stdcall *D3DVIEWPORT3_SetBackgroundDepth2_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDS);
HRESULT __stdcall D3DVIEWPORT3_HOOK_SetBackgroundDepth2(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDS);

typedef HRESULT (__stdcall *D3DVIEWPORT3_GetBackgroundDepth2_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpDDS, LPBOOL lpValid);
HRESULT __stdcall D3DVIEWPORT3_HOOK_GetBackgroundDepth2(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpDDS, LPBOOL lpValid);

typedef HRESULT (__stdcall *D3DVIEWPORT3_Clear2_Type)(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags, D3DCOLOR dwColor, D3DVALUE dvZ, DWORD dwStencil);
HRESULT __stdcall D3DVIEWPORT3_HOOK_Clear2(LPVOID *ppvOut, DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags, D3DCOLOR dwColor, D3DVALUE dvZ, DWORD dwStencil);

#endif