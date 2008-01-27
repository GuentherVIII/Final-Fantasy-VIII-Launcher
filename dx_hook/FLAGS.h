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

#ifndef _FLAGS_H
#define _FLAGS_H

#include <windows.h>
#include <stdio.h>
#include <utility>
#include <ddraw.h>
#include <d3d.h>

#define pf(flag) std::pair<HRESULT, const char *>(flag, #flag)
typedef std::pair<HRESULT, const char *> PAIR_FLAG;

//Windows
extern PAIR_FLAG FLAGS_WS[];
extern UINT CFLAGS_WS;

extern PAIR_FLAG FLAGS_WS_EX[];
extern UINT CFLAGS_WS_EX;

//DirectX
extern PAIR_FLAG FLAGS_DDSCAPS1[];
extern UINT CFLAGS_DDSCAPS1;
extern PAIR_FLAG FLAGS_DDSD[];
extern UINT CFLAGS_DDSD;
extern PAIR_FLAG FLAGS_DDPCAPS[];
extern UINT CFLAGS_DDPCAPS;
extern PAIR_FLAG FLAGS_D3DCLEAR[];
extern UINT CFLAGS_D3DCLEAR;
extern PAIR_FLAG FLAGS_D3DFVF[];
extern UINT CFLAGS_D3DFVF;
extern PAIR_FLAG FLAGS_DDPF[];
extern UINT CFLAGS_DDPF;

void FlagsToString(PAIR_FLAG FLAGS[], UINT num, DWORD dwFlags, char *buffer, UINT size);

#endif