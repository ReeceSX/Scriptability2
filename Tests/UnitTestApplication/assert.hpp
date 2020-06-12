/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: assert.hpp
    Date: 2020-6-9
    Originator: Reece
    Purpose:
***/
#pragma once

#include <string>

namespace Scriptability::UnitTesting
{
    template<typename... Args>
    static void Assert(bool value, const char * function, const char * file, int line, const std::string &fmt, Args... args)
    {
        if (value) 
            return;
            
        Console::Warn("assertion hit - %s#%i (%s)", file, line, function);
        Console::Warn(fmt, args...);
        
        EndTest(TestResponse::kUnitError);
    }
}

#define UnitAssert(tru, str, ...)                                                          \
    do {                                                                                   \
        Scriptability::UnitTesting::Assert(tru, __FUNCTION__, __FILE__, __LINE__, str, __VA_ARGS__); \
    } while (0)
