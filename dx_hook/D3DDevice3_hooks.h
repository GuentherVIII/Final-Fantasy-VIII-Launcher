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

#ifndef _D3DDEVICE3_HOOKS
#define _D3DDEVICE3_HOOKS

#include <ddraw.h>
#include <d3d.h>
#include <windows.h>
#include <stdio.h>
#include "apihijack.h"
#include "HOOKS_BASE.h"

extern SVTBL_HOOK d3ddevice3_hooks[];
extern const unsigned int count_d3ddevice3_hooks;
extern bool ishooked_d3ddevice3_hooks;

//DECLARATIONS
typedef HRESULT (__stdcall *D3DDEVICE3_QueryInterface_Type)(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);
HRESULT __stdcall D3DDEVICE3_HOOK_QueryInterface(LPVOID *ppvOut, REFIID riid, LPVOID FAR *ppvObj);

typedef ULONG (__stdcall *D3DDEVICE3_AddRef_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DDEVICE3_HOOK_AddRef(LPVOID *ppvOut);

typedef ULONG (__stdcall *D3DDEVICE3_Release_Type)(LPVOID *ppvOut);
ULONG __stdcall D3DDEVICE3_HOOK_Release(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DDEVICE3_GetCaps_Type)(LPVOID *ppvOut, LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc);
HRESULT __stdcall D3DDEVICE3_HOOK_GetCaps(LPVOID *ppvOut, LPD3DDEVICEDESC lpD3DHWDevDesc, LPD3DDEVICEDESC lpD3DHELDevDesc);

typedef HRESULT (__stdcall *D3DDEVICE3_GetStats_Type)(LPVOID *ppvOut, LPD3DSTATS lpD3DStats);
HRESULT __stdcall D3DDEVICE3_HOOK_GetStats(LPVOID *ppvOut, LPD3DSTATS lpD3DStats);

typedef HRESULT (__stdcall *D3DDEVICE3_AddViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport);
HRESULT __stdcall D3DDEVICE3_HOOK_AddViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport);

typedef HRESULT (__stdcall *D3DDEVICE3_DeleteViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport);
HRESULT __stdcall D3DDEVICE3_HOOK_DeleteViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport);

typedef HRESULT (__stdcall *D3DDEVICE3_NextViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport, LPDIRECT3DVIEWPORT3 *lplpAnotherViewport, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_NextViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpDirect3DViewport, LPDIRECT3DVIEWPORT3 *lplpAnotherViewport, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_EnumTextureFormats_Type)(LPVOID *ppvOut, LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpArg);
HRESULT __stdcall D3DDEVICE3_HOOK_EnumTextureFormats(LPVOID *ppvOut, LPD3DENUMPIXELFORMATSCALLBACK lpd3dEnumTextureProc, LPVOID lpArg);

typedef HRESULT (__stdcall *D3DDEVICE3_BeginScene_Type)(LPVOID *ppvOut);
HRESULT __stdcall D3DDEVICE3_HOOK_BeginScene(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DDEVICE3_EndScene_Type)(LPVOID *ppvOut);
HRESULT __stdcall D3DDEVICE3_HOOK_EndScene(LPVOID *ppvOut);

typedef HRESULT (__stdcall *D3DDEVICE3_GetDirect3D_Type)(LPVOID *ppvOut, LPDIRECT3D3 *lplpD3D);
HRESULT __stdcall D3DDEVICE3_HOOK_GetDirect3D(LPVOID *ppvOut, LPDIRECT3D3 *lplpD3D);

typedef HRESULT (__stdcall *D3DDEVICE3_SetCurrentViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpd3dViewport);
HRESULT __stdcall D3DDEVICE3_HOOK_SetCurrentViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 lpd3dViewport);

typedef HRESULT (__stdcall *D3DDEVICE3_GetCurrentViewport_Type)(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpd3dViewport);
HRESULT __stdcall D3DDEVICE3_HOOK_GetCurrentViewport(LPVOID *ppvOut, LPDIRECT3DVIEWPORT3 *lplpd3dViewport);

