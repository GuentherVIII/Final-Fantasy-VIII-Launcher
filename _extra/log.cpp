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

#include "log.h"

LOGLEVEL cLog::m_logLevel = LL_DISABLED;
std::map<HRESULT, char *> cLog::m_errcodes;

void cLog::SetLogLevel(LOGLEVEL _ll) { cLog::m_logLevel = _ll; }
void cLog::GetLogLevel(LOGLEVEL *_ll) { *_ll = cLog::m_logLevel; }

cLog& cLog::p(REFIID a) {
	/*
	DEFINE_GUID( CLSID_DirectDraw,					0xD7B70EE0,	0x4340,	0x11CF,	0xB0,	0x63,	0x00,	0x20,	0xAF,	0xC2,	0xCD,	0x35 );
	DEFINE_GUID( CLSID_DirectDraw7,					0x3c305196,	0x50db,	0x11d3,	0x9c,	0xfe,	0x00,	0xc0,	0x4f,	0xd9,	0x30,	0xc5 );
	DEFINE_GUID( CLSID_DirectDrawClipper,			0x593817A0,	0x7DB3,	0x11CF,	0xA2,	0xDE,	0x00,	0xAA,	0x00,	0xb9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirectDraw,					0x6C14DB80,	0xA733,	0x11CE,	0xA5,	0x21,	0x00,	0x20,	0xAF,	0x0B,	0xE5,	0x60 );
	DEFINE_GUID( IID_IDirectDraw2,					0xB3A6F3E0,	0x2B43,	0x11CF,	0xA2,	0xDE,	0x00,	0xAA,	0x00,	0xB9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirectDraw4,					0x9c59509a,	0x39bd,	0x11d1,	0x8c,	0x4a,	0x00,	0xc0,	0x4f,	0xd9,	0x30,	0xc5 );
	DEFINE_GUID( IID_IDirectDraw7,					0x15e65ec0,	0x3b9c,	0x11d2,	0xb9,	0x2f,	0x00,	0x60,	0x97,	0x97,	0xea,	0x5b );
	DEFINE_GUID( IID_IDirectDrawSurface,			0x6C14DB81,	0xA733,	0x11CE,	0xA5,	0x21,	0x00,	0x20,	0xAF,	0x0B,	0xE5,	0x60 );
	DEFINE_GUID( IID_IDirectDrawSurface2,			0x57805885,	0x6eec,	0x11cf,	0x94,	0x41,	0xa8,	0x23,	0x03,	0xc1,	0x0e,	0x27 );
	DEFINE_GUID( IID_IDirectDrawSurface3,			0xDA044E00,	0x69B2,	0x11D0,	0xA1,	0xD5,	0x00,	0xAA,	0x00,	0xB8,	0xDF,	0xBB );
	DEFINE_GUID( IID_IDirectDrawSurface4,			0x0B2B8630,	0xAD35,	0x11D0,	0x8E,	0xA6,	0x00,	0x60,	0x97,	0x97,	0xEA,	0x5B );
	DEFINE_GUID( IID_IDirectDrawSurface7,			0x06675a80,	0x3b9b,	0x11d2,	0xb9,	0x2f,	0x00,	0x60,	0x97,	0x97,	0xea,	0x5b );
	DEFINE_GUID( IID_IDirectDrawPalette,			0x6C14DB84,	0xA733,	0x11CE,	0xA5,	0x21,	0x00,	0x20,	0xAF,	0x0B,	0xE5,	0x60 );
	DEFINE_GUID( IID_IDirectDrawClipper,			0x6C14DB85,	0xA733,	0x11CE,	0xA5,	0x21,	0x00,	0x20,	0xAF,	0x0B,	0xE5,	0x60 );
	DEFINE_GUID( IID_IDirectDrawColorControl,		0x4B9F0EE0,	0x0D7E,	0x11D0,	0x9B,	0x06,	0x00,	0xA0,	0xC9,	0x03,	0xA3,	0xB8 );
	DEFINE_GUID( IID_IDirectDrawGammaControl,		0x69C11C3E,	0xB46B,	0x11D1,	0xAD,	0x7A,	0x00,	0xC0,	0x4F,	0xC2,	0x9B,	0x4E );
	DEFINE_GUID( IID_IDirect3D,						0x3BBA0080,	0x2421,	0x11CF,	0xA3,	0x1A,	0x00,	0xAA,	0x00,	0xB9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirect3D2,					0x6aae1ec1,	0x662a,	0x11d0,	0x88,	0x9d,	0x00,	0xaa,	0x00,	0xbb,	0xb7,	0x6a);
	DEFINE_GUID( IID_IDirect3D3,					0xbb223240,	0xe72b,	0x11d0,	0xa9,	0xb4,	0x00,	0xaa,	0x00,	0xc0,	0x99,	0x3e);
	DEFINE_GUID( IID_IDirect3D7,					0xf5049e77,	0x4861,	0x11d2,	0xa4,	0x7,	0x0,	0xa0,	0xc9,	0x6,	0x29,	0xa8);
	DEFINE_GUID( IID_IDirect3DRampDevice,			0xF2086B20,	0x259F,	0x11CF,	0xA3,	0x1A,	0x00,	0xAA,	0x00,	0xB9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirect3DRGBDevice,			0xA4665C60,	0x2673,	0x11CF,	0xA3,	0x1A,	0x00,	0xAA,	0x00,	0xB9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirect3DHALDevice,			0x84E63dE0,	0x46AA,	0x11CF,	0x81,	0x6F,	0x00,	0x00,	0xC0,	0x20,	0x15,	0x6E );
	DEFINE_GUID( IID_IDirect3DMMXDevice,			0x881949a1,	0xd6f3,	0x11d0,	0x89,	0xab,	0x00,	0xa0,	0xc9,	0x05,	0x41,	0x29 );
	DEFINE_GUID( IID_IDirect3DRefDevice,			0x50936643,	0x13e9,	0x11d1,	0x89,	0xaa,	0x0,	0xa0,	0xc9,	0x5,	0x41,	0x29);
	DEFINE_GUID( IID_IDirect3DNullDevice,			0x8767df22,	0xbacc,	0x11d1,	0x89,	0x69,	0x0,	0xa0,	0xc9,	0x6,	0x29,	0xa8);
	DEFINE_GUID( IID_IDirect3DTnLHalDevice,			0xf5049e78,	0x4861,	0x11d2,	0xa4,	0x7,	0x0,	0xa0,	0xc9,	0x6,	0x29,	0xa8);
	DEFINE_GUID( IID_IDirect3DDevice,				0x64108800,	0x957d,	0x11d0,	0x89,	0xab,	0x00,	0xa0,	0xc9,	0x05,	0x41,	0x29 );
	DEFINE_GUID( IID_IDirect3DDevice2,				0x93281501,	0x8cf8,	0x11d0,	0x89,	0xab,	0x0,	0xa0,	0xc9,	0x5,	0x41,	0x29);
	DEFINE_GUID( IID_IDirect3DDevice3,				0xb0ab3b60,	0x33d7,	0x11d1,	0xa9,	0x81,	0x0,	0xc0,	0x4f,	0xd7,	0xb1,	0x74);
	DEFINE_GUID( IID_IDirect3DDevice7,				0xf5049e79,	0x4861,	0x11d2,	0xa4,	0x7,	0x0,	0xa0,	0xc9,	0x6,	0x29,	0xa8);
	DEFINE_GUID( IID_IDirect3DTexture,				0x2CDCD9E0,	0x25A0,	0x11CF,	0xA3,	0x1A,	0x00,	0xAA,	0x00,	0xB9,	0x33,	0x56 );
	DEFINE_GUID( IID_IDirect3DTexture2,				0x93281502,	0x8cf8,	0x11d0,	0x89,	0xab,	0x0,	0xa0,	0xc9,	0x5,	0x41,	0x29);
	DEFINE_GUID( IID_IDirect3DLight,				0x4417C142,	0x33AD,	0x11CF,	0x81,	0x6F,	0x00,	0x00,	0xC0,	0x20,	0x15,	0x6E );
	DEFINE_GUID( IID_IDirect3DMaterial,				0x4417C144,	0x33AD,	0x11CF,	0x81,	0x6F,	0x00,	0x00,	0xC0,	0x20,	0x15,	0x6E );
	DEFINE_GUID( IID_IDirect3DMaterial2,			0x93281503,	0x8cf8,	0x11d0,	0x89,	0xab,	0x0,	0xa0,	0xc9,	0x5,	0x41,	0x29);
	DEFINE_GUID( IID_IDirect3DMaterial3,			0xca9c46f4,	0xd3c5,	0x11d1,	0xb7,	0x5a,	0x0,	0x60,	0x8,	0x52,	0xb3,	0x12);
	DEFINE_GUID( IID_IDirect3DExecuteBuffer,		0x4417C145,	0x33AD,	0x11CF,	0x81,	0x6F,	0x00,	0x00,	0xC0,	0x20,	0x15,	0x6E );
	DEFINE_GUID( IID_IDirect3DViewport,				0x4417C146,	0x33AD,	0x11CF,	0x81,	0x6F,	0x00,	0x00,	0xC0,	0x20,	0x15,	0x6E );
	DEFINE_GUID( IID_IDirect3DViewport2,			0x93281500,	0x8cf8,	0x11d0,	0x89,	0xab,	0x0,	0xa0,	0xc9,	0x5,	0x41,	0x29);
	DEFINE_GUID( IID_IDirect3DViewport3,			0xb0ab3b61,	0x33d7,	0x11d1,	0xa9,	0x81,	0x0,	0xc0,	0x4f,	0xd7,	0xb1,	0x74);
	DEFINE_GUID( IID_IDirect3DVertexBuffer,			0x7a503555,	0x4a83,	0x11d1,	0xa5,	0xdb,	0x0,	0xa0,	0xc9,	0x3,	0x67,	0xf8);
	DEFINE_GUID( IID_IDirect3DVertexBuffer7,		0xf5049e7d,	0x4861,	0x11d2,	0xa4,	0x7,	0x0,	0xa0,	0xc9,	0x6,	0x29,	0xa8);
	*/

	if(a == CLSID_DirectDraw) { LOG_PUT("REFIID = CLSID_DirectDraw");
	//} else if(a == CLSID_DirectDraw7) { LOG_PUT("REFIID = CLSID_DirectDraw7");
	} else if(a == CLSID_DirectDrawClipper) { LOG_PUT("REFIID = CLSID_DirectDrawClipper");
	} else if(a == IID_IDirectDraw) { LOG_PUT("REFIID = IID_IDirectDraw");
	} else if(a == IID_IDirectDraw2) { LOG_PUT("REFIID = IID_IDirectDraw2");
	} else if(a == IID_IDirectDraw4) { LOG_PUT("REFIID = IID_IDirectDraw4");
	//} else if(a == IID_IDirectDraw7) { LOG_PUT("REFIID = IID_IDirectDraw7");
	} else if(a == IID_IDirectDrawSurface) { LOG_PUT("REFIID = IID_IDirectDrawSurface");
	} else if(a == IID_IDirectDrawSurface2) { LOG_PUT("REFIID = IID_IDirectDrawSurface2");
	} else if(a == IID_IDirectDrawSurface3) { LOG_PUT("REFIID = IID_IDirectDrawSurface3");
	} else if(a == IID_IDirectDrawSurface4) { LOG_PUT("REFIID = IID_IDirectDrawSurface4");
	//} else if(a == IID_IDirectDrawSurface7) { LOG_PUT("REFIID = IID_IDirectDrawSurface7");
	} else if(a == IID_IDirectDrawPalette) { LOG_PUT("REFIID = IID_IDirectDrawPalette");
	} else if(a == IID_IDirectDrawClipper) { LOG_PUT("REFIID = IID_IDirectDrawClipper");
	} else if(a == IID_IDirectDrawColorControl) { LOG_PUT("REFIID = IID_IDirectDrawColorControl");
	} else if(a == IID_IDirectDrawGammaControl) { LOG_PUT("REFIID = IID_IDirectDrawGammaControl");
	} else if(a == IID_IDirect3D) { LOG_PUT("REFIID = IID_IDirect3D");
	} else if(a == IID_IDirect3D2) { LOG_PUT("REFIID = IID_IDirect3D2");
	} else if(a == IID_IDirect3D3) { LOG_PUT("REFIID = IID_IDirect3D3");
	//} else if(a == IID_IDirect3D7) { LOG_PUT("REFIID = IID_IDirect3D7");
	} else if(a == IID_IDirect3DRampDevice) { LOG_PUT("REFIID = IID_IDirect3DRampDevice");
	} else if(a == IID_IDirect3DRGBDevice) { LOG_PUT("REFIID = IID_IDirect3DRGBDevice");
	} else if(a == IID_IDirect3DHALDevice) { LOG_PUT("REFIID = IID_IDirect3DHALDevice");
	} else if(a == IID_IDirect3DMMXDevice) { LOG_PUT("REFIID = IID_IDirect3DMMXDevice");
	} else if(a == IID_IDirect3DRefDevice) { LOG_PUT("REFIID = IID_IDirect3DRefDevice");
	} else if(a == IID_IDirect3DNullDevice) { LOG_PUT("REFIID = IID_IDirect3DNullDevice");
	//} else if(a == IID_IDirect3DTnLHalDevice) { LOG_PUT("REFIID = IID_IDirect3DTnLHalDevice");
	} else if(a == IID_IDirect3DDevice) { LOG_PUT("REFIID = IID_IDirect3DDevice");
	} else if(a == IID_IDirect3DDevice2) { LOG_PUT("REFIID = IID_IDirect3DDevice2");
	} else if(a == IID_IDirect3DDevice3) { LOG_PUT("REFIID = IID_IDirect3DDevice3");
	//} else if(a == IID_IDirect3DDevice7) { LOG_PUT("REFIID = IID_IDirect3DDevice7");
	} else if(a == IID_IDirect3DTexture) { LOG_PUT("REFIID = IID_IDirect3DTexture");
	} else if(a == IID_IDirect3DTexture2) { LOG_PUT("REFIID = IID_IDirect3DTexture2");
	} else if(a == IID_IDirect3DLight) { LOG_PUT("REFIID = IID_IDirect3DLight");
	} else if(a == IID_IDirect3DMaterial) { LOG_PUT("REFIID = IID_IDirect3DMaterial");
	} else if(a == IID_IDirect3DMaterial2) { LOG_PUT("REFIID = IID_IDirect3DMaterial2");
	} else if(a == IID_IDirect3DMaterial3) { LOG_PUT("REFIID = IID_IDirect3DMaterial3");
	} else if(a == IID_IDirect3DExecuteBuffer) { LOG_PUT("REFIID = IID_IDirect3DExecuteBuffer");
	} else if(a == IID_IDirect3DViewport) { LOG_PUT("REFIID = IID_IDirect3DViewport");
	} else if(a == IID_IDirect3DViewport2) { LOG_PUT("REFIID = IID_IDirect3DViewport2");
	} else if(a == IID_IDirect3DViewport3) { LOG_PUT("REFIID = IID_IDirect3DViewport3");
	} else if(a == IID_IDirect3DVertexBuffer) { LOG_PUT("REFIID = IID_IDirect3DVertexBuffer");
	//} else if(a == IID_IDirect3DVertexBuffer7) { LOG_PUT("REFIID = IID_IDirect3DVertexBuffer7");
	} else { LOG_PUT("REFIID = { %#010lx, %#06x, %#06x, { %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x, %#04x } }", a.Data1, a.Data2, a.Data3, a.Data4[0], a.Data4[1], a.Data4[2], a.Data4[3], a.Data4[4], a.Data4[5], a.Data4[6], a.Data4[7]); }
}

