include "Dependencies.lua"

workspace "ZScreen"
	architecture "x86_64"
	startproject "ZVEngine"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "Build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Vendor/Premake5"
	include "Vendor/ImGui"
	include "Vendor/glad"
group ""

include "ZVCore"
include "ZVEngine"
