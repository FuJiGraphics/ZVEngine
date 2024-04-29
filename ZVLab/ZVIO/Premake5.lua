project "ZVIO"
    kind "StaticLib"
    language "C++"

    targetdir ("../lib/%{cfg.buildcfg}")
	objdir ("../lib/%{cfg.buildcfg}")

    files
	{
		"%{IncludeDir.ZVLAB}/ZVIO/src/**.h",
		"%{IncludeDir.ZVLAB}/ZVIO/src/**.cpp",
	}

    includedirs
    {
		"%{IncludeDir.ZVLAB}/ZVIO/src/",
		"%{IncludeDir.FZLib}",
		"%{IncludeDir.ACS}",
    }

	libdirs 
	{
		"%{LibraryDir.FZLib}",
	}

	links
	{
		"%{Library.FZLib}",
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"
		defines
		{
			"ZV_PLATFORM_WINDOWS",
		}

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
