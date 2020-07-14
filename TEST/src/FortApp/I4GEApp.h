#pragma once

#include "i4pch.h"

#include "FortImGui/imgui.h"
#include "FortImGui/FortD3D9/imgui_impl_dx9.h"
#include "FortImGui/FortD3D9/imgui_impl_win32.h"
#include <d3d9.h>
#include "WinWnd.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

namespace I4GE {

	class I4GEApp
	{
	private:
		WinWnd* winWnd;
		
	public:
		int isRightCreatedWindow;
	public:
		I4GEApp();
		~I4GEApp();
		
		
		void Run();
		
	};
	I4GEApp* MakeApp();
}
