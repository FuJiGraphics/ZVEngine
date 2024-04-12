project "glad"
    kind "StaticLib"
    language "C++"

    targetdir ("lib/%{cfg.buildcfg}")
	objdir ("lib/%{cfg.buildcfg}")

	includedirs
	{
		"%{IncludeDir.GLAD}",
	}

    files
	{
		"%{wks.location}/Vendor/glad/include/glad/glad.h",
		"%{wks.location}/Vendor/glad/include/KHR/khrplatform.h",
		"%{wks.location}/Vendor/glad/src/glad.c",
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
