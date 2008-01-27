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

#include "HOOKS_BASE.h"

BOOL g_binkActive = FALSE;
UINT g_binkInactiveClearCount = 1;
LPVOID g_binkCpySurface = NULL;
LPVOID g_binkStruct = NULL;
CVIEWPORT g_currentviewport = { 0, 0, 0, 0, 0, 0, 0, 0 };
std::map<LPVOID, LPVOID> textures;
LPVOID g_d3ddevice = NULL;
GAME g_game;
LPVOID g_syskeyboard = NULL;
DEBUGOPTIONS g_debugoptions = {
#ifdef _DEBUG_LOG
	true,
#else
	false,
#endif
	false
};

std::map<HRESULT, char *> errcodes;
void _LogDXError(HRESULT ret) {
	if(g_debugoptions.debug_log == true) {
		if(errcodes.size() <= 0) {
			errcodes[DDERR_ALREADYINITIALIZED] = "DDERR_ALREADYINITIALIZED: The object has already been initialized.";
			errcodes[DDERR_BLTFASTCANTCLIP] = "DDERR_BLTFASTCANTCLIP: A DirectDrawClipper object is attached to a source surface that has passed into a call to the IDirectDrawSurface4::BltFast method.";
			errcodes[DDERR_CANNOTATTACHSURFACE] = "DDERR_CANNOTATTACHSURFACE: A surface cannot be attached to another requested surface.";
			errcodes[DDERR_CANNOTDETACHSURFACE] = "DDERR_CANNOTDETACHSURFACE: A surface cannot be detached from another requested surface.";
			errcodes[DDERR_CANTCREATEDC] = "DDERR_CANTCREATEDC: Windows can not create any more device contexts (DCs), or a DC was requested for a palette-indexed surface when the surface had no palette and the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)."; 
			errcodes[DDERR_CANTDUPLICATE] = "DDERR_CANTDUPLICATE: Primary and 3-D surfaces, or surfaces that are implicitly created, cannot be duplicated."; 
			errcodes[DDERR_CANTLOCKSURFACE] = "DDERR_CANTLOCKSURFACE: Access to this surface is refused because an attempt was made to lock the primary surface without DCI support.";
			errcodes[DDERR_CANTPAGELOCK] = "DDERR_CANTPAGELOCK: An attempt to page lock a surface failed. Page lock will not work on a display-memory surface or an emulated primary surface.";
			errcodes[DDERR_CANTPAGEUNLOCK] = "DDERR_CANTPAGEUNLOCK: An attempt to page unlock a surface failed. Page unlock will not work on a display-memory surface or an emulated primary surface.";
			errcodes[DDERR_CLIPPERISUSINGHWND] = "DDERR_CLIPPERISUSINGHWND: An attempt was made to set a clip list for a DirectDrawClipper object that is already monitoring a window handle.";
			errcodes[DDERR_COLORKEYNOTSET] = "DDERR_COLORKEYNOTSET: No source color key is specified for this operation.";
			errcodes[DDERR_CURRENTLYNOTAVAIL] = "DDERR_CURRENTLYNOTAVAIL: No support is currently available.";
			errcodes[DDERR_DCALREADYCREATED] = "DDERR_DCALREADYCREATED: A device context (DC) has already been returned for this surface. Only one DC can be retrieved for each surface.";
			errcodes[DDERR_DEVICEDOESNTOWNSURFACE] = "DDERR_DEVICEDOESNTOWNSURFACE: Surfaces created by one DirectDraw device cannot be used directly by another DirectDraw device.";
			errcodes[DDERR_DIRECTDRAWALREADYCREATED] = "DDERR_DIRECTDRAWALREADYCREATED: A DirectDraw object representing this driver has already been created for this process.";
			errcodes[DDERR_EXCEPTION] = "DDERR_EXCEPTION: An exception was encountered while performing the requested operation.";
			errcodes[DDERR_EXCLUSIVEMODEALREADYSET] = "DDERR_EXCLUSIVEMODEALREADYSET: An attempt was made to set the cooperative level when it was already set to exclusive.";
			errcodes[DDERR_EXPIRED] = "DDERR_EXPIRED: The data has expired and is therefore no longer valid.";
			errcodes[DDERR_GENERIC] = "DDERR_GENERIC: There is an undefined error condition.";
			errcodes[DDERR_HEIGHTALIGN] = "DDERR_HEIGHTALIGN: The height of the provided rectangle is not a multiple of the required alignment.";
			errcodes[DDERR_HWNDALREADYSET] = "DDERR_HWNDALREADYSET: The DirectDraw cooperative level window handle has already been set. It cannot be reset while the process has surfaces or palettes created.";
			errcodes[DDERR_HWNDSUBCLASSED] = "DDERR_HWNDSUBCLASSED: DirectDraw is prevented from restoring state because the DirectDraw cooperative level window handle has been subclassed.";
			errcodes[DDERR_IMPLICITLYCREATED] = "DDERR_IMPLICITLYCREATED: The surface cannot be restored because it is an implicitly created surface.";
			errcodes[DDERR_INCOMPATIBLEPRIMARY] = "DDERR_INCOMPATIBLEPRIMARY: The primary surface creation request does not match with the existing primary surface.";
			errcodes[DDERR_INVALIDCAPS] = "DDERR_INVALIDCAPS: One or more of the capability bits passed to the callback function are incorrect.";
			errcodes[DDERR_INVALIDCLIPLIST] = "DDERR_INVALIDCLIPLIST: DirectDraw does not support the provided clip list.";
			errcodes[DDERR_INVALIDDIRECTDRAWGUID] = "DDERR_INVALIDDIRECTDRAWGUID: The globally unique identifier (GUID) passed to the DirectDrawCreate function is not a valid DirectDraw driver identifier.";
			errcodes[DDERR_INVALIDMODE] = "DDERR_INVALIDMODE: DirectDraw does not support the requested mode.";
			errcodes[DDERR_INVALIDOBJECT] = "DDERR_INVALIDOBJECT: DirectDraw received a pointer that was an invalid DirectDraw object.";
			errcodes[DDERR_INVALIDPARAMS] = "DDERR_INVALIDPARAMS: One or more of the parameters passed to the method are incorrect.";
			errcodes[DDERR_INVALIDPIXELFORMAT] = "DDERR_INVALIDPIXELFORMAT: The pixel format was invalid as specified.";
			errcodes[DDERR_INVALIDPOSITION] = "DDERR_INVALIDPOSITION: The position of the overlay on the destination is no longer legal.";
			errcodes[DDERR_INVALIDRECT] = "DDERR_INVALIDRECT: The provided rectangle was invalid.";
			errcodes[DDERR_INVALIDSTREAM] = "DDERR_INVALIDSTREAM: The specified stream contains invalid data.";
			errcodes[DDERR_INVALIDSURFACETYPE] = "DDERR_INVALIDSURFACETYPE: The requested operation could not be performed because the surface was of the wrong type.";
			errcodes[DDERR_LOCKEDSURFACES] = "DDERR_LOCKEDSURFACES: One or more surfaces are locked, causing the failure of the requested operation.";
			errcodes[DDERR_MOREDATA] = "DDERR_MOREDATA: There is more data available than the specified buffer size can hold.";
			errcodes[DDERR_NO3D] = "DDERR_NO3D: No 3-D hardware or emulation is present.";
			errcodes[DDERR_NOALPHAHW] = "DDERR_NOALPHAHW: No alpha acceleration hardware is present or available, causing the failure of the requested operation.";
			errcodes[DDERR_NOBLTHW] = "DDERR_NOBLTHW: No blitter hardware is present.";
			errcodes[DDERR_NOCLIPLIST] = "DDERR_NOCLIPLIST: No clip list is available.";
			errcodes[DDERR_NOCLIPPERATTACHED] = "DDERR_NOCLIPPERATTACHED: No DirectDrawClipper object is attached to the surface object.";
			errcodes[DDERR_NOCOLORCONVHW] = "DDERR_NOCOLORCONVHW: The operation cannot be carried out because no color-conversion hardware is present or available.";
			errcodes[DDERR_NOCOLORKEY] = "DDERR_NOCOLORKEY: The surface does not currently have a color key.";
			errcodes[DDERR_NOCOLORKEYHW] = "DDERR_NOCOLORKEYHW: The operation cannot be carried out because there is no hardware support for the destination color key.";
			errcodes[DDERR_NOCOOPERATIVELEVELSET] = "DDERR_NOCOOPERATIVELEVELSET: A create function is called without the IDirectDraw4::SetCooperativeLevel method being called.";
			errcodes[DDERR_NODC] = "DDERR_NODC: No DC has ever been created for this surface.";
			errcodes[DDERR_NODDROPSHW] = "DDERR_NODDROPSHW: No DirectDraw raster operation (ROP) hardware is available.";
			errcodes[DDERR_NODIRECTDRAWHW] = "DDERR_NODIRECTDRAWHW: Hardware-only DirectDraw object creation is not possible; the driver does not support any hardware.";
			errcodes[DDERR_NODIRECTDRAWSUPPORT] = "DDERR_NODIRECTDRAWSUPPORT: DirectDraw support is not possible with the current display driver.";
			errcodes[DDERR_NOEMULATION] = "DDERR_NOEMULATION: Software emulation is not available.";
			errcodes[DDERR_NOEXCLUSIVEMODE] = "DDERR_NOEXCLUSIVEMODE: The operation requires the application to have exclusive mode, but the application does not have exclusive mode.";
			errcodes[DDERR_NOFLIPHW] = "DDERR_NOFLIPHW: Flipping visible surfaces is not supported.";
			errcodes[DDERR_NOFOCUSWINDOW] = "DDERR_NOFOCUSWINDOW: An attempt was made to create or set a device window without first setting the focus window.";
			errcodes[DDERR_NOGDI] = "DDERR_NOGDI: No GDI is present.";
			errcodes[DDERR_NOHWND] = "DDERR_NOHWND: Clipper notification requires a window handle, or no window handle has been previously set as the cooperative level window handle.";
			errcodes[DDERR_NOMIPMAPHW] = "DDERR_NOMIPMAPHW: The operation cannot be carried out because no mipmap capable texture mapping hardware is present or available.";
			errcodes[DDERR_NOMIRRORHW] = "DDERR_NOMIRRORHW: The operation cannot be carried out because no mirroring hardware is present or available.";
			errcodes[DDERR_NONONLOCALVIDMEM] = "DDERR_NONONLOCALVIDMEM: An attempt was made to allocate non-local video memory from a device that does not support non-local video memory.";
			errcodes[DDERR_NOOPTIMIZEHW] = "DDERR_NOOPTIMIZEHW: The device does not support optimized surfaces.";
			errcodes[DDERR_NOOVERLAYDEST] = "DDERR_NOOVERLAYDEST: The IDirectDrawSurface4::GetOverlayPosition method is called on an overlay that the IDirectDrawSurface4::UpdateOverlay method has not been called on to establish a destination.";
			errcodes[DDERR_NOOVERLAYHW] = "DDERR_NOOVERLAYHW: The operation cannot be carried out because no overlay hardware is present or available.";
			errcodes[DDERR_NOPALETTEATTACHED] = "DDERR_NOPALETTEATTACHED: No palette object is attached to this surface.";
			errcodes[DDERR_NOPALETTEHW] = "DDERR_NOPALETTEHW: There is no hardware support for 16- or 256-color palettes.";
			errcodes[DDERR_NORASTEROPHW] = "DDERR_NORASTEROPHW: The operation cannot be carried out because no appropriate raster operation hardware is present or available.";
			errcodes[DDERR_NOROTATIONHW] = "DDERR_NOROTATIONHW: The operation cannot be carried out because no rotation hardware is present or available.";
			errcodes[DDERR_NOSTRETCHHW] = "DDERR_NOSTRETCHHW: The operation cannot be carried out because there is no hardware support for stretching.";
			errcodes[DDERR_NOT4BITCOLOR] = "DDERR_NOT4BITCOLOR: The DirectDrawSurface object is not using a 4-bit color palette and the requested operation requires a 4-bit color palette.";
			errcodes[DDERR_NOT4BITCOLORINDEX] = "DDERR_NOT4BITCOLORINDEX: The DirectDrawSurface object is not using a 4-bit color index palette and the requested operation requires a 4-bit color index palette.";
			errcodes[DDERR_NOT8BITCOLOR] = "DDERR_NOT8BITCOLOR: The DirectDrawSurface object is not using an 8-bit color palette and the requested operation requires an 8-bit color palette.";
			errcodes[DDERR_NOTAOVERLAYSURFACE] = "DDERR_NOTAOVERLAYSURFACE: An overlay component is called for a non-overlay surface.";
			errcodes[DDERR_NOTEXTUREHW] = "DDERR_NOTEXTUREHW: The operation cannot be carried out because no texture-mapping hardware is present or available.";
			errcodes[DDERR_NOTFLIPPABLE] = "DDERR_NOTFLIPPABLE: An attempt has been made to flip a surface that cannot be flipped.";
			errcodes[DDERR_NOTFOUND] = "DDERR_NOTFOUND: The requested item was not found.";
			errcodes[DDERR_NOTINITIALIZED] = "DDERR_NOTINITIALIZED: An attempt was made to call an interface method of a DirectDraw object created by CoCreateInstance before the object was initialized.";
			errcodes[DDERR_NOTLOADED] = "DDERR_NOTLOADED: The surface is an optimized surface, but it has not yet been allocated any memory.";
			errcodes[DDERR_NOTLOCKED] = "DDERR_NOTLOCKED: An attempt is made to unlock a surface that was not locked.";
			errcodes[DDERR_NOTPAGELOCKED] = "DDERR_NOTPAGELOCKED: An attempt is made to page unlock a surface with no outstanding page locks.";
			errcodes[DDERR_NOTPALETTIZED] = "DDERR_NOTPALETTIZED: The surface being used is not a palette-based surface.";
			errcodes[DDERR_NOVSYNCHW] = "DDERR_NOVSYNCHW: The operation cannot be carried out because there is no hardware support for vertical blank synchronized operations.";
			errcodes[DDERR_NOZBUFFERHW] = "DDERR_NOZBUFFERHW: The operation to create a z-buffer in display memory or to perform a blit using a z-buffer cannot be carried out because there is no hardware support for z-buffers.";
			errcodes[DDERR_NOZOVERLAYHW] = "DDERR_NOZOVERLAYHW: The overlay surfaces cannot be z-layered based on the z-order because the hardware does not support z-ordering of overlays.";
			errcodes[DDERR_OUTOFCAPS] = "DDERR_OUTOFCAPS: The hardware needed for the requested operation has already been allocated.";
			errcodes[DDERR_OUTOFMEMORY] = "DDERR_OUTOFMEMORY: DirectDraw does not have enough memory to perform the operation.";
			errcodes[DDERR_OUTOFVIDEOMEMORY] = "DDERR_OUTOFVIDEOMEMORY: DirectDraw does not have enough display memory to perform the operation.";
			errcodes[DDERR_OVERLAPPINGRECTS] = "DDERR_OVERLAPPINGRECTS: Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other.";
			errcodes[DDERR_OVERLAYCANTCLIP] = "DDERR_OVERLAYCANTCLIP: The hardware does not support clipped overlays.";
			errcodes[DDERR_OVERLAYCOLORKEYONLYONEACTIVE] = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE: An attempt was made to have more than one color key active on an overlay.";
			errcodes[DDERR_OVERLAYNOTVISIBLE] = "DDERR_OVERLAYNOTVISIBLE: The IDirectDrawSurface4::GetOverlayPosition method is called on a hidden overlay.";
			errcodes[DDERR_PALETTEBUSY] = "DDERR_PALETTEBUSY: Access to this palette is refused because the palette is locked by another thread.";
			errcodes[DDERR_PRIMARYSURFACEALREADYEXISTS] = "DDERR_PRIMARYSURFACEALREADYEXISTS: This process has already created a primary surface.";
			errcodes[DDERR_REGIONTOOSMALL] = "DDERR_REGIONTOOSMALL: The region passed to the IDirectDrawClipper::GetClipList method is too small.";
			errcodes[DDERR_SURFACEALREADYATTACHED] = "DDERR_SURFACEALREADYATTACHED: An attempt was made to attach a surface to another surface to which it is already attached.";
			errcodes[DDERR_SURFACEALREADYDEPENDENT] = "DDERR_SURFACEALREADYDEPENDENT: An attempt was made to make a surface a dependency of another surface to which it is already dependent.";
			errcodes[DDERR_SURFACEBUSY] = "DDERR_SURFACEBUSY: Access to the surface is refused because the surface is locked by another thread.";
			errcodes[DDERR_SURFACEISOBSCURED] = "DDERR_SURFACEISOBSCURED: Access to the surface is refused because the surface is obscured.";
			errcodes[DDERR_SURFACELOST] = "DDERR_SURFACELOST: Access to the surface is refused because the surface memory is gone. Call the IDirectDrawSurface4::Restore method on this surface to restore the memory associated with it.";
			errcodes[DDERR_SURFACENOTATTACHED] = "DDERR_SURFACENOTATTACHED: The requested surface is not attached.";
			errcodes[DDERR_TOOBIGHEIGHT] = "DDERR_TOOBIGHEIGHT: The height requested by DirectDraw is too large.";
			errcodes[DDERR_TOOBIGSIZE] = "DDERR_TOOBIGSIZE: The size requested by DirectDraw is too large. However, the individual height and width are valid sizes.";
			errcodes[DDERR_TOOBIGWIDTH] = "DDERR_TOOBIGWIDTH: The width requested by DirectDraw is too large.";
			errcodes[DDERR_UNSUPPORTED] = "DDERR_UNSUPPORTED: The operation is not supported.";
			errcodes[DDERR_UNSUPPORTEDFORMAT] = "DDERR_UNSUPPORTEDFORMAT: The pixel format requested is not supported by DirectDraw.";
			errcodes[DDERR_UNSUPPORTEDMASK] = "DDERR_UNSUPPORTEDMASK: The bitmask in the pixel format requested is not supported by DirectDraw.";
			errcodes[DDERR_UNSUPPORTEDMODE] = "DDERR_UNSUPPORTEDMODE: The display is currently in an unsupported mode.";
			errcodes[DDERR_VERTICALBLANKINPROGRESS] = "DDERR_VERTICALBLANKINPROGRESS: A vertical blank is in progress.";
			errcodes[DDERR_VIDEONOTACTIVE] = "DDERR_VIDEONOTACTIVE: The video port is not active.";
			errcodes[DDERR_WASSTILLDRAWING] = "DDERR_WASSTILLDRAWING: The previous blit operation that is transferring information to or from this surface is incomplete.";
			errcodes[DDERR_WRONGMODE] = "DDERR_WRONGMODE: This surface cannot be restored because it was created in a different mode.";
			errcodes[DDERR_XALIGN] = "DDERR_XALIGN: The provided rectangle was not horizontally aligned on a required boundary.";
		}

		if(ret != S_OK) {
			if(errcodes.find(ret) != errcodes.end()) {
				Log("ERROR: %s", errcodes[ret]);
			} else {
				Log("ERROR: UNKNOWN");
			}
		}
	}
}

