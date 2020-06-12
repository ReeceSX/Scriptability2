/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s].
    Please do no evil.

    File: ScriptabilityTypes.hpp
    Date: 2020-6-12
    Originator: Reece
    Purpose:
***/
#pragma once

namespace Scriptability::Types
{
    #if defined(SCRIPTABILITY_COMPILER_MSVC)
        using int8_t   = signed char;
        using int16_t  = short;
        using int32_t  = int;
        using int64_t  = long long;
        using uint8_t  = unsigned char;
        using uint16_t = unsigned short;
        using uint32_t = unsigned int;
        using uint64_t = unsigned long long;
    
    #elif defined(SCRIPTABILITY_COMPILER_CLANG) || defined(SCRIPTABILITY_COMPILER_GCC8)
        using int8_t   = __INT8_TYPE__;  
        using int16_t  = __INT16_TYPE__;   
        using int32_t  = __INT32_TYPE__;   
        using int64_t  = __INT64_TYPE__;   
        using uint8_t  = __UINT8_TYPE__;   
        using uint16_t = __UINT16_TYPE__;
        using uint32_t = __UINT32_TYPE__;
        using uint64_t = __UINT64_TYPE__;
    #endif

    #if defined(SCRIPTABILITY_X86)
        using size_t = uint32_t;
    #elif defined(SCRIPTABILITY_X64)
        using size_t = uint64_t;
    #elif defined(SCRIPTABILITY_ARM)
        using size_t = uint64_t;
    #else
        #error unsupported architecture. current supports: aarch64, x86_64, x86_32
    #endif
}