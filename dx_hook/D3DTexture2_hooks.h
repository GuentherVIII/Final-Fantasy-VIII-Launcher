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

#ifndef _D3DTEXTURE2_HOOKS
#define _D3DTEXTURE2_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3dtexture2_hooks[];
extern const unsigned int count_d3dtexture2_hooks;
extern bool ishooked_d3dtexture2_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3DTEXTURE2_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3DTEXTURE2_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3DTEXTURE2_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DTEXTURE2_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3DTEXTURE2_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DTEXTURE2_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DTEXTURE2_GetHandle_Type)(LPVOID *ppvOut, LPDIRECT3DDEVICE2 lpDirect3DDevice2, LPD3DTEXTUREHANDLE lpHandle);
HRESULT __stdcall D3DTEXTURE2_HOOK_GetHandle(LPVOID *ppvOut, LPDIRECT3DDEVICE2 lpDirect3DDevice2, LPD3DTEXTUREHANDLE lpHandle);

typedef HRESULT (__stdcall *D3DTEXTURE2_PaletteChanged_Type)(LPVOID *ppvOut, DWORD dwStart, DWORD dwCount);
HRESULT __stdcall D3DTEXTURE2_HOOK_PaletteChanged(LPVOID *ppvOut, DWORD dwStart, DWORD dwCount);

typedef HRESULT (__stdcall *D3DTEXTURE2_Load_Type)(LPVOID *ppvOut, LPDIRECT3DTEXTURE2 lpD3DTexture2);
HRESULT __stdcall D3DTEXTURE2_HOOK_Load(LPVOID *ppvOut, LPDIRECT3DTEXTURE2 lpD3DTexture2);


#endif