void HookVTBLCalls(LPVOID *ppvObj, SVTBL_HOOK *vtbl_hooks, const unsigned int count_vtbl_hooks, const char *cstrInterface) {
	DWORD* ppvtbl = (DWORD*)*ppvObj;
	DWORD* pvtbl = (DWORD*) *ppvtbl;

	DWORD flOldProtect, flNewProtect, flDontCare;
	MEMORY_BASIC_INFORMATION mbi;

	//Get the current protection attributes                            
	VirtualQuery((void*)pvtbl, &mbi, sizeof(mbi));

	//remove ReadOnly and ExecuteRead attributes, add on ReadWrite flag
	flNewProtect = mbi.Protect;
	flNewProtect &= ~(PAGE_READONLY | PAGE_EXECUTE_READ | PAGE_EXECUTE | PAGE_WRITECOPY);
	flNewProtect |= (PAGE_READWRITE);

	if(!VirtualProtect((void*)pvtbl, sizeof(PVOID)*count_vtbl_hooks, flNewProtect, &flOldProtect)) {
		DWORD dwErr = GetLastError();
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
		Log("\t->%s\n", (LPCTSTR)lpMsgBuf);
		LocalFree(lpMsgBuf);
	} else {
		for(unsigned int i = 0; i < count_vtbl_hooks; i++) {
			if(vtbl_hooks[i].newFunc != NULL) {
				DWORD* pFuncOffset = MakePtr(DWORD *, pvtbl, vtbl_hooks[i].offset);
				vtbl_hooks[i].oldFunc = (DWORD *)*pFuncOffset;
				*pFuncOffset = (DWORD)vtbl_hooks[i].newFunc;

				Log("\t->HOOKED: %s::%s(%#010lx -> %#010lx)\n", cstrInterface, vtbl_hooks[i].name, vtbl_hooks[i].oldFunc, vtbl_hooks[i].newFunc);
			}
		}


		//Put the page attributes back the way they were.
		VirtualProtect((void*)pvtbl, sizeof(PVOID)*count_vtbl_hooks, flOldProtect, &flDontCare);
	}
}

void SetD3DRect(D3DRECT &rect, DWORD _x1, DWORD _x2, DWORD _y1, DWORD _y2) {
	rect.x1 = rect.lX1 = _x1;
	rect.x2 = rect.lX2 = _x2;
	rect.y1 = rect.lY1 = _y1;
	rect.y2 = rect.lY2 = _y2;
}