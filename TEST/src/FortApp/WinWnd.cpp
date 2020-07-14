#include "i4pch.h"
#include "WinWnd.h"


static LPDIRECT3DDEVICE9			g_pd3dDevice = NULL;
static LPDIRECT3DVERTEXDECLARATION9 g_Decl;
static D3DPRESENT_PARAMETERS		g_d3dpp;
static LPDIRECT3D9					pD3D;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);




LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
/*
I4GE::WinWnd* Create(const I4GE::WinWnd::WinWndProp& props)
{
	return new WinWnd(props);
}
*/

I4GE::WinWnd::WinWnd()
{
	Files = new FileWorker();
}

I4GE::WinWnd::~WinWnd()
{

}

int I4GE::WinWnd::init()
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;
	std::wstring stemp1 = Convert.s2ws(WWprop.m_Title);
	LPCWSTR WindTitle = stemp1.c_str();
	std::wstring stemp2 = Convert.s2ws(WWprop.m_ClassName);
	LPCWSTR	WindClass = stemp2.c_str();
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW/*CS_CLASSDC*/, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, WindClass, NULL };

	RegisterClassEx(&wc);
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		UnregisterClass(WindClass, wc.hInstance);
		return 0;
	}
	
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;//D3DFMT_UNKNOWN;
	g_d3dpp.BackBufferWidth = WWprop.m_Width;
	g_d3dpp.BackBufferHeight = WWprop.m_Height;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE; // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // Present without vsync, maximum unthrottled framerate

	// create a device class using this information and the info from the d3dpp stuct
	
	hwnd = CreateWindow(WindClass, WindTitle, WS_OVERLAPPEDWINDOW, 100, 100, WWprop.m_Width, WWprop.m_Height, NULL, NULL, wc.hInstance, NULL);
	// Create the D3DDevice
	

	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, /*D3DDEVTYPE_REF*/D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{
		pD3D->Release();
		UnregisterClass(WindClass, wc.hInstance);
		return 0;
	}
	
	SetContextSheet(hwnd);
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);

	wcD2 = wc;
	hwndD2 = hwnd;
	msgD2 = msg;
	return 1;
}
void I4GE::WinWnd::SetContextSheet(HWND hwnd)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	// Setup Platform/Renderer bindings
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX9_Init(g_pd3dDevice);
	Files->Init(g_pd3dDevice);

	//sq_Tst_Sheet.CreateData(GetWndWidth(), GetWndHeight());
	// Setup Style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	hwndD2 = hwnd;
}
void I4GE::WinWnd::Shoutdown(WNDCLASSEX wc, HWND hwnd)
{
	std::wstring stemp2 = Convert.s2ws(WWprop.m_ClassName);
	LPCWSTR	WindClass = stemp2.c_str();
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	DestroyWindow(hwnd);
	UnregisterClass(WindClass, wc.hInstance);
}
void I4GE::WinWnd::LoopSre()
{
	// Start the Dear ImGui frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Files->DemoWindow(clear_color);
	Files->MyContent();
	// Rendering
	ImGui::EndFrame();
	D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * 255.0f), (int)(clear_color.y * 255.0f), (int)(clear_color.z * 255.0f), (int)(clear_color.w * 255.0f));
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
	

	g_pd3dDevice->EndScene();
	if (g_pd3dDevice->BeginScene() >= 0)
	{

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		g_pd3dDevice->EndScene();
	}
	
	HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	

	// Handle loss of D3D9 device
	if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		g_pd3dDevice->Reset(&g_d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}

}
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
