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

#include "dllmain.h"

typedef HRESULT (__stdcall *DirectDrawCreate_Type)(GUID FAR *, LPDIRECTDRAW FAR *, IUnknown FAR *);
typedef HRESULT (__stdcall *DirectInputCreateA_Type)(HINSTANCE, DWORD, LPDIRECTINPUT *, LPUNKNOWN);
typedef void *(__stdcall *BinkOpen_Type)(HANDLE, UINT32);
typedef void (__stdcall *BinkClose_Type)(void *);
typedef int (__stdcall *BinkCopyToBuffer_Type)(void *, void *, int, int, int, int, int);

extern SDLLHook *DLLHooks[];

HRESULT __stdcall MyDirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter ) {
	DirectDrawCreate_Type OldFn = (DirectDrawCreate_Type)DLLHooks[0]->Functions[0].OrigFn;
	HRESULT ret = OldFn(lpGUID, lplpDD, pUnkOuter);

	Log("_EXPORT::DirectDrawCreate()\n");
	if(ret == S_OK && ishooked_ddraw_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpDD, ddraw_hooks, count_ddraw_hooks, "IDirectDraw");
		ishooked_ddraw_hooks = true;
	}

	return ret;
}

HRESULT __stdcall MyDirectInputCreateA(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUT *lplpDirectInput, LPUNKNOWN pUnkOuter) {
	DirectInputCreateA_Type OldFn = (DirectInputCreateA_Type)DLLHooks[1]->Functions[0].OrigFn;
	HRESULT ret = OldFn(hinst, dwVersion, lplpDirectInput, pUnkOuter);

	Log("_EXPORT::DirectInputCreateA(hinst=%#010lx, dwVersion=%#010lx, lplpDirectInput=%#010lx *[%#010lx], pUnkOuter=%#010lx)\n", hinst, dwVersion, lplpDirectInput, (lplpDirectInput != NULL ? *lplpDirectInput : NULL), pUnkOuter);
	if(ret == S_OK && ishooked_dinput_hooks == false) {
		HookVTBLCalls((LPVOID *)lplpDirectInput, dinput_hooks, count_dinput_hooks, "IDirectInput");
		ishooked_dinput_hooks = true;
	}

	return ret;
}

 void * __stdcall MyBinkOpen(HANDLE BinkFile, UINT32 Flags) {
	BinkOpen_Type OldFn = (BinkOpen_Type)DLLHooks[2]->Functions[0].OrigFn;
	void *ret = OldFn(BinkFile, Flags);

	/*if(ret != NULL) {
		_Log("Flags: %#010lx", Flags);
		for(int i = 0; i < 20; i++) _Log("%d: %#010lx", i, *(((LPDWORD)ret)+i));
	}*/

	g_binkActive = TRUE;
	g_binkStruct = ret;

	Log("_EXPORT::BinkOpen(%p, %p) = %p\n", BinkFile, Flags, ret);

	return ret;
}

void __stdcall MyBinkClose(void *BinkStruct) {
	g_binkActive = FALSE;
	g_binkStruct = NULL;

	BinkClose_Type OldFn = (BinkClose_Type)DLLHooks[2]->Functions[1].OrigFn;
	OldFn(BinkStruct);
	if(g_binkCpySurface != NULL) {
		((LPDIRECTDRAWSURFACE4)g_binkCpySurface)->Release();
		g_binkCpySurface = NULL;
	}

	Log("_EXPORT::BinkClose(%p)\n", BinkStruct);

	return;
}

/* mostly guesses */
int __stdcall MyBinkCopyToBuffer(void *BinkStruct, void *surface, int pitch, int height, int a, int b, int c) {

	BinkCopyToBuffer_Type OldFn = (BinkCopyToBuffer_Type)DLLHooks[2]->Functions[2].OrigFn;
	int r = OldFn(BinkStruct, surface, pitch, height, a, b, c);
	
/* FF8 uses BinkCopyToBuffer to copy the video into a locked DDrawSurface. The surface is locked just before and unlocked just after,
so that just stretching the surface that is unlocked directly after this call would suffice. This check is for safety.
Don't stretch the surface here, but let DDraw do a hardware blit on the unlocked surface. */
	if (g_lastLockedSurfaceData == surface)
		g_binkSurfaceNeedsStretch = true;

	Log("_EXPORT::BinkCopyToBuffer(%#010lx, %#010lx, %#010lx, %#010lx, %#010lx, %#010lx, %#010lx)=%p\n", BinkStruct, surface, pitch, height, a, b, c, r);

	return r;
}


