local triggerPairs = { };
triggerPairs["target-linux"] = "_LINUX_SCRIPTABILITY_PREPROCESSOR";
triggerPairs["target-switch"] = "_SWITCH_SCRIPTABILITY_PREPROCESSOR";
triggerPairs["target-android"] = "_ANDROID_SCRIPTABILITY_PREPROCESSOR";
triggerPairs["target-linux-kernel"] = "_LINUX_KERNEL_SCRIPTABILITY_PREPROCESSOR";
triggerPairs["target-ntos"] = "_NTOS_SCRIPTABILITY_PREPROCESSOR";
triggerPairs["target-ps4"] = "_PS4_SCRIPTABILITY_PREPROCESSOR";
return require("lookupCmdArgs")(triggerPairs, true);