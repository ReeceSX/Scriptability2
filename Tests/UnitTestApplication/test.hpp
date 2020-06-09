/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s].
    Please do no evil.

    File: test.hpp
    Date: 2020-6-9
    Originator: Reece
    Purpose:
***/
#pragma once

static_assert(sizeof(int) <= sizeof(uint32_t), "not enough space to store exit code in sizeof(int)");

namespace Scriptability::UnitTesting
{
    const uint16_t kExitMagic = 0x1771; // avoid UB by avoiding twos complement

    enum class TestResponse
    {
        kPass,
        kPassWithWarn,
        kUnitError,
        kScriptabilityError
    };

    static int ToExitCode(TestResponse code)
    {
        uint32_t exit = 0;

        exit |= (kExitMagic << 16);
        exit |= static_cast<uint16_t>(code);

        return static_cast<int>(exit);
    }

    static bool ToTestResponse(int code, TestResponse &response)
    {
        uint32_t exit = static_cast<int>(code);

        if (((exit >> 16) & 0xFFFF) != kExitMagic)
            return false;

        response = static_cast<TestResponse>(exit & 0xFFFF);

        return true;
    }
}