HINSTANCE hinstance = NULL;

SDLLHook D3DHook = {
	"DDRAW.DLL",
	{
		{ "DirectDrawCreate", (PDWORD)MyDirectDrawCreate },
		{ NULL, NULL }
	}
};
SDLLHook DINPUTHook = {
	"DINPUT.DLL",
	{
		{ "DirectInputCreateA", (PDWORD)MyDirectInputCreateA },
		{ NULL, NULL }
	}
};

SDLLHook Binkw32Hook = {
	"BINKW32.DLL",
	{
		{ "_BinkOpen@8", (PDWORD)MyBinkOpen },
		{ "_BinkClose@4", (PDWORD)MyBinkClose },
		{ "_BinkCopyToBuffer@28", (PDWORD)MyBinkCopyToBuffer },
		{ NULL, NULL }
	}
};
SDLLHook *DLLHooks[] = { &D3DHook, &DINPUTHook, &Binkw32Hook};
const unsigned int cDLLHooks = 3;

// main get called every time a process is spawned  
BOOL APIENTRY DllMain(HINSTANCE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		hinstance = hModule;

		memset(&g_config, 0, sizeof(g_config));
		LoadConfig(g_config);

		{ //LG
		g_game.modX = (float)displaymode_options[g_config.displaymode].resX/640.0f;
		g_game.modY = (float)displaymode_options[g_config.displaymode].resY/480.0f;
		g_game.mod = (g_game.modX > g_game.modY ? g_game.modY : g_game.modX);
		float width = (float)displaymode_options[g_config.displaymode].resX;
		float height = (float)displaymode_options[g_config.displaymode].resY;

		//Stretch 4:3 Aspect Ratio only applies to non-4:3 aspect ratios
		if(g_game.modX-g_game.modY <= 0.0001 && g_game.modX-g_game.modY >= -0.0001) { //float inprecision
			g_config.stretch_4_3_ar = 0;
		}

		if(g_config.stretch_4_3_ar == 0) {
			if(g_game.modX > g_game.modY) {
				//4:3, 16:10, 16:9 etc.
				width = 640.0f*g_game.modY;
				if((UINT)(floor(width))%2==1) g_game.width = (DWORD)ceil(width);
				else g_game.width = (DWORD)floor(width);
				g_game.height = (DWORD)height;
			} else {
				//1:1, 1:2 etc. (not really used but it can never hurt...)
				g_game.width = (DWORD)width;
				height = 480.0f*g_game.modX;
				if((UINT)(floor(height))%2==1) g_game.height = (DWORD)ceil(height);
				else g_game.height = (DWORD)floor(height);
			}
		} else {
			g_game.width = (DWORD)width;
			g_game.height = (DWORD)height;
		}
		}

		Log("DLL injected into FF8.exe\n");
		HookAPICalls(DLLHooks, cDLLHooks);
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		LogClose();
		break;
	}
	return TRUE;
}

/*
//__declspec(dllexport) LRESULT CALLBACK hookproc(int ncode,WPARAM wparam,LPARAM lparam)
LRESULT CALLBACK hookproc(int ncode,WPARAM wparam,LPARAM lparam) {
	return (CallNextHookEx(hHook,ncode,wparam,lparam));//pass control to next hook in the hook chain.
} 
//__declspec(dllexport) int installCOMHook(void)
COMHOOKDLL_API int installCOMHook(void) {
	hHook = NULL;
	hHook = SetWindowsHookEx(WH_CBT,hookproc,hinstance,NULL);
	if(hHook == NULL) {
		DWORD dwErr = GetLastError();
		// lookup error code and display it
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwErr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL
		);
		MessageBox(NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION);
		// Free the buffer.
		LocalFree(lpMsgBuf);         

		return 0;
	}

	return 1;
}

COMHOOKDLL_API int removeCOMHook(void) {
	UnhookWindowsHookEx(hHook);
	return 1;
}
*/