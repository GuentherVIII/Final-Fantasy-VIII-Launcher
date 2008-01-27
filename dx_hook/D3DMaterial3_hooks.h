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

#ifndef _D3DMATERIAL3_HOOKS
#define _D3DMATERIAL3_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3dmaterial3_hooks[];
extern const unsigned int count_d3dmaterial3_hooks;
extern bool ishooked_d3dmaterial3_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3DMATERIAL3_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3DMATERIAL3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3DMATERIAL3_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DMATERIAL3_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3DMATERIAL3_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DMATERIAL3_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DMATERIAL3_SetMaterial_Type)(LPVOID *ppvOut, LPD3DMATERIAL lpMat);
HRESULT __stdcall D3DMATERIAL3_HOOK_SetMaterial(LPVOID *ppvOut, LPD3DMATERIAL lpMat);

typedef HRESULT (__stdcall *D3DMATERIAL3_GetMaterial_Type)(LPVOID *ppvOut, LPD3DMATERIAL lpMat);
HRESULT __stdcall D3DMATERIAL3_HOOK_GetMaterial(LPVOID *ppvOut, LPD3DMATERIAL lpMat);

typedef HRESULT (__stdcall *D3DMATERIAL3_GetHandle_Type)(LPVOID *ppvOut, LPDIRECT3DDEVICE3 lpDirect3DDevice, LPD3DMATERIALHANDLE lpHandle);
HRESULT __stdcall D3DMATERIAL3_HOOK_GetHandle(LPVOID *ppvOut, LPDIRECT3DDEVICE3 lpDirect3DDevice, LPD3DMATERIALHANDLE lpHandle);

#endif