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

//APIHIJACK.CPP - Based on DelayLoadProfileDLL.CPP, by Matt Pietrek for MSJ February 2000.
//http://msdn.microsoft.com/library/periodic/period00/hood0200.htm
//Adapted by Wade Brainerd, wadeb@wadeb.com
//Adapted by Martin Mueller, wingcommander@usa.net
//Modified by Tobias Sebring (aka. Magix)
#include "apihijack.h"

/*
//SAVE/RESTORE REGISTERS

__asm   pushad  // Save all general purpose registers
PDWORD pRetAddr = (PDWORD)(&this - 1);

DLPD_IAT_STUB * pDLPDStub = (DLPD_IAT_STUB *)(*pRetAddr - 5);
__asm   popad   // Restore all general purpose registers
*/

//Given an HMODULE, returns a pointer to the PE header
PIMAGE_NT_HEADERS PEHeaderFromHModule(HMODULE hModule) {
	PIMAGE_NT_HEADERS pNTHeader = 0;

	__try {
		if(PIMAGE_DOS_HEADER(hModule)->e_magic != IMAGE_DOS_SIGNATURE) __leave;

		pNTHeader = PIMAGE_NT_HEADERS(PBYTE(hModule) + PIMAGE_DOS_HEADER(hModule)->e_lfanew);
		if(pNTHeader->Signature != IMAGE_NT_SIGNATURE) pNTHeader = 0;
	}
	__except(EXCEPTION_EXECUTE_HANDLER) {
	}

	return pNTHeader;
}

//Redirect IAT for one DLL
bool RedirectIAT(SDLLHook *DLLHook, PIMAGE_IMPORT_DESCRIPTOR pImportDesc, PVOID pBaseLoadAddr) {
	PIMAGE_THUNK_DATA pIAT; //Ptr to import address table
	PIMAGE_THUNK_DATA pINT; //Ptr to import names table
	PIMAGE_THUNK_DATA pIteratingIAT;

	//Figure out which OS platform we're on
	OSVERSIONINFO osvi; 
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	GetVersionEx(&osvi);

	//If no import names table, we can't redirect this, so bail
	if(pImportDesc->OriginalFirstThunk == 0) return false;

	pIAT = MakePtr(PIMAGE_THUNK_DATA, pBaseLoadAddr, pImportDesc->FirstThunk);
	pINT = MakePtr(PIMAGE_THUNK_DATA, pBaseLoadAddr, pImportDesc->OriginalFirstThunk);

	//Count how many entries there are in this IAT.  Array is 0 terminated
	pIteratingIAT = pIAT;
	unsigned cFuncs = 0;
	while(pIteratingIAT->u1.Function) {
		cFuncs++;
		pIteratingIAT++;
	}

	if(cFuncs == 0) return false;

	DWORD flOldProtect, flNewProtect, flDontCare;
	MEMORY_BASIC_INFORMATION mbi;
                         
	VirtualQuery(pIAT, &mbi, sizeof(mbi));

	flNewProtect = mbi.Protect;
	flNewProtect &= ~(PAGE_READONLY | PAGE_EXECUTE_READ | PAGE_EXECUTE);
	flNewProtect |= (PAGE_READWRITE);

	if(!VirtualProtect(pIAT, sizeof(PVOID) * cFuncs, flNewProtect, &flOldProtect)) return false;

	pIteratingIAT = pIAT;
	while(pIteratingIAT->u1.Function) {
		void *HookFn = NULL;

		//We're only interested in imports by name not ordinal
		if(!IMAGE_SNAP_BY_ORDINAL(pINT->u1.Ordinal)) {
			PIMAGE_IMPORT_BY_NAME pImportName = MakePtr(PIMAGE_IMPORT_BY_NAME, pBaseLoadAddr, pINT->u1.AddressOfData);

			//Do we want to hook this function?
			SFunctionHook* FHook = DLLHook->Functions;
			while(FHook->Name) {
				if(lstrcmpi(FHook->Name, (char *)pImportName->Name) == 0) {
					Log("\t->HOOKED: %s\n",(char *)pImportName->Name);
					
					FHook->OrigFn = (unsigned long*)pIteratingIAT->u1.Function;
					HookFn = FHook->HookFn;
					break;
				}
				
				FHook++;
			}

		}

		//Replace the IAT function pointer if we have a hook
		if(HookFn) {
			//Cheez-o hack to see if what we're importing is code or data.
			//If it's code, we shouldn't be able to write to it
			if(IsBadWritePtr((PVOID)pIteratingIAT->u1.Function, 1)) {
				pIteratingIAT->u1.Function = (DWORD)HookFn;
			} else if(osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) {
				//Special hack for Win9X, which builds stubs for imported
				//functions in system DLLs (Loaded above 2GB). These stubs are
				//writeable, so we have to explicitly check for this case
				if(pIteratingIAT->u1.Function > (DWORD)0x80000000) pIteratingIAT->u1.Function = (DWORD)HookFn;
			}
		}

		pIteratingIAT++;
		pINT++;
	}

	VirtualProtect(pIAT, sizeof(PVOID) *cFuncs, flOldProtect, &flDontCare);

	return true;
}

//Top level routine to find the EXE's imports, and redirect them
bool HookAPICalls(SDLLHook **DLLHooks, const unsigned int cDLLHooks) {
	if(!DLLHooks) return false;

	HMODULE hModEXE = GetModuleHandle(0);
	PIMAGE_NT_HEADERS pExeNTHdr = PEHeaderFromHModule(hModEXE);
	if(!pExeNTHdr) return false;

	DWORD importRVA = pExeNTHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
	if(!importRVA) return false;

	//Convert imports RVA to a usable pointer
	PIMAGE_IMPORT_DESCRIPTOR pImportDesc = MakePtr(PIMAGE_IMPORT_DESCRIPTOR, hModEXE, importRVA);

	while(pImportDesc->FirstThunk) {
		PSTR pszImportModuleName = MakePtr(PSTR, hModEXE, pImportDesc->Name);

		Log("IAT: %s\n", pszImportModuleName);

		//Are we looking to hook exports from multiple DLLs?
		for(unsigned int ch = 0; ch < cDLLHooks; ch++) {
			if(lstrcmpi(pszImportModuleName, DLLHooks[ch]->Name) == 0) {
				Log("\t(%s MATCH)\n", DLLHooks[ch]->Name);
				
				RedirectIAT( DLLHooks[ch], pImportDesc, (PVOID)hModEXE );
			}
		}

		pImportDesc++;
	}

	return false;
}