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

#ifndef _DDRAW4_HOOKS
#define _DDRAW4_HOOKS

#include <ddraw.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK ddraw4_hooks[];
extern const unsigned int count_ddraw4_hooks;
extern bool ishooked_ddraw4_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DDRAW4_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DDRAW4_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DDRAW4_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW4_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DDRAW4_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW4_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_Compact_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW4_HOOK_Compact(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_CreateClipper_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW4_HOOK_CreateClipper(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW4_CreatePalette_Type)(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW4_HOOK_CreatePalette(LPVOID *ppvOut, DWORD dwFlags, LPPALETTEENTRY lpDDColorArray, LPDIRECTDRAWPALETTE FAR *lplpDDPalette, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW4_CreateSurface_Type)(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE4 FAR *lplpDDSurface4, IUnknown FAR *pUnkOuter);
HRESULT __stdcall DDRAW4_HOOK_CreateSurface(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE4 FAR *lplpDDSurface4, IUnknown FAR *pUnkOuter);

typedef HRESULT (__stdcall *DDRAW4_DuplicateSurface_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurface4, LPDIRECTDRAWSURFACE4 FAR *lplpDupDDSurface4);
HRESULT __stdcall DDRAW4_HOOK_DuplicateSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurface4, LPDIRECTDRAWSURFACE4 FAR *lplpDupDDSurface4);

typedef HRESULT (__stdcall *DDRAW4_EnumDisplayModes_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext, LPDDENUMMODESCALLBACK2 lpEnumModesCallback2);
HRESULT __stdcall DDRAW4_HOOK_EnumDisplayModes(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext, LPDDENUMMODESCALLBACK2 lpEnumModesCallback2);

typedef HRESULT (__stdcall *DDRAW4_EnumSurfaces_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSD2, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback2);
HRESULT __stdcall DDRAW4_HOOK_EnumSurfaces(LPVOID *ppvOut, DWORD dwFlags, LPDDSURFACEDESC2 lpDDSD2, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback2);

typedef HRESULT (__stdcall *DDRAW4_FlipToGDISurface_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW4_HOOK_FlipToGDISurface(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_GetCaps_Type)(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps);
HRESULT __stdcall DDRAW4_HOOK_GetCaps(LPVOID *ppvOut, LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps);

typedef HRESULT (__stdcall *DDRAW4_GetDisplayMode_Type)(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc2);
HRESULT __stdcall DDRAW4_HOOK_GetDisplayMode(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc2);

typedef HRESULT (__stdcall *DDRAW4_GetFourCCCodes_Type)(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes);
HRESULT __stdcall DDRAW4_HOOK_GetFourCCCodes(LPVOID *ppvOut, LPDWORD lpNumCodes, LPDWORD lpCodes);

typedef HRESULT (__stdcall *DDRAW4_GetGDISurface_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE2 FAR *lplpGDIDDSurface4);
HRESULT __stdcall DDRAW4_HOOK_GetGDISurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE2 FAR *lplpGDIDDSurface4);

typedef HRESULT (__stdcall *DDRAW4_GetMonitorFrequency_Type)(LPVOID *ppvOut, LPDWORD lpdwFrequency);
HRESULT __stdcall DDRAW4_HOOK_GetMonitorFrequency(LPVOID *ppvOut, LPDWORD lpdwFrequency);

typedef HRESULT (__stdcall *DDRAW4_GetScanLine_Type)(LPVOID *ppvOut, LPDWORD lpdwScanLine);
HRESULT __stdcall DDRAW4_HOOK_GetScanLine(LPVOID *ppvOut, LPDWORD lpdwScanLine);

typedef HRESULT (__stdcall *DDRAW4_GetVerticalBlankStatus_Type)(LPVOID *ppvOut, LPBOOL lpbIsInVB);
HRESULT __stdcall DDRAW4_HOOK_GetVerticalBlankStatus(LPVOID *ppvOut, LPBOOL lpbIsInVB);

typedef HRESULT (__stdcall *DDRAW4_Initialize_Type)(LPVOID *ppvOut, GUID FAR *lpGUID);
HRESULT __stdcall DDRAW4_HOOK_Initialize(LPVOID *ppvOut, GUID FAR *lpGUID);

typedef HRESULT (__stdcall *DDRAW4_RestoreDisplayMode_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW4_HOOK_RestoreDisplayMode(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_SetCooperativeLevel_Type)(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags);
HRESULT __stdcall DDRAW4_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hWnd, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAW4_SetDisplayMode_Type)(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags);
HRESULT __stdcall DDRAW4_HOOK_SetDisplayMode(LPVOID *ppvOut, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAW4_WaitForVerticalBlank_Type)(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent);
HRESULT __stdcall DDRAW4_HOOK_WaitForVerticalBlank(LPVOID *ppvOut, DWORD dwFlags, HANDLE hEvent);

typedef HRESULT (__stdcall *DDRAW4_GetAvailableVidMem_Type)(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps2, LPDWORD lpdwTotal, LPDWORD lpdwFree);
HRESULT __stdcall DDRAW4_HOOK_GetAvailableVidMem(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps2, LPDWORD lpdwTotal, LPDWORD lpdwFree);

typedef HRESULT (__stdcall *DDRAW4_GetSurfaceFromDC_Type)(LPVOID *ppvOut, HDC hdc, LPDIRECTDRAWSURFACE4 *lpDDS4);
HRESULT __stdcall DDRAW4_HOOK_GetSurfaceFromDC(LPVOID *ppvOut, HDC hdc, LPDIRECTDRAWSURFACE4 *lpDDS4);

typedef HRESULT (__stdcall *DDRAW4_RestoreAllSurfaces_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW4_HOOK_RestoreAllSurfaces(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_TestCooperativeLevel_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAW4_HOOK_TestCooperativeLevel(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAW4_GetDeviceIdentifier_Type)(LPVOID *ppvOut, LPDDDEVICEIDENTIFIER lpdddi, DWORD dwFlags);
HRESULT __stdcall DDRAW4_HOOK_GetDeviceIdentifier(LPVOID *ppvOut, LPDDDEVICEIDENTIFIER lpdddi, DWORD dwFlags);

#endif