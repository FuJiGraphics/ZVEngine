include "Dependencies.lua"

workspace "ZVEngine"
	architecture "x86_64"
	startproject "ZVCore"

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

outputdir = "Build/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/"

group "Dependencies"
	include "Vendor/Premake5"
	include "Vendor/ImGui"
	include "Vendor/glad"
group ""

include "ZVCore"