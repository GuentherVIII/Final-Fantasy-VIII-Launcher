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

#include "DInputDevice_hooks.h"
#include "dllmain.h"

//{ NULL, 0, NULL, NULL },	//
#ifdef _DEBUG
SVTBL_HOOK dinputdevice_hooks[] = {
/*0*/	{ "QueryInterface",			0x00, NULL, (PDWORD)DINPUTDEVICE_HOOK_QueryInterface },
/*1*/	{ "AddRef",					0x04, NULL, (PDWORD)DINPUTDEVICE_HOOK_AddRef },
/*2*/	{ "Release",				0x08, NULL, (PDWORD)DINPUTDEVICE_HOOK_Release },
/*3*/	{ "GetCapabilities",		0x0C, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetCapabilities },
/*4*/	{ "EnumObjects",			0x10, NULL, (PDWORD)DINPUTDEVICE_HOOK_EnumObjects },
/*5*/	{ "GetProperty",			0x14, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetProperty },
/*6*/	{ "SetProperty",			0x18, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetProperty },
/*7*/	{ "Acquire",				0x1C, NULL, (PDWORD)DINPUTDEVICE_HOOK_Acquire },
/*8*/	{ "Unacquire",				0x20, NULL, (PDWORD)DINPUTDEVICE_HOOK_Unacquire },
/*9*/	{ "GetDeviceState",			0x24, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceState },
/*10*/	{ "GetDeviceData",			0x28, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceData },
/*11*/	{ "SetDataFormat",			0x2C, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetDataFormat },
/*12*/	{ "SetEventNotification",	0x30, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetEventNotification },
/*13*/	{ "SetCooperativeLevel",	0x34, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetCooperativeLevel },
/*14*/	{ "GetObjectInfo",			0x38, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetObjectInfo },
/*15*/	{ "GetDeviceInfo",			0x3C, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceInfo },
/*16*/	{ "RunControlPanel",		0x40, NULL, (PDWORD)DINPUTDEVICE_HOOK_RunControlPanel },
/*17*/	{ "Initialize",				0x44, NULL, (PDWORD)DINPUTDEVICE_HOOK_Initialize },
};
#else
SVTBL_HOOK dinputdevice_hooks[] = {
/*0*/	{ NULL, 0, NULL, NULL },	//{ "QueryInterface",			0x00, NULL, (PDWORD)DINPUTDEVICE_HOOK_QueryInterface },
/*1*/	{ NULL, 0, NULL, NULL },	//{ "AddRef",					0x04, NULL, (PDWORD)DINPUTDEVICE_HOOK_AddRef },
/*2*/	{ NULL, 0, NULL, NULL },	//{ "Release",				0x08, NULL, (PDWORD)DINPUTDEVICE_HOOK_Release },
/*3*/	{ NULL, 0, NULL, NULL },	//{ "GetCapabilities",		0x0C, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetCapabilities },
/*4*/	{ NULL, 0, NULL, NULL },	//{ "EnumObjects",			0x10, NULL, (PDWORD)DINPUTDEVICE_HOOK_EnumObjects },
/*5*/	{ NULL, 0, NULL, NULL },	//{ "GetProperty",			0x14, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetProperty },
/*6*/	{ NULL, 0, NULL, NULL },	//{ "SetProperty",			0x18, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetProperty },
/*7*/	{ NULL, 0, NULL, NULL },	//{ "Acquire",				0x1C, NULL, (PDWORD)DINPUTDEVICE_HOOK_Acquire },
/*8*/	{ NULL, 0, NULL, NULL },	//{ "Unacquire",				0x20, NULL, (PDWORD)DINPUTDEVICE_HOOK_Unacquire },
/*9*/	{ "GetDeviceState",			0x24, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceState },
/*10*/	{ NULL, 0, NULL, NULL },	//{ "GetDeviceData",			0x28, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceData },
/*11*/	{ NULL, 0, NULL, NULL },	//{ "SetDataFormat",			0x2C, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetDataFormat },
/*12*/	{ NULL, 0, NULL, NULL },	//{ "SetEventNotification",	0x30, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetEventNotification },
/*13*/	{ NULL, 0, NULL, NULL },	//{ "SetCooperativeLevel",	0x34, NULL, (PDWORD)DINPUTDEVICE_HOOK_SetCooperativeLevel },
/*14*/	{ NULL, 0, NULL, NULL },	//{ "GetObjectInfo",			0x38, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetObjectInfo },
/*15*/	{ NULL, 0, NULL, NULL },	//{ "GetDeviceInfo",			0x3C, NULL, (PDWORD)DINPUTDEVICE_HOOK_GetDeviceInfo },
/*16*/	{ NULL, 0, NULL, NULL },	//{ "RunControlPanel",		0x40, NULL, (PDWORD)DINPUTDEVICE_HOOK_RunControlPanel },
/*17*/	{ NULL, 0, NULL, NULL },	//{ "Initialize",				0x44, NULL, (PDWORD)DINPUTDEVICE_HOOK_Initialize },
};
#endif
const unsigned int count_dinputdevice_hooks = 18;
bool ishooked_dinputdevice_hooks = false;

