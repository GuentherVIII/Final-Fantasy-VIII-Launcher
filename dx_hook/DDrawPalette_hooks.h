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

#ifndef _DDRAWPALETTE_HOOKS
#define _DDRAWPALETTE_HOOKS

#include <ddraw.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK ddrawpalette_hooks[];
extern const unsigned int count_ddrawpalette_hooks;
extern bool ishooked_ddrawpalette_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DDRAWPALETTE_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DDRAWPALETTE_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DDRAWPALETTE_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW_HOOKPALETTE_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DDRAWPALETTE_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DDRAW_HOOKPALETTE_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DDRAWPALETTE_GetCaps_Type)(LPVOID *ppvOut, LPDWORD lpdwCaps);
HRESULT __stdcall DDRAWPALETTE_HOOK_GetCaps(LPVOID *ppvOut, LPDWORD lpdwCaps);

typedef HRESULT (__stdcall *DDRAWPALETTE_GetEntries_Type)(LPVOID *ppvOut, DWORD dwFlags, DWORD dwBase, DWORD dwNumEntries, LPPALETTEENTRY lpEntries);
HRESULT __stdcall DDRAWPALETTE_HOOK_GetEntries(LPVOID *ppvOut, DWORD dwFlags, DWORD dwBase, DWORD dwNumEntries, LPPALETTEENTRY lpEntries);

typedef HRESULT (__stdcall *DDRAWPALETTE_Initialize_Type)(LPVOID *ppvOut, LPDIRECTDRAW lpDD, DWORD dwFlags, LPPALETTEENTRY lpDDColorTable);
HRESULT __stdcall DDRAWPALETTE_HOOK_Initialize(LPVOID *ppvOut, LPDIRECTDRAW lpDD, DWORD dwFlags, LPPALETTEENTRY lpDDColorTable);

typedef HRESULT (__stdcall *DDRAWPALETTE_SetEntries_Type)(LPVOID *ppvOut, DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries);
HRESULT __stdcall DDRAWPALETTE_HOOK_SetEntries(LPVOID *ppvOut, DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries);

#endif