/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: test.cpp
    Date: 2020-6-12
    Originator: Reece
    Purpose: Lightweight and portable unit test abstraction
***/
#include <ScriptabilityCommon.hpp>
#include "test.hpp"

#include <stdlib.h>

void Scriptability::UnitTesting::EndTest(TestResponse response)
{
    exit(ToExitCode(response));
}