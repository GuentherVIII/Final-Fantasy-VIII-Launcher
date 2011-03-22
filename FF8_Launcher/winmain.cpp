/*
Final Fantasy VIII Launcher
Copyright 2007, 2008 Tobias Sebring
Copyright 2010 Günther <guenther.emu@freenet.de>


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

#include "winmain.h"

_TCHAR g_szAppTitle[] = _T("Final Fantasy VIII Launcher v1.4");
_TCHAR g_szClassName[] = _T("FF8Launcher");
HINSTANCE g_hInst = NULL;
HWND g_hwndMain = NULL, g_hwndInterface = NULL;
HMENU g_hMenuMain = NULL;
HBRUSH g_hbr = NULL;
DWORD g_dwWindowStyle = 0;
LPSTR g_lpCmdLine = NULL;

#define _NL _T("\r\n")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
	g_hInst = hInstance;
	g_lpCmdLine = lpCmdLine;

	InitCommonControls();

	MSG msg;
	WNDCLASS wndclass;

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_WINDOW); //(HBRUSH)(COLOR_APPWORKSPACE+1);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = (HICON)LoadImage(g_hInst, MAKEINTRESOURCE(IDI_APP), IMAGE_ICON, 0, 0, LR_SHARED); //LoadIcon(NULL, MAKEINTRESOURCE(IDI_APP));
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = g_szClassName;
	wndclass.lpszMenuName = NULL; //MAKEINTRESOURCE(IDR_MAINMNU);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClass(&wndclass)) {
		MessageBox(NULL, _T("Couldn't register window class!"), g_szAppTitle, MB_ICONERROR);
		return 0;
	}

	g_hMenuMain = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MAINMNU));
	//g_hMenuInitWnd = GetSubMenu(g_hMenuInit, INIT_MENU_POS);

	g_dwWindowStyle = WS_OVERLAPPEDWINDOW & ~(WS_SIZEBOX | WS_MAXIMIZEBOX );
	g_hwndMain = CreateWindow(g_szClassName, g_szAppTitle, g_dwWindowStyle, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, g_hMenuMain, hInstance, NULL);
	ShowWindow(g_hwndMain, iCmdShow);
	UpdateWindow(g_hwndMain);

	while(GetMessage(&msg, NULL, 0, 0)) {
		if(IsDialogMessage(g_hwndInterface, &msg)) continue;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//DestroyMenu(g_hMenuInit);

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
	case WM_CREATE:
		{ //LG
		g_hwndMain = hwnd;

		DWORD color = GetSysColor(COLOR_WINDOW);
		unsigned int c_r = 0, c_g = 0, c_b = 0;
		c_r = GetRValue(color);
		c_g = GetGValue(color);
		c_b = GetBValue(color);

		g_hbr = CreateSolidBrush(RGB(c_r-3, c_g-3, c_b-1));

		CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_INTERFACE), g_hwndMain, (DLGPROC)InterfaceProc);
		
		RECT rect;
		GetWindowRect(g_hwndInterface, &rect);
		AdjustWindowRect(&rect, g_dwWindowStyle, GetMenu(g_hwndMain) != NULL ? true : false);
		SetWindowPos(g_hwndMain, NULL, 0, 0, rect.right-rect.left, rect.bottom-rect.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOREPOSITION);
		ShowWindow(g_hwndInterface, SW_SHOW);
		}
		return 0;

	case WM_COMMAND:
		switch(wParam) {
		case ID_HELP_ABOUT:
			{ //LG
				CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_ABOUT), g_hwndMain, (DLGPROC)AboutProc);
			}
			return 0;

		case ID_FILE_PLAYFF8:
			LaunchGame(g_lpCmdLine);
			return 0;
		case ID_FILE_EXIT:
			DestroyWindow(g_hwndMain);
		}
		break;

	case WM_DESTROY:
		DeleteObject(g_hbr);
		DestroyWindow(g_hwndInterface);

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK InterfaceProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
	case WM_INITDIALOG:
		{ //LG
		g_hwndInterface = hwnd;

		memset(&g_config, 0, sizeof(g_config));
		g_config.fullscreen = TRUE;
		LoadConfig(g_config);

		//Populate controls
		HWND hwndDispMode = GetDlgItem(g_hwndInterface, IDC_DDDISPLAYMODE);
		for(UINT i = 0; i < displaymode_options_count; i++) {
			ComboBox_AddString(hwndDispMode, displaymode_options[i].name);
		}
		ComboBox_SetCurSel(hwndDispMode, g_config.displaymode);

		HWND hwndFSAA = GetDlgItem(g_hwndInterface, IDC_DDFSAA);
		for(UINT i = 0; i < fsaa_options_count; i++) {
			ComboBox_AddString(hwndFSAA, fsaa_options[i].name);
		}
		ComboBox_SetCurSel(hwndFSAA, g_config.fsaa);

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_FULLSCREEN),
			(g_config.fullscreen ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_8BITPFIX),
			(g_config.b8_paletted_textures_fix ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_KEEP43AR),
			(!g_config.stretch_4_3_ar ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_BLACKBARS),
			(g_config.eliminate_black_bars ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_LFILTER),
			(g_config.force_texture_filtering ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_ALPHA),
			(g_config.force_alpha_transparency ? BST_CHECKED : BST_UNCHECKED));

		Button_SetCheck(GetDlgItem(g_hwndInterface, IDC_EXPERTMODE),
			(g_config.expert_mode ? BST_CHECKED : BST_UNCHECKED));
		
		return true;
		}

	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case IDC_BTPLAY:
			LaunchGame(g_lpCmdLine);
			return TRUE;

		case IDC_DDDISPLAYMODE:
			g_config.displaymode = ComboBox_GetCurSel(GetDlgItem(g_hwndInterface, IDC_DDDISPLAYMODE));
			SaveConfig(g_config);
			return TRUE;

		case IDC_DDFSAA:
			g_config.fsaa = ComboBox_GetCurSel(GetDlgItem(g_hwndInterface, IDC_DDFSAA));
			SaveConfig(g_config);
			return TRUE;

		case IDC_FULLSCREEN:
			g_config.fullscreen = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_FULLSCREEN)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_8BITPFIX:
			g_config.b8_paletted_textures_fix = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_8BITPFIX)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_KEEP43AR:
			g_config.stretch_4_3_ar = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_KEEP43AR)) != BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_BLACKBARS:
			g_config.eliminate_black_bars = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_BLACKBARS)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_LFILTER:
			g_config.force_texture_filtering = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_LFILTER)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_ALPHA:
			g_config.force_alpha_transparency = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_ALPHA)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;

		case IDC_EXPERTMODE:
			g_config.expert_mode = Button_GetCheck(GetDlgItem(g_hwndInterface, IDC_EXPERTMODE)) == BST_CHECKED;
			SaveConfig(g_config);
			return TRUE;
		}


	//Sets background of child dialog boxes to transparent
	/*case WM_CTLCOLORDLG:
		{
		HDC hDC = (HDC)wParam;
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)GetStockObject(HOLLOW_BRUSH);

	case WM_CTLCOLORBTN:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLOREDIT:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORSTATIC:
		{
		HDC hDC = (HDC)wParam;
		SetBkColor(hDC, GetSysColor(COLOR_WINDOW));
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)g_hbr;
	*/
	}

	return FALSE;
}

