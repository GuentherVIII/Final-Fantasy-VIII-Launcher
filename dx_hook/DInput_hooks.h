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

#ifndef _DINPUT_HOOKS
#define _DINPUT_HOOKS

#define DIRECTINPUT_VERSION 0x0500

#include <dinput.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK dinput_hooks[];
extern const unsigned int count_dinput_hooks;
extern bool ishooked_dinput_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DINPUT_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DINPUT_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DINPUT_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DINPUT_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DINPUT_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DINPUT_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DINPUT_CreateDevice_Type)(LPVOID *ppvOut, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
HRESULT __stdcall DINPUT_HOOK_CreateDevice(LPVOID *ppvOut, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

typedef HRESULT (__stdcall *DINPUT_EnumDevices_Type)(LPVOID *ppvOut, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags); 
HRESULT __stdcall DINPUT_HOOK_EnumDevices(LPVOID *ppvOut, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags); 

typedef HRESULT (__stdcall *DINPUT_GetDeviceStatus_Type)(LPVOID *ppvOut, REFGUID rguidInstance);
HRESULT __stdcall DINPUT_HOOK_GetDeviceStatus(LPVOID *ppvOut, REFGUID rguidInstance);

typedef HRESULT (__stdcall *DINPUT_RunControlPanel_Type)(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags);
HRESULT __stdcall DINPUT_HOOK_RunControlPanel(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags);

typedef HRESULT (__stdcall *DINPUT_Initialize_Type)(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion);
HRESULT __stdcall DINPUT_HOOK_Initialize(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion);

#endif