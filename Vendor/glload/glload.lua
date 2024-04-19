project "glload"
    kind "StaticLib"
    language "C++"

    targetdir ("lib/%{cfg.buildcfg}")
	objdir ("lib/%{cfg.buildcfg}")

	includedirs
	{
		"%{IncludeDir.GLLOAD}",
	}

    files
	{
		"%{wks.location}/Vendor/glload/include/glload/gl_*.h",
		"%{wks.location}/Vendor/glload/include/glload/gl_*.hpp",
		"%{wks.location}/Vendor/glload/include/glload/gll.h",
		"%{wks.location}/Vendor/glload/include/glload/gll.hpp",
		"%{wks.location}/Vendor/glload/src/gl_*",
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
	
	configuration "plainc"
		excludes {
			"source/*.cpp",
			"include/glload/*.hpp",
		}
	
	configuration "windows"
		defines {"WIN32"}
		files {"include/glload/wgl_*.h",}
		files {"source/wgl_*"}
	
	configuration "linux"
	    defines {"LOAD_X11"}
		files {"include/glload/glx_*.h"}
		files {"source/glx_*"}

	configuration "Debug"
		flags "Unicode";
		defines {"DEBUG", "_DEBUG", "MEMORY_DEBUGGING"};
		objdir "Debug";
		flags "Symbols";
		targetname "glloadD";

	configuration "Release"
		defines {"NDEBUG", "RELEASE"};
		flags "Unicode";
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		objdir "Release";
		targetname "glload"