LRESULT CALLBACK AboutProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static _TCHAR *buffer = NULL;

	switch(message) {
	case WM_INITDIALOG:
		{ //LG
		
		HWND hwndAboutText = GetDlgItem(hwnd, IDC_ABOUTTEXT);

		tifstream ifs;
		ifs.open(_T("readme.txt"), std::ios::binary);
		if(ifs.is_open()) {
			ifs.seekg(0, std::ios::end);
			int length = ifs.tellg();
			ifs.seekg(0, std::ios::beg);
			ifs.clear();

			buffer = new _TCHAR[length+1];
			ifs.read(buffer, length);
			buffer[ifs.gcount()] = _T('\0');
			
			ifs.close();
			Edit_SetText(hwndAboutText, buffer);
		} else Edit_SetText(hwndAboutText, _T("readme.txt file is missing..."));

		ShowWindow(hwnd, SW_SHOW);
		return true;
		}

	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case IDOK:
		case IDCANCEL:
			if(buffer != NULL) {
				delete[] buffer;
				buffer = NULL;
			}

			EndDialog(hwnd, NULL);
			return TRUE;
		}

	//Sets background of child dialog boxes to transparent
	case WM_CTLCOLORDLG:
		{
		//HDC hDC = (HDC)wParam;
		//SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORBTN:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLOREDIT:
		return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);

	case WM_CTLCOLORSTATIC:
		{
		HDC hDC = (HDC)wParam;
		SetBkColor(hDC, GetSysColor(COLOR_WINDOW));
		SetBkMode(hDC, TRANSPARENT);
		}
		return (INT_PTR)g_hbr;
	
	}

	return FALSE;
}

