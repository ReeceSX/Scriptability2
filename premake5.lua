require("options")


local unitTestPlatforms = {"target-win32", "target-linux"}
local scriptabilityLuaPlatforms = {"target-win32", "target-linux", "target-android", "target-switch"}
local expectedSupport = {"target-ps4", "target-switch", "target-linux-kernel"}

for k in pairs(expectedSupport) do
    if (_OPTIONS[k]) then
        print("Platform support should be implemented soon :tm:")
        return
    end
end

local defintions = require("preprocessors")
local projectCopyCmds = require("buildPostProcess");


local isWin = _G.scriptcfg["target-win32"]
    

platforms(require("platform"));


workspace "Scriptability"
    configurations { "Debug", "Release" }

    location "Build_WorkingDirectory"

    symbols "On"
    staticruntime "On"

    filter "configurations:Debug"
        targetdir "bin/debug"
        defines { "DEBUG" }

    filter "configurations:Release"
        targetdir "bin/release"
        defines { "NDEBUG" }
        optimize "Size"

    filter {}

    flags { "NoIncrementalLink" }
    editandcontinue "Off"


setupProject = require("project")
setupUnitTest = require("unitTest")

group "Code"

if (isWin) then
    require("vscommon")
end 

setupProject("ScriptabilityCore", "SharedLib", true);


group "Unit Tests"

setupUnitTest("All")