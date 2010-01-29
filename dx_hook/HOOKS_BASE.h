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

#ifndef _HOOKS_BASE
#define _HOOKS_BASE

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <fstream>
#include <d3d.h>
#include <ddraw.h>
#include "log.h"
#include "apihijack.h"
#include "flags.h"
#include "../FF8_Launcher/config.h"

//#define FF8_WINDOWED //Old, before resolutions, does not work/for reference.

#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }

struct SVTBL_HOOK {
	char *name;
	DWORD offset;
	DWORD *oldFunc;
	DWORD *newFunc;
};

struct CVIEWPORT {
	DWORD width, height, x, y;
	DWORD old_width, old_height, old_x, old_y;
};

struct GAME {
	float modX, modY;
	DWORD width, height;
};

class DEBUGOPTIONS {
public:
	bool debug_log;
	bool tex_uvmap_notextures;

	void SaveOptions(void) {
		extern FF8Config_DispMode displaymode_options[];
		extern FF8Config g_config;
		std::ofstream ofs;
		ofs.open("dbgoptions.txt", std::ios::app);
		if(ofs.is_open()) {
			ofs << displaymode_options[g_config.displaymode].name << "\n";
			ofs << "debug_log: " << this->debug_log << "\n";
			ofs << "tex_uvmap_notextures: " << this->tex_uvmap_notextures << "\n";
			ofs << "\n";

			ofs.close();
		}
	}
};

extern BOOL g_binkActive;
extern LPDIRECTDRAWSURFACE4 g_decoyBackBuffer;
extern LPVOID g_binkStruct;
extern CVIEWPORT g_currentviewport;
extern std::map<LPDIRECT3DTEXTURE2, LPDIRECTDRAWSURFACE4> textures;
extern LPVOID g_d3ddevice;
extern GAME g_game;
extern DEBUGOPTIONS g_debugoptions;

#ifdef _DEBUG
#define LogDXError(ret) _LogDXError(ret);
#else
#define LogDXError(ret)
#endif

//DECLARATIONS
void _LogDXError(HRESULT ret);
void HookVTBLCalls(LPVOID *ppvObj, SVTBL_HOOK *vtbl_hooks, const unsigned int count_vtbl_hooks, const char *cstrInterface);
void SetD3DRect(D3DRECT &rect, DWORD _x1, DWORD _x2, DWORD _y1, DWORD _y2);
#endif