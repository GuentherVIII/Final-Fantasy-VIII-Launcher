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

//Based on DelayLoadProfileDLL.CPP, by Matt Pietrek for MSJ February 2000.
//http://msdn.microsoft.com/library/periodic/period00/hood0200.htm
//Adapted by Wade Brainerd, wadeb@wadeb.com
//Modified by Tobias Sebring (aka. Magix)

#ifndef APIHIJACK_H
#define APIHIJACK_H

#pragma warning(disable:4200) //A structure or union contains an array with zero size.
#pragma warning(disable:4311) //type cast > size
#pragma warning(disable:4312) //type cast < size

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "log.h"

//Macro for convenient pointer addition.
#define MakePtr(cast, ptr, addValue ) (cast)( (DWORD)(ptr)+(DWORD)(addValue))

/*#pragma pack(push, 1)
struct DLPD_IAT_STUB {
	BYTE    instr_CALL;
	DWORD   data_call;
	BYTE    instr_JMP;
	DWORD   data_JMP;
	DWORD   count;
	DWORD   pszNameOrOrdinal;

	DLPD_IAT_STUB() : instr_CALL(0xE8), instr_JMP(0xE9), count(0) {}
};
#pragma pack(pop)*/

struct SFunctionHook {
	char* Name;
	DWORD* HookFn;
	DWORD* OrigFn;
};

struct SDLLHook {
	char* Name;
	SFunctionHook Functions[];
};

PIMAGE_NT_HEADERS PEHeaderFromHModule(HMODULE hModule);
bool RedirectIAT(SDLLHook *DLLHook, PIMAGE_IMPORT_DESCRIPTOR pImportDesc, PVOID pBaseLoadAddr);
bool HookAPICalls(SDLLHook** DLLHooks, const unsigned int cDLLHooks);

#endif