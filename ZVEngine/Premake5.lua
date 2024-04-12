project "ZVEngine"
		location "ZVEngine"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
    systemversion "latest"  

    targetdir ("Dist/")
    objdir ("Dist/")

	prebuildcommands
	{
		"{MKDIR} %[Dist/lib/%{cfg.buildcfg}/%{cfg.architecture}/]",
	} 

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp",
    }

	includedirs
    {
        "%{prj.name}",
        "%{prj.name}/src",
		"%{IncludeDir.ZVCore}",
		"%{IncludeDir.FZLib}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
    }

	libdirs 
	{
	}

	links
	{
		"ZVCore",
		"%{Library.FZLib}",
		"%{Library.GLFW}",
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