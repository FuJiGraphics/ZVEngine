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
}

libdirs 
{
	"%{LibraryDir.FZLib}",
	"%{LibraryDir.GLFW}",
	"%{LibraryDir.SOIL2}",
}

links
{
	"%{Library.FZLib}",
	"%{Library.GLFW}",
	"%{Library.SOIL2}",
	"GLAD",
	"ImGui",
	"Opengl32.lib",
}

filter "system:Windows"
defines
{
    "ZV_PLATFORM_WINDOWS",
}

postbuildcommands {
    -- 폴더를 만들고 파일을 복사하는 명령 추가
    "{MKDIR} %{wks.location}/include/ZVCore/",
	"{COPY} %{IncludeDir.ZVCore}/ %{wks.location}/include/ZVCore",
	"{DELETE} %{wks.location}/include/ZVCore/platform/**.cpp",
}

filter "configurations:Debug"
    defines "ZV_DEBUG"
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    defines "ZV_RELEASE"
    runtime "Release"
    optimize "On"