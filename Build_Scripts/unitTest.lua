local defintions = require("preprocessors")
local projectCopyCmds = require("buildPostProcess")

local isWin = _G.scriptcfg["target-win32"]

function setupUnitTest(name, ship) 
    project(name)

    targetname(name)
    language("C++")
    cppdialect("C++17")
    kind("ConsoleApp")

    if (isWin) then
        characterset("MBCS")
        staticruntime("Off")
    end
    

    location("Tests/" .. name)

    defines
    {
        "_ITERATOR_DEBUG_LEVEL=0",
    }

    defines(defintions)

    includedirs
    {
        "Include",
        "Tests/UnitTestApplication",
        "Tests/" .. name 
    }

    files
    {
        "Tests/UnitTestApplication/**.*pp",
        "Tests/" .. name .. "/**.*pp",
        "Tests/" .. name .. "/**.masm",
    }

    if projectCopyCmds ~= true then
        projectCopyCmds(name, "ConsoleApp", "../../Build_Developers/Tests")
    end
end

return setupUnitTest