cLog& cLog::p(HRESULT a) {
	if(m_errcodes.size() <= 0) {
		m_errcodes[DDERR_ALREADYINITIALIZED] = "DDERR_ALREADYINITIALIZED: The object has already been initialized.";
		m_errcodes[DDERR_BLTFASTCANTCLIP] = "DDERR_BLTFASTCANTCLIP: A DirectDrawClipper object is attached to a source surface that has passed into a call to the IDirectDrawSurface4::BltFast method.";
		m_errcodes[DDERR_CANNOTATTACHSURFACE] = "DDERR_CANNOTATTACHSURFACE: A surface cannot be attached to another requested surface.";
		m_errcodes[DDERR_CANNOTDETACHSURFACE] = "DDERR_CANNOTDETACHSURFACE: A surface cannot be detached from another requested surface.";
		m_errcodes[DDERR_CANTCREATEDC] = "DDERR_CANTCREATEDC: Windows can not create any more device contexts (DCs), or a DC was requested for a palette-indexed surface when the surface had no palette and the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)."; 
		m_errcodes[DDERR_CANTDUPLICATE] = "DDERR_CANTDUPLICATE: Primary and 3-D surfaces, or surfaces that are implicitly created, cannot be duplicated."; 
		m_errcodes[DDERR_CANTLOCKSURFACE] = "DDERR_CANTLOCKSURFACE: Access to this surface is refused because an attempt was made to lock the primary surface without DCI support.";
		m_errcodes[DDERR_CANTPAGELOCK] = "DDERR_CANTPAGELOCK: An attempt to page lock a surface failed. Page lock will not work on a display-memory surface or an emulated primary surface.";
		m_errcodes[DDERR_CANTPAGEUNLOCK] = "DDERR_CANTPAGEUNLOCK: An attempt to page unlock a surface failed. Page unlock will not work on a display-memory surface or an emulated primary surface.";
		m_errcodes[DDERR_CLIPPERISUSINGHWND] = "DDERR_CLIPPERISUSINGHWND: An attempt was made to set a clip list for a DirectDrawClipper object that is already monitoring a window handle.";
		m_errcodes[DDERR_COLORKEYNOTSET] = "DDERR_COLORKEYNOTSET: No source color key is specified for this operation.";
		m_errcodes[DDERR_CURRENTLYNOTAVAIL] = "DDERR_CURRENTLYNOTAVAIL: No support is currently available.";
		m_errcodes[DDERR_DCALREADYCREATED] = "DDERR_DCALREADYCREATED: A device context (DC) has already been returned for this surface. Only one DC can be retrieved for each surface.";
		m_errcodes[DDERR_DEVICEDOESNTOWNSURFACE] = "DDERR_DEVICEDOESNTOWNSURFACE: Surfaces created by one DirectDraw device cannot be used directly by another DirectDraw device.";
		m_errcodes[DDERR_DIRECTDRAWALREADYCREATED] = "DDERR_DIRECTDRAWALREADYCREATED: A DirectDraw object representing this driver has already been created for this process.";
		m_errcodes[DDERR_EXCEPTION] = "DDERR_EXCEPTION: An exception was encountered while performing the requested operation.";
		m_errcodes[DDERR_EXCLUSIVEMODEALREADYSET] = "DDERR_EXCLUSIVEMODEALREADYSET: An attempt was made to set the cooperative level when it was already set to exclusive.";
		m_errcodes[DDERR_EXPIRED] = "DDERR_EXPIRED: The data has expired and is therefore no longer valid.";
		m_errcodes[DDERR_GENERIC] = "DDERR_GENERIC: There is an undefined error condition.";
		m_errcodes[DDERR_HEIGHTALIGN] = "DDERR_HEIGHTALIGN: The height of the provided rectangle is not a multiple of the required alignment.";
		m_errcodes[DDERR_HWNDALREADYSET] = "DDERR_HWNDALREADYSET: The DirectDraw cooperative level window handle has already been set. It cannot be reset while the process has surfaces or palettes created.";
		m_errcodes[DDERR_HWNDSUBCLASSED] = "DDERR_HWNDSUBCLASSED: DirectDraw is prevented from restoring state because the DirectDraw cooperative level window handle has been subclassed.";
		m_errcodes[DDERR_IMPLICITLYCREATED] = "DDERR_IMPLICITLYCREATED: The surface cannot be restored because it is an implicitly created surface.";
		m_errcodes[DDERR_INCOMPATIBLEPRIMARY] = "DDERR_INCOMPATIBLEPRIMARY: The primary surface creation request does not match with the existing primary surface.";
		m_errcodes[DDERR_INVALIDCAPS] = "DDERR_INVALIDCAPS: One or more of the capability bits passed to the callback function are incorrect.";
		m_errcodes[DDERR_INVALIDCLIPLIST] = "DDERR_INVALIDCLIPLIST: DirectDraw does not support the provided clip list.";
		m_errcodes[DDERR_INVALIDDIRECTDRAWGUID] = "DDERR_INVALIDDIRECTDRAWGUID: The globally unique identifier (GUID) passed to the DirectDrawCreate function is not a valid DirectDraw driver identifier.";
		m_errcodes[DDERR_INVALIDMODE] = "DDERR_INVALIDMODE: DirectDraw does not support the requested mode.";
		m_errcodes[DDERR_INVALIDOBJECT] = "DDERR_INVALIDOBJECT: DirectDraw received a pointer that was an invalid DirectDraw object.";
		m_errcodes[DDERR_INVALIDPARAMS] = "DDERR_INVALIDPARAMS: One or more of the parameters passed to the method are incorrect.";
		m_errcodes[DDERR_INVALIDPIXELFORMAT] = "DDERR_INVALIDPIXELFORMAT: The pixel format was invalid as specified.";
		m_errcodes[DDERR_INVALIDPOSITION] = "DDERR_INVALIDPOSITION: The position of the overlay on the destination is no longer legal.";
		m_errcodes[DDERR_INVALIDRECT] = "DDERR_INVALIDRECT: The provided rectangle was invalid.";
		m_errcodes[DDERR_INVALIDSTREAM] = "DDERR_INVALIDSTREAM: The specified stream contains invalid data.";
		m_errcodes[DDERR_INVALIDSURFACETYPE] = "DDERR_INVALIDSURFACETYPE: The requested operation could not be performed because the surface was of the wrong type.";
		m_errcodes[DDERR_LOCKEDSURFACES] = "DDERR_LOCKEDSURFACES: One or more surfaces are locked, causing the failure of the requested operation.";
		m_errcodes[DDERR_MOREDATA] = "DDERR_MOREDATA: There is more data available than the specified buffer size can hold.";
		m_errcodes[DDERR_NO3D] = "DDERR_NO3D: No 3-D hardware or emulation is present.";
		m_errcodes[DDERR_NOALPHAHW] = "DDERR_NOALPHAHW: No alpha acceleration hardware is present or available, causing the failure of the requested operation.";
		m_errcodes[DDERR_NOBLTHW] = "DDERR_NOBLTHW: No blitter hardware is present.";
		m_errcodes[DDERR_NOCLIPLIST] = "DDERR_NOCLIPLIST: No clip list is available.";
		m_errcodes[DDERR_NOCLIPPERATTACHED] = "DDERR_NOCLIPPERATTACHED: No DirectDrawClipper object is attached to the surface object.";
		m_errcodes[DDERR_NOCOLORCONVHW] = "DDERR_NOCOLORCONVHW: The operation cannot be carried out because no color-conversion hardware is present or available.";
		m_errcodes[DDERR_NOCOLORKEY] = "DDERR_NOCOLORKEY: The surface does not currently have a color key.";
		m_errcodes[DDERR_NOCOLORKEYHW] = "DDERR_NOCOLORKEYHW: The operation cannot be carried out because there is no hardware support for the destination color key.";
		m_errcodes[DDERR_NOCOOPERATIVELEVELSET] = "DDERR_NOCOOPERATIVELEVELSET: A create function is called without the IDirectDraw4::SetCooperativeLevel method being called.";
		m_errcodes[DDERR_NODC] = "DDERR_NODC: No DC has ever been created for this surface.";
		m_errcodes[DDERR_NODDROPSHW] = "DDERR_NODDROPSHW: No DirectDraw raster operation (ROP) hardware is available.";
		m_errcodes[DDERR_NODIRECTDRAWHW] = "DDERR_NODIRECTDRAWHW: Hardware-only DirectDraw object creation is not possible; the driver does not support any hardware.";
		m_errcodes[DDERR_NODIRECTDRAWSUPPORT] = "DDERR_NODIRECTDRAWSUPPORT: DirectDraw support is not possible with the current display driver.";
		m_errcodes[DDERR_NOEMULATION] = "DDERR_NOEMULATION: Software emulation is not available.";
		m_errcodes[DDERR_NOEXCLUSIVEMODE] = "DDERR_NOEXCLUSIVEMODE: The operation requires the application to have exclusive mode, but the application does not have exclusive mode.";
		m_errcodes[DDERR_NOFLIPHW] = "DDERR_NOFLIPHW: Flipping visible surfaces is not supported.";
		m_errcodes[DDERR_NOFOCUSWINDOW] = "DDERR_NOFOCUSWINDOW: An attempt was made to create or set a device window without first setting the focus window.";
		m_errcodes[DDERR_NOGDI] = "DDERR_NOGDI: No GDI is present.";
		m_errcodes[DDERR_NOHWND] = "DDERR_NOHWND: Clipper notification requires a window handle, or no window handle has been previously set as the cooperative level window handle.";
		m_errcodes[DDERR_NOMIPMAPHW] = "DDERR_NOMIPMAPHW: The operation cannot be carried out because no mipmap capable texture mapping hardware is present or available.";
		m_errcodes[DDERR_NOMIRRORHW] = "DDERR_NOMIRRORHW: The operation cannot be carried out because no mirroring hardware is present or available.";
		m_errcodes[DDERR_NONONLOCALVIDMEM] = "DDERR_NONONLOCALVIDMEM: An attempt was made to allocate non-local video memory from a device that does not support non-local video memory.";
		m_errcodes[DDERR_NOOPTIMIZEHW] = "DDERR_NOOPTIMIZEHW: The device does not support optimized surfaces.";
		m_errcodes[DDERR_NOOVERLAYDEST] = "DDERR_NOOVERLAYDEST: The IDirectDrawSurface4::GetOverlayPosition method is called on an overlay that the IDirectDrawSurface4::UpdateOverlay method has not been called on to establish a destination.";
		m_errcodes[DDERR_NOOVERLAYHW] = "DDERR_NOOVERLAYHW: The operation cannot be carried out because no overlay hardware is present or available.";
		m_errcodes[DDERR_NOPALETTEATTACHED] = "DDERR_NOPALETTEATTACHED: No palette object is attached to this surface.";
		m_errcodes[DDERR_NOPALETTEHW] = "DDERR_NOPALETTEHW: There is no hardware support for 16- or 256-color palettes.";
		m_errcodes[DDERR_NORASTEROPHW] = "DDERR_NORASTEROPHW: The operation cannot be carried out because no appropriate raster operation hardware is present or available.";
		m_errcodes[DDERR_NOROTATIONHW] = "DDERR_NOROTATIONHW: The operation cannot be carried out because no rotation hardware is present or available.";
		m_errcodes[DDERR_NOSTRETCHHW] = "DDERR_NOSTRETCHHW: The operation cannot be carried out because there is no hardware support for stretching.";
		m_errcodes[DDERR_NOT4BITCOLOR] = "DDERR_NOT4BITCOLOR: The DirectDrawSurface object is not using a 4-bit color palette and the requested operation requires a 4-bit color palette.";
		m_errcodes[DDERR_NOT4BITCOLORINDEX] = "DDERR_NOT4BITCOLORINDEX: The DirectDrawSurface object is not using a 4-bit color index palette and the requested operation requires a 4-bit color index palette.";
		m_errcodes[DDERR_NOT8BITCOLOR] = "DDERR_NOT8BITCOLOR: The DirectDrawSurface object is not using an 8-bit color palette and the requested operation requires an 8-bit color palette.";
		m_errcodes[DDERR_NOTAOVERLAYSURFACE] = "DDERR_NOTAOVERLAYSURFACE: An overlay component is called for a non-overlay surface.";
		m_errcodes[DDERR_NOTEXTUREHW] = "DDERR_NOTEXTUREHW: The operation cannot be carried out because no texture-mapping hardware is present or available.";
		m_errcodes[DDERR_NOTFLIPPABLE] = "DDERR_NOTFLIPPABLE: An attempt has been made to flip a surface that cannot be flipped.";
		m_errcodes[DDERR_NOTFOUND] = "DDERR_NOTFOUND: The requested item was not found.";
		m_errcodes[DDERR_NOTINITIALIZED] = "DDERR_NOTINITIALIZED: An attempt was made to call an interface method of a DirectDraw object created by CoCreateInstance before the object was initialized.";
		m_errcodes[DDERR_NOTLOADED] = "DDERR_NOTLOADED: The surface is an optimized surface, but it has not yet been allocated any memory.";
		m_errcodes[DDERR_NOTLOCKED] = "DDERR_NOTLOCKED: An attempt is made to unlock a surface that was not locked.";
		m_errcodes[DDERR_NOTPAGELOCKED] = "DDERR_NOTPAGELOCKED: An attempt is made to page unlock a surface with no outstanding page locks.";
		m_errcodes[DDERR_NOTPALETTIZED] = "DDERR_NOTPALETTIZED: The surface being used is not a palette-based surface.";
		m_errcodes[DDERR_NOVSYNCHW] = "DDERR_NOVSYNCHW: The operation cannot be carried out because there is no hardware support for vertical blank synchronized operations.";
		m_errcodes[DDERR_NOZBUFFERHW] = "DDERR_NOZBUFFERHW: The operation to create a z-buffer in display memory or to perform a blit using a z-buffer cannot be carried out because there is no hardware support for z-buffers.";
		m_errcodes[DDERR_NOZOVERLAYHW] = "DDERR_NOZOVERLAYHW: The overlay surfaces cannot be z-layered based on the z-order because the hardware does not support z-ordering of overlays.";
		m_errcodes[DDERR_OUTOFCAPS] = "DDERR_OUTOFCAPS: The hardware needed for the requested operation has already been allocated.";
		m_errcodes[DDERR_OUTOFMEMORY] = "DDERR_OUTOFMEMORY: DirectDraw does not have enough memory to perform the operation.";
		m_errcodes[DDERR_OUTOFVIDEOMEMORY] = "DDERR_OUTOFVIDEOMEMORY: DirectDraw does not have enough display memory to perform the operation.";
		m_errcodes[DDERR_OVERLAPPINGRECTS] = "DDERR_OVERLAPPINGRECTS: Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other.";
		m_errcodes[DDERR_OVERLAYCANTCLIP] = "DDERR_OVERLAYCANTCLIP: The hardware does not support clipped overlays.";
		m_errcodes[DDERR_OVERLAYCOLORKEYONLYONEACTIVE] = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE: An attempt was made to have more than one color key active on an overlay.";
		m_errcodes[DDERR_OVERLAYNOTVISIBLE] = "DDERR_OVERLAYNOTVISIBLE: The IDirectDrawSurface4::GetOverlayPosition method is called on a hidden overlay.";
		m_errcodes[DDERR_PALETTEBUSY] = "DDERR_PALETTEBUSY: Access to this palette is refused because the palette is locked by another thread.";
		m_errcodes[DDERR_PRIMARYSURFACEALREADYEXISTS] = "DDERR_PRIMARYSURFACEALREADYEXISTS: This process has already created a primary surface.";
		m_errcodes[DDERR_REGIONTOOSMALL] = "DDERR_REGIONTOOSMALL: The region passed to the IDirectDrawClipper::GetClipList method is too small.";
		m_errcodes[DDERR_SURFACEALREADYATTACHED] = "DDERR_SURFACEALREADYATTACHED: An attempt was made to attach a surface to another surface to which it is already attached.";
		m_errcodes[DDERR_SURFACEALREADYDEPENDENT] = "DDERR_SURFACEALREADYDEPENDENT: An attempt was made to make a surface a dependency of another surface to which it is already dependent.";
		m_errcodes[DDERR_SURFACEBUSY] = "DDERR_SURFACEBUSY: Access to the surface is refused because the surface is locked by another thread.";
		m_errcodes[DDERR_SURFACEISOBSCURED] = "DDERR_SURFACEISOBSCURED: Access to the surface is refused because the surface is obscured.";
		m_errcodes[DDERR_SURFACELOST] = "DDERR_SURFACELOST: Access to the surface is refused because the surface memory is gone. Call the IDirectDrawSurface4::Restore method on this surface to restore the memory associated with it.";
		m_errcodes[DDERR_SURFACENOTATTACHED] = "DDERR_SURFACENOTATTACHED: The requested surface is not attached.";
		m_errcodes[DDERR_TOOBIGHEIGHT] = "DDERR_TOOBIGHEIGHT: The height requested by DirectDraw is too large.";
		m_errcodes[DDERR_TOOBIGSIZE] = "DDERR_TOOBIGSIZE: The size requested by DirectDraw is too large. However, the individual height and width are valid sizes.";
		m_errcodes[DDERR_TOOBIGWIDTH] = "DDERR_TOOBIGWIDTH: The width requested by DirectDraw is too large.";
		m_errcodes[DDERR_UNSUPPORTED] = "DDERR_UNSUPPORTED: The operation is not supported.";
		m_errcodes[DDERR_UNSUPPORTEDFORMAT] = "DDERR_UNSUPPORTEDFORMAT: The pixel format requested is not supported by DirectDraw.";
		m_errcodes[DDERR_UNSUPPORTEDMASK] = "DDERR_UNSUPPORTEDMASK: The bitmask in the pixel format requested is not supported by DirectDraw.";
		m_errcodes[DDERR_UNSUPPORTEDMODE] = "DDERR_UNSUPPORTEDMODE: The display is currently in an unsupported mode.";
		m_errcodes[DDERR_VERTICALBLANKINPROGRESS] = "DDERR_VERTICALBLANKINPROGRESS: A vertical blank is in progress.";
		m_errcodes[DDERR_VIDEONOTACTIVE] = "DDERR_VIDEONOTACTIVE: The video port is not active.";
		m_errcodes[DDERR_WASSTILLDRAWING] = "DDERR_WASSTILLDRAWING: The previous blit operation that is transferring information to or from this surface is incomplete.";
		m_errcodes[DDERR_WRONGMODE] = "DDERR_WRONGMODE: This surface cannot be restored because it was created in a different mode.";
		m_errcodes[DDERR_XALIGN] = "DDERR_XALIGN: The provided rectangle was not horizontally aligned on a required boundary.";
	}

	if(a != S_OK) {
		if(m_errcodes.find(a) != m_errcodes.end()) {
			LOG_PUT("ERROR: %s", m_errcodes[a]);
		} else {
			LOG_PUT("ERROR: UNKNOWN");
		}
	}

	return *this;
}