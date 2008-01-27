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

#ifndef _D3D_HOOKS
#define _D3D_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3d_hooks[];
extern const unsigned int count_d3d_hooks;
extern bool ishooked_d3d_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3D_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3D_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3D_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3D_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3D_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3D_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3D_Initialize_Type)(LPVOID *ppvOut, REFCLSID refclsid);
HRESULT __stdcall D3D_HOOK_Initialize(LPVOID *ppvOut, REFCLSID refclsid);

typedef HRESULT (__stdcall *D3D_EnumDevices_Type)(LPVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);
HRESULT __stdcall D3D_HOOK_EnumDevices(LPVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);

typedef HRESULT (__stdcall *D3D_CreateLight_Type)(LPVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, IUnknown *pUnkOuter);
HRESULT __stdcall D3D_HOOK_CreateLight(LPVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, IUnknown *pUnkOuter);

typedef HRESULT (__stdcall *D3D_CreateMaterial_Type)(LPVOID *ppvOut, LPDIRECT3DMATERIAL *lplpDirect3DMaterial, IUnknown *pUnkOuter);
HRESULT __stdcall D3D_HOOK_CreateMaterial(LPVOID *ppvOut, LPDIRECT3DMATERIAL *lplpDirect3DMaterial, IUnknown *pUnkOuter);

typedef HRESULT (__stdcall *D3D_CreateViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT *lplpD3DViewport,IUnknown *pUnkOuter);
HRESULT __stdcall D3D_HOOK_CreateViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT *lplpD3DViewport,IUnknown *pUnkOuter);

typedef HRESULT (__stdcall *D3D_FindDevice_Type)(LPVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR);
HRESULT __stdcall D3D_HOOK_FindDevice(LPVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR);

#endif