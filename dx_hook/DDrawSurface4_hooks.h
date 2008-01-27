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

#ifndef _DDRAWSURFACE4_HOOKS
#define _DDRAWSURFACE4_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"
#include "ddraw4_hooks.h"

extern SVTBL_HOOK ddrawsurface4_hooks[];
extern const unsigned int count_ddrawsurface4_hooks;
extern bool ishooked_ddrawsurface4_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DDRAWSURFACE4_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DDRAWSURFACE4_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DDRAWSURFACE4_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAWSURFACE4_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DDRAWSURFACE4_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAWSURFACE4_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAWSURFACE4_AddAttachedSurface_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);
HRESULT __stdcall DDRAWSURFACE4_HOOK_AddAttachedSurface(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);

typedef HRESULT (__stdcall *DDRAWSURFACE4_AddOverlayDirtyRect_Type)(LPVOID *ppvOut, LPRECT lpRect);
HRESULT __stdcall DDRAWSURFACE4_HOOK_AddOverlayDirtyRect(LPVOID *ppvOut, LPRECT lpRect);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Blt_Type)(LPVOID *ppvOut, LPRECT lpDestRect, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Blt(LPVOID *ppvOut, LPRECT lpDestRect, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);

typedef HRESULT (__stdcall *DDRAWSURFACE4_BltBatch_Type)(LPVOID *ppvOut, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_BltBatch(LPVOID *ppvOut, LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_BltFast_Type)(LPVOID *ppvOut, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
HRESULT __stdcall DDRAWSURFACE4_HOOK_BltFast(LPVOID *ppvOut, DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);

typedef HRESULT (__stdcall *DDRAWSURFACE4_DeleteAttachedSurface_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);
HRESULT __stdcall DDRAWSURFACE4_HOOK_DeleteAttachedSurface(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface);

typedef HRESULT (__stdcall *DDRAWSURFACE4_EnumAttachedSurfaces_Type)(LPVOID *ppvOut, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback);
HRESULT __stdcall DDRAWSURFACE4_HOOK_EnumAttachedSurfaces(LPVOID *ppvOut, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback);

typedef HRESULT (__stdcall *DDRAWSURFACE4_EnumOverlayZOrders_Type)(LPVOID *ppvOut, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback);
HRESULT __stdcall DDRAWSURFACE4_HOOK_EnumOverlayZOrders(LPVOID *ppvOut, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Flip_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurfaceTargetOverride, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Flip(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpDDSurfaceTargetOverride, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetAttachedSurface_Type)(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE4 FAR *lplpDDAttachedSurface);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetAttachedSurface(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE4 FAR *lplpDDAttachedSurface);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetBltStatus_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetBltStatus(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetCaps_Type)(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetCaps(LPVOID *ppvOut, LPDDSCAPS2 lpDDSCaps);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetClipper_Type)(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetClipper(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER FAR *lplpDDClipper);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetColorKey_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetColorKey(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetDC_Type)(LPVOID *ppvOut, HDC FAR *lphDC);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetDC(LPVOID *ppvOut, HDC FAR *lphDC);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetFlipStatus_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetFlipStatus(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetOverlayPosition_Type)(LPVOID *ppvOut, LPLONG lplX, LPLONG lplY);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetOverlayPosition(LPVOID *ppvOut, LPLONG lplX, LPLONG lplY);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetPalette_Type)(LPVOID *ppvOut, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPalette(LPVOID *ppvOut, LPDIRECTDRAWPALETTE FAR *lplpDDPalette);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetPixelFormat_Type)(LPVOID *ppvOut, LPDDPIXELFORMAT lpDDPixelFormat);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPixelFormat(LPVOID *ppvOut, LPDDPIXELFORMAT lpDDPixelFormat);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetSurfaceDesc_Type)(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetSurfaceDesc(LPVOID *ppvOut, LPDDSURFACEDESC2 lpDDSurfaceDesc);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Initialize_Type)(LPVOID *ppvOut, LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Initialize(LPVOID *ppvOut, LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);

typedef HRESULT (__stdcall *DDRAWSURFACE4_IsLost_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAWSURFACE4_HOOK_IsLost(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Lock_Type)(LPVOID *ppvOut, LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Lock(LPVOID *ppvOut, LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);

typedef HRESULT (__stdcall *DDRAWSURFACE4_ReleaseDC_Type)(LPVOID *ppvOut, HDC hDC);
HRESULT __stdcall DDRAWSURFACE4_HOOK_ReleaseDC(LPVOID *ppvOut, HDC hDC);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Restore_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Restore(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetClipper_Type)(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER lpDDClipper);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetClipper(LPVOID *ppvOut, LPDIRECTDRAWCLIPPER lpDDClipper);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetColorKey_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetColorKey(LPVOID *ppvOut, DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetOverlayPosition_Type)(LPVOID *ppvOut, LONG lX, LONG lY);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetOverlayPosition(LPVOID *ppvOut, LONG lX, LONG lY);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetPalette_Type)(LPVOID *ppvOut, LPDIRECTDRAWPALETTE lpDDPalette);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetPalette(LPVOID *ppvOut, LPDIRECTDRAWPALETTE lpDDPalette);

typedef HRESULT (__stdcall *DDRAWSURFACE4_Unlock_Type)(LPVOID *ppvOut, LPRECT lpRect);
HRESULT __stdcall DDRAWSURFACE4_HOOK_Unlock(LPVOID *ppvOut, LPRECT lpRect);

typedef HRESULT (__stdcall *DDRAWSURFACE4_UpdateOverlay_Type)(LPVOID *ppvOut, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE4 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlay(LPVOID *ppvOut, LPRECT lpSrcRect, LPDIRECTDRAWSURFACE4 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);

typedef HRESULT (__stdcall *DDRAWSURFACE4_UpdateOverlayDisplay_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlayDisplay(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_UpdateOverlayZOrder_Type)(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSReference);
HRESULT __stdcall DDRAWSURFACE4_HOOK_UpdateOverlayZOrder(LPVOID *ppvOut, DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSReference);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetDDInterface_Type)(LPVOID *ppvOut, LPVOID FAR *lplpDD);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetDDInterface(LPVOID *ppvOut, LPVOID FAR *lplpDD);

typedef HRESULT (__stdcall *DDRAWSURFACE4_PageLock_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_PageLock(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_PageUnlock_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_PageUnlock(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetSurfaceDesc_Type)(LPVOID *ppvOut, LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetSurfaceDesc(LPVOID *ppvOut, LPDDSURFACEDESC2 lpddsd2, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_SetPrivateData_Type)(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpData, DWORD cbSize, DWORD dwFlags);
HRESULT __stdcall DDRAWSURFACE4_HOOK_SetPrivateData(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpData, DWORD cbSize, DWORD dwFlags);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetPrivateData_Type)(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpBuffer, LPDWORD lpcbBufferSize);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetPrivateData(LPVOID *ppvOut, REFGUID guidTag, LPVOID lpBuffer, LPDWORD lpcbBufferSize);

typedef HRESULT (__stdcall *DDRAWSURFACE4_FreePrivateData_Type)(LPVOID *ppvOut, REFGUID guidTag);
HRESULT __stdcall DDRAWSURFACE4_HOOK_FreePrivateData(LPVOID *ppvOut, REFGUID guidTag);

typedef HRESULT (__stdcall *DDRAWSURFACE4_GetUniquenessValue_Type)(LPVOID *ppvOut, LPDWORD lpValue);
HRESULT __stdcall DDRAWSURFACE4_HOOK_GetUniquenessValue(LPVOID *ppvOut, LPDWORD lpValue);

typedef HRESULT (__stdcall *DDRAWSURFACE4_ChangeUniquenessValue_Type)(LPVOID *ppvOut);
HRESULT __stdcall DDRAWSURFACE4_HOOK_ChangeUniquenessValue(LPVOID *ppvOut);

#endif