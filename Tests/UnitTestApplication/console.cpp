/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: console.cpp
    Date: 2020-6-9
    Originator: Reece
    Purpose: Lightweight and portable unit test abstraction
***/
#include <ScriptabilityCommon.hpp>

#include "console.hpp"

#if defined(SCRIPTABILITY_PLATFORM_WIN32)
#include <windows.h>
#endif

#include <string>
#include <cstdio>
#include <array>
#include <stdarg.h>

using namespace Scriptability::UnitTesting;
using namespace Scriptability::UnitTesting::Console;

#if defined(SCRIPTABILITY_PLATFORM_WIN32)
static bool SupportsColor = false;
#else
static bool SupportsColor = true;
#endif

std::array<std::string, static_cast<size_t>(AnsiColor::kCount)> AnsiCheats  {
    "\033[0;31m",
    "\033[1;31m",
    "\033[0;32m",
    "\033[1;32m",
    "\033[0;33m",
    "\033[01;33m"
    "\033[0;34m",
    "\033[1;34m",
    "\033[0;35m",
    "\033[1;35m",
    "\033[0;36m",
    "\033[1;36m",
    "\033[0m",
    "\033[0m"
};

static std::string FormatPrintfIn(const std::string &prefix, const std::string &fmt, AnsiColor color)
{
    std::string ret;

    if (SupportsColor)
    {
        ret = AnsiCheats[static_cast<size_t>(color)];
    }

    ret += "[" + prefix + "]\t| ";
    ret += fmt;

    if (SupportsColor)
    {
        ret += AnsiCheats[static_cast<size_t>(AnsiColor::kReset)];
    }

    return  ret;
}

void Console::WriteLine(const std::string &prefix, const std::string &fmt, AnsiColor color, ...)
{
    va_list args;
    char *buffer;
    size_t length;
    
    auto temp = FormatPrintfIn(prefix, fmt, color);

    va_start(args, color);
    {
        length = vsnprintf(nullptr, 0, temp.c_str(), args) + 1;

        if (length == 1)
        {
            puts("vsprint error");
            return;
        }

        buffer = reinterpret_cast<char *>(alloca(length));

        if (!buffer)
        {
            puts("undefined behaviour");
            return;
        }

        buffer[length - 1] = '\0'; // be safe :)
        vsnprintf(buffer, length, temp.c_str(), args);
    }
    va_end(args);

    puts(buffer);
}

void Console::Init()
{
    #ifdef SCRIPTABILITY_PLATFORM_WIN32
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (handle == INVALID_HANDLE_VALUE)
    {
        puts("couldn't enable color. bad handle");
        return;
    }

    DWORD mode = 0;
    if (!(GetConsoleMode(handle, &mode) &&
        SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)))
    {
        puts("couldn't enable color");
        return;
    }
     
    SupportsColor = true;
    #endif
}