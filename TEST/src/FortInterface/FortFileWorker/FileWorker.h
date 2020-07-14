#pragma once
#include "FortImGui/imgui.h"
#include <tchar.h>
#include "ConvertSheet.h"
#include <d3d9.h>
#include "FortInterface/IntefaceItem/Warehouse.h"

namespace I4GE {

	class FileWorker
	{
	private:
		Warehouse* warehouse1;
		Iron Irontype;
		Copper Coppertype;
		Bolt Bolttype;
		//inline static std::string nameFile = "Skr.obj";
		inline static char InputNameFile [22] ;
		ConvertSheet Convert;
		inline static bool show_demo_window = false;
		inline static bool show_helper = false;
		inline static bool show_another_window = false;
		inline static bool show_fileworker = false;
		inline static bool show_optimization_tool = true;
	public:
		
	public:
		FileWorker();
		~FileWorker();
		void Init(IDirect3DDevice9* device);
		void PlantContent();
		void RenderTriandle();
		void MyContent();
		void DemoWindow(ImVec4& clear_color);
	};

}