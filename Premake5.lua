include "Dependencies.lua"

workspace "ZVEngine"
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

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Vendor/Premake5"
	include "Vendor/ImGui"
	include "Vendor/glad"
group ""

include "ZVCore"
include "ZVEngine"
