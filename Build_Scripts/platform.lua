local archMap = {};
archMap["target-x86-32"] = "x86";
archMap["target-x86-64"] = "x86_64";
archMap["target-arm"] = "ARM";
 
return require("lookupCmdArgs")(archMap, true);