/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: entrypoint.cpp
    Date: 2020-6-9
    Originator: Reece
    Purpose:
***/
#include <ScriptabilityCommon.hpp>

#include "test.hpp"
#include "console.hpp"

using namespace Scriptability::UnitTesting;

extern void RunTests();

int main(int argsc, const char ** argsv)
{
    Console::Init();
    RunTests();
    return ToExitCode(TestResponse::kPass);
}    