/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s].
    Please do no evil.

    File: ScriptabilityEnvrionment.hpp
    Date: 2020-6-9
    Originator: Reece
    Purpose:
***/
#pragma once

#if defined(__clang_major__)
    #define SCRIPTABILITY_COMPILER_CLANG
#elif defined(_MSC_VER)
    #define SCRIPTABILITY_COMPILER_MSVC
#elif __GNUC__ > 8 || __GNUC__ == 8
    #define SCRIPTABILITY_COMPILER_GCC8
    #define SCRIPTABILITY_COMMUNISM_COMPILER
#elif __GNUC__
    #error GCC outdated
#else
    #error Illegal Compiler
#endif

#if defined(_LINUX_KERNEL_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_KERNEL_LINUX
#elif defined(_NTOS_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_NTOS
#elif defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
    #define SCRIPTABILITY_PLATFORM_WIN32
#elif defined(__ANDROID__) || defined(_ANDROID_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_ANDROID
#elif defined(__linux__) || defined(_LINUX_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_LINUX
#elif defined(_SWITCH_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_SWITCH
#elif defined(_PS4_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_PS4
#elif defined(_WII_SCRIPTABILITY_PREPROCESSOR)
    #define SCRIPTABILITY_PLATFORM_WII
#endif

#if defined(SCRIPTABILITY_COMPILER_MSVC)

    #if defined(_M_X64)
        #define SCRIPTABILITY_ABI_MSFT_64
        #define SCRIPTABILITY_X64
    #else
        #define SCRIPTABILITY_X86
        #define SCRIPTABILITY_ABI_CDECL
    #endif

    #define SCRIPTABILITY_SYMBOL_IMPORT __declspec(dllimport) 
    #define SCRIPTABILITY_SYMBOL_EXPORT extern __declspec(dllexport) 

#elif defined(SCRIPTABILITY_COMMUNISM_COMPILER) ||  defined(SCRIPTABILITY_COMPILER_CLANG)

    #if defined(__x86_64__)
        #define SCRIPTABILITY_X64
        #if defined(SCRIPTABILITY_PLATFORM_WIN32) || defined(SCRIPTABILITY_PLATFORM_NTOS)
            #define SCRIPTABILITY_ABI_MSFT_64
        #else
            #define SCRIPTABILITY_ABI_SYSV
        #endif
    #elif defined(__aarch64__)
        #define SCRIPTABILITY_ARM
        #define SCRIPTABILITY_ABI_ARM
    #else
        #define SCRIPTABILITY_X86
        #define SCRIPTABILITY_ABI_CDECL
    #endif

    #define SCRIPTABILITY_SYMBOL_IMPORT __attribute__(dllimport) 
    #define SCRIPTABILITY_SYMBOL_EXPORT extern __attribute__(dllexport) 

#endif
