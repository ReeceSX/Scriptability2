local defintions = require("preprocessors")
local projectCopyCmds = require("buildPostProcess")

local isWin = _G.scriptcfg["target-win32"] == true

function setupProject(name, type, ship) 
    project(name)

    targetname(name)
    language("C++")
    cppdialect("C++17")
    kind(type)

    if (isWin) then
        characterset("MBCS")
        staticruntime("Off")
    end

    location(name)

    defines
    {
        "_ITERATOR_DEBUG_LEVEL=0",
    }

    defines(defintions)

    includedirs
    {
        "Include",
        name .. "/Include"
    }

    files
    {
        name .. "/Source/**.*pp",
        name .. "/Source/**.masm"
    }

    if projectCopyCmds ~= true then
        if ship then
            projectCopyCmds(name, type, "../Build_Ship")
        end
        projectCopyCmds(name, type, "../Build_Developers")
    end
end

return setupProject