typedef HRESULT (__stdcall *D3DDEVICE3_SetRenderTarget_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpNewRenderTarget, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_SetRenderTarget(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 lpNewRenderTarget, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_GetRenderTarget_Type)(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpRenderTarget);
HRESULT __stdcall D3DDEVICE3_HOOK_GetRenderTarget(LPVOID *ppvOut, LPDIRECTDRAWSURFACE4 *lplpRenderTarget);

typedef HRESULT (__stdcall *D3DDEVICE3_Begin_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dpt, DWORD dwVertexTypeDesc, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_Begin(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dpt, DWORD dwVertexTypeDesc, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_BeginIndexed_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_BeginIndexed(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_Vertex_Type)(LPVOID *ppvOut, LPVOID lpVertex);
HRESULT __stdcall D3DDEVICE3_HOOK_Vertex(LPVOID *ppvOut, LPVOID lpVertex);

typedef HRESULT (__stdcall *D3DDEVICE3_Index_Type)(LPVOID *ppvOut, WORD wVertexIndex);
HRESULT __stdcall D3DDEVICE3_HOOK_Index(LPVOID *ppvOut, WORD wVertexIndex);

typedef HRESULT (__stdcall *D3DDEVICE3_End_Type)(LPVOID *ppvOut, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_End(LPVOID *ppvOut, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_GetRenderState_Type)(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState);
HRESULT __stdcall D3DDEVICE3_HOOK_GetRenderState(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState);

typedef HRESULT (__stdcall *D3DDEVICE3_SetRenderState_Type)(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState);
HRESULT __stdcall D3DDEVICE3_HOOK_SetRenderState(LPVOID *ppvOut, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState);

typedef HRESULT (__stdcall *D3DDEVICE3_GetLightState_Type)(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState);
HRESULT __stdcall D3DDEVICE3_HOOK_GetLightState(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState);

typedef HRESULT (__stdcall *D3DDEVICE3_SetLightState_Type)(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState);
HRESULT __stdcall D3DDEVICE3_HOOK_SetLightState(LPVOID *ppvOut, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState);

typedef HRESULT (__stdcall *D3DDEVICE3_SetTransform_Type)(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);
HRESULT __stdcall D3DDEVICE3_HOOK_SetTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);

typedef HRESULT (__stdcall *D3DDEVICE3_GetTransform_Type)(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);
HRESULT __stdcall D3DDEVICE3_HOOK_GetTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);

typedef HRESULT (__stdcall *D3DDEVICE3_MultiplyTransform_Type)(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);
HRESULT __stdcall D3DDEVICE3_HOOK_MultiplyTransform(LPVOID *ppvOut, D3DTRANSFORMSTATETYPE dtstTransformStateType, LPD3DMATRIX lpD3DMatrix);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawPrimitive_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitive(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawIndexedPrimitive_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitive(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_SetClipStatus_Type)(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus);
HRESULT __stdcall D3DDEVICE3_HOOK_SetClipStatus(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus);

typedef HRESULT (__stdcall *D3DDEVICE3_GetClipStatus_Type)(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus);
HRESULT __stdcall D3DDEVICE3_HOOK_GetClipStatus(LPVOID *ppvOut, LPD3DCLIPSTATUS lpD3DClipStatus);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawPrimitiveStrided_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitiveStrided(LPVOID *ppvOut, D3DPRIMITIVETYPE dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawIndexedPrimitiveStrided_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitiveStrided(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD dwVertexTypeDesc, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwVertexCount, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawPrimitiveVB_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawPrimitiveVB(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, DWORD dwStartVertex, DWORD dwNumVertices, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_DrawIndexedPrimitiveVB_Type)(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);
HRESULT __stdcall D3DDEVICE3_HOOK_DrawIndexedPrimitiveVB(LPVOID *ppvOut, D3DPRIMITIVETYPE d3dptPrimitiveType, LPDIRECT3DVERTEXBUFFER lpd3dVertexBuffer, LPWORD lpwIndices, DWORD dwIndexCount, DWORD dwFlags);

typedef HRESULT (__stdcall *D3DDEVICE3_ComputeSphereVisibility_Type)(LPVOID *ppvOut, LPD3DVECTOR lpCenters, LPD3DVALUE lpRadii, DWORD dwNumSpheres, DWORD dwFlags, LPDWORD lpdwReturnValues);
HRESULT __stdcall D3DDEVICE3_HOOK_ComputeSphereVisibility(LPVOID *ppvOut, LPD3DVECTOR lpCenters, LPD3DVALUE lpRadii, DWORD dwNumSpheres, DWORD dwFlags, LPDWORD lpdwReturnValues);

typedef HRESULT (__stdcall *D3DDEVICE3_GetTexture_Type)(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 *lplpTexture);
HRESULT __stdcall D3DDEVICE3_HOOK_GetTexture(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 *lplpTexture);

typedef HRESULT (__stdcall *D3DDEVICE3_SetTexture_Type)(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 lpTexture);
HRESULT __stdcall D3DDEVICE3_HOOK_SetTexture(LPVOID *ppvOut, DWORD dwStage, LPDIRECT3DTEXTURE2 lpTexture);

typedef HRESULT (__stdcall *D3DDEVICE3_GetTextureStageState_Type)(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, LPDWORD lpdwValue);
HRESULT __stdcall D3DDEVICE3_HOOK_GetTextureStageState(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, LPDWORD lpdwValue);

typedef HRESULT (__stdcall *D3DDEVICE3_SetTextureStageState_Type)(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, DWORD dwValue);
HRESULT __stdcall D3DDEVICE3_HOOK_SetTextureStageState(LPVOID *ppvOut, DWORD dwStage, D3DTEXTURESTAGESTATETYPE dwState, DWORD dwValue);

typedef HRESULT (__stdcall *D3DDEVICE3_ValidateDevice_Type)(LPVOID *ppvOut, LPDWORD lpdwPasses);
HRESULT __stdcall D3DDEVICE3_HOOK_ValidateDevice(LPVOID *ppvOut, LPDWORD lpdwPasses);

#endif