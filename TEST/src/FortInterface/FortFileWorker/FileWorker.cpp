#include "i4pch.h"
#include "FileWorker.h"
#include <d3d9.h>
#include "d3dx9.h"


static LPDIRECT3DDEVICE9             g_pd3dDevice = NULL;

void I4GE::FileWorker::Init(IDirect3DDevice9* device)
{
	g_pd3dDevice = device;
	warehouse1 = new Warehouse(3);
}
I4GE::FileWorker::FileWorker()
{
	
}

I4GE::FileWorker::~FileWorker()
{

}


void I4GE::FileWorker::MyContent()
{	
	
	{
		static LPDIRECT3DTEXTURE9 ppTexture = NULL;
		ImGui::Begin("Animals");
			ImGui::BeginGroup();
				static bool d;
				if (!d)
				{
					D3DXCreateTextureFromFile(g_pd3dDevice, L"morderaccmanFace.png", &ppTexture);
					d = true;
				}
				ImGui::Image(ppTexture,ImVec2(250.0f,150.0f));
			ImGui::EndGroup();
			ImGui::SameLine();
		
			ImGui::BeginChild(2, ImVec2(200.0f, 0.0f));
				{
					ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
					if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
					{
						if (ImGui::BeginTabItem("General"))
						{
							ImGui::Text("Name:");
							ImGui::Text("Type:");
							ImGui::Text("Diet:");
							ImGui::EndTabItem();
						}
						if (ImGui::BeginTabItem("Size"))
						{
							ImGui::Text("Size:");
							ImGui::Text("Weight:");
							ImGui::EndTabItem();
						}
						if (ImGui::BeginTabItem("Life"))
						{
							static float Sliderpls;
							ImGui::Text("Wild life:");
							ImGui::Text("Not Wild life:");
							ImGui::SliderFloat("RedList", &Sliderpls, 0.0f, 100.0f);
							ImGui::EndTabItem();
						}
						ImGui::EndTabBar();
					}
				}
			ImGui::EndChild();
		ImGui::End();
	}
	if(show_fileworker)
	{
		ImGui::Begin("FileWorker");
		ImGui::Text("Name file");
		ImGui::SameLine();
		ImGui::InputText("", InputNameFile, 22);
		ImGui::SameLine();
		if (ImGui::Button("Create"))
		{
			std::string nameFile = InputNameFile;
			std::wstring stemp = Convert.s2ws(nameFile);
			LPCWSTR NameFile = stemp.c_str();
			CreateFile(NameFile, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		}
		ImGui::End();
	}
	if(show_optimization_tool)
	{
		ImGui::Begin("Optimization");
		ImGui::Text("System Info:\n    %.3f ms/frame\n    (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}
	//{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("FileWorker", NULL, &show_fileworker);
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Open Popup"))
			{
				ImGui::OpenPopup("Some Popup");
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Tools"))
		{
			ImGui::MenuItem("Optimization", NULL, &show_optimization_tool);
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{
			if (ImGui::MenuItem("Open Popup"))
			{
				ImGui::OpenPopup("Some Popup");
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("Helper", NULL, &show_helper);
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
	static LPDIRECT3DTEXTURE9 ppTexture = NULL;
	static int selectedBox;
	static bool d;
	warehouse1->TypeIndiacator(Irontype);
	warehouse1->TypeIndiacator(Coppertype);
	warehouse1->TypeIndiacator(Bolttype);
	ImGui::Begin("Warehouse");
	ImGui::BeginChild("left pane", ImVec2(150, 0), true);
	ImGui::BeginGroup();
	for (int i = 0; i < warehouse1->m_amountofBox; i++)
	{
		if (ImGui::Selectable(warehouse1->arrayBoxes[i].Name.c_str(), selectedBox == i))
			selectedBox = i;
	}
	ImGui::EndGroup();
	ImGui::EndChild();
	ImGui::SameLine();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
	ImGui::Text("Type:");
	ImGui::SameLine();
	ImGui::Text(warehouse1->arrayBoxes[selectedBox].Name.c_str());
	ImGui::Text("Capacity:");
	ImGui::SameLine();
	ImGui::Text(warehouse1->arrayBoxes[selectedBox].strcapacity.c_str());
	ImGui::Text("Description:");
	ImGui::SameLine();
	ImGui::Text(warehouse1->arrayBoxes[selectedBox].Description.c_str());
	ImGui::Text("Icon:");
	static int Changeofselected = 0;
	if (Changeofselected != selectedBox)
	{
		d = false;
		Changeofselected = selectedBox;
	}
	if (!d)
	{
		std::wstring stemp = Convert.s2ws(warehouse1->arrayBoxes[selectedBox].Icon);
		LPCWSTR NameFile = stemp.c_str();
		D3DXCreateTextureFromFile(g_pd3dDevice, NameFile, &ppTexture);
		d = true;
	}
	ImGui::SameLine();
	ImGui::Image(ppTexture, ImVec2(50.0f, 50.0f));
	ImGui::EndChild();
	ImGui::End();

}
void I4GE::FileWorker::DemoWindow(ImVec4 &clear_color)
{

	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	if(show_helper)
	{
		static float f = 0.0f;
		static int counter = 0;
		ImGui::ShowMetricsWindow((bool*)true);
		ImGui::Begin("Helper");
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		
		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
		ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);
		ImGui::End();
	}

	// 3. Show another simple window.
	if (show_another_window)
	{
		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}
}
void I4GE::FileWorker::RenderTriandle()
{
	
}