project "StbImage"
    kind "StaticLib"
    language "C++"

    targetdir ("lib/%{cfg.buildcfg}")
	objdir ("lib/%{cfg.buildcfg}")

	includedirs
	{
		"%{IncludeDir.STBIMAGE}",
	}

    files
	{
		"%{wks.location}/Vendor/StbImage/include/stb_image.h",
		"%{wks.location}/Vendor/StbImage/include/stb_image.cpp",
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
