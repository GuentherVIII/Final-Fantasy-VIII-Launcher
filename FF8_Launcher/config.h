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

#ifndef _CONFIG_H
#define _CONFIG_H

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <fstream>
#include <sstream>

#define FF8_CONFIG_FILE _T("config.cfg")

struct FF8Config {
	UINT displaymode;
	UINT fsaa;
	UINT b8_paletted_textures_fix;
	UINT force_texture_filtering;
	UINT force_alpha_transparency;
	UINT expert_mode;
	float tex_uvmap_adj_backgrounds;
	float tex_uvmap_adj_interface;
	UINT stretch_4_3_ar;
	UINT eliminate_black_bars;
};

//not used (delete?)
#define FF8CONFIG_WS_NORMAL 0
#define FF8CONFIG_WS_16_10 1
#define FF8CONFIG_WS_16_9 2

struct FF8Config_DispMode {
	_TCHAR *name;
	UINT resX;
	UINT resY;
	UINT bpp;
	UINT wide;
};

struct FF8Config_FSAA {
	_TCHAR *name;
	UINT mode;
};

extern FF8Config g_config;
extern FF8Config_DispMode displaymode_options[];
extern UINT displaymode_options_count;
extern FF8Config_FSAA fsaa_options[];
extern UINT fsaa_options_count;

typedef std::basic_string<_TCHAR, std::char_traits<_TCHAR> > tstring;
typedef std::basic_ifstream<_TCHAR, std::char_traits<_TCHAR> > tifstream;
typedef std::basic_ofstream<_TCHAR, std::char_traits<_TCHAR> > tofstream;
typedef std::basic_stringstream<_TCHAR, std::char_traits<_TCHAR> > tstringstream;

int LoadConfig(FF8Config &cfg);
int SaveConfig(FF8Config &cfg);
int parseInt(_TCHAR *str);
float parseFloat(_TCHAR *str);

#endif