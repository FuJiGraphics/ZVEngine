project "ZVEngine"
		location "ZVEngine"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
    systemversion "latest"  

    targetdir ("../Dist/")
    objdir ("../Dist/")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp",
    }

	includedirs
    {
        "%{prj.name}",
        "%{prj.name}/core",
        "%{prj.name}/src",
		"%{IncludeDir.ZVCore}/export/",
		"%{IncludeDir.FZLib}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.SOIL2}",
		"%{IncludeDir.OpenCV}",
    }

	libdirs 
	{
		"%{LibraryDir.SOIL2}",
		"%{LibraryDir.OpenCV}",

	}

	links
	{
		"ZVCore",
		"%{Library.FZLib}",
		"%{Library.GLFW}",
		"%{Library.SOIL2}",
		"%{Library.OpenCV}",
		"GLAD",
		"ImGui",
		"Opengl32.lib", 
	}

	postbuildcommands 
	{ 
		"{RMDIR} %[Dist/log/]",
	}

    filter "system:Windows"
    defines
    {
        "ZV_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
        defines "ZV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "ZV_RELEASE"
        runtime "Release"
        optimize "On"