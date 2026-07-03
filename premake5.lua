workspace "pig-appimage-manager"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    project "PIG"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "build/%{cfg.buildcfg}"

    files {
        "include/**.hpp"
        "src/**.cpp"
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
