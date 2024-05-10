project "Premake"
	kind "Utility"

	-- wks는 현재 작업 중인 워크스페이스(workspace)를 나타내며, 
	-- location은 해당 워크스페이스의 디렉토리 경로를 나타냅니다. 
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{wks.location}/**premake5.lua"
	}

	postbuildmessage "Regenerating project files with Premake5!"
	postbuildcommands
	{
		"\"%{prj.location}bin/premake5\" %{_ACTION} --file=\"%{wks.location}premake5.lua\""
	}
