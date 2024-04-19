project "ImGui"
    kind "StaticLib"
    language "C++"

    targetdir ("lib/%{cfg.buildcfg}")
	objdir ("lib/%{cfg.buildcfg}")

    files
	{
		"include/imgui/imconfig.h",
		"include/imgui/imgui.h",
		"include/imgui/imgui.cpp",
		"include/imgui/imgui_draw.cpp",
		"include/imgui/imgui_internal.h",
		"include/imgui/imgui_widgets.cpp",
		"include/imgui/imstb_rectpack.h",
		"include/imgui/imstb_textedit.h",
		"include/imgui/imstb_truetype.h",
        "include/imgui/imgui_tables.cpp",
		"include/imgui/imgui_demo.cpp",
        "include/imgui/backends/imgui_impl_opengl3.cpp",
        "include/imgui/backends/imgui_impl_opengl3.h",
        "include/imgui/backends/imgui_impl_opengl3_loader.h",
        "include/imgui/backends/imgui_impl_glfw.cpp",
        "include/imgui/backends/imgui_impl_glfw.h",
        "include/imgui/extensions/*.cpp",
        "include/imgui/extensions/*.h",
	}

    includedirs
    {
        "%{IncludeDir.ImGui}/imgui",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
    }

	libdirs 
	{
		"%{LibraryDir.GLFW}",
		"%{LibraryDir.GLAD}",
	}

	links
	{
		"%{Library.GLFW}",
		"%{Library.GLAD}",
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
