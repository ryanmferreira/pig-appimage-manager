workspace "pig-appimage-manager"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    project "pig"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "build/%{cfg.buildcfg}/%{cfg.architecture}"
    objdir "build/%{cfg.buildcfg}/%{cfg.architecture}/obj"

    toolset "clang"

    includedirs {"include"}

    files {
        "include/**.hpp",
        "src/**.cpp"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
