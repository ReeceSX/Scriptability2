local isWin = _G.scriptcfg["target-win32"]

project "Common Include"

    targetname("common")
    language("C++")
    cppdialect("C++17")
    kind("SharedLib")
    location("../Include")

    if (isWin) then
        characterset("MBCS")
        staticruntime("Off")
    end

    defines
    {
        "_ITERATOR_DEBUG_LEVEL=0",
    }

    files
    {
        "../Include/**.hpp"
    }
