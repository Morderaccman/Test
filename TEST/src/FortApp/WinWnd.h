#pragma once

#include "FortImGui/imgui.h"
#include "FortImGui/FortD3D9/imgui_impl_dx9.h"
#include "FortImGui/FortD3D9/imgui_impl_win32.h"
#include <d3d9.h>
#include "FortInterface/FortFileWorker/FileWorker.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include "ConvertSheet.h"


namespace I4GE
{
	class WinWnd
	{
	public:
		WNDCLASSEX wcD2;
		HWND hwndD2;
		MSG msgD2;
		
	private:
		
		ImVec4 clear_color = ImVec4(0.200f, 0.200f, 0.200f, 1.00f);
		ConvertSheet Convert;
		FileWorker* Files;
	public:
		
	public:
		struct WinWndProp
		{
			std::string m_ClassName;
			std::string m_Title;
			unsigned int m_Width;
			unsigned int m_Height;
			WinWndProp(const std::string ClassName = "I4",
				const std::string Title = "I4GE - Create Some Cool Sheet",
				unsigned int Width = 1080,
				unsigned int Height = 720)
				: m_ClassName(ClassName), m_Title(Title), m_Width(Width), m_Height(Height)
			{}
		};
	public:
		WinWndProp& WWprop = WinWnd::WinWndProp();
		std::string GetWndTitle()   { return WWprop.m_Title; }
		unsigned int GetWndWidth()  { return WWprop.m_Width; }
		unsigned int GetWndHeight() { return WWprop.m_Height; }
		WinWnd();
		~WinWnd();
		int init();
		void SetContextSheet(HWND hwnd);
		void Shoutdown(WNDCLASSEX wc, HWND hwnd);
		void LoopSre();
	};
	WinWnd* Create(const WinWnd::WinWndProp& props = WinWnd::WinWndProp());
}