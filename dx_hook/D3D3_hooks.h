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

#ifndef _D3D3_HOOKS
#define _D3D3_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3d3_hooks[];
extern const unsigned int count_d3d3_hooks;
extern bool ishooked_d3d3_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3D3_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3D3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3D3_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3D3_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3D3_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3D3_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3D3_EnumDevices_Type)(PVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);
HRESULT __stdcall D3D3_HOOK_EnumDevices(PVOID *ppvOut, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);

typedef HRESULT (__stdcall *D3D3_CreateLight_Type)(PVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, LPUNKNOWN pUnkOuter);
HRESULT __stdcall D3D3_HOOK_CreateLight(PVOID *ppvOut, LPDIRECT3DLIGHT *lplpDirect3DLight, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *D3D3_CreateMaterial_Type)(PVOID *ppvOut, LPDIRECT3DMATERIAL3 *lplpDirect3DMaterial, LPUNKNOWN pUnkOuter);
HRESULT __stdcall D3D3_HOOK_CreateMaterial(PVOID *ppvOut, LPDIRECT3DMATERIAL3 *lplpDirect3DMaterial, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *D3D3_CreateViewport_Type)(PVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpD3DViewport, LPUNKNOWN pUnkOuter);
HRESULT __stdcall D3D3_HOOK_CreateViewport(PVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpD3DViewport, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *D3D3_FindDevice_Type)(PVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR);
HRESULT __stdcall D3D3_HOOK_FindDevice(PVOID *ppvOut, LPD3DFINDDEVICESEARCH lpD3DFDS, LPD3DFINDDEVICERESULT lpD3DFDR);

typedef HRESULT (__stdcall *D3D3_CreateDevice_Type)(PVOID *ppvOut, REFCLSID refclsid, LPDIRECTDRAWSURFACE4 lpDDS, LPDIRECT3DDEVICE3 *lplpD3DDevice, LPUNKNOWN pUnkOuter);
HRESULT __stdcall D3D3_HOOK_CreateDevice(PVOID *ppvOut, REFCLSID refclsid, LPDIRECTDRAWSURFACE4 lpDDS, LPDIRECT3DDEVICE3 *lplpD3DDevice, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *D3D3_CreateVertexBuffer_Type)(PVOID *ppvOut, LPD3DVERTEXBUFFERDESC lpVBDesc, LPDIRECT3DVERTEXBUFFER *lpD3DVertexBuffer, DWORD dwFlags, LPUNKNOWN pUnkOuter);
HRESULT __stdcall D3D3_HOOK_CreateVertexBuffer(PVOID *ppvOut, LPD3DVERTEXBUFFERDESC lpVBDesc, LPDIRECT3DVERTEXBUFFER *lpD3DVertexBuffer, DWORD dwFlags, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *D3D3_EnumZBufferFormats_Type)(PVOID *ppvOut, REFCLSID riidDevice, LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback, LPVOID lpContext);
HRESULT __stdcall D3D3_HOOK_EnumZBufferFormats(PVOID *ppvOut, REFCLSID riidDevice, LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback, LPVOID lpContext);

typedef HRESULT (__stdcall *D3D3_EvictManagedTextures_Type)(PVOID *ppvOut);
HRESULT __stdcall D3D3_HOOK_EvictManagedTextures(PVOID *ppvOut);

#endif