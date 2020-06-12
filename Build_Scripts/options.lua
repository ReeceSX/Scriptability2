newoption {
    trigger = "target-x86-32",
    description = "Compiles x86_32 target and binaries"
}

newoption {
    trigger = "target-x86-64",
    description = "Compiles x86_64 target and binaries"
}

newoption {
    trigger = "target-arm",
    description = "Compiles arm aarch64 target and binaries (must have clang build chain or msvc arm optionals)"
}

newoption {
    trigger = "target-win32",
    description = "Specifies Win32 as the host and compile machine"
}

newoption {
    trigger = "target-ntos",
    description = "Specifies NTOS as the host and compile machine"
}

newoption {
    trigger = "target-linux",
    description = "Specifies linux as the host and compile machine"
}

newoption {
    trigger = "target-android",
    description = "Specifies android as the host and NDK build chain"
}

newoption {
    trigger = "target-linux-kernel",
    description = "Specifies linux-kernel as the host and compile machine"
}

newoption {
    trigger = "target-switch",
    description = "Specifies NX as the host and devkitpro build chain"
}

newoption {
    trigger = "target-ps4",
    description = "Specifies PS4 as the host and devkitpro build chain"
}

newoption {
    trigger = "target-cake",
    description = "secret source"
}


local tbl = 
{"target-x86-32", 
"target-x86-64",
"target-arm",
"target-win32",
"target-ntos",
"target-linux",
"target-android",
"target-linux-kernel",
"target-switch",
"target-ps4",
"target-cake" };

_G.scriptcfg = {}; 

for k in pairs(tbl) do
    k = tbl[k]
    if (_OPTIONS[k]) then
        _G.scriptcfg[k] = true;
    end
end