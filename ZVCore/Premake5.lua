project "ZVCore"
	location "ZVCore"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
systemversion "latest"  

files
{
	"%{prj.name}/src/**.cpp",
	"%{prj.name}/src/**.h",
}

includedirs
{
	"%{prj.name}",
    "%{prj.name}/src",
	"%{IncludeDir.FZLib}",
	"%{IncludeDir.GLFW}",
	"%{IncludeDir.ImGui}",
	"%{IncludeDir.GLAD}",
	"%{IncludeDir.SOIL2}",
	"%{IncludeDir.OpenCV}",
}

libdirs 
{
	"%{LibraryDir.FZLib}",
	"%{LibraryDir.GLFW}",
	"%{LibraryDir.SOIL2}",
	"%{LibraryDir.OpenCV}",
}

links
{
	"%{Library.FZLib}",
	"%{Library.GLFW}",
	"%{Library.SOIL2}",
	"%{Library.OpenCV}",
	"GLAD",
	"ImGui",
	"Opengl32.lib",
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