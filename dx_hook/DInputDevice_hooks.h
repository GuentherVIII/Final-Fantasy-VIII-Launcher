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

#ifndef _DINPUTDEVICE_HOOKS
#define _DINPUTDEVICE_HOOKS

#define DIRECTINPUT_VERSION 0x0500

#include <dinput.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK dinputdevice_hooks[];
extern const unsigned int count_dinputdevice_hooks;
extern bool ishooked_dinputdevice_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *DINPUTDEVICE_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall DINPUTDEVICE_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *DINPUTDEVICE_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall DINPUTDEVICE_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *DINPUTDEVICE_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall DINPUTDEVICE_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetCapabilities_Type)(LPVOID *ppvOut, LPDIDEVCAPS lpDIDevCaps);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetCapabilities(LPVOID *ppvOut, LPDIDEVCAPS lpDIDevCaps);

typedef HRESULT (__stdcall *DINPUTDEVICE_EnumObjects_Type)(LPVOID *ppvOut, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);
HRESULT __stdcall DINPUTDEVICE_HOOK_EnumObjects(LPVOID *ppvOut, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetProperty_Type)(LPVOID *ppvOut, REFGUID rguidProp, LPDIPROPHEADER pdiph);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetProperty(LPVOID *ppvOut, REFGUID rguidProp, LPDIPROPHEADER pdiph);

typedef HRESULT (__stdcall *DINPUTDEVICE_SetProperty_Type)(LPVOID *ppvOut, REFGUID rguidProp, LPCDIPROPHEADER pdiph);
HRESULT __stdcall DINPUTDEVICE_HOOK_SetProperty(LPVOID *ppvOut, REFGUID rguidProp, LPCDIPROPHEADER pdiph);

typedef HRESULT (__stdcall *DINPUTDEVICE_Acquire_Type)(LPVOID *ppvOut);
HRESULT __stdcall DINPUTDEVICE_HOOK_Acquire(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DINPUTDEVICE_Unacquire_Type)(LPVOID *ppvOut);
HRESULT __stdcall DINPUTDEVICE_HOOK_Unacquire(LPVOID *ppvOut);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetDeviceState_Type)(LPVOID *ppvOut, DWORD cbData, LPVOID lpvData);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceState(LPVOID *ppvOut, DWORD cbData, LPVOID lpvData);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetDeviceData_Type)(LPVOID *ppvOut, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceData(LPVOID *ppvOut, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

typedef HRESULT (__stdcall *DINPUTDEVICE_SetDataFormat_Type)(LPVOID *ppvOut, LPCDIDATAFORMAT lpdf);
HRESULT __stdcall DINPUTDEVICE_HOOK_SetDataFormat(LPVOID *ppvOut, LPCDIDATAFORMAT lpdf);

typedef HRESULT (__stdcall *DINPUTDEVICE_SetEventNotification_Type)(LPVOID *ppvOut, HANDLE hEvent);
HRESULT __stdcall DINPUTDEVICE_HOOK_SetEventNotification(LPVOID *ppvOut, HANDLE hEvent);

typedef HRESULT (__stdcall *DINPUTDEVICE_SetCooperativeLevel_Type)(LPVOID *ppvOut, HWND hwnd, DWORD dwFlags);
HRESULT __stdcall DINPUTDEVICE_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hwnd, DWORD dwFlags);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetObjectInfo_Type)(LPVOID *ppvOut, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetObjectInfo(LPVOID *ppvOut, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow);

typedef HRESULT (__stdcall *DINPUTDEVICE_GetDeviceInfo_Type)(LPVOID *ppvOut, LPDIDEVICEINSTANCEA pdidi);
HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceInfo(LPVOID *ppvOut, LPDIDEVICEINSTANCEA pdidi);

typedef HRESULT (__stdcall *DINPUTDEVICE_RunControlPanel_Type)(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags);
HRESULT __stdcall DINPUTDEVICE_HOOK_RunControlPanel(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags);

typedef HRESULT (__stdcall *DINPUTDEVICE_Initialize_Type)(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
HRESULT __stdcall DINPUTDEVICE_HOOK_Initialize(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);

#endif