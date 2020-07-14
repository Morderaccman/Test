workspace "Test1"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--IncludeDirs = {}
--IncludeDirs["GLFW"] = "VOI.I4GE/glfw/include"
--IncludeDirs["Glad"] = "VOI.I4GE/Glad/include"
--IncludeDirs["ImGui"] = "VOI.I4GE/ImGui"
--IncludeDirs["vulkan-1"] = "VOI.I4GE/VulkanSDK"

--include "VOI.I4GE/glfw"
--include "VOI.I4GE/Glad"
--include "VOI.I4GE/ImGui"
--include "VOI.I4GE/VulkanSDK"

project "TEST"
	location "TEST"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir ("OutputDir/" .. outputdir .. "/%{prj.name}")
	objdir ("InterDir/" .. outputdir .. "/%{prj.name}")

	pchheader "i4pch.h"
	pchsource "TEST/src/i4pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"TEST/src",
		"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
	}

	links
	{
		"d3d9.lib",
		"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx9.lib"
		--"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dxof.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"I4_WND_PLATFORM",
			"I4_DLL"
		}

	filter "configurations:Debug"
		defines "I4_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "I4_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "I4_DIST"
		runtime "Release"
		symbols "On"

