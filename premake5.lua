workspace "Acorn"
	architecture "x86_64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputsdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Acorn"
	location "Acorn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputsdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputsdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines 
		{
			"AC_PLATFORM_WINDOWS",
			"AC_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputsdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AC_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputsdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputsdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Acorn/vendor/spdlog/include",
		"Acorn/src"
	}

	links
	{
		"Acorn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines 
		{
			"AC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AC_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"