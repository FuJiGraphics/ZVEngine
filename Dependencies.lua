
-- Dependencies
VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["ZVCore"]	= "%{wks.location}/ZVCore/ZVCore/src"
IncludeDir["ImGui"]		= "%{wks.location}/Vendor/ImGui/include"
IncludeDir["FZLib"]		= "%{wks.location}/Vendor/FZLib/include"
IncludeDir["GLFW"]		= "%{wks.location}/Vendor/GLFW/include"
IncludeDir["GLAD"]		= "%{wks.location}/Vendor/glad/include"
IncludeDir["SOIL2"]		= "%{wks.location}/Vendor/SOIL2/include"
IncludeDir["OpenCV"]	= "%{wks.location}/Vendor/OpenCV2/include"

LibraryDir = {}
LibraryDir["FZLib"]		= "%{wks.location}/Vendor/FZLib/lib/%{cfg.buildcfg}/%{cfg.architecture}"
LibraryDir["GLFW"]		= "%{wks.location}/Vendor/GLFW/lib/%{cfg.buildcfg}"
LibraryDir["ImGui"]		= "%{wks.location}/Vendor/ImGui/lib/%{cfg.buildcfg}"
LibraryDir["GLAD"]		= "%{wks.location}/Vendor/glad/lib/%{cfg.buildcfg}"
LibraryDir["SOIL2"]		= "%{wks.location}/Vendor/SOIL2/lib/"..os.target().."/%{cfg.buildcfg}"
LibraryDir["OpenCV"]	= "%{wks.location}/Vendor/OpenCV2/lib/%{cfg.buildcfg}"

Library = {}
Library["FZLib"]		= "%{wks.location}/Vendor/FZLib/lib/%{cfg.buildcfg}/%{cfg.architecture}/FZLib.lib"
Library["GLFW"]			= "%{wks.location}/Vendor/GLFW/lib/%{cfg.buildcfg}/glfw3.lib"
Library["ImGui"]		= "%{wks.location}/Vendor/ImGui/lib/%{cfg.buildcfg}/ImGui.lib"
Library["GLAD"]			= "%{wks.location}/Vendor/glad/lib/%{cfg.buildcfg}/glad.lib"
Library["SOIL2"]		= "%{wks.location}/Vendor/SOIL2/lib/"..os.target().."/%{cfg.buildcfg}/soil2.lib"
Library["OpenCV"]		= "%{wks.location}/Vendor/OpenCV2/lib/%{cfg.buildcfg}/opencv.lib"