void LaunchGame(LPCSTR lpCmdLine) {
	//Get FF8.exe path
	_TCHAR exe_path[MAX_PATH];
	memset(&exe_path, 0, sizeof(_TCHAR)*MAX_PATH);

	_TCHAR dir_path[MAX_PATH];
	DWORD dir_path_size = MAX_PATH*sizeof(_TCHAR);
	memset(&dir_path, 0, dir_path_size);

	int lpCmdLineF_size = (int)strlen(lpCmdLine)+1;
	_TCHAR *lpCmdLineF = new _TCHAR[lpCmdLineF_size];
	#ifdef  _UNICODE
	MultiByteToWideChar(CP_UTF8, 0, lpCmdLine, -1, lpCmdLineF, lpCmdLineF_size);
	#else
	_sntprintf_s(lpCmdLineF, lpCmdLineF_size, lpCmdLineF_size, _T("%s"), lpCmdLine);
	#endif

	FILE *fs;
	if(lpCmdLineF_size > 1 && ((fs = _wfsopen(lpCmdLineF, _T("r"), _SH_DENYNO)) != NULL)) {
		//From file
		fclose(fs);

		_sntprintf_s((_TCHAR *)&dir_path, MAX_PATH, MAX_PATH, _T("%s"), lpCmdLineF);
		for(int i = MAX_PATH-1; i >= 0; i--) {
			if(dir_path[i] == _T('\\')) {
				dir_path[i] = _T('\0');
				break;
			}
		}

		_sntprintf_s((_TCHAR *)&exe_path, MAX_PATH, MAX_PATH, _T("%s"), lpCmdLineF);
	} else {
		//From registry
		HKEY hFF8_key = NULL;

		if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Square Soft, Inc\\FINAL FANTASY VIII\\1.00"), 0, KEY_QUERY_VALUE, &hFF8_key)) {
			if(ERROR_SUCCESS == RegQueryValueEx(hFF8_key, _T("AppPath"), NULL, NULL, (LPBYTE)&dir_path, &dir_path_size)) {
				_sntprintf_s((_TCHAR *)&exe_path, MAX_PATH, MAX_PATH, _T("%s\\FF8.exe"), dir_path);
			}
		}
	}

	if(_tcslen((_TCHAR *)&exe_path) <= 0) {
		MessageBox(NULL, _T("FF8.exe path missing from both command line and registry.\n\nCorrect Usage:\nc:\\games\\ff8_loader.exe c:\\games\\ff8.exe"), _T("Final Fantasy VIII Launcher"), MB_OK | MB_ICONERROR);
	} else {
		//Inject our library into the target process
		//installCOMHook();


		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		memset(&si, 0, sizeof(si));
		memset(&pi, 0, sizeof(pi));
		si.cb = sizeof(si);

		//Launch ff8.exe
		if(!CreateProcess(NULL, (LPWSTR)&exe_path, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL /*(LPCWSTR)&dir_path*/, &si, &pi)) {
			_TCHAR mbuffer[255];
			_sntprintf_s((_TCHAR *)&mbuffer, 150, 150, _T("CreateProcess(FF8.exe) returned an error...\n\nERROR CODE: %d\n"),  GetLastError());
			MessageBox(NULL, (_TCHAR *)&mbuffer, _T("Final Fantasy VIII Launcher"), MB_OK | MB_ICONERROR);
		}



		HANDLE hThread;
		_TCHAR currdirPath[MAX_PATH], libPath[MAX_PATH];
		void* pLibRemote;
		DWORD hLibModule;
		HMODULE hKernel32 = GetModuleHandle(_T("Kernel32"));

		if(GetCurrentDirectory(MAX_PATH, currdirPath)) {
			//Error
		}
		_sntprintf_s(libPath, MAX_PATH, MAX_PATH, _T("%s\\dx_hook.dll"), currdirPath);

		pLibRemote = VirtualAllocEx(pi.hProcess, NULL, sizeof(libPath), MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(pi.hProcess, pLibRemote, (void*)libPath, sizeof(libPath), NULL );

		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE) GetProcAddress(hKernel32, "LoadLibraryW"), pLibRemote, 0, NULL);
		WaitForSingleObject(hThread, INFINITE);
		GetExitCodeThread(hThread, &hLibModule);
		CloseHandle(hThread);
		VirtualFreeEx(pi.hProcess, pLibRemote, sizeof(libPath), MEM_RELEASE);

		// now start running the application
		ResumeThread(pi.hThread);

		//Destroy the application window and wait for the FF8.exe process to return before therminating the launcher process
		DestroyWindow(g_hwndMain); 
		WaitForSingleObject(pi.hProcess, INFINITE);


		//Unload DLL
		hThread = ::CreateRemoteThread(pi.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE) GetProcAddress(hKernel32, "FreeLibraryW"), (LPVOID)hLibModule, 0, NULL);
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);


		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		//Release COM-hook and cleanup
		//removeCOMHook();
	}

	delete lpCmdLineF;
	lpCmdLineF = NULL;
}
