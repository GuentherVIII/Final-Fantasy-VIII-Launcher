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

#ifndef _DDRAW_HOOKS
#define _DDRAW_HOOKS

#include <ddraw.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK ddraw_hooks[];
extern const unsigned int count_ddraw_hooks;
extern bool ishooked_ddraw_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DDRAW_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DDRAW_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DDRAW_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DDRAW_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW_Compact_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW_HOOK_Compact(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW_CreateClipper_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW_HOOK_CreateClipper(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW_CreatePalette_Type)(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW_HOOK_CreatePalette(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW_CreateSurface_Type)(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR *lplpDDSurface, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW_HOOK_CreateSurface(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR *lplpDDSurface, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW_DuplicateSurface_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface);
HRESULT __stdcall DDRAW_HOOK_DuplicateSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface);

typedef HRESULT (__stdcall *DDRAW_EnumDisplayModes_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback);
HRESULT __stdcall DDRAW_HOOK_EnumDisplayModes(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback);

typedef HRESULT (__stdcall *DDRAW_EnumSurfaces_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
HRESULT __stdcall DDRAW_HOOK_EnumSurfaces(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);

typedef HRESULT (__stdcall *DDRAW_FlipToGDISurface_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW_HOOK_FlipToGDISurface(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW_GetCaps_Type)(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps);
HRESULT __stdcall DDRAW_HOOK_GetCaps(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps);

typedef HRESULT (__stdcall *DDRAW_GetDisplayMode_Type)(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc2);
HRESULT __stdcall DDRAW_HOOK_GetDisplayMode(LPVOID *ppvOut, LPDDSURFACEDESC lpDDSurfaceDesc2);

typedef HRESULT (__stdcall *DDRAW_GetFourCCCodes_Type)(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes);
HRESULT __stdcall DDRAW_HOOK_GetFourCCCodes(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes);

typedef HRESULT (__stdcall *DDRAW_GetGDISurface_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE FAR *lplpGDIDDSurface);
HRESULT __stdcall DDRAW_HOOK_GetGDISurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE FAR *lplpGDIDDSurface);

typedef HRESULT (__stdcall *DDRAW_GetMonitorFrequency_Type)(LPVOID *ppvOut, LPDWORD lpdwFrequency);
HRESULT __stdcall DDRAW_HOOK_GetMonitorFrequency(LPVOID *ppvOut, LPDWORD lpdwFrequency);

typedef HRESULT (__stdcall *DDRAW_GetScanLine_Type)(LPVOID *ppvOut, LPDWORD lpdwScanLine);
HRESULT __stdcall DDRAW_HOOK_GetScanLine(LPVOID *ppvOut, LPDWORD lpdwScanLine);

typedef HRESULT (__stdcall *DDRAW_GetVerticalBlankStatus_Type)(LPVOID *ppvOut, LPBOOL lpbIsInVB);
HRESULT __stdcall DDRAW_HOOK_GetVerticalBlankStatus(LPVOID *ppvOut, LPBOOL lpbIsInVB);

typedef HRESULT (__stdcall *DDRAW_Initialize_Type)(LPVOID *ppvOut, GUID FAR *lpGUID);
HRESULT __stdcall DDRAW_HOOK_Initialize(LPVOID *ppvOut, GUID FAR *lpGUID);

typedef HRESULT (__stdcall *DDRAW_RestoreDisplayMode_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW_HOOK_RestoreDisplayMode(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW_SetCooperativeLevel_Type)(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags);
HRESULT __stdcall DDRAW_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAW_SetDisplayMode_Type)(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP);
HRESULT __stdcall DDRAW_HOOK_SetDisplayMode(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP);

typedef HRESULT (__stdcall *DDRAW_WaitForVerticalBlank_Type)(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent);
HRESULT __stdcall DDRAW_HOOK_WaitForVerticalBlank(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent);

#endif