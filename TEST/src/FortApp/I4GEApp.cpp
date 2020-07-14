#include "i4pch.h"
#include "FortApp/I4GEApp.h"

namespace I4GE {

	I4GEApp::I4GEApp()
	{
		winWnd = new WinWnd();
		isRightCreatedWindow = winWnd->init();

	}

	I4GEApp::~I4GEApp()
	{
		WNDCLASSEX wc = winWnd->wcD2;
		HWND hwnd = winWnd->hwndD2;
		winWnd->Shoutdown(wc, hwnd);
	}

	void I4GEApp::Run()
	{
		MSG msg = winWnd->msgD2;
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				continue;
			}
			winWnd->LoopSre();
		}
	}

	I4GEApp* I4GE::MakeApp()
	{
		return new I4GEApp();
	}
}