project "ZVMotion"
    kind "StaticLib"
    language "C++"

    targetdir ("../lib/%{cfg.buildcfg}")
	objdir ("../lib/%{cfg.buildcfg}")

    files
	{
		"%{IncludeDir.ZVLAB}/ZVMotion/src/**.h",
		"%{IncludeDir.ZVLAB}/ZVMotion/src/**.cpp",
	}

    includedirs
    {
		"%{IncludeDir.ZVLAB}/ZVMotion/src/",
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