HRESULT __stdcall DINPUTDEVICE_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj) {
	const unsigned int hpos = 0;

	DINPUTDEVICE_QueryInterface_Type ofn = (DINPUTDEVICE_QueryInterface_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, riid, ppvObj);
	LogDXError(ret);

	Log("IDirectInputDevice::%s(%#010lx, { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }, %#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut, riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7], ppvObj);

	return ret;
}

ULONG __stdcall DINPUTDEVICE_HOOK_AddRef(LPVOID *ppvOut) {
	const unsigned int hpos = 1;

	DINPUTDEVICE_AddRef_Type ofn = (DINPUTDEVICE_AddRef_Type)dinputdevice_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectInputDevice::%s()\n", dinputdevice_hooks[hpos].name);

	return ret;
}

ULONG __stdcall DINPUTDEVICE_HOOK_Release(LPVOID *ppvOut) {
	const unsigned int hpos = 2;

	DINPUTDEVICE_Release_Type ofn = (DINPUTDEVICE_Release_Type)dinputdevice_hooks[hpos].oldFunc;
	ULONG ret = ofn(ppvOut);

	Log("IDirectInputDevice::%s(%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetCapabilities(LPVOID *ppvOut, LPDIDEVCAPS lpDIDevCaps) {
	const unsigned int hpos = 3;

	DINPUTDEVICE_GetCapabilities_Type ofn = (DINPUTDEVICE_GetCapabilities_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpDIDevCaps);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_EnumObjects(LPVOID *ppvOut, LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags) {
	const unsigned int hpos = 4;

	DINPUTDEVICE_EnumObjects_Type ofn = (DINPUTDEVICE_EnumObjects_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpCallback, pvRef, dwFlags);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetProperty(LPVOID *ppvOut, REFGUID rguidProp, LPDIPROPHEADER pdiph) {
	const unsigned int hpos = 5;

	DINPUTDEVICE_GetProperty_Type ofn = (DINPUTDEVICE_GetProperty_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, rguidProp, pdiph);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_SetProperty(LPVOID *ppvOut, REFGUID rguidProp, LPCDIPROPHEADER pdiph) {
	const unsigned int hpos = 6;

	DINPUTDEVICE_SetProperty_Type ofn = (DINPUTDEVICE_SetProperty_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, rguidProp, pdiph);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_Acquire(LPVOID *ppvOut) {
	const unsigned int hpos = 7;

	DINPUTDEVICE_Acquire_Type ofn = (DINPUTDEVICE_Acquire_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_Unacquire(LPVOID *ppvOut) {
	const unsigned int hpos = 8;

	DINPUTDEVICE_Unacquire_Type ofn = (DINPUTDEVICE_Unacquire_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceState(LPVOID *ppvOut, DWORD cbData, LPVOID lpvData) {
	const unsigned int hpos = 9;
	static DWORD dwPrev[256];
	static BYTE vDataOld[256];

	DINPUTDEVICE_GetDeviceState_Type ofn = (DINPUTDEVICE_GetDeviceState_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, cbData, lpvData);

	if(ret == S_OK && g_config.expert_mode >= 1) {
		DWORD dwNow = GetTickCount();
		#define KEYDOWN(key, delay) ((((LPBYTE)lpvData)[key] & 0x80) && (dwNow - dwPrev[key] >= delay))
		#define KEYPRESS(key) ((((LPBYTE)lpvData)[key] & 0x80) && (vDataOld[key] ^ 0x80))
		#define DELAY_REPEAT(key) dwPrev[key] = dwNow;

		if(KEYDOWN(DIK_LCONTROL, 0)) {
			if(KEYDOWN(DIK_COMMA, 250)) {
				//decrease tex_uvmap_adj_background
				g_config.tex_uvmap_adj_backgrounds -= 0.0001f;
				SaveConfig(g_config);
				DELAY_REPEAT(DIK_COMMA);

			} else if(KEYDOWN(DIK_PERIOD, 250)) {
				//increase tex_uvmap_adj_background
				g_config.tex_uvmap_adj_backgrounds += 0.0001f;
				SaveConfig(g_config);
				DELAY_REPEAT(DIK_PERIOD);

			}
#ifdef _DEBUG
			if(KEYPRESS(DIK_L)) {
				//toggle debug_log
				g_debugoptions.debug_log = (g_debugoptions.debug_log == false ? true : false);
			} else if(KEYPRESS(DIK_K)) {
				//write debugoptions to file
				g_debugoptions.SaveOptions();
			}
#endif
		} else if(KEYDOWN(DIK_LALT, 0)) {
			if(KEYDOWN(DIK_COMMA, 250)) {
				//decrease tex_uvmap_adj_interface
				g_config.tex_uvmap_adj_interface -= 0.0001f;
				SaveConfig(g_config);
				DELAY_REPEAT(DIK_COMMA);

			} else if(KEYDOWN(DIK_PERIOD, 250)) {
				//increase tex_uvmap_adj_interface
				g_config.tex_uvmap_adj_interface += 0.0001f;
				SaveConfig(g_config);
				DELAY_REPEAT(DIK_PERIOD);

			}
		}
#ifdef _DEBUG
		if(KEYDOWN(DIK_LCONTROL, 0) || KEYDOWN(DIK_LALT, 0)) {
			if(KEYPRESS(DIK_M)) {
				//toggle tex_uvmap_notextures
				g_debugoptions.tex_uvmap_notextures = (g_debugoptions.tex_uvmap_notextures == false ? true : false);
			}
		}
		if(KEYPRESS(DIK_ESCAPE)) {
			if(g_binkActive == TRUE && g_binkStruct != NULL) {
				//DEBUG ONLY! HIGHLY UNSTABLE!
				*(((LPDWORD)g_binkStruct)+5) = *(((LPDWORD)g_binkStruct)+4);

				/*
				typedef int (__stdcall *BinkWait_Type)(void *binkStruct);
				typedef void (__stdcall *BinkGoto_Type)(void *, UINT32, UINT32);

				HMODULE hModule = GetModuleHandle("BINKW32.DLL");
				BinkGoto_Type _bgoto = (BinkGoto_Type)GetProcAddress(hModule, "_BinkGoto@12");
				BinkWait_Type _bwait = (BinkWait_Type)GetProcAddress(hModule, "_BinkWait@4");
				while(_bwait(g_binkStruct)) { _Log("_bwait() rtn 1;"); }
				_bgoto(g_binkStruct, *(((LPDWORD)g_binkStruct)+4), 0);
				*/
			}
		}
#endif
		//Save the Key States
		memcpy(vDataOld, lpvData, sizeof(BYTE)*256);
	}

	Log("IDirectInputDevice::%s(this=%#010lx, cbData=%#010lx (%d), lpvData=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut, cbData, cbData, lpvData);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceData(LPVOID *ppvOut, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags) {
	const unsigned int hpos = 10;

	DINPUTDEVICE_GetDeviceData_Type ofn = (DINPUTDEVICE_GetDeviceData_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, cbObjectData, rgdod, pdwInOut, dwFlags);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_SetDataFormat(LPVOID *ppvOut, LPCDIDATAFORMAT lpdf) {
	const unsigned int hpos = 11;

	DINPUTDEVICE_SetDataFormat_Type ofn = (DINPUTDEVICE_SetDataFormat_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, lpdf);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_SetEventNotification(LPVOID *ppvOut, HANDLE hEvent) {
	const unsigned int hpos = 12;

	DINPUTDEVICE_SetEventNotification_Type ofn = (DINPUTDEVICE_SetEventNotification_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hEvent);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_SetCooperativeLevel(LPVOID *ppvOut, HWND hwnd, DWORD dwFlags) {
	const unsigned int hpos = 13;

	DINPUTDEVICE_SetCooperativeLevel_Type ofn = (DINPUTDEVICE_SetCooperativeLevel_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hwnd, dwFlags);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetObjectInfo(LPVOID *ppvOut, LPDIDEVICEOBJECTINSTANCEA pdidoi, DWORD dwObj, DWORD dwHow) {
	const unsigned int hpos = 14;

	DINPUTDEVICE_GetObjectInfo_Type ofn = (DINPUTDEVICE_GetObjectInfo_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, pdidoi, dwObj, dwHow);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_GetDeviceInfo(LPVOID *ppvOut, LPDIDEVICEINSTANCEA pdidi) {
	const unsigned int hpos = 15;

	DINPUTDEVICE_GetDeviceInfo_Type ofn = (DINPUTDEVICE_GetDeviceInfo_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, pdidi);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_RunControlPanel(LPVOID *ppvOut, HWND hwndOwner, DWORD dwFlags) {
	const unsigned int hpos = 16;

	DINPUTDEVICE_RunControlPanel_Type ofn = (DINPUTDEVICE_RunControlPanel_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hwndOwner, dwFlags);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}

HRESULT __stdcall DINPUTDEVICE_HOOK_Initialize(LPVOID *ppvOut, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid) {
	const unsigned int hpos = 17;

	DINPUTDEVICE_Initialize_Type ofn = (DINPUTDEVICE_Initialize_Type)dinputdevice_hooks[hpos].oldFunc;
	HRESULT ret = ofn(ppvOut, hinst, dwVersion, rguid);

	Log("IDirectInputDevice::%s(this=%#010lx)\n", dinputdevice_hooks[hpos].name, ppvOut);

	return ret;
}
