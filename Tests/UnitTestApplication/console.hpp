/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s].
    Please do no evil.

    File: console.hpp
    Date: 2020-6-9
    Originator: Reece
    Purpose:
***/
#pragma once

#include <string>

namespace Scriptability::UnitTesting::Console
{
    enum class AnsiiColor
    {
        kRed,
        kBoldRed,
        kGreen,
        kBoldGreen,
        kYellow,
        kBoldYellow,
        kBlue,
        kBoldBlue,
        kMagenta,
        kBoldMagenta,
        kCyan,
        kBoldCyan,
        kReset,
        kCount
    };

    void Init();
    void WriteLine(const std::string &prefix, const std::string &fmt, AnsiiColor color, ...);

    template<typename... Args>
    static void Log(const std::string &fmt, Args... args)
    {
        WriteLine("Log", fmt, AnsiiColor::kGreen, args...);
    }

    template<typename... Args>
    static void Warn(const std::string &fmt, Args... args)
    {
        WriteLine("Warn", fmt, AnsiiColor::kRed, args...);
    }

    template<typename... Args>
    static void Debug(const std::string &fmt, Args... args)
    {
        WriteLine("Debug", fmt, AnsiiColor::kYellow, args...);
    }
}