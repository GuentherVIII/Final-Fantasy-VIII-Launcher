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

#include "DInput_hooks.h"
#include "DInputDevice_hooks.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK dinput_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DINPUT_HOOK_QueryInterface },
/*1*/	{ "AddRef",					0x04, NULL, (PDWORD)DINPUT_HOOK_AddRef },
/*2*/	{ "Release",				0x08, NULL, (PDWORD)DINPUT_HOOK_Release },
/*3*/	{ "CreateDevice",			0x0C, NULL, (PDWORD)DINPUT_HOOK_CreateDevice },
/*4*/	{ "EnumDevices",			0x10, NULL, (PDWORD)DINPUT_HOOK_EnumDevices },
/*5*/	{ "GetDeviceStatus",		0x14, NULL, (PDWORD)DINPUT_HOOK_GetDeviceStatus },
/*6*/	{ "RunControlPanel",		0x18, NULL, (PDWORD)DINPUT_HOOK_RunControlPanel },
/*7*/	{ "Initialize",				0x1C, NULL, (PDWORD)DINPUT_HOOK_Initialize },
};
#else
SVTBL_HOOK dinput_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)DINPUT_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DINPUT_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DINPUT_HOOK_Release },
/*3*/	{ "CreateDevice",			0x0C, NULL, (PDWORD)DINPUT_HOOK_CreateDevice },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "EnumDevices",			0x10, NULL, (PDWORD)DINPUT_HOOK_EnumDevices },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "GetDeviceStatus",		0x14, NULL, (PDWORD)DINPUT_HOOK_GetDeviceStatus },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "RunControlPanel",		0x18, NULL, (PDWORD)DINPUT_HOOK_RunControlPanel },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x1C, NULL, (PDWORD)DINPUT_HOOK_Initialize },
};
#endif
const unsigned int count_dinput_hooks = 8;
bool ishooked_dinput_hooks = false;

HRESULT __stdcall DINPUT_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	DINPUT_QueryInterface_Type ofn = (DINPUT_QueryInterface_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectInput::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", dinput_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall DINPUT_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	DINPUT_AddRef_Type ofn = (DINPUT_AddRef_Type)dinput_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectInput::%s()\n", dinput_hooks[hpos].name);

	return ret;
}

ULONG __stdcall DINPUT_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	DINPUT_Release_Type ofn = (DINPUT_Release_Type)dinput_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectInput::%s(%#010lx)\n", dinput_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUT_HOOK_CreateDevice(LPVOID *ppvOut, REFGUID rguid, LPDIRECTINPUTDEVICEA *lplpDirectInputDevice, LPUNKNOWN pUnkOuter) {
	const unsigned int hpos = 3;

	DINPUT_CreateDevice_Type ofn = (DINPUT_CreateDevice_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, rguid, lplpDirectInputDevice, pUnkOuter);

	Log("IDirectInput::%s(this=%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, lplpDirectInputDevice=%#010lx *[%#010lx], pUnkOuter=%#010lx)\n", dinput_hooks[hpos].name, ppvOut, rguid.Data1, rguid.Data2, rguid.Data3, rguid.Data4[0], rguid.Data4[1], rguid.Data4[2], rguid.Data4[3], rguid.Data4[4], rguid.Data4[5], rguid.Data4[6], rguid.Data4[7], lplpDirectInputDevice, (lplpDirectInputDevice != NULL ? *lplpDirectInputDevice : NULL), pUnkOuter);
	if(ret == S_OK && rguid == GUID_SysKeyboard && ishooked_dinputdevice_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpDirectInputDevice, dinputdevice_hooks, count_dinputdevice_hooks, "IDirectInputDevice");
		ishooked_dinputdevice_hooks = true;
	}

	return ret;
}

HRESULT __stdcall DINPUT_HOOK_EnumDevices(LPVOID *ppvOut, DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags) {
	const unsigned int hpos = 4;

	DINPUT_EnumDevices_Type ofn = (DINPUT_EnumDevices_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, dwDevType, lpCallback, pvRef, dwFlags);

	Log("IDirectInput::%s(this=%#010lx, dwDevType=%#010lx, lpCallback=%#010lx, pvRef=%#010lx, dwFlags=%#010lx)\n", dinput_hooks[hpos].name, ppvOut, dwDevType, lpCallback, pvRef, dwFlags);

	return ret;
}

HRESULT __stdcall DINPUT_HOOK_GetDeviceStatus(LPVOID *ppvOut, REFGUID rguidInstance) {
	const unsigned int hpos = 5;

	DINPUT_GetDeviceStatus_Type ofn = (DINPUT_GetDeviceStatus_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, rguidInstance);

	Log("IDirectInput::%s(%#010lx)\n", dinput_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUT_HOOK_RunControlPanel(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags) {
	const unsigned int hpos = 6;

	DINPUT_RunControlPanel_Type ofn = (DINPUT_RunControlPanel_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hwndOwner, dwFlags);

	Log("IDirectInput::%s(%#010lx)\n", dinput_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUT_HOOK_Initialize(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion) {
	const unsigned int hpos = 7;

	DINPUT_Initialize_Type ofn = (DINPUT_Initialize_Type)dinput_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hinst, dwVersion);

	Log("IDirectInput::%s(%#010lx)\n", dinput_hooks[hpos].name, ppvOut);

	return ret;
}