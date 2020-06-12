
function win32Fmt(name, type, dir, ex)     
    -- TODO: printf
    return "{COPY} \"%{cfg.targetdir}/".. name .. "." .. ex .. "\" \"" .. dir .. "/" .. name .. ".%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}.".. ex .. "*\"";
end

function postBuildCmdsCopyWindows(name, type, dir) 
    if (type == "SharedLib") then
        postbuildcommands {
            win32Fmt(name, type, dir, "dll")
        }
    elseif (type == "StaticLib") then
    elseif (type == "ConsoleApp") then
        postbuildcommands {
            win32Fmt(name, type, dir, "exe")
        }
    end
end

local handlers = {};
handlers["target-win32"] = postBuildCmdsCopyWindows;
return require("lookupCmdArgs")(